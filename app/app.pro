TEMPLATE = app
unix {
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -Werror
}

QMAKE_CXXFLAGS += -std=c++11

QT+=widgets
QT+=network
QT+=concurrent
HEADERS += Thread.hh
HEADERS += Network/NetworkServerHandler.hh
HEADERS += User/PTUser.hh
SOURCES = main.cpp
SOURCES += User/PTUser.cpp
SOURCES += Network/NetworkServerHandler.cpp
unix {
LIBS = ../gui/libgui.a
}
win32 {
LIBS = ..\gui\release\gui.lib
}
unix {
TARGET = ../babelUI
}

win32 {
TARGET = ..\babelUI
}
