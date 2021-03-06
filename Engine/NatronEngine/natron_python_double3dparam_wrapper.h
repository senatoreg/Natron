#ifndef SBK_DOUBLE3DPARAMWRAPPER_H
#define SBK_DOUBLE3DPARAMWRAPPER_H

#include <PyParameter.h>


// Extra includes
#include <PyParameter.h>
class Double3DParamWrapper : public Natron::Python::Double3DParam
{
public:
    ~Double3DParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_DOUBLE2DPARAMWRAPPER_H
#  define SBK_DOUBLE2DPARAMWRAPPER_H

// Inherited base class:
class Double2DParamWrapper : public Natron::Python::Double2DParam
{
public:
    ~Double2DParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_DOUBLE2DPARAMWRAPPER_H

#  ifndef SBK_DOUBLEPARAMWRAPPER_H
#  define SBK_DOUBLEPARAMWRAPPER_H

// Inherited base class:
class DoubleParamWrapper : public Natron::Python::DoubleParam
{
public:
    ~DoubleParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_DOUBLEPARAMWRAPPER_H

#  ifndef SBK_ANIMATEDPARAMWRAPPER_H
#  define SBK_ANIMATEDPARAMWRAPPER_H

// Inherited base class:
class AnimatedParamWrapper : public Natron::Python::AnimatedParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Natron::Python::Param * param, int thisDimension) { Natron::Python::AnimatedParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    ~AnimatedParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_ANIMATEDPARAMWRAPPER_H

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

#endif // SBK_DOUBLE3DPARAMWRAPPER_H

