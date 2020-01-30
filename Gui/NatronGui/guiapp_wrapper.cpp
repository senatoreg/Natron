
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#if SHIBOKEN_MAJOR_VERSION < 2
#include <typeresolver.h>
#endif
#include <typeinfo>
#include "natrongui_python.h"
#include "natron_helper.h"

#include "guiapp_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyAppInstance.h>
#include <PyGuiApp.h>
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <PyParameter.h>
#include <PythonPanels.h>
#include <list>
#include <map>


// Native ---------------------------------------------------------

void GuiAppWrapper::pysideInitQtMetaTypes()
{
}

GuiAppWrapper::~GuiAppWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_GuiAppFunc_clearSelection(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.clearSelection(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:clearSelection", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: clearSelection(Group*)
    if (numArgs == 0) {
        overloadId = 0; // clearSelection(Group*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0])))) {
        overloadId = 0; // clearSelection(Group*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_clearSelection_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.clearSelection(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0]))))
                    goto Sbk_GuiAppFunc_clearSelection_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Group* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // clearSelection(Group*)
            cppSelf->clearSelection(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_clearSelection_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.clearSelection");
#else
        const char* overloads[] = {"NatronEngine.Group = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.clearSelection", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_createModalDialog(PyObject* self)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createModalDialog()
            PyModalDialog * cppResult = cppSelf->createModalDialog();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_GuiAppFunc_deselectNode(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deselectNode(Effect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArg)))) {
        overloadId = 0; // deselectNode(Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_deselectNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Effect* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deselectNode(Effect*)
            cppSelf->deselectNode(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_deselectNode_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.deselectNode");
#else
        const char* overloads[] = {"NatronEngine.Effect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.deselectNode", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getActiveTabWidget(PyObject* self)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveTabWidget()const
            PyTabWidget * cppResult = const_cast<const ::GuiApp*>(cppSelf)->getActiveTabWidget();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_GuiAppFunc_getActiveViewer(PyObject* self)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveViewer()const
            PyViewer * cppResult = const_cast<const ::GuiApp*>(cppSelf)->getActiveViewer();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYVIEWER_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_GuiAppFunc_getDirectoryDialog(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getDirectoryDialog(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getDirectoryDialog", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getDirectoryDialog(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getDirectoryDialog(QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#else
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#endif
        overloadId = 0; // getDirectoryDialog(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getDirectoryDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "location");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getDirectoryDialog(): got multiple values for keyword argument 'location'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
#if SHIBOKEN_MAJOR_VERSION >= 2
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
#else
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
#endif
                    goto Sbk_GuiAppFunc_getDirectoryDialog_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getDirectoryDialog(QString)const
            QString cppResult = const_cast<const ::GuiApp*>(cppSelf)->getDirectoryDialog(cppArg0);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getDirectoryDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getDirectoryDialog");
#else
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getDirectoryDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getFilenameDialog(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:getFilenameDialog", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getFilenameDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#else
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#endif
        if (numArgs == 1) {
            overloadId = 0; // getFilenameDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
            overloadId = 0; // getFilenameDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getFilenameDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "location");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): got multiple values for keyword argument 'location'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
#if SHIBOKEN_MAJOR_VERSION >= 2
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#else
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#endif
                    goto Sbk_GuiAppFunc_getFilenameDialog_TypeError;
            }
        }
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getFilenameDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::GuiApp*>(cppSelf)->getFilenameDialog(cppArg0, cppArg1);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getFilenameDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getFilenameDialog");
#else
        const char* overloads[] = {"QStringList, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getFilenameDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getRGBColorDialog(PyObject* self)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getRGBColorDialog()const
            ColorTuple* cppResult = new ColorTuple(const_cast<const ::GuiApp*>(cppSelf)->getRGBColorDialog());
            pyResult = Shiboken::Object::newObject((SbkObjectType*)SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_GuiAppFunc_getSelectedNodes(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSelectedNodes(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getSelectedNodes", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getSelectedNodes(Group*)const
    if (numArgs == 0) {
        overloadId = 0; // getSelectedNodes(Group*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0])))) {
        overloadId = 0; // getSelectedNodes(Group*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getSelectedNodes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSelectedNodes(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0]))))
                    goto Sbk_GuiAppFunc_getSelectedNodes_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Group* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getSelectedNodes(Group*)const
            // Begin code injection

            std::list<Effect*> effects = cppSelf->getSelectedNodes(cppArg0);
            PyObject* ret = PyList_New((int) effects.size());
            int idx = 0;
            for (std::list<Effect*>::iterator it = effects.begin(); it!=effects.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], *it);
            // Ownership transferences.
            Shiboken::Object::getOwnership(item);
            PyList_SET_ITEM(ret, idx, item);
            }
            return ret;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getSelectedNodes_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSelectedNodes");
#else
        const char* overloads[] = {"NatronEngine.Group = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSelectedNodes", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getSequenceDialog(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:getSequenceDialog", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getSequenceDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#else
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#endif
        if (numArgs == 1) {
            overloadId = 0; // getSequenceDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
            overloadId = 0; // getSequenceDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getSequenceDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "location");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): got multiple values for keyword argument 'location'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
#if SHIBOKEN_MAJOR_VERSION >= 2
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#else
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#endif
                    goto Sbk_GuiAppFunc_getSequenceDialog_TypeError;
            }
        }
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getSequenceDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::GuiApp*>(cppSelf)->getSequenceDialog(cppArg0, cppArg1);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getSequenceDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSequenceDialog");
#else
        const char* overloads[] = {"QStringList, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSequenceDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getTabWidget(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getTabWidget(QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // getTabWidget(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getTabWidget_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getTabWidget(QString)const
            PyTabWidget * cppResult = const_cast<const ::GuiApp*>(cppSelf)->getTabWidget(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getTabWidget_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getTabWidget");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getTabWidget", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getUserPanel(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getUserPanel(QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // getUserPanel(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getUserPanel_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getUserPanel(QString)const
            PyPanel * cppResult = const_cast<const ::GuiApp*>(cppSelf)->getUserPanel(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYPANEL_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getUserPanel_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getUserPanel");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getUserPanel", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_getViewer(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getViewer(QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // getViewer(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_getViewer_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewer(QString)const
            PyViewer * cppResult = const_cast<const ::GuiApp*>(cppSelf)->getViewer(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_PYVIEWER_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_getViewer_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getViewer");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getViewer", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_moveTab(PyObject* self, PyObject* args)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveTab", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveTab(QString,PyTabWidget*)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
#endif
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (pyArgs[1])))) {
        overloadId = 0; // moveTab(QString,PyTabWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_moveTab_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::PyTabWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveTab(QString,PyTabWidget*)
            bool cppResult = cppSelf->moveTab(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_moveTab_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.moveTab");
#else
        const char* overloads[] = {"unicode, NatronGui.PyTabWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.moveTab", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_registerPythonPanel(PyObject* self, PyObject* args)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerPythonPanel", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: registerPythonPanel(PyPanel*,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_PYPANEL_IDX], (pyArgs[0])))
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // registerPythonPanel(PyPanel*,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_registerPythonPanel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::PyPanel* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // registerPythonPanel(PyPanel*,QString)
            cppSelf->registerPythonPanel(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_registerPythonPanel_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.registerPythonPanel");
#else
        const char* overloads[] = {"NatronGui.PyPanel, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.registerPythonPanel", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_renderBlocking(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_GuiAppFunc_renderBlocking_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:renderBlocking", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: renderBlocking(Effect*,int,int,int)
    // 1: renderBlocking(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // renderBlocking(Effect*,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // renderBlocking(Effect*,int,int,int)
        }
    } else if (numArgs == 1
        && PyList_Check(pyArgs[0])) {
        overloadId = 1; // renderBlocking(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_renderBlocking_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // renderBlocking(Effect * writeNode, int firstFrame, int lastFrame, int frameStep)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "frameStep");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): got multiple values for keyword argument 'frameStep'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_GuiAppFunc_renderBlocking_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::Effect* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // renderBlocking(Effect*,int,int,int)
                cppSelf->renderBlocking(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
        case 1: // renderBlocking(const std::list<Effect * > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps)
        {

            if (!PyErr_Occurred()) {
                // renderBlocking(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
                // Begin code injection

                if (!PyList_Check(pyArgs[1-1])) {
                PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                return 0;
                }
                std::list<Effect*> effects;

                std::list<int> firstFrames;

                std::list<int> lastFrames;

                std::list<int> frameSteps;

                int size = (int)PyList_GET_SIZE(pyArgs[1-1]);
                for (int i = 0; i < size; ++i) {
                PyObject* tuple = PyList_GET_ITEM(pyArgs[1-1],i);
                if (!tuple) {
                PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                return 0;
                }

                int tupleSize = PyTuple_GET_SIZE(tuple);
                if (tupleSize != 4 && tupleSize != 3) {
                PyErr_SetString(PyExc_TypeError, "the tuple must have 3 or 4 items.");
                return 0;
                }
                ::Effect* writeNode = ((::Effect*)0);
                    Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], PyTuple_GET_ITEM(tuple, 0), &(writeNode));
                int firstFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 1), &(firstFrame));
                int lastFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 2), &(lastFrame));
                int frameStep;
                if (tupleSize == 4) {
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 3), &(frameStep));
                } else {
                frameStep = INT_MIN;
                }
                effects.push_back(writeNode);
                firstFrames.push_back(firstFrame);
                lastFrames.push_back(lastFrame);
                frameSteps.push_back(frameStep);
                }

                cppSelf->renderBlocking(effects,firstFrames,lastFrames, frameSteps);

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_renderBlocking_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.renderBlocking");
#else
        const char* overloads[] = {"NatronEngine.Effect, int, int, int = 1", "list, list, list, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.renderBlocking", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_saveFilenameDialog(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:saveFilenameDialog", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: saveFilenameDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#else
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#endif
        if (numArgs == 1) {
            overloadId = 0; // saveFilenameDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
            overloadId = 0; // saveFilenameDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_saveFilenameDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "location");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): got multiple values for keyword argument 'location'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
#if SHIBOKEN_MAJOR_VERSION >= 2
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#else
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#endif
                    goto Sbk_GuiAppFunc_saveFilenameDialog_TypeError;
            }
        }
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // saveFilenameDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::GuiApp*>(cppSelf)->saveFilenameDialog(cppArg0, cppArg1);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_saveFilenameDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveFilenameDialog");
#else
        const char* overloads[] = {"QStringList, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveFilenameDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_saveSequenceDialog(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:saveSequenceDialog", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: saveSequenceDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#else
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
#endif
        if (numArgs == 1) {
            overloadId = 0; // saveSequenceDialog(QStringList,QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
            overloadId = 0; // saveSequenceDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_saveSequenceDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "location");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): got multiple values for keyword argument 'location'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
#if SHIBOKEN_MAJOR_VERSION >= 2
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#else
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
#endif
                    goto Sbk_GuiAppFunc_saveSequenceDialog_TypeError;
            }
        }
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // saveSequenceDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::GuiApp*>(cppSelf)->saveSequenceDialog(cppArg0, cppArg1);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_GuiAppFunc_saveSequenceDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveSequenceDialog");
#else
        const char* overloads[] = {"QStringList, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveSequenceDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_selectAllNodes(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.selectAllNodes(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:selectAllNodes", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: selectAllNodes(Group*)
    if (numArgs == 0) {
        overloadId = 0; // selectAllNodes(Group*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0])))) {
        overloadId = 0; // selectAllNodes(Group*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_selectAllNodes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.selectAllNodes(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[0]))))
                    goto Sbk_GuiAppFunc_selectAllNodes_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Group* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // selectAllNodes(Group*)
            cppSelf->selectAllNodes(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_selectAllNodes_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectAllNodes");
#else
        const char* overloads[] = {"NatronEngine.Group = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectAllNodes", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_selectNode(PyObject* self, PyObject* args)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "selectNode", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: selectNode(Effect*,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // selectNode(Effect*,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_selectNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Effect* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // selectNode(Effect*,bool)
            cppSelf->selectNode(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_selectNode_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectNode");
#else
        const char* overloads[] = {"NatronEngine.Effect, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectNode", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_setSelection(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelection(std::list<Effect*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_EFFECTPTR_IDX], (pyArg)))) {
        overloadId = 0; // setSelection(std::list<Effect*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_setSelection_TypeError;

    // Call function/method
    {
        ::std::list<Effect * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelection(std::list<Effect*>)
            cppSelf->setSelection(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_setSelection_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.setSelection");
#else
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.setSelection", overloads);
#endif
        return 0;
}

static PyObject* Sbk_GuiAppFunc_unregisterPythonPanel(PyObject* self, PyObject* pyArg)
{
    ::GuiApp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::GuiApp*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_GUIAPP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unregisterPythonPanel(PyPanel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_PYPANEL_IDX], (pyArg)))) {
        overloadId = 0; // unregisterPythonPanel(PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_GuiAppFunc_unregisterPythonPanel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::PyPanel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterPythonPanel(PyPanel*)
            cppSelf->unregisterPythonPanel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_GuiAppFunc_unregisterPythonPanel_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.unregisterPythonPanel");
#else
        const char* overloads[] = {"NatronGui.PyPanel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.unregisterPythonPanel", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_GuiApp_methods[] = {
    {"clearSelection", (PyCFunction)Sbk_GuiAppFunc_clearSelection, METH_VARARGS|METH_KEYWORDS},
    {"createModalDialog", (PyCFunction)Sbk_GuiAppFunc_createModalDialog, METH_NOARGS},
    {"deselectNode", (PyCFunction)Sbk_GuiAppFunc_deselectNode, METH_O},
    {"getActiveTabWidget", (PyCFunction)Sbk_GuiAppFunc_getActiveTabWidget, METH_NOARGS},
    {"getActiveViewer", (PyCFunction)Sbk_GuiAppFunc_getActiveViewer, METH_NOARGS},
    {"getDirectoryDialog", (PyCFunction)Sbk_GuiAppFunc_getDirectoryDialog, METH_VARARGS|METH_KEYWORDS},
    {"getFilenameDialog", (PyCFunction)Sbk_GuiAppFunc_getFilenameDialog, METH_VARARGS|METH_KEYWORDS},
    {"getRGBColorDialog", (PyCFunction)Sbk_GuiAppFunc_getRGBColorDialog, METH_NOARGS},
    {"getSelectedNodes", (PyCFunction)Sbk_GuiAppFunc_getSelectedNodes, METH_VARARGS|METH_KEYWORDS},
    {"getSequenceDialog", (PyCFunction)Sbk_GuiAppFunc_getSequenceDialog, METH_VARARGS|METH_KEYWORDS},
    {"getTabWidget", (PyCFunction)Sbk_GuiAppFunc_getTabWidget, METH_O},
    {"getUserPanel", (PyCFunction)Sbk_GuiAppFunc_getUserPanel, METH_O},
    {"getViewer", (PyCFunction)Sbk_GuiAppFunc_getViewer, METH_O},
    {"moveTab", (PyCFunction)Sbk_GuiAppFunc_moveTab, METH_VARARGS},
    {"registerPythonPanel", (PyCFunction)Sbk_GuiAppFunc_registerPythonPanel, METH_VARARGS},
    {"renderBlocking", (PyCFunction)Sbk_GuiAppFunc_renderBlocking, METH_VARARGS|METH_KEYWORDS},
    {"saveFilenameDialog", (PyCFunction)Sbk_GuiAppFunc_saveFilenameDialog, METH_VARARGS|METH_KEYWORDS},
    {"saveSequenceDialog", (PyCFunction)Sbk_GuiAppFunc_saveSequenceDialog, METH_VARARGS|METH_KEYWORDS},
    {"selectAllNodes", (PyCFunction)Sbk_GuiAppFunc_selectAllNodes, METH_VARARGS|METH_KEYWORDS},
    {"selectNode", (PyCFunction)Sbk_GuiAppFunc_selectNode, METH_VARARGS},
    {"setSelection", (PyCFunction)Sbk_GuiAppFunc_setSelection, METH_O},
    {"unregisterPythonPanel", (PyCFunction)Sbk_GuiAppFunc_unregisterPythonPanel, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_GuiApp_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_GuiApp_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
// Class Definition -----------------------------------------------
extern "C" {
#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_GuiApp_Type = nullptr;
static SbkObjectType *Sbk_GuiApp_TypeF(void)
{
    return _Sbk_GuiApp_Type;
}

static PyType_Slot Sbk_GuiApp_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_GuiApp_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_GuiApp_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_GuiApp_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_GuiApp_spec = {
    "NatronGui.GuiApp",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_GuiApp_slots
};
#else
static SbkObjectType Sbk_GuiApp_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronGui.GuiApp",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_GuiApp_traverse,
    /*tp_clear*/            Sbk_GuiApp_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_GuiApp_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
#endif
} //extern

static void* Sbk_GuiApp_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Group >()))
        return dynamic_cast< ::GuiApp*>(reinterpret_cast< ::Group*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void GuiApp_PythonToCpp_GuiApp_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_GuiApp_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_GuiApp_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_GuiApp_PythonToCpp_GuiApp_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_GuiApp_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_GuiApp_Type))
#endif
        return GuiApp_PythonToCpp_GuiApp_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* GuiApp_PTR_CppToPython_GuiApp(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::GuiApp *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_GuiApp_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::GuiApp*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_GuiApp_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *GuiApp_SignatureStrings[] = {
    "NatronGui.GuiApp.clearSelection(group:NatronEngine.Group=0)",
    "NatronGui.GuiApp.createModalDialog()->NatronGui.PyModalDialog",
    "NatronGui.GuiApp.deselectNode(effect:NatronEngine.Effect)",
    "NatronGui.GuiApp.getActiveTabWidget()->NatronGui.PyTabWidget",
    "NatronGui.GuiApp.getActiveViewer()->NatronEngine.Effect",
    "NatronGui.GuiApp.getDirectoryDialog(location:QString=QString())->QString",
    "NatronGui.GuiApp.getFilenameDialog(filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.getRGBColorDialog()->NatronEngine.ColorTuple",
    "NatronGui.GuiApp.getSelectedNodes(group:NatronEngine.Group=0)->QList[NatronEngine.Effect]",
    "NatronGui.GuiApp.getSequenceDialog(filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.getTabWidget(name:QString)->NatronGui.PyTabWidget",
    "NatronGui.GuiApp.getUserPanel(scriptName:QString)->NatronGui.PyPanel",
    "NatronGui.GuiApp.moveTab(scriptName:QString,pane:NatronGui.PyTabWidget)->bool",
    "NatronGui.GuiApp.registerPythonPanel(panel:NatronGui.PyPanel,pythonFunction:QString)",
    "1:NatronGui.GuiApp.renderBlocking(writeNode:NatronEngine.Effect,firstFrame:int,lastFrame:int,frameStep:int=1)",
    "0:NatronGui.GuiApp.renderBlocking(effects:QList[NatronEngine.Effect],firstFrames:QList[int],lastFrames:QList[int],frameSteps:QList[int])",
    "NatronGui.GuiApp.saveFilenameDialog(filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.saveSequenceDialog(filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.selectAllNodes(group:NatronEngine.Group=0)",
    "NatronGui.GuiApp.selectNode(effect:NatronEngine.Effect,clearPreviousSelection:bool)",
    "NatronGui.GuiApp.setSelection(nodes:QList[NatronEngine.Effect])",
    "NatronGui.GuiApp.unregisterPythonPanel(panel:NatronGui.PyPanel)",
    nullptr}; // Sentinel
#endif

void init_GuiApp(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_GuiApp_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "GuiApp",
        "GuiApp*",
        &Sbk_GuiApp_spec,
        GuiApp_SignatureStrings,
        &Shiboken::callCppDestructor< ::GuiApp >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_APP_IDX]),
        0,
        0    );

    SbkNatronGuiTypes[SBK_GUIAPP_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_GuiApp_TypeF());
#else
    SbkNatronGuiTypes[SBK_GUIAPP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_GuiApp_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "GuiApp", "GuiApp*",
        &Sbk_GuiApp_Type, &Shiboken::callCppDestructor< ::GuiApp >, (SbkObjectType*)SbkNatronEngineTypes[SBK_APP_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_GuiApp_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_GuiApp_Type,
#endif
        GuiApp_PythonToCpp_GuiApp_PTR,
        is_GuiApp_PythonToCpp_GuiApp_PTR_Convertible,
        GuiApp_PTR_CppToPython_GuiApp);

    Shiboken::Conversions::registerConverterName(converter, "GuiApp");
    Shiboken::Conversions::registerConverterName(converter, "GuiApp*");
    Shiboken::Conversions::registerConverterName(converter, "GuiApp&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::GuiApp).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::GuiAppWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_GuiApp_TypeF(), &Sbk_GuiApp_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_GuiApp_Type, &Sbk_GuiApp_typeDiscovery);
#endif


    GuiAppWrapper::pysideInitQtMetaTypes();
}
