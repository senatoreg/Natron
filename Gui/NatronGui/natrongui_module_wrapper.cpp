
#include <sbkpython.h>
#include <shiboken.h>
#include <algorithm>
#include <signature.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>
#include "natrongui_python.h"



// Extra includes

// Current module's type array.
PyTypeObject **SbkNatronGuiTypes = nullptr;
// Current module's PyObject pointer.
PyObject *SbkNatronGuiModuleObject = nullptr;
// Current module's converter array.
SbkConverter **SbkNatronGuiTypeConverters = nullptr;
void cleanGuiTypesAttributes(void) {
    if (PY_VERSION_HEX >= 0x03000000 && PY_VERSION_HEX < 0x03060000)
        return; // PYSIDE-953: testbinding crashes in Python 3.5 when hasattr touches types!
    for (int i = 0, imax = SBK_NatronGui_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject *>(SbkNatronGuiTypes[i]);
        Shiboken::AutoDecRef attrName(Py_BuildValue("s", "staticMetaObject"));
        if (pyType && PyObject_HasAttr(pyType, attrName))
            PyObject_SetAttr(pyType, attrName, Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef NatronGui_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_Natron_Python_PyViewer(PyObject *module);
void init_Natron_Python_PyTabWidget(PyObject *module);
void init_Natron_Python_PyModalDialog(PyObject *module);
void init_Natron_Python_PyPanel(PyObject *module);
void init_Natron_Python_PyGuiApplication(PyObject *module);
void init_Natron_Python_GuiApp(PyObject *module);

// Required modules' type and converter arrays.
PyTypeObject **SbkPySide2_QtGuiTypes;
SbkConverter **SbkPySide2_QtGuiTypeConverters;
PyTypeObject **SbkPySide2_QtWidgetsTypes;
SbkConverter **SbkPySide2_QtWidgetsTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'const std::map<QString,Natron::Python::NodeCreationProperty* > &'.
static PyObject *_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_CppToPython__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::map<QString,Natron::Python::NodeCreationProperty* > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdMapToPyDict - START
    PyObject* pyOut = PyDict_New();
    ::std::map<QString,Natron::Python::NodeCreationProperty* >::const_iterator it = cppInRef.begin();
    for (; it != cppInRef.end(); ++it) {
    ::QString key = it->first;
    ::Natron::Python::NodeCreationProperty* value = it->second;
    PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
    PyObject* pyValue = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]), value);
    PyDict_SetItem(pyOut, pyKey, pyValue);
    Py_DECREF(pyKey);
    Py_DECREF(pyValue);
    }
    return pyOut;
    // TEMPLATE - stdMapToPyDict - END

}
static void _conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::map<QString,Natron::Python::NodeCreationProperty* > *>(cppOut);
    // TEMPLATE - pyDictToStdMap - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
    ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
    ::Natron::Python::NodeCreationProperty* cppValue{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]), value, &(cppValue));
    cppOutRef.insert(std::make_pair(cppKey, cppValue));
    }
    // TEMPLATE - pyDictToStdMap - END

}
static PythonToCppFunc is__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, *PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX])->converter, true, pyIn))
        return _conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::Effect* >'.
static PyObject *_std_list_Natron_Python_EffectPTR__CppToPython__std_list_Natron_Python_EffectPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::Effect* > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdListToPyList - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::std::list<Natron::Python::Effect* >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
    ::Natron::Python::Effect* cppItem(*it);
    PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppItem));
    }
    return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void _std_list_Natron_Python_EffectPTR__PythonToCpp__std_list_Natron_Python_EffectPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::Effect* > *>(cppOut);
    // TEMPLATE - pyListToStdList - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    ::Natron::Python::Effect* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is__std_list_Natron_Python_EffectPTR__PythonToCpp__std_list_Natron_Python_EffectPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], pyIn))
        return _std_list_Natron_Python_EffectPTR__PythonToCpp__std_list_Natron_Python_EffectPTR_;
    return {};
}

// C++ to Python conversion for type 'std::list<QString >'.
static PyObject *_std_list_QString__CppToPython__std_list_QString_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<QString > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdListToPyList - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::std::list<QString >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
    ::QString cppItem(*it);
    PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
    }
    return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void _std_list_QString__PythonToCpp__std_list_QString_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<QString > *>(cppOut);
    // TEMPLATE - pyListToStdList - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    ::QString cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is__std_list_QString__PythonToCpp__std_list_QString__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return _std_list_QString__PythonToCpp__std_list_QString_;
    return {};
}

// C++ to Python conversion for type 'const std::list<int > &'.
static PyObject *_conststd_list_int_REF_CppToPython__conststd_list_int_REF(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<int > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdListToPyList - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::std::list<int >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
    int cppItem(*it);
    PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppItem));
    }
    return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void _conststd_list_int_REF_PythonToCpp__conststd_list_int_REF(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<int > *>(cppOut);
    // TEMPLATE - pyListToStdList - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is__conststd_list_int_REF_PythonToCpp__conststd_list_int_REF_Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return _conststd_list_int_REF_PythonToCpp__conststd_list_int_REF;
    return {};
}

