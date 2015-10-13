TEMPLATE = lib
CONFIG += staticlib
CONFIG += qt
QT+=widgets
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++11
HEADERS = MainWidget.hh
HEADERS += Home.hh
HEADERS += Contact.hh
HEADERS += Conversation.hh
HEADERS += LoginWidget.hh
SOURCES = MainWidget.cpp
SOURCES += Contact.cpp
SOURCES += Home.cpp
SOURCES += Conversation.cpp
SOURCES += LoginWidget.cpp
