TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../source/main.cpp \
    ../source/Listnode.cpp \
    ../source/List.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../source/Listnode.h \
    ../source/List.h

