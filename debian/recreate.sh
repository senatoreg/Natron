#!/bin/sh 
echo =========================
echo Building Engine
echo =========================
shiboken2 --avoid-protected-hack --enable-pyside-extensions -I. -IEngine -IGlobal -Ilibs/OpenFX/include -I/usr/include $(pkg-config --cflags shiboken2) $(pkg-config --cflags pyside2) $(pkg-config --cflags Qt5Core | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Gui | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Widgets | sed 's,-D[a-zA-Z0-9_]\+,,g') --typesystem-paths=/usr/share/PySide2/typesystems --output-directory=Engine Engine/Pyside2_Engine_Python.h Engine/typesystem2_engine.xml
echo =========================
echo Building Gui
echo =========================
shiboken2 --avoid-protected-hack --enable-pyside-extensions -I. -IEngine -IGlobal -IGui -Ilibs/OpenFX/include -I/usr/include $(pkg-config --cflags shiboken2) $(pkg-config --cflags pyside2) $(pkg-config --cflags Qt5Core | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Gui | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Widgets | sed 's,-D[a-zA-Z0-9_]\+,,g') --typesystem-paths=/usr/share/PySide2/typesystems:Engine --output-directory=Gui Gui/Pyside2_Gui_Python.h Gui/typesystem2_natronGui.xml
