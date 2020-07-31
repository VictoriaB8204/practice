/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Marker.h"

#ifdef __cplusplus
extern "C"{
#endif

class CMarkerCreator
{
public:
    virtual IMarker* FactoryMethod() const = 0;

    IMarker* CreateObject() const
    {
        return this->FactoryMethod();
    }

    virtual ~CMarkerCreator(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
