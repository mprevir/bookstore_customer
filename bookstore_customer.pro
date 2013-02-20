#-------------------------------------------------
#
# Project created by QtCreator 2013-02-17T16:41:34
#
#-------------------------------------------------

QT       += core gui
QT +=sql\

TARGET = bookstore_customer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    book.cpp

HEADERS  += mainwindow.h \
    login.h \
    book.h

FORMS    += mainwindow.ui \
    login.ui
