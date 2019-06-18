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
        src/codegen.cpp \
        src/io.cpp \
        src/lexer.cpp \
        src/parser.cpp \
        src/stb.c \
  src/lemon-parser.c \

HEADERS += \
  src/ast.hpp \
  src/c_lexer.h \
  src/codegen.hpp \
  src/io.hpp \
  src/lexer.hpp \
  src/parser.hpp \
  src/lemon-parser.h

DISTFILES += \
  src/lemon-parser.out \
  src/lemon-parser.ly
