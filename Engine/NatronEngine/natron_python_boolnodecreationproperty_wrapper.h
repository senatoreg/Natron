#ifndef SBK_BOOLNODECREATIONPROPERTYWRAPPER_H
#define SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>


// Extra includes
#include <vector>
class BoolNodeCreationPropertyWrapper : public Natron::Python::BoolNodeCreationProperty
{
public:
    BoolNodeCreationPropertyWrapper(bool value);
    BoolNodeCreationPropertyWrapper(const std::vector<bool > & values = std::vector< bool >());
    ~BoolNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_NODECREATIONPROPERTYWRAPPER_H
#  define SBK_NODECREATIONPROPERTYWRAPPER_H

// Inherited base class:
class NodeCreationPropertyWrapper : public Natron::Python::NodeCreationProperty
{
public:
    NodeCreationPropertyWrapper();
    ~NodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_NODECREATIONPROPERTYWRAPPER_H

#endif // SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

