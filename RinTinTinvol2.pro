#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T18:14:52
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = RinTinTinvol2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Communication/server.cpp \
    Communication/tcpsocket.cpp \
    Communication/socketpool.cpp \
    Communication/communication.cpp \
   # Logic/logika.cpp \
   # Deserialization/dataaccessobject.cpp \
   # Deserialization/deserializacja.cpp \
    Deserialization/pakiet.cpp \
    Parser/protocolparser.cpp \
    Exceptions/badpackageexception.cpp \
    Exceptions/exception.cpp
   # Communication/datasender.cpp


HEADERS += \
    Communication/server.h \
    Communication/tcpsocket.h \
    Communication/socketpool.h \
    Communication/communication.h \
   # Logic/logika.h \
   # Deserialization/dataaccessobject.h \
   # Deserialization/deserializacja.h \
    Deserialization/pakiet.h \
    Parser/protocolparser.h \
    Parser/packettype.h \
    Exceptions/badpackageexception.h \
    Exceptions/exception.h
   # Communication/datasender.h
