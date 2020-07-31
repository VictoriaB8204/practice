/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalObject.h"

#ifdef __cplusplus
extern "C"{
#endif

class CIntervalObjectCreator
{
public:
    virtual IIntervalObject* FactoryMethod() const = 0;

    IIntervalObject* CreateObject() const
    {
        return this->FactoryMethod();
    }

    virtual ~CIntervalObjectCreator(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
