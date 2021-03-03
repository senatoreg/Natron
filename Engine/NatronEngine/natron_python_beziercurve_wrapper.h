#ifndef SBK_BEZIERCURVEWRAPPER_H
#define SBK_BEZIERCURVEWRAPPER_H

#include <PyRoto.h>


// Extra includes
#include <list>
#include <PyParameter.h>
#include <PyRoto.h>
class BezierCurveWrapper : public Natron::Python::BezierCurve
{
public:
    ~BezierCurveWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_ITEMBASEWRAPPER_H
#  define SBK_ITEMBASEWRAPPER_H

// Inherited base class:
class ItemBaseWrapper : public Natron::Python::ItemBase
{
public:
    ~ItemBaseWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_ITEMBASEWRAPPER_H

#endif // SBK_BEZIERCURVEWRAPPER_H

