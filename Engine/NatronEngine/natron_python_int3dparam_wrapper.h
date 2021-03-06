#ifndef SBK_INT3DPARAMWRAPPER_H
#define SBK_INT3DPARAMWRAPPER_H

#include <PyParameter.h>


// Extra includes
#include <PyParameter.h>
class Int3DParamWrapper : public Natron::Python::Int3DParam
{
public:
    ~Int3DParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_INT2DPARAMWRAPPER_H
#  define SBK_INT2DPARAMWRAPPER_H

// Inherited base class:
class Int2DParamWrapper : public Natron::Python::Int2DParam
{
public:
    ~Int2DParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_INT2DPARAMWRAPPER_H

#  ifndef SBK_INTPARAMWRAPPER_H
#  define SBK_INTPARAMWRAPPER_H

// Inherited base class:
class IntParamWrapper : public Natron::Python::IntParam
{
public:
    ~IntParamWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_INTPARAMWRAPPER_H

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

#endif // SBK_INT3DPARAMWRAPPER_H

