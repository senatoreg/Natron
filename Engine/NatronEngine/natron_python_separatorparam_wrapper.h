#ifndef SBK_SEPARATORPARAMWRAPPER_H
#define SBK_SEPARATORPARAMWRAPPER_H

#include <PyParameter.h>


// Extra includes
#include <PyParameter.h>
class SeparatorParamWrapper : public Natron::Python::SeparatorParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Natron::Python::Param * param, int thisDimension) { Natron::Python::SeparatorParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~SeparatorParamWrapper();
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

#endif // SBK_SEPARATORPARAMWRAPPER_H

