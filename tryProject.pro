QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    diagram_manager/IntervalSample.cpp \
    diagram_manager/Plot.cpp \
    diagram_manager/PlotCurve.cpp \
    diagram_manager/PlotHistogram.cpp \
    diagram_manager/PlotIntervalCurve.cpp \
    diagram_manager/PlotMarker.cpp \
    diagram_manager/Symbol.cpp \
    main.cpp \
    mainwindow.cpp \
    tmp.cpp

HEADERS += \
    diagram_manager/Curve.h \
    diagram_manager/CurveCreator.h \
    diagram_manager/Diagram.h \
    diagram_manager/DiagramCreator.h \
    diagram_manager/IntervalObject.h \
    diagram_manager/IntervalObjectCreator.h \
    diagram_manager/IntervalSample.h \
    diagram_manager/Marker.h \
    diagram_manager/MarkerCreator.h \
    diagram_manager/Plot.h \
    diagram_manager/PlotCreator.h \
    diagram_manager/PlotCurve.h \
    diagram_manager/PlotCurveCreator.h \
    diagram_manager/PlotHistogram.h \
    diagram_manager/PlotHistogramCreator.h \
    diagram_manager/PlotIntervalCurve.h \
    diagram_manager/PlotIntervalCurveCreator.h \
    diagram_manager/PlotMarker.h \
    diagram_manager/PlotMarkerCreator.h \
    diagram_manager/Symbol.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QWTPATH += "$$PWD/qwt"

win32 {
    CONFIG(debug, debug|release) {
        QMAKE_PRE_LINK=xcopy \"$(subst /,\\,$$QWTPATH)\\qwtd.dll\" \".\\debug\" /F /Y
        LIBS += "$$QWTPATH/qwtd.dll"
    }
    CONFIG(release, debug|release) {
        QMAKE_PRE_LINK=xcopy \"$(subst /,\\,$$QWTPATH)\\qwt.dll\" \".\\release\" /F /Y
        LIBS += "$$QWTPATH/qwt.dll"
    }
}

INCLUDEPATH += $$QWTPATH
VPATH += $$QWTPATH
