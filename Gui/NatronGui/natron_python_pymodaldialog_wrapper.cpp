
// default includes
#include <shiboken.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <algorithm>
#include <set>
#include <iterator>

// module include
#include "natrongui_python.h"

// main header
#include "natron_python_pymodaldialog_wrapper.h"

// inner classes

#include <cctype>
#include <cstring>

using namespace Natron;



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void PyModalDialogWrapper::pysideInitQtMetaTypes()
{
}

void PyModalDialogWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

PyModalDialogWrapper::~PyModalDialogWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_PyModalDialogFunc_getParam(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyModalDialog *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyModalDialog::getParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyModalDialogFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Natron::Python::Param * cppResult = const_cast<const ::Natron::Python::PyModalDialog *>(cppSelf)->getParam(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyModalDialogFunc_getParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.getParam");
        return {};
}

static PyObject *Sbk_Natron_Python_PyModalDialogFunc_setParamChangedCallback(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyModalDialog *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyModalDialog::setParamChangedCallback(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setParamChangedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyModalDialogFunc_setParamChangedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParamChangedCallback(QString)
            cppSelf->setParamChangedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyModalDialogFunc_setParamChangedCallback_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.setParamChangedCallback");
        return {};
}


static const char *Sbk_Natron_Python_PyModalDialog_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_PyModalDialog_methods[] = {
    {"getParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyModalDialogFunc_getParam), METH_O},
    {"setParamChangedCallback", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyModalDialogFunc_setParamChangedCallback), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_PyModalDialog_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::PyModalDialog *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<PyModalDialogWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_PyModalDialog_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyModalDialog_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1 };
int *
Sbk_Natron_Python_PyModalDialog_mi_init(const void *cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        const auto *class_ptr = reinterpret_cast<const Natron::Python::PyModalDialog *>(cptr);
        const auto base = reinterpret_cast<uintptr_t>(class_ptr);
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder *>(class_ptr)) - base));
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder *>(static_cast<const Natron::Python::PyModalDialog *>(static_cast<const void *>(class_ptr)))) - base));

        offsets.erase(0);

        std::copy(offsets.cbegin(), offsets.cend(), mi_offsets);
    }
    return mi_offsets;
}
static void * Sbk_Natron_Python_PyModalDialogSpecialCastFunction(void *obj, SbkObjectType *desiredType)
{
    auto me = reinterpret_cast< ::Natron::Python::PyModalDialog *>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]))
        return static_cast< ::Natron::Python::UserParamHolder *>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyModalDialog_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyModalDialog_TypeF(void)
{
    return _Sbk_Natron_Python_PyModalDialog_Type;
}

static PyType_Slot Sbk_Natron_Python_PyModalDialog_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_PyModalDialog_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_PyModalDialog_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_PyModalDialog_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_PyModalDialog_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyModalDialog_spec = {
    "1:NatronGui.PyModalDialog",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyModalDialog_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyModalDialog_PythonToCpp_PyModalDialog_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyModalDialog_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyModalDialog_PythonToCpp_PyModalDialog_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyModalDialog_TypeF())))
        return PyModalDialog_PythonToCpp_PyModalDialog_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *PyModalDialog_PTR_CppToPython_PyModalDialog(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyModalDialog *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyModalDialog_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyModalDialog_SignatureStrings[] = {
    "NatronGui.PyModalDialog.getParam(self,scriptName:QString)->NatronEngine.Natron.Python.Param",
    "NatronGui.PyModalDialog.setParamChangedCallback(self,callback:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_PyModalDialog(PyObject *module)
{
    PyObject *Sbk_Natron_Python_PyModalDialog_Type_bases = PyTuple_Pack(1,
        reinterpret_cast<PyObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]));

    _Sbk_Natron_Python_PyModalDialog_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyModalDialog",
        "Natron::Python::PyModalDialog*",
        &Sbk_Natron_Python_PyModalDialog_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::PyModalDialog >,
        0,
        Sbk_Natron_Python_PyModalDialog_Type_bases,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_PyModalDialog_Type);
    InitSignatureStrings(pyType, Natron_Python_PyModalDialog_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_PyModalDialog_Type), Sbk_Natron_Python_PyModalDialog_PropertyStrings);
    SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyModalDialog_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyModalDialog_TypeF(),
        PyModalDialog_PythonToCpp_PyModalDialog_PTR,
        is_PyModalDialog_PythonToCpp_PyModalDialog_PTR_Convertible,
        PyModalDialog_PTR_CppToPython_PyModalDialog);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyModalDialog");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyModalDialog*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyModalDialog&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyModalDialog");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyModalDialog*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyModalDialog&");
    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog");
    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog*");
    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyModalDialog).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyModalDialogWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_Natron_Python_PyModalDialog_mi_init;
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_Natron_Python_PyModalDialog_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_Natron_Python_PyModalDialog_TypeF(), &Sbk_Natron_Python_PyModalDialogSpecialCastFunction);

    PyModalDialogWrapper::pysideInitQtMetaTypes();
}
