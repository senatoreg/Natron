#ifndef SBK_BUTTONPARAMWRAPPER_H
#define SBK_BUTTONPARAMWRAPPER_H

#include <PyParameter.h>


// Extra includes
#include <PyParameter.h>
class ButtonParamWrapper : public Natron::Python::ButtonParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Natron::Python::Param * param, int thisDimension) { Natron::Python::ButtonParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~ButtonParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_PARAMWRAPPER_H
#  define SBK_PARAMWRAPPER_H

// Inherited base class:
class ParamWrapper : public Natron::Python::Param
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Natron::Python::Param * param, int thisDimension) { Natron::Python::Param::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~ParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_PARAMWRAPPER_H

#endif // SBK_BUTTONPARAMWRAPPER_H