// C++ to Python conversion for type 'std::vector<std::string > *'.
static PyObject *_std_vector_std_string_PTR_CppToPython__std_vector_std_string_PTR(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<std::string > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdVectorToPyList - START
    ::std::vector<std::string >::size_type vectorSize = cppInRef.size();
    PyObject* pyOut = PyList_New((int) vectorSize);
    for (::std::vector<std::string >::size_type idx = 0; idx < vectorSize; ++idx) {
    ::std::string cppItem(cppInRef[idx]);
    PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppItem));
    }
    return pyOut;
    // TEMPLATE - stdVectorToPyList - END

}
static void _std_vector_std_string_PTR_PythonToCpp__std_vector_std_string_PTR(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<std::string > *>(cppOut);
    // TEMPLATE - pySeqToStdVector - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
    ::std::string cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pySeqToStdVector - END

}
static PythonToCppFunc is__std_vector_std_string_PTR_PythonToCpp__std_vector_std_string_PTR_Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), pyIn))
        return _std_vector_std_string_PTR_PythonToCpp__std_vector_std_string_PTR;
    return {};
}

// C++ to Python conversion for type 'QList<QAction* >'.
static PyObject *_QList_QActionPTR__CppToPython__QList_QActionPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::QList<QAction* > *>(const_cast<void *>(cppIn));
    // TEMPLATE - cpplist_to_pylist_conversion - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::QList<QAction* >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::QAction* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QACTION_IDX]), cppItem));
    }
    return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QActionPTR__PythonToCpp__QList_QActionPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QList<QAction* > *>(cppOut);
    // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
        Shiboken::AutoDecRef pyItem(iternext(it));
        if (pyItem.isNull()) {
            if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
                PyErr_Clear();
            break;
        }
        ::QAction* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QACTION_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide2_QtWidgetsTypes[SBK_QACTION_IDX], pyIn))
        return _QList_QActionPTR__PythonToCpp__QList_QActionPTR_;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::Param* >'.
static PyObject *_std_list_Natron_Python_ParamPTR__CppToPython__std_list_Natron_Python_ParamPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::Param* > *>(const_cast<void *>(cppIn));
    // TEMPLATE - stdListToPyList - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::std::list<Natron::Python::Param* >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
    ::Natron::Python::Param* cppItem(*it);
    PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), cppItem));
    }
    return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void _std_list_Natron_Python_ParamPTR__PythonToCpp__std_list_Natron_Python_ParamPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::Param* > *>(cppOut);
    // TEMPLATE - pyListToStdList - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    ::Natron::Python::Param* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is__std_list_Natron_Python_ParamPTR__PythonToCpp__std_list_Natron_Python_ParamPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], pyIn))
        return _std_list_Natron_Python_ParamPTR__PythonToCpp__std_list_Natron_Python_ParamPTR_;
    return {};
}

// C++ to Python conversion for type 'QList<QVariant >'.
static PyObject *_QList_QVariant__CppToPython__QList_QVariant_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::QList<QVariant > *>(const_cast<void *>(cppIn));
    // TEMPLATE - cpplist_to_pylist_conversion - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::QList<QVariant >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::QVariant cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppItem));
    }
    return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QVariant__PythonToCpp__QList_QVariant_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QList<QVariant > *>(cppOut);
    // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
        Shiboken::AutoDecRef pyItem(iternext(it));
        if (pyItem.isNull()) {
            if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
                PyErr_Clear();
            break;
        }
        ::QVariant cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return _QList_QVariant__PythonToCpp__QList_QVariant_;
    return {};
}

// C++ to Python conversion for type 'QList<QString >'.
static PyObject *_QList_QString__CppToPython__QList_QString_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::QList<QString > *>(const_cast<void *>(cppIn));
    // TEMPLATE - cpplist_to_pylist_conversion - START
    PyObject* pyOut = PyList_New((int) cppInRef.size());
    ::QList<QString >::const_iterator it = cppInRef.begin();
    for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::QString cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
    }
    return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QString__PythonToCpp__QList_QString_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QList<QString > *>(cppOut);
    // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
        Shiboken::AutoDecRef pyItem(iternext(it));
        if (pyItem.isNull()) {
            if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
                PyErr_Clear();
            break;
        }
        ::QString cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QString__PythonToCpp__QList_QString__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return _QList_QString__PythonToCpp__QList_QString_;
    return {};
}

// C++ to Python conversion for type 'QMap<QString,QVariant >'.
static PyObject *_QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::QMap<QString,QVariant > *>(const_cast<void *>(cppIn));
    // TEMPLATE - cppmap_to_pymap_conversion - START
    PyObject *pyOut = PyDict_New();
    for (::QMap<QString,QVariant >::const_iterator it = cppInRef.begin(), end = cppInRef.end(); it != end; ++it) {
        ::QString key = it.key();
        ::QVariant value = it.value();
        PyObject *pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
        PyObject *pyValue = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
        PyDict_SetItem(pyOut, pyKey, pyValue);
        Py_DECREF(pyKey);
        Py_DECREF(pyValue);
    }
    return pyOut;
    // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QMap<QString,QVariant > *>(cppOut);
    // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject *key;
    PyObject *value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QVariant cppValue;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_;
    return {};
}


