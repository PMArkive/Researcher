QT += widgets

TARGET = Researcher
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++1z

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Forms/Researcher.ui

HEADERS += \
    Core/Global.hpp \
    Core/IRNG.hpp \
    Core/IRNG64.hpp \
    Core/LCRNG.hpp \
    Core/LCRNG64.hpp \
    Core/MTRNG.hpp \
    Core/ResearcherFrame.hpp \
    Core/ResearcherModel.hpp \
    Core/SFMT.hpp \
    Core/TinyMT.hpp \
    Forms/Controls/TextBox.hpp \
    Forms/Researcher.hpp

SOURCES += \
    Core/LCRNG.cpp \
    Core/LCRNG64.cpp \
    Core/MTRNG.cpp \
    Core/ResearcherFrame.cpp \
    Core/ResearcherModel.cpp \
    Core/SFMT.cpp \
    Core/TinyMT.cpp \
    Forms/Controls/TextBox.cpp \
    Forms/Researcher.cpp \
    main.cpp
