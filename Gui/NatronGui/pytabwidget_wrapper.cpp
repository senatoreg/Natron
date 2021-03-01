
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

#include "pytabwidget_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PythonPanels.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_PyTabWidgetFunc_appendTab(PyObject* self, PyObject* pyArg)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendTab(PyPanel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_PYPANEL_IDX], (pyArg)))) {
        overloadId = 0; // appendTab(PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_appendTab_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::PyPanel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendTab(PyPanel*)
            // Begin code injection

            bool cppResult = cppSelf->appendTab(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyTabWidgetFunc_appendTab_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.appendTab");
#else
        const char* overloads[] = {"NatronGui.PyPanel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.appendTab", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_closeCurrentTab(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeCurrentTab()
            cppSelf->closeCurrentTab();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyTabWidgetFunc_closePane(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closePane()
            cppSelf->closePane();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyTabWidgetFunc_closeTab(PyObject* self, PyObject* pyArg)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closeTab(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // closeTab(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_closeTab_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeTab(int)
            cppSelf->closeTab(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyTabWidgetFunc_closeTab_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.closeTab");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.closeTab", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_count(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()
            int cppResult = cppSelf->count();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyTabWidgetFunc_currentWidget(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentWidget()
            QWidget * cppResult = cppSelf->currentWidget();
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX], cppResult);
#else
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyTabWidgetFunc_floatCurrentTab(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // floatCurrentTab()
            cppSelf->floatCurrentTab();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyTabWidgetFunc_floatPane(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // floatPane()
            cppSelf->floatPane();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyTabWidgetFunc_getCurrentIndex(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentIndex()const
            int cppResult = const_cast<const ::PyTabWidget*>(cppSelf)->getCurrentIndex();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyTabWidgetFunc_getScriptName(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::PyTabWidget*>(cppSelf)->getScriptName();
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
}

static PyObject* Sbk_PyTabWidgetFunc_getTabLabel(PyObject* self, PyObject* pyArg)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getTabLabel(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getTabLabel(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_getTabLabel_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getTabLabel(int)const
            QString cppResult = const_cast<const ::PyTabWidget*>(cppSelf)->getTabLabel(cppArg0);
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

    Sbk_PyTabWidgetFunc_getTabLabel_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.getTabLabel");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.getTabLabel", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_insertTab(PyObject* self, PyObject* args)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertTab", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertTab(int,PyPanel*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_PYPANEL_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertTab(int,PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_insertTab_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::PyPanel* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertTab(int,PyPanel*)
            // Begin code injection

            cppSelf->insertTab(cppArg0,cppArg1);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyTabWidgetFunc_insertTab_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyTabWidget.insertTab");
#else
        const char* overloads[] = {"int, NatronGui.PyPanel", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyTabWidget.insertTab", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_removeTab(PyObject* self, PyObject* pyArg)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeTab(QWidget*)
    // 1: removeTab(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // removeTab(int)
#if SHIBOKEN_MAJOR_VERSION >= 2
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX], (pyArg)))) {
#else
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
#endif
      overloadId = 0; // removeTab(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_removeTab_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // removeTab(QWidget * tab)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // removeTab(QWidget*)
                cppSelf->removeTab(cppArg0);
            }
            break;
        }
        case 1: // removeTab(int index)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // removeTab(int)
                cppSelf->removeTab(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyTabWidgetFunc_removeTab_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.removeTab");
#else
        const char* overloads[] = {"PySide.QtGui.QWidget", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.removeTab", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_setCurrentIndex(PyObject* self, PyObject* pyArg)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyTabWidgetFunc_setCurrentIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentIndex(int)
            cppSelf->setCurrentIndex(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyTabWidgetFunc_setCurrentIndex_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.setCurrentIndex");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyTabWidget.setCurrentIndex", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyTabWidgetFunc_setNextTabCurrent(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setNextTabCurrent()
            cppSelf->setNextTabCurrent();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyTabWidgetFunc_splitHorizontally(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // splitHorizontally()
            PyTabWidget * cppResult = cppSelf->splitHorizontally();
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

static PyObject* Sbk_PyTabWidgetFunc_splitVertically(PyObject* self)
{
    ::PyTabWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyTabWidget*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // splitVertically()
            PyTabWidget * cppResult = cppSelf->splitVertically();
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

static PyMethodDef Sbk_PyTabWidget_methods[] = {
    {"appendTab", (PyCFunction)Sbk_PyTabWidgetFunc_appendTab, METH_O},
    {"closeCurrentTab", (PyCFunction)Sbk_PyTabWidgetFunc_closeCurrentTab, METH_NOARGS},
    {"closePane", (PyCFunction)Sbk_PyTabWidgetFunc_closePane, METH_NOARGS},
    {"closeTab", (PyCFunction)Sbk_PyTabWidgetFunc_closeTab, METH_O},
    {"count", (PyCFunction)Sbk_PyTabWidgetFunc_count, METH_NOARGS},
    {"currentWidget", (PyCFunction)Sbk_PyTabWidgetFunc_currentWidget, METH_NOARGS},
    {"floatCurrentTab", (PyCFunction)Sbk_PyTabWidgetFunc_floatCurrentTab, METH_NOARGS},
    {"floatPane", (PyCFunction)Sbk_PyTabWidgetFunc_floatPane, METH_NOARGS},
    {"getCurrentIndex", (PyCFunction)Sbk_PyTabWidgetFunc_getCurrentIndex, METH_NOARGS},
    {"getScriptName", (PyCFunction)Sbk_PyTabWidgetFunc_getScriptName, METH_NOARGS},
    {"getTabLabel", (PyCFunction)Sbk_PyTabWidgetFunc_getTabLabel, METH_O},
    {"insertTab", (PyCFunction)Sbk_PyTabWidgetFunc_insertTab, METH_VARARGS},
    {"removeTab", (PyCFunction)Sbk_PyTabWidgetFunc_removeTab, METH_O},
    {"setCurrentIndex", (PyCFunction)Sbk_PyTabWidgetFunc_setCurrentIndex, METH_O},
    {"setNextTabCurrent", (PyCFunction)Sbk_PyTabWidgetFunc_setNextTabCurrent, METH_NOARGS},
    {"splitHorizontally", (PyCFunction)Sbk_PyTabWidgetFunc_splitHorizontally, METH_NOARGS},
    {"splitVertically", (PyCFunction)Sbk_PyTabWidgetFunc_splitVertically, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PyTabWidget_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PyTabWidget_clear(PyObject* self)
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
static SbkObjectType *_Sbk_PyTabWidget_Type = nullptr;
static SbkObjectType *Sbk_PyTabWidget_TypeF(void)
{
    return _Sbk_PyTabWidget_Type;
}

static PyType_Slot Sbk_PyTabWidget_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PyTabWidget_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PyTabWidget_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PyTabWidget_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_PyTabWidget_spec = {
    "NatronGui.PyTabWidget",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PyTabWidget_slots
};
#else
static SbkObjectType Sbk_PyTabWidget_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronGui.PyTabWidget",
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
    /*tp_traverse*/         Sbk_PyTabWidget_traverse,
    /*tp_clear*/            Sbk_PyTabWidget_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PyTabWidget_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyTabWidget_PythonToCpp_PyTabWidget_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PyTabWidget_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PyTabWidget_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PyTabWidget_PythonToCpp_PyTabWidget_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PyTabWidget_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PyTabWidget_Type))
#endif
        return PyTabWidget_PythonToCpp_PyTabWidget_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyTabWidget_PTR_CppToPython_PyTabWidget(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PyTabWidget *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PyTabWidget_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::PyTabWidget*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_PyTabWidget_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PyTabWidget_SignatureStrings[] = {
    "NatronGui.PyTabWidget.appendTab(tab:NatronGui.PyPanel)->bool",
    "NatronGui.PyTabWidget.closeCurrentTab()",
    "NatronGui.PyTabWidget.closePane()",
    "NatronGui.PyTabWidget.closeTab(index:int)",
    "NatronGui.PyTabWidget.count()->int",
    "NatronGui.PyTabWidget.currentWidget()->PySide2.QtWidgets.QWidget",
    "NatronGui.PyTabWidget.floatCurrentTab()",
    "NatronGui.PyTabWidget.floatPane()",
    "NatronGui.PyTabWidget.getCurrentIndex()->int",
    "NatronGui.PyTabWidget.getScriptName()->QString",
    "NatronGui.PyTabWidget.getTabLabel(index:int)->QString",
    "NatronGui.PyTabWidget.insertTab(index:int,tab:NatronGui.PyPanel)",
    "NatronGui.PyTabWidget.removeTab(index:int)",
    "NatronGui.PyTabWidget.setCurrentIndex(index:int)",
    "NatronGui.PyTabWidget.setNextTabCurrent()",
    "NatronGui.PyTabWidget.splitHorizontally()->NatronGui.PyTabWidget",
    "NatronGui.PyTabWidget.splitVertically()->NatronGui.PyTabWidget",
    nullptr}; // Sentinel
#endif

void init_PyTabWidget(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
      _Sbk_PyTabWidget_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyTabWidget",
        "PyTabWidget*",
        &Sbk_PyTabWidget_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        PyTabWidget_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::PyTabWidget >,
        0,
        0,
        0    );

    SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PyTabWidget_TypeF());
#else
    SbkNatronGuiTypes[SBK_PYTABWIDGET_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PyTabWidget_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PyTabWidget", "PyTabWidget*",
        &Sbk_PyTabWidget_Type, &Shiboken::callCppDestructor< ::PyTabWidget >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PyTabWidget_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PyTabWidget_Type,
#endif
        PyTabWidget_PythonToCpp_PyTabWidget_PTR,
        is_PyTabWidget_PythonToCpp_PyTabWidget_PTR_Convertible,
        PyTabWidget_PTR_CppToPython_PyTabWidget);

    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget");
    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget*");
    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyTabWidget).name());



}