#ifdef IS_PY3K
static struct PyModuleDef moduledef = {
    /* m_base     */ PyModuleDef_HEAD_INIT,
    /* m_name     */ "NatronGui",
    /* m_doc      */ nullptr,
    /* m_size     */ -1,
    /* m_methods  */ NatronGui_methods,
    /* m_reload   */ nullptr,
    /* m_traverse */ nullptr,
    /* m_clear    */ nullptr,
    /* m_free     */ nullptr
};

#endif

// The signatures string for the global functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronGui_SignatureStrings[] = {
    nullptr}; // Sentinel

SBK_MODULE_INIT_FUNCTION_BEGIN(NatronGui)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtGui"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtGuiTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtGuiTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtWidgets"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtWidgetsTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtWidgetsTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("NatronEngine"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkNatronEngineTypes = Shiboken::Module::getTypes(requiredModule);
        SbkNatronEngineTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject *cppApi[SBK_NatronGui_IDX_COUNT];
    SbkNatronGuiTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter *sbkConverters[SBK_NatronGui_CONVERTERS_IDX_COUNT];
    SbkNatronGuiTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject *module = Shiboken::Module::create("NatronGui", &moduledef);
#else
    PyObject *module = Shiboken::Module::create("NatronGui", NatronGui_methods);
#endif

    // Make module available from global scope
    SbkNatronGuiModuleObject = module;

    // Initialize classes in the type system
    init_Natron_Python_PyViewer(module);
    init_Natron_Python_PyTabWidget(module);
    init_Natron_Python_PyModalDialog(module);
    init_Natron_Python_PyPanel(module);
    init_Natron_Python_PyGuiApplication(module);
    init_Natron_Python_GuiApp(module);

    // Register converter for type 'const std::map<QString,Natron::Python::NodeCreationProperty*>&'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_CppToPython__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], "const std::map<QString,Natron::Python::NodeCreationProperty*>&");
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], "std::map<QString,Natron::Python::NodeCreationProperty*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX],
        _conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF,
        is__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp__conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_Convertible);

    // Register converter for type 'std::list<Natron::Python::Effect*>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _std_list_Natron_Python_EffectPTR__CppToPython__std_list_Natron_Python_EffectPTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX], "std::list<Natron::Python::Effect*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX],
        _std_list_Natron_Python_EffectPTR__PythonToCpp__std_list_Natron_Python_EffectPTR_,
        is__std_list_Natron_Python_EffectPTR__PythonToCpp__std_list_Natron_Python_EffectPTR__Convertible);

    // Register converter for type 'std::list<QString>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _std_list_QString__CppToPython__std_list_QString_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_QSTRING_IDX], "std::list<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_QSTRING_IDX],
        _std_list_QString__PythonToCpp__std_list_QString_,
        is__std_list_QString__PythonToCpp__std_list_QString__Convertible);

    // Register converter for type 'const std::list<int>&'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _conststd_list_int_REF_CppToPython__conststd_list_int_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_INT_IDX], "const std::list<int>&");
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_INT_IDX], "std::list<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_INT_IDX],
        _conststd_list_int_REF_PythonToCpp__conststd_list_int_REF,
        is__conststd_list_int_REF_PythonToCpp__conststd_list_int_REF_Convertible);

    // Register converter for type 'std::vector<std::string>*'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_VECTOR_STD_STRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _std_vector_std_string_PTR_CppToPython__std_vector_std_string_PTR);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_VECTOR_STD_STRING_IDX], "std::vector<std::string>*");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_VECTOR_STD_STRING_IDX],
        _std_vector_std_string_PTR_PythonToCpp__std_vector_std_string_PTR,
        is__std_vector_std_string_PTR_PythonToCpp__std_vector_std_string_PTR_Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'std::list<Natron::Python::Param*>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _std_list_Natron_Python_ParamPTR__CppToPython__std_list_Natron_Python_ParamPTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX], "std::list<Natron::Python::Param*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX],
        _std_list_Natron_Python_ParamPTR__PythonToCpp__std_list_Natron_Python_ParamPTR_,
        is__std_list_Natron_Python_ParamPTR__PythonToCpp__std_list_Natron_Python_ParamPTR__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkNatronGuiTypeConverters[SBK_NATRONGUI_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronGuiTypeConverters[SBK_NATRONGUI_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkNatronGuiTypes);
    Shiboken::Module::registerTypeConverters(module, SbkNatronGuiTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module NatronGui");
    }
    PySide::registerCleanupFunction(cleanGuiTypesAttributes);

    FinishSignatureInitialization(module, NatronGui_SignatureStrings);

SBK_MODULE_INIT_FUNCTION_END
