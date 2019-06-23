#include <iostream>
#include "src/io.hpp"
#include "src/parser.hpp"
#include "src/ast.hpp"
#include <cctype>

#include <chrono>
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using time_point = high_resolution_clock::time_point;

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

int main(int argc, char ** argv)
{
    {
        using namespace llvm;
        LLVMContext TheContext;
        IRBuilder<> Builder(TheContext);
        std::unique_ptr<Module> TheModule = llvm::make_unique<Module>("blightc_module", TheContext);

        auto rootExpr = std::make_unique<Ast::BinaryExpression>(
            Ast::BinaryOperator::Multiply,
            std::make_unique<Ast::IntConstant>(10),
            std::make_unique<Ast::BinaryExpression>(
                Ast::BinaryOperator::Add,
                std::make_unique<Ast::IntConstant>(20),
                std::make_unique<Ast::IntConstant>(30)
            )
        );

        Function * fun =
        ({
             // Make the function type:  double(double,double) etc.
             std::vector<Type*> params;
             auto * FT = FunctionType::get(Type::getInt32Ty(TheContext), params, false);

             Function *F = Function::Create(FT, Function::ExternalLinkage, "main", TheModule.get());

             unsigned idx = 0;
             for (auto & arg : F->args())
             arg.setName("arg" + std::to_string(idx++));

             {   // not a prototype
                 // Create a new basic block to start insertion into.
                 BasicBlock *BB = BasicBlock::Create(TheContext, "entry", F);
                 Builder.SetInsertPoint(BB);

                 //                NamedValues.clear();
                 //                for (auto &Arg : TheFunction->args())
                 //                  NamedValues[Arg.getName()] = &Arg;

                 Ast::TranslationContext ctx {TheContext, Builder};

                 if (Value *RetVal = rootExpr->translate(ctx)) {
                     // Finish off the function.
                     Builder.CreateRet(RetVal);

                     // Validate the generated code, checking for consistency.
                     verifyFunction(*F);
                 }
                 else {
                     // Error reading body, remove function.
                     F->eraseFromParent();
                     F = nullptr;
                 }
             }
             F;
         });

        // Print out all of the generated code.
        TheModule->print(errs(), nullptr);

        return 0;
    }


    auto const main_file = IO::load_file(argv[1]);

    if(not main_file)
        return 1;

    std::string source(main_file->data(), main_file->size());

    Parser parser;

    time_point const start = high_resolution_clock::now();
    if(not parser.parse(source)) {
        std::cerr << "Failed to parse the input file!" << std::endl;
        return 1;
    }
    time_point const end = high_resolution_clock::now();

    std::cout << "parsing took " << duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0 << "ms" << std::endl;

    return 0;
}
