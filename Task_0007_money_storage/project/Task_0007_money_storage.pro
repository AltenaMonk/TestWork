TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    MoneyValue.cpp \
    String.cpp
    String.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    MoneyValue.h \
    String.h

