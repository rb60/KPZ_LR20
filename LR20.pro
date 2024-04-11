QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cheese.cpp \
    chessedialog.cpp \
    creamery.cpp \
    creamerydialog.cpp \
    dairyfarm.cpp \
    farmdialog.cpp \
    listvisitor.cpp \
    main.cpp \
    mainwindow.cpp \
    milk.cpp \
    milkdialog.cpp

HEADERS += \
    cheese.h \
    chessedialog.h \
    creamery.h \
    creamerydialog.h \
    dairyfarm.h \
    farmdialog.h \
    listvisitor.h \
    mainwindow.h \
    milk.h \
    milkdialog.h \
    visitor.h \
    visitorelement.h

FORMS += \
    chessedialog.ui \
    creamerydialog.ui \
    farmdialog.ui \
    mainwindow.ui \
    milkdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
