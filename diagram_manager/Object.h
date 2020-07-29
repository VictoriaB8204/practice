/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Plot.h"

#ifdef __cplusplus
extern "C"{
#endif

class IObject
{
public:
    virtual void Attach( IDiagram * ) = 0;
    virtual void SetTitle( QString ) = 0;
    virtual void SetPen( QPen ) = 0;
    virtual ~IObject();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
