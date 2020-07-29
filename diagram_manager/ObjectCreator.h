/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Object.h"

#ifdef __cplusplus
extern "C"{
#endif

class CObjectCreator
{
public:
    virtual IObject* FactoryMethod() const = 0;
    IObject* CreateDiagram() const
    {
        return this->FactoryMethod();
    }
    virtual ~CObjectCreator();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
