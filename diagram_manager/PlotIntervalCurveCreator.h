/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "ObjectCreator.h"
#include "PlotIntervalCurve.h"

class CPlotIntervalCurveCreator : public CObjectCreator
{
public:
    IObject* FactoryMethod() const override
    {
        return new CPlotIntervalCurve();
    }
};
