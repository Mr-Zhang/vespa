// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include "xmlserializable.h"
#include <sstream>
#include <vespa/vespalib/util/exceptions.h>

namespace vespalib {
namespace xml {

template<typename T>
XmlAttribute::XmlAttribute(const std::string& name, const T& value, uint32_t flags)
    : _name(name),
      _value(),
      _next()
{
    std::ostringstream ost;
    if (flags & HEX) ost << std::hex << "0x";
    ost << value;
    _value = ost.str();
    if (!isLegalName(name)) {
        throw vespalib::IllegalArgumentException("Name '" + name + "' contains "
                "illegal XML characters and cannot be used as attribute name");
    }
}

}
}
