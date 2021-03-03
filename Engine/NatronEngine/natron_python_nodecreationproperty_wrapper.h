#ifndef SBK_NODECREATIONPROPERTYWRAPPER_H
#define SBK_NODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>

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

#endif // SBK_NODECREATIONPROPERTYWRAPPER_H

