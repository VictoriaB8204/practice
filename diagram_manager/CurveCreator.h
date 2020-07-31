/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Curve.h"

#ifdef __cplusplus
extern "C"{
#endif

class CCurveCreator
{
public:
    virtual ICurve* FactoryMethod() const = 0;
    ICurve* CreateObject() const
    {
        return this->FactoryMethod();
    }
    virtual ~CCurveCreator(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
