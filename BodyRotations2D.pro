QT += core widgets

QMAKE_CXX = clang++
CONFIG += c++17

HEADERS += \
    body.H \
    canvas.H

SOURCES += \
    body.C \
    canvas.C \
    main.C

