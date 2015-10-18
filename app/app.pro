TEMPLATE = app
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -std=c++11
QT+=widgets
QT+=network
SOURCES = main.cpp
SOURCES += User/PTUser.cpp
SOURCES += Network/NetworkServerHandler.cpp
LIBS = ../gui/libgui.a
TARGET = ../babelUI
