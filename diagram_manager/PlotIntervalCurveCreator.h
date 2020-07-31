/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalObjectCreator.h"
#include "PlotIntervalCurve.h"

class CPlotIntervalCurveCreator : public CIntervalObjectCreator
{
public:
    IIntervalObject* FactoryMethod() const override
    {
        return new CPlotIntervalCurve();
    }
};
