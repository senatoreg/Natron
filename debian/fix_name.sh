#!/bin/sh
sed -i'.postsbk' -e '/[a-z0-9]\+_NATRON_NAMESPACE/ {s,\([a-zA-Z0-9]\+\)_\(NATRON_NAMESPACE\),\1_Natron,g}' \
                 -e '/NATRON_NAMESPACE_[A-Za-z0-9][a-z0-9]\+/ {s,\(NATRON_NAMESPACE\)_\([A-Za-z0-9][a-z0-9]\+\),Natron_\2,g}' \
    ./Engine/NatronEngine/natron_namespace_wrapper.cpp \
    ./Engine/NatronEngine/natronengine_module_wrapper.cpp
