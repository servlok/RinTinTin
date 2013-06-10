#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T18:14:52
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui
QT       += sql

TARGET = RinTinTinvol2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Communication/server.cpp \
    Communication/tcpsocket.cpp \
    Communication/socketpool.cpp \
    Communication/communication.cpp \
    Deserialization/pakiet.cpp \
    Parser/protocolparser.cpp \
    Exceptions/badpackageexception.cpp \
    Exceptions/exception.cpp \
    Deserialization/deserializacja.cpp \
    Logic/dataaccessobject.cpp \
    Logic/logika.cpp \
    Logic/stategetcomments.cpp \
    Logic/stategetrestaurant.cpp \
    Logic/statedefault.cpp

HEADERS += \
    Communication/server.h \
    Communication/tcpsocket.h \
    Communication/socketpool.h \
    Communication/communication.h \
    Deserialization/pakiet.h \
    Parser/protocolparser.h \
    Parser/packettype.h \
    Exceptions/badpackageexception.h \
    Exceptions/exception.h \
    Deserialization/deserializacja.h \
    Logic/dataaccessobject.h \
    Logic/logika.h \
    Logic/stategetcomments.h \
    Logic/stategetrestaurant.h \
    Logic/statedefault.h


