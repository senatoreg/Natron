#ifndef SBK_STRINGNODECREATIONPROPERTYWRAPPER_H
#define SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

#include <PyAppInstance.h>


// Extra includes
#include <vector>
class StringNodeCreationPropertyWrapper : public Natron::Python::StringNodeCreationProperty
{
public:
    StringNodeCreationPropertyWrapper(const std::string & value);
    StringNodeCreationPropertyWrapper(const std::vector<std::string > & values = std::vector< std::string >());
    ~StringNodeCreationPropertyWrapper();
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

#endif // SBK_STRINGNODECREATIONPROPERTYWRAPPER_H

