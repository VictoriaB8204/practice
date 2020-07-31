/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Diagram.h"

#ifdef __cplusplus
extern "C"{
#endif

class CDiagramCreator
{
public:
    virtual IDiagram* FactoryMethod() const = 0;
    IDiagram* CreateDiagram() const
    {
        return this->FactoryMethod();
    }
    virtual ~CDiagramCreator(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
