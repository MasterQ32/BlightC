#ifndef AST_HPP
#define AST_HPP

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include "types.hpp"

namespace Ast
{
    struct TranslationContext {
        llvm::LLVMContext & context;
        llvm::IRBuilder<> & builder;
    };

    enum class UnaryOperator
    {
        Minus,        //  -
        Plus,         //  +
        BitInvert,    //  ~
        LogicNot,     //  !
        SizeOf,       //  sizeof
        PreIncrement, //  ++
        PreDecrement, //  --
        AddressOf,    //  &
        Dereference,  //  *
    };

    enum class BinaryOperator
    {
        Add,            //  +
        Subtract,       //  -
        Multiply,       //  *
        Divide,         //  /
        Modulo,         //  %
        LogicAnd,       //  &&
        LogicOr,        //  ||
        BinaryAnd,      //  &
        BinaryOr,       //  |
        BinaryXor,      //  ^
        Equals,         //  ==
        Differs,        //  !=
        Greater,        //  >
        GreaterOrEqual, //  >=
        Less,           //  <
        LessOrEqual,    //  <=
        ShiftLeft,      //  <<
        ShiftRight,     //  >>
        // assignment-ops are pre-separated in the AST generation process
    };

    struct Location { int line, column; };

    struct Node
    {
        Location start, end;

        virtual ~Node();
    };

    struct Expression : Node
    {
        virtual ~Expression() = default;

        virtual llvm::Value * translate(TranslationContext & ctx) = 0;
    };

    struct BinaryExpression : Expression
    {
        std::unique_ptr<Expression> lhs, rhs;
        BinaryOperator op;

        explicit BinaryExpression(
                BinaryOperator _op,
                std::unique_ptr<Expression> && _lhs,
                std::unique_ptr<Expression> && _rhs
            ) : lhs(std::move(_lhs)), rhs(std::move(_rhs)), op(_op)
        {

        }

        llvm::Value * translate(TranslationContext &ctx) override {
            auto *L = lhs->translate(ctx);
            auto *R = rhs->translate(ctx);
            if (!L || !R)
                return nullptr;

            switch (op)
            {
            case BinaryOperator::Add:      return ctx.builder.CreateAdd(L, R, "addtmp");
            case BinaryOperator::Subtract: return ctx.builder.CreateSub(L, R, "subtmp");
            case BinaryOperator::Multiply: return ctx.builder.CreateMul(L, R, "multmp");
            default: return nullptr;
            }
        }
    };

    struct IntConstant : Expression
    {
        blightc_long value;
        explicit IntConstant(blightc_long val) : value(val) { }

        llvm::Value * translate(TranslationContext &ctx) override {
            return llvm::ConstantInt::get(ctx.context, llvm::APInt(32, value, true));
        }
    };
}

#endif // AST_HPP
