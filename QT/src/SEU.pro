QT       += core gui
QT       += sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admenu.cpp \
    admin.cpp \
    main.cpp \
    mainwindow.cpp \
    rank.cpp \
    school.cpp \
    scoremenu.cpp \
    student.cpp \
    stupassmod.cpp \
    stuscore.cpp \
    teacher.cpp \
    teamenu.cpp \
    teapassmod.cpp \
    tmodify.cpp \
    tsearch.cpp

HEADERS += \
    admenu.h \
    admin.h \
    mainwindow.h \
    rank.h \
    school.h \
    scoremenu.h \
    student.h \
    stupassmod.h \
    stuscore.h \
    teacher.h \
    teamenu.h \
    teapassmod.h \
    tmodify.h \
    tsearch.h

FORMS += \
    admenu.ui \
    admin.ui \
    mainwindow.ui \
    rank.ui \
    school.ui \
    scoremenu.ui \
    student.ui \
    stupassmod.ui \
    stuscore.ui \
    teacher.ui \
    teamenu.ui \
    teapassmod.ui \
    tmodify.ui \
    tsearch.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    EYE.JPG \
    LIB.png \
    SCHOOL.qbs \
    SCHOOL.qbs.user \
    SEU.pro.user \
    apass.txt \
    doubt.txt \
    pass.txt \
    score.txt \
    tpass.txt
