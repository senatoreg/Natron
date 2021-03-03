#ifndef SBK_LAYERWRAPPER_H
#define SBK_LAYERWRAPPER_H

#include <PyRoto.h>


// Extra includes
#include <PyRoto.h>
#include <list>
#include <PyParameter.h>
class LayerWrapper : public Natron::Python::Layer
{
public:
    ~LayerWrapper();
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

#endif // SBK_LAYERWRAPPER_H

