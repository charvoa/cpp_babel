TEMPLATE = app
unix {
QMAKE_CXX = g++-4.9
}

QMAKE_CXXFLAGS += -std=c++11

QT+=widgets
QT+=network

HEADERS += Thread.hh
HEADERS += Network/NetworkServerHandler.hh
HEADERS += User/PTUser.hh
HEADERS += Network/TCPProtocolHelper.hh
HEADERS += Mutex/Mutex.hh

SOURCES += Network/TCPProtocolHelper.cpp
SOURCES += main.cpp
SOURCES += User/PTUser.cpp
SOURCES += Network/NetworkServerHandler.cpp
SOURCES += Mutex/Mutex.cpp
SOURCES += Mutex/MutexLocker.cpp
SOURCES += Contact/Contact.cpp
unix {
LIBS += ../gui/libgui.a
LIBS +=  -lasound -lpthread -lrt
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
