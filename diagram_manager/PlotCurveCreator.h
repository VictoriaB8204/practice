/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "ObjectCreator.h"
#include "PlotCurve.h"

class CPlotCurveCreator : public CObjectCreator
{
public:
    IObject* FactoryMethod() const override
    {
        return new CPlotCurve();
    }
};
