/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalObjectCreator.h"
#include "PlotHistogram.h"

class CPlotHistogramCreator : public CIntervalObjectCreator
{
public:
    IIntervalObject* FactoryMethod() const override
    {
        return new CPlotHistogram();
    }
};
