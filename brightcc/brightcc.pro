TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$quote(/home/felix/projects/stb/)

linux: {
  LIBS += -lstdc++fs
}

SOURCES += \
        main.cpp \
        src/ast.cpp \
  src/bison-parser.tab.cc \
        src/codegen.cpp \
        src/io.cpp \
        src/lexer.cpp \
        src/parser.cpp \
        src/stb.c \

HEADERS += \
  src/ast.hpp \
  src/bison-parser.tab.hh \
  src/bison-parser.yy \
  src/c_lexer.h \
  src/codegen.hpp \
  src/io.hpp \
  src/lexer.hpp \
  src/parser.hpp \
  src/lemon-parser.h

DISTFILES +=
