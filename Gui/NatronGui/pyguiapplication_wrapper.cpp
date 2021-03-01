
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

#include "pyguiapplication_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyAppInstance.h>
#include <PyGuiApp.h>
#include <qpixmap.h>


// Native ---------------------------------------------------------

void PyGuiApplicationWrapper::pysideInitQtMetaTypes()
{
}

PyGuiApplicationWrapper::PyGuiApplicationWrapper() : PyGuiApplication() {
    // ... middle
}

PyGuiApplicationWrapper::~PyGuiApplicationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_PyGuiApplication_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::PyGuiApplication >()))
        return -1;

    ::PyGuiApplicationWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyGuiApplication()
            cptr = new ::PyGuiApplicationWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::PyGuiApplication >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_PyGuiApplicationFunc_addMenuCommand(PyObject* self, PyObject* args)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_PyGuiApplicationFunc_addMenuCommand_TypeError;

    if (!PyArg_UnpackTuple(args, "addMenuCommand", 2, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addMenuCommand(QString,QString)
    // 1: addMenuCommand(QString,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    if (numArgs >= 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        if (numArgs == 2) {
            overloadId = 0; // addMenuCommand(QString,QString)
        } else if (numArgs == 4
#if SHIBOKEN_MAJOR_VERSION >= 2
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX]), (pyArgs[3])))) {
#else
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))) {
#endif
            overloadId = 1; // addMenuCommand(QString,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_addMenuCommand_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addMenuCommand(const QString & grouping, const QString & pythonFunctionName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addMenuCommand(QString,QString)
                cppSelf->addMenuCommand(cppArg0, cppArg1);
            }
            break;
        }
        case 1: // addMenuCommand(const QString & grouping, const QString & pythonFunctionName, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::Key cppArg2 = ((::Qt::Key)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::KeyboardModifier> cppArg3 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addMenuCommand(QString,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
                cppSelf->addMenuCommand(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyGuiApplicationFunc_addMenuCommand_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.addMenuCommand");
#else
        const char* overloads[] = {"unicode, unicode", "unicode, unicode, PySide.QtCore.Qt.Key, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.addMenuCommand", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_errorDialog(PyObject* self, PyObject* args)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "errorDialog", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: errorDialog(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // errorDialog(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_errorDialog_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // errorDialog(QString,QString)
            cppSelf->errorDialog(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyGuiApplicationFunc_errorDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.errorDialog");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.errorDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_getGuiInstance(PyObject* self, PyObject* pyArg)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getGuiInstance(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getGuiInstance(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_getGuiInstance_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getGuiInstance(int)const
            GuiApp * cppResult = const_cast<const ::PyGuiApplication*>(cppSelf)->getGuiInstance(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronGuiTypes[SBK_GUIAPP_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyGuiApplicationFunc_getGuiInstance_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyGuiApplication.getGuiInstance");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyGuiApplication.getGuiInstance", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_getIcon(PyObject* self, PyObject* pyArg)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getIcon(NATRON_NAMESPACE::PixmapEnum)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX]), (pyArg)))) {
        overloadId = 0; // getIcon(NATRON_NAMESPACE::PixmapEnum)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_getIcon_TypeError;

    // Call function/method
    {
        ::NATRON_NAMESPACE::PixmapEnum cppArg0 = ((::NATRON_NAMESPACE::PixmapEnum)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getIcon(NATRON_NAMESPACE::PixmapEnum)const
            QPixmap cppResult = const_cast<const ::PyGuiApplication*>(cppSelf)->getIcon(cppArg0);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyGuiApplicationFunc_getIcon_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyGuiApplication.getIcon");
#else
        const char* overloads[] = {"NatronEngine.NATRON_NAMESPACE.PixmapEnum", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyGuiApplication.getIcon", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_informationDialog(PyObject* self, PyObject* args)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "informationDialog", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: informationDialog(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // informationDialog(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_informationDialog_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // informationDialog(QString,QString)
            cppSelf->informationDialog(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyGuiApplicationFunc_informationDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.informationDialog");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.informationDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_questionDialog(PyObject* self, PyObject* args)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "questionDialog", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: questionDialog(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // questionDialog(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_questionDialog_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // questionDialog(QString,QString)
            NATRON_NAMESPACE::StandardButtonEnum cppResult = NATRON_NAMESPACE::StandardButtonEnum(cppSelf->questionDialog(cppArg0, cppArg1));
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyGuiApplicationFunc_questionDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.questionDialog");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.questionDialog", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyGuiApplicationFunc_warningDialog(PyObject* self, PyObject* args)
{
    ::PyGuiApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyGuiApplication*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "warningDialog", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: warningDialog(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // warningDialog(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyGuiApplicationFunc_warningDialog_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // warningDialog(QString,QString)
            cppSelf->warningDialog(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyGuiApplicationFunc_warningDialog_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.warningDialog");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyGuiApplication.warningDialog", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_PyGuiApplication_methods[] = {
    {"addMenuCommand", (PyCFunction)Sbk_PyGuiApplicationFunc_addMenuCommand, METH_VARARGS},
    {"errorDialog", (PyCFunction)Sbk_PyGuiApplicationFunc_errorDialog, METH_VARARGS},
    {"getGuiInstance", (PyCFunction)Sbk_PyGuiApplicationFunc_getGuiInstance, METH_O},
    {"getIcon", (PyCFunction)Sbk_PyGuiApplicationFunc_getIcon, METH_O},
    {"informationDialog", (PyCFunction)Sbk_PyGuiApplicationFunc_informationDialog, METH_VARARGS},
    {"questionDialog", (PyCFunction)Sbk_PyGuiApplicationFunc_questionDialog, METH_VARARGS},
    {"warningDialog", (PyCFunction)Sbk_PyGuiApplicationFunc_warningDialog, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PyGuiApplication_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PyGuiApplication_clear(PyObject* self)
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
static SbkObjectType *_Sbk_PyGuiApplication_Type = nullptr;
static SbkObjectType *Sbk_PyGuiApplication_TypeF(void)
{
    return _Sbk_PyGuiApplication_Type;
}

static PyType_Slot Sbk_PyGuiApplication_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PyGuiApplication_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PyGuiApplication_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PyGuiApplication_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_PyGuiApplication_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_PyGuiApplication_spec = {
    "NatronGui.PyGuiApplication",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PyGuiApplication_slots
};
#else
static SbkObjectType Sbk_PyGuiApplication_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronGui.PyGuiApplication",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_PyGuiApplication_traverse,
    /*tp_clear*/            Sbk_PyGuiApplication_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PyGuiApplication_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_PyGuiApplication_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
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

static void* Sbk_PyGuiApplication_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::PyCoreApplication >()))
        return dynamic_cast< ::PyGuiApplication*>(reinterpret_cast< ::PyCoreApplication*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyGuiApplication_PythonToCpp_PyGuiApplication_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PyGuiApplication_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PyGuiApplication_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PyGuiApplication_PythonToCpp_PyGuiApplication_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PyGuiApplication_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PyGuiApplication_Type))
#endif
        return PyGuiApplication_PythonToCpp_PyGuiApplication_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyGuiApplication_PTR_CppToPython_PyGuiApplication(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PyGuiApplication *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PyGuiApplication_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::PyGuiApplication*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_PyGuiApplication_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PyGuiApplication_SignatureStrings[] = {
    "NatronGui.PyGuiApplication()",
    "1:NatronGui.PyGuiApplication.addMenuCommand(grouping:QString,pythonFunctionName:QString)",
    "0:NatronGui.PyGuiApplication.addMenuCommand(grouping:QString,pythonFunctionName:QString,key:PySide2.QtCore.Qt.Key,modifiers:PySide2.QtCore.Qt.KeyboardModifiers)",
    "NatronGui.PyGuiApplication.errorDialog(title:QString,message:QString)",
    "NatronGui.PyGuiApplication.getGuiInstance(idx:int)->NatronGui.GuiApp",
    "NatronGui.PyGuiApplication.getIcon(val:NatronEngine.Natron.PixmapEnum)->PySide2.QtGui.QPixmap",
    "NatronGui.PyGuiApplication.informationDialog(title:QString,message:QString)",
    "NatronGui.PyGuiApplication.questionDialog(title:QString,message:QString)->NatronEngine.Natron.StandardButtonEnum",
    "NatronGui.PyGuiApplication.warningDialog(title:QString,message:QString)",
    nullptr}; // Sentinel
#endif

void init_PyGuiApplication(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_PyGuiApplication_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyGuiApplication",
        "PyGuiApplication*",
        &Sbk_PyGuiApplication_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        PyGuiApplication_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::PyGuiApplication >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX]),
        0,
        0    );

    SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PyGuiApplication_TypeF());
#else
    SbkNatronGuiTypes[SBK_PYGUIAPPLICATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PyGuiApplication_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PyGuiApplication", "PyGuiApplication*",
        &Sbk_PyGuiApplication_Type, &Shiboken::callCppDestructor< ::PyGuiApplication >, (SbkObjectType*)SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PyGuiApplication_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PyGuiApplication_Type,
#endif
        PyGuiApplication_PythonToCpp_PyGuiApplication_PTR,
        is_PyGuiApplication_PythonToCpp_PyGuiApplication_PTR_Convertible,
        PyGuiApplication_PTR_CppToPython_PyGuiApplication);

    Shiboken::Conversions::registerConverterName(converter, "PyGuiApplication");
    Shiboken::Conversions::registerConverterName(converter, "PyGuiApplication*");
    Shiboken::Conversions::registerConverterName(converter, "PyGuiApplication&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyGuiApplication).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyGuiApplicationWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_PyGuiApplication_TypeF(), &Sbk_PyGuiApplication_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_PyGuiApplication_Type, &Sbk_PyGuiApplication_typeDiscovery);
#endif


    PyGuiApplicationWrapper::pysideInitQtMetaTypes();
}
