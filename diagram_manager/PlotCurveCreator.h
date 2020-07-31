/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "CurveCreator.h"
#include "PlotCurve.h"

class CPlotCurveCreator : public CCurveCreator
{
public:
    ICurve* FactoryMethod() const override
    {
        return new CPlotCurve();
    }
};
