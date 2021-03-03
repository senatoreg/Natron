boost: LIBS += -lboost_serialization
PKGCONFIG += expat
PKGCONFIG += fontconfig
QMAKE_CFLAGS -= -include Python.h
QMAKE_CXXFLAGS -= -include Python.h
QMAKE_CFLAGS += $$system($$PYTHON_CONFIG --includes) -include Python.h
QMAKE_CXXFLAGS += $$system($$PYTHON_CONFIG --includes) -include Python.h

equals(QT_MAJOR_VERSION, 5) {
cairo {
        PKGCONFIG += cairo
        LIBS -=  $$system(pkg-config --variable=libdir cairo)/libcairo.a
}
pyside {
        PKGCONFIG -= pyside
        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)
        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtCore
        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtGui
        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside2)/QtWidgets
        INCLUDEPATH += $$system(pkg-config --variable=includedir Qt5Core)
        INCLUDEPATH += $$system(pkg-config --variable=includedir Qt5Gui)
        INCLUDEPATH += $$system(pkg-config --variable=includedir Qt5Widgets)
        #LIBS += -lpyside-python2.7
        LIBS += $$system(pkg-config --libs pyside2) $$system(pkg-config --libs python3-embed)
}
shiboken {
        PKGCONFIG -= shiboken
        INCLUDEPATH += $$system(pkg-config --variable=includedir shiboken2)
        #LIBS += -lshiboken2-python2.7
        LIBS += $$system(pkg-config --libs shiboken2) $$system(pkg-config --libs python3-embed)
}
#shiboken:  INCLUDEPATH -= $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken
shiboken:  INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/shiboken

#pyside:    INCLUDEPATH -= $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2
pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2

#pyside:    INCLUDEPATH -= $$system(python2 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
pyside:    INCLUDEPATH += $$system(python3 -c \"from distutils.sysconfig import get_python_lib; print(get_python_lib())\")/PySide2/include/PySide2/QtCore
}

python: LIBS += $$system(pkg-config  --libs python3-embed)
