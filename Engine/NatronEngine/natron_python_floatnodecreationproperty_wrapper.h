#ifndef SBK_FLOATNODECREATIONPROPERTYWRAPPER_H
#define SBK_FLOATNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>


// Extra includes
#include <vector>
class FloatNodeCreationPropertyWrapper : public Natron::Python::FloatNodeCreationProperty
{
public:
    FloatNodeCreationPropertyWrapper(const std::vector<double > & values = std::vector< double >());
    FloatNodeCreationPropertyWrapper(double value);
    ~FloatNodeCreationPropertyWrapper();
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

#endif // SBK_FLOATNODECREATIONPROPERTYWRAPPER_H

