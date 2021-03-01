
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
#include "natronengine_python.h"
#include "natron_helper.h"

#include "pathparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>
#include <list>
#include <vector>


// Native ---------------------------------------------------------

void PathParamWrapper::pysideInitQtMetaTypes()
{
}

PathParamWrapper::~PathParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_PathParamFunc_getTable(PyObject* self)
{
    PathParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PathParamWrapper*)((::PathParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PATHPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTable(std::list<std::vector<std::string> >*)const
            // Begin code injection

            std::list<std::vector<std::string> > table;
            cppSelf->getTable(&table);

            std::size_t outListSize = table.size();
            PyObject* outList = PyList_New((int) outListSize);

            std::size_t i = 0;
            for (std::list<std::vector<std::string> >::iterator it = table.begin(); it != table.end(); ++it, ++i) {
            std::size_t subListSize = it->size();
            PyObject* subList = PyList_New((int) subListSize);
            for (std::size_t j = 0; j < subListSize; ++j) {
            std::string cppItem = (*it)[j];
            PyList_SET_ITEM(subList, j, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppItem));
            }
            PyList_SET_ITEM(outList, i, subList);
            }

            return outList;

            // End of code injection


            pyResult = Py_None;
            Py_INCREF(Py_None);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PathParamFunc_setAsMultiPathTable(PyObject* self)
{
    PathParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PathParamWrapper*)((::PathParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PATHPARAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setAsMultiPathTable()
            cppSelf->setAsMultiPathTable();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PathParamFunc_setTable(PyObject* self, PyObject* pyArg)
{
    PathParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PathParamWrapper*)((::PathParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PATHPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTable(std::list<std::vector<std::string> >)
    if (PySequence_Check(pyArg)) {
        overloadId = 0; // setTable(std::list<std::vector<std::string> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PathParamFunc_setTable_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setTable(std::list<std::vector<std::string> >)
            // Begin code injection


            if (!PyList_Check(pyArg)) {
                PyErr_SetString(PyExc_TypeError, "table must be a list of list objects.");
                return 0;
            }

            std::list<std::vector<std::string> > table;

            int size = (int)PyList_GET_SIZE(pyArg);
            for (int i = 0; i < size; ++i) {


                PyObject* subList = PyList_GET_ITEM(pyArg,i);
                if (!subList || !PyList_Check(subList)) {
                    PyErr_SetString(PyExc_TypeError, "table must be a list of list objects.");
                    return 0;
                }
                int subSize = (int)PyList_GET_SIZE(subList);
                std::vector<std::string> rowVec(subSize);

                for (int j = 0; j < subSize; ++j) {
                    PyObject* pyString = PyList_GET_ITEM(subList,j);
#if PY_MAJOR_VERSION >= 3
                    if ( PyUnicode_Check(pyString) ) {
                        char* buf = PyUnicode_AsUTF8(pyString);
#else
                    if ( PyString_Check(pyString) ) {
                        char* buf = PyString_AsString(pyString);
#endif
                        if (buf) {
                            std::string ret;
                            ret.append(buf);
                            rowVec[j] = ret;
                            }
                    } else if (PyUnicode_Check(pyString) ) {
                        PyObject* utf8pyobj = PyUnicode_AsUTF8String(pyString); // newRef
                        if (utf8pyobj) {
                            char* cstr = PyBytes_AS_STRING(utf8pyobj); // Borrowed pointer
                            std::string ret;
                            ret.append(cstr);
                            Py_DECREF(utf8pyobj);
                            rowVec[j] = ret;
                        }
                    }
                }
                table.push_back(rowVec);
            }

            cppSelf->setTable(table);


            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PathParamFunc_setTable_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PathParam.setTable");
#else
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PathParam.setTable", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_PathParam_methods[] = {
    {"getTable", (PyCFunction)Sbk_PathParamFunc_getTable, METH_NOARGS},
    {"setAsMultiPathTable", (PyCFunction)Sbk_PathParamFunc_setAsMultiPathTable, METH_NOARGS},
    {"setTable", (PyCFunction)Sbk_PathParamFunc_setTable, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PathParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PathParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_PathParam_Type = nullptr;
static SbkObjectType *Sbk_PathParam_TypeF(void)
{
    return _Sbk_PathParam_Type;
}

static PyType_Slot Sbk_PathParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PathParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PathParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PathParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_PathParam_spec = {
    "NatronEngine.PathParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PathParam_slots
};
#else
static SbkObjectType Sbk_PathParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.PathParam",
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
    /*tp_traverse*/         Sbk_PathParam_traverse,
    /*tp_clear*/            Sbk_PathParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PathParam_methods,
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

static void* Sbk_PathParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::PathParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PathParam_PythonToCpp_PathParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PathParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PathParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PathParam_PythonToCpp_PathParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PathParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PathParam_Type))
#endif
        return PathParam_PythonToCpp_PathParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PathParam_PTR_CppToPython_PathParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PathParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PathParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::PathParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_PathParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PathParam_SignatureStrings[] = {
    "NatronEngine.PathParam.getTable(table:QList[QVector])",
    "NatronEngine.PathParam.isMultiPathTable()->bool",
    "NatronEngine.PathParam.setAsMultiPathTable()",
    "NatronEngine.PathParam.setTable(table:QList[QVector])",
    nullptr}; // Sentinel
#endif

void init_PathParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_PathParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PathParam",
        "PathParam*",
        &Sbk_PathParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        PathParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::PathParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_PATHPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PathParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_PATHPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PathParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PathParam", "PathParam*",
        &Sbk_PathParam_Type, &Shiboken::callCppDestructor< ::PathParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PathParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PathParam_Type,
#endif
        PathParam_PythonToCpp_PathParam_PTR,
        is_PathParam_PythonToCpp_PathParam_PTR_Convertible,
        PathParam_PTR_CppToPython_PathParam);

    Shiboken::Conversions::registerConverterName(converter, "PathParam");
    Shiboken::Conversions::registerConverterName(converter, "PathParam*");
    Shiboken::Conversions::registerConverterName(converter, "PathParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PathParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PathParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_PathParam_TypeF(), &Sbk_PathParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_PathParam_Type, &Sbk_PathParam_typeDiscovery);
#endif


    PathParamWrapper::pysideInitQtMetaTypes();
}
