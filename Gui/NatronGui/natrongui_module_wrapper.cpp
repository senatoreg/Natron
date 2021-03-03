
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
void cleanTypesAttributes(void) {
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
static PyObject *Sbk_Natron_PythonFunc_PyStringToStdString(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::PyStringToStdString(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // PyStringToStdString(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_PyStringToStdString_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyStringToStdString(PyObject*)
            std::string cppResult = ::Natron::Python::PyStringToStdString(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_PyStringToStdString_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Python.PyStringToStdString");
        return {};
}

static PyObject *Sbk_NatronFunc_getAmountFreePhysicalRAM(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAmountFreePhysicalRAM()
            std::size_t cppResult = ::Natron::getAmountFreePhysicalRAM();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_PythonFunc_getAttrRecursive(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getAttrRecursive", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getAttrRecursive(std::string,PyObject*,bool*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && PyObject_Check(pyArgs[1])
        && PyBool_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // getAttrRecursive(std::string,PyObject*,bool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getAttrRecursive_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getAttrRecursive(std::string,PyObject*,bool*)
            PyObject * cppResult = ::Natron::Python::getAttrRecursive(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_getAttrRecursive_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Python.getAttrRecursive");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getFunctionArguments(PyObject *self, PyObject *args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getFunctionArguments", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_VECTOR_STD_STRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getFunctionArguments_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::vector<std::string > *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
            ::Natron::Python::getFunctionArguments(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_PythonFunc_getFunctionArguments_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Python.getFunctionArguments");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getGroupInfos(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getGroupInfos", 9, 9, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
    if (numArgs == 9
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[6])))
        && PyBool_Check(pyArgs[7]) && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[8])))) {
        overloadId = 0; // getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getGroupInfos_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::string *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::std::string *cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::std::string *cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        ::std::string *cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        ::std::string *cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        bool *cppArg7;
        pythonToCpp[7](pyArgs[7], &cppArg7);
        unsigned int *cppArg8;
        pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!PyErr_Occurred()) {
            // getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
            bool cppResult = ::Natron::Python::getGroupInfos(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_getGroupInfos_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Python.getGroupInfos");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getMainModule(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getMainModule()
            PyObject * cppResult = ::Natron::Python::getMainModule();
            pyResult = Shiboken::Conversions::copyToPython(, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_PythonFunc_interpretPythonScript(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "interpretPythonScript", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::interpretPythonScript(std::string,std::string*,std::string*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[2])))) {
        overloadId = 0; // interpretPythonScript(std::string,std::string*,std::string*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_interpretPythonScript_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::string *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // interpretPythonScript(std::string,std::string*,std::string*)
            bool cppResult = ::Natron::Python::interpretPythonScript(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_interpretPythonScript_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Python.interpretPythonScript");
        return {};
}

static PyObject *Sbk_NatronFunc_isApplication32Bits(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isApplication32Bits()
            bool cppResult = ::Natron::isApplication32Bits();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_NatronFunc_isFailureRetCode(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Natron::isFailureRetCode(Natron::StatusEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // isFailureRetCode(Natron::StatusEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc_isFailureRetCode_TypeError;

    // Call function/method
    {
        ::Natron::StatusEnum cppArg0{Natron::eStatusOK};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isFailureRetCode(Natron::StatusEnum)
            bool cppResult = ::Natron::isFailureRetCode(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc_isFailureRetCode_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.isFailureRetCode");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendly(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendly(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendly(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendly(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendly(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Python.makeNameScriptFriendly");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendlyWithDots(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendlyWithDots(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendlyWithDots(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendlyWithDots(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Python.makeNameScriptFriendlyWithDots");
        return {};
}

static PyObject *Sbk_NatronFunc___rne__(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "__rne__", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: static Natron::operator!=(Natron::RectD,Natron::RectD)
    // 1: static Natron::operator!=(Natron::RectI,Natron::RectI)
    if (numArgs >= 2
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArg)))
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArg)))) {
        overloadId = 1; // operator!=(Natron::RectI,Natron::RectI)
    } else if (numArgs >= 2
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArg)))
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArg)))) {
        overloadId = 0; // operator!=(Natron::RectD,Natron::RectD)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return {};
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc___rne___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator!=(const Natron::RectD & b1, const Natron::RectD & b2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectD *cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectD *cppArg1;
            pythonToCpp(pyArg, &cppArg1);

            if (!PyErr_Occurred()) {
                // operator!=(Natron::RectD,Natron::RectD)
                bool cppResult = (*cppSelf) != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // operator!=(const Natron::RectI & b1, const Natron::RectI & b2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectI *cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectI *cppArg1;
            pythonToCpp(pyArg, &cppArg1);

            if (!PyErr_Occurred()) {
                // operator!=(Natron::RectI,Natron::RectI)
                bool cppResult = (*cppSelf) != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc___rne___TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.__rne__");
        return {};
}

static PyObject *Sbk_NatronFunc___req__(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "__req__", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: static Natron::operator==(Natron::RectD,Natron::RectD)
    // 1: static Natron::operator==(Natron::RectI,Natron::RectI)
    if (numArgs >= 2
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArg)))
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArg)))) {
        overloadId = 1; // operator==(Natron::RectI,Natron::RectI)
    } else if (numArgs >= 2
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArg)))
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArg)))) {
        overloadId = 0; // operator==(Natron::RectD,Natron::RectD)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return {};
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc___req___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator==(const Natron::RectD & b1, const Natron::RectD & b2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectD *cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectD *cppArg1;
            pythonToCpp(pyArg, &cppArg1);

            if (!PyErr_Occurred()) {
                // operator==(Natron::RectD,Natron::RectD)
                bool cppResult = (*cppSelf) == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // operator==(const Natron::RectI & b1, const Natron::RectI & b2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectI *cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            if (!Shiboken::Object::isValid(pyArg))
                return {};
            ::Natron::RectI *cppArg1;
            pythonToCpp(pyArg, &cppArg1);

            if (!PyErr_Occurred()) {
                // operator==(Natron::RectI,Natron::RectI)
                bool cppResult = (*cppSelf) == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc___req___TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.__req__");
        return {};
}


static PyMethodDef NatronGui_methods[] = {
    {"PyStringToStdString", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_PyStringToStdString), METH_O},
    {"getAmountFreePhysicalRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getAmountFreePhysicalRAM), METH_NOARGS},
    {"getAttrRecursive", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getAttrRecursive), METH_VARARGS},
    {"getFunctionArguments", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getFunctionArguments), METH_VARARGS},
    {"getGroupInfos", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getGroupInfos), METH_VARARGS},
    {"getMainModule", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getMainModule), METH_NOARGS},
    {"interpretPythonScript", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_interpretPythonScript), METH_VARARGS},
    {"isApplication32Bits", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isApplication32Bits), METH_NOARGS},
    {"isFailureRetCode", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isFailureRetCode), METH_O},
    {"makeNameScriptFriendly", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendly), METH_O},
    {"makeNameScriptFriendlyWithDots", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots), METH_O},
    {"operator!=", reinterpret_cast<PyCFunction>(Sbk_NatronFunc___rne__), METH_VARARGS},
    {"operator==", reinterpret_cast<PyCFunction>(Sbk_NatronFunc___req__), METH_VARARGS},
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
PyTypeObject **SbkPySide2_QtCoreTypes;
SbkConverter **SbkPySide2_QtCoreTypeConverters;
PyTypeObject **SbkNatronEngineTypes;
SbkConverter **SbkNatronEngineTypeConverters;

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
    "NatronGui.Python.PyStringToStdString(obj:PyObject)->std.string",
    "NatronGui.Natron.getAmountFreePhysicalRAM()->std.size_t",
    "NatronGui.Python.getAttrRecursive(fullyQualifiedName:std.string,parentObj:PyObject,isDefined:bool*)->PyObject",
    "NatronGui.Python.getFunctionArguments(pyFunc:std.string,error:std.string*,args:std.vector[std.string])",
    "NatronGui.Python.getGroupInfos(modulePath:std.string,pythonModule:std.string,pluginID:std.string*,pluginLabel:std.string*,iconFilePath:std.string*,grouping:std.string*,description:std.string*,isToolset:bool*,version:unsigned int*)->bool",
    "NatronGui.Python.getMainModule()->PyObject",
    "NatronGui.Python.interpretPythonScript(script:std.string,error:std.string*,output:std.string*)->bool",
    "NatronGui.Natron.isApplication32Bits()->bool",
    "NatronGui.Natron.isFailureRetCode(code:NatronEngine.Natron.StatusEnum)->bool",
    "NatronGui.Python.makeNameScriptFriendly(str:std.string)->std.string",
    "NatronGui.Python.makeNameScriptFriendlyWithDots(str:std.string)->std.string",
    "1:NatronGui.Natron.__rne__(b1:NatronEngine.Natron.RectD,b2:NatronEngine.Natron.RectD)->bool",
    "0:NatronGui.Natron.__rne__(b1:NatronEngine.Natron.RectI,b2:NatronEngine.Natron.RectI)->bool",
    "1:NatronGui.Natron.__req__(b1:NatronEngine.Natron.RectD,b2:NatronEngine.Natron.RectD)->bool",
    "0:NatronGui.Natron.__req__(b1:NatronEngine.Natron.RectI,b2:NatronEngine.Natron.RectI)->bool",
    nullptr}; // Sentinel

SBK_MODULE_INIT_FUNCTION_BEGIN(NatronGui)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtGui"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtGuiTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtGuiTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
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
    PySide::registerCleanupFunction(cleanTypesAttributes);

    FinishSignatureInitialization(module, NatronGui_SignatureStrings);

SBK_MODULE_INIT_FUNCTION_END
