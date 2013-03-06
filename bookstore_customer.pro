#-------------------------------------------------
#
# Project created by QtCreator 2013-02-17T16:41:34
#
#-------------------------------------------------

QT       += core gui
QT +=sql\

#INCLUDEPATH+=D:\Qt\Desktop\Qt\4.8.1\mingw\plugins\sqldrivers
#QTPLUGIN += qsqloci4
#CONFIG += static

QMAKE_LFLAGS += -static-libgcc
TARGET = bookstore_customer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    book.cpp \
    usersetting.cpp

HEADERS  += mainwindow.h \
    login.h \
    book.h \
    usersetting.h

FORMS    += mainwindow.ui \
    login.ui \
    usersetting.ui
