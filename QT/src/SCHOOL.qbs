import qbs.FileInfo

QtApplication {
    Depends { name: "Qt.widgets" }

    cpp.defines: [
        // You can make your code fail to compile if it uses deprecated APIs.
        // In order to do so, uncomment the following line.
        //"QT_DISABLE_DEPRECATED_BEFORE=0x060000" // disables all the APIs deprecated before Qt 6.0.0
    ]

    files: [
        "admenu.cpp",
        "admenu.h",
        "admenu.ui",
        "admin.cpp",
        "admin.h",
        "admin.ui",
        "image.qrc",
        "main.cpp",
        "mainwindow.cpp",
        "mainwindow.h",
        "mainwindow.ui",
        "pic/pss_3.png",
        "rank.cpp",
        "rank.h",
        "rank.ui",
        "scoremenu.cpp",
        "scoremenu.h",
        "scoremenu.ui",
        "student.cpp",
        "student.h",
        "student.ui",
        "stupassmod.cpp",
        "stupassmod.h",
        "stupassmod.ui",
        "stuscore.cpp",
        "stuscore.h",
        "stuscore.ui",
        "teacher.cpp",
        "teacher.h",
        "teacher.ui",
        "teamenu.cpp",
        "teamenu.h",
        "teamenu.ui",
        "teapassmod.cpp",
        "teapassmod.h",
        "teapassmod.ui",
        "tmodify.cpp",
        "tmodify.h",
        "tmodify.ui",
        "tsearch.cpp",
        "tsearch.h",
        "tsearch.ui",
    ]

    install: true
    installDir: qbs.targetOS.contains("qnx") ? FileInfo.joinPaths("/tmp", name, "bin") : base
}
