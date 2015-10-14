TEMPLATE = app
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -std=c++11
QT+=widgets
SOURCES = main.cpp
SOURCES += User/PTUser.cpp

LIBS = ../gui/libgui.a
TARGET = ../babelUI
