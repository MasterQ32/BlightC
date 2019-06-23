TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$quote(/home/felix/projects/stb/)

linux: {
  LIBS += -lstdc++fs

  RPATK_ROOT = /home/felix/projects/rpatk/
  INCLUDEPATH += $$quote($$RPATK_ROOT)
  INCLUDEPATH += $$quote($$RPATK_ROOT/arch/unix/x86_64)
  LIBS += -L$$quote($$RPATK_ROOT/rpa/build/unix/x86_64/out) -lrpa
  LIBS += -L$$quote($$RPATK_ROOT/rvm/build/unix/x86_64/out) -lrvm
  LIBS += -L$$quote($$RPATK_ROOT/rlib/build/unix/x86_64/out) -lrlib

  QMAKE_CXXFLAGS += $$system(llvm-config --cxxflags)
  LIBS           += $$system(llvm-config --cxxflags --ldflags --system-libs --libs core)
}

SOURCES += \
        main.cpp \
        src/ast.cpp \
        src/codegen.cpp \
        src/io.cpp \
        src/parser.cpp \
        src/stb.c \

HEADERS += \
  src/ast.hpp \
  src/c_lexer.h \
  src/codegen.hpp \
  src/io.hpp \
  src/parser.hpp \
  src/types.hpp

DISTFILES += \
  src/bison-parser.yy \
  src/blight-c.bnf
