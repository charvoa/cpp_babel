TEMPLATE = lib
CONFIG += staticlib
CONFIG += qt
QT+=widgets
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++11
HEADERS = MyWidget.hh
HEADERS += Home.hh
HEADERS += Contact.hh
SOURCES = MyWidget.cpp
SOURCES += Contact.cpp
SOURCES += Home.cpp
