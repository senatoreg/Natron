#!/bin/sh 
echo ====================================================
echo Removing previous Engine and Gui wrapper directories
echo ====================================================
rm -rf Engine/NatronEngine/* Gui/NatronGui/*
echo ===============
echo Building Engine
echo ===============
shiboken2 --avoid-protected-hack --enable-pyside-extensions -I. -IEngine -IGlobal -Ilibs/OpenFX/include -I/usr/include $(pkg-config --cflags shiboken2) $(pkg-config --cflags pyside2) $(pkg-config --cflags Qt5Core | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Gui | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Widgets | sed 's,-D[a-zA-Z0-9_]\+,,g') --typesystem-paths=/usr/share/PySide2/typesystems --output-directory=Engine Engine/Pyside2_Engine_Python.h Engine/typesystem2_engine.xml
echo =================================================
echo Casting \'set\' function to intParam in 2D and 3D
echo =================================================
sed -i'.postsbk' -e '/cppSelf->set(\(cppArg[0-9,]\+\)\{1\});/ {s/\(cppSelf\)\(->.*;$\)/reinterpret_cast<Natron::Python::IntParam *>(\1)\2/g}' Engine/NatronEngine/natron_python_int2dparam_wrapper.cpp
sed -i'.postsbk' -e '/cppSelf->set(\(cppArg[0-9,]\+\)\{1,2\});/ {s/\(cppSelf\)\(->.*;$\)/reinterpret_cast<Natron::Python::IntParam *>(\1)\2/g}' Engine/NatronEngine/natron_python_int3dparam_wrapper.cpp
echo ============
echo Building Gui
echo ============
shiboken2 --avoid-protected-hack --enable-pyside-extensions -I. -IEngine -IGlobal -IGui -Ilibs/OpenFX/include -I/usr/include $(pkg-config --cflags shiboken2) $(pkg-config --cflags pyside2) $(pkg-config --cflags Qt5Core | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Gui | sed 's,-D[a-zA-Z0-9_]\+,,g') $(pkg-config --cflags Qt5Widgets | sed 's,-D[a-zA-Z0-9_]\+,,g') --typesystem-paths=/usr/share/PySide2/typesystems:Engine --output-directory=Gui Gui/Pyside2_Gui_Python.h Gui/typesystem2_natronGui.xml
echo =============================
echo Fixing Duplicate Declarations
echo =============================
sed -i'.postsbk' \
-e '/PyTypeObject \*\*SbkPySide2_QtCoreTypes;/d' \
-e '/SbkConverter \*\*SbkPySide2_QtCoreTypeConverters;/d' \
-e '/PyTypeObject \*\*SbkNatronEngineTypes;/d' \
-e '/SbkConverter \*\*SbkNatronEngineTypeConverters;/d' \
-e 's,cleanTypesAttributes,cleanGuiTypesAttributes,g' \
Gui/NatronGui/natrongui_module_wrapper.cpp
#DROP_ENUM=`awk '/enum-type/ {gsub("^ *<.*=\"","",$0);gsub("\".*$","",$0);print "/::" $0 "/d"}' Engine/typesystem2_engine.xml`
#sed -i'.postsbk' ''$DROP_ENUM'' Gui/NatronGui/natrongui_python.h
