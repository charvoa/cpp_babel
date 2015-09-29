TEMPLATE = app
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -std=c++11
QT+=widgets
SOURCES = main.cpp

LIBS = ../core/libcore.a
TARGET = ../babelUI
