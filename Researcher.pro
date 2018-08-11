#-------------------------------------------------
#
# Project created by QtCreator 2018-08-11T15:13:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Researcher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Forms/Researcher.ui

HEADERS += \
    Core/IRNG.hpp \
    Core/IRNG64.hpp \
    Core/LCRNG.hpp \
    Core/LCRNG64.hpp \
    Core/MTRNG.hpp \
    Core/ResearcherFrame.hpp \
    Core/ResearcherModel.hpp \
    Core/SFMT.hpp \
    Core/TinyMT.hpp \
    Forms/Controls/QTextBox.hpp \
    Forms/Researcher.hpp

SOURCES += \
    Core/LCRNG.cpp \
    Core/LCRNG64.cpp \
    Core/MTRNG.cpp \
    Core/ResearcherFrame.cpp \
    Core/ResearcherModel.cpp \
    Core/SFMT.cpp \
    Core/TinyMT.cpp \
    Forms/Controls/QTextBox.cpp \
    Forms/Researcher.cpp \
    main.cpp
