TEMPLATE = lib
CONFIG += staticlib
CONFIG += qt
QT+=widgets
QT+=network
QT+=concurrent
unix {
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++11
}
HEADERS = MainWidget.hh
HEADERS += Home.hh
HEADERS += Contact.hh
HEADERS += Conversation.hh
HEADERS += LoginWidget.hh
HEADERS += SignupWidget.hh
HEADERS += DataHandler.hh

SOURCES = MainWidget.cpp
SOURCES += Contact.cpp
SOURCES += Home.cpp
SOURCES += Conversation.cpp
SOURCES += LoginWidget.cpp
SOURCES += SignupWidget.cpp
SOURCES += DataHandler.cpp
