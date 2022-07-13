QT -= gui

QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = server
TEMPLATE = app

OBJECTS_DIR = .obj
MOC_DIR = .moc
UI_DIR = .uic
RCC_DIR = .rcc


DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    tcpserver.cpp

HEADERS += \
    tcpserver.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
