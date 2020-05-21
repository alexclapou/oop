######################################################################
# Automatically generated by qmake (3.1) Mon May 18 21:45:56 2020
######################################################################

TEMPLATE = app
TARGET = 10
INCLUDEPATH += .
QT += gui widgets

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += gui.h \
    action.h \
    moc_predefs.h \
    repository.h \
    repositoryexception.h \
    service.h \
    task.h \
    ui_gui.h \
    validatetask.h
FORMS += gui.ui
SOURCES += gui.cpp main.cpp \
    action.cpp \
    moc_gui.cpp \
    repository.cpp \
    repositoryexception.cpp \
    service.cpp \
    task.cpp \
    ui_gui.cpp \
    validatetask.cpp

DISTFILES += \
    10 \
    10.pro.user \
    Makefile \
    gui.o \
    main.o \
    moc_gui.o
