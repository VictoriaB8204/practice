/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "ObjectCreator.h"
#include "PlotHistogram.h"

class CPlotHistogramCreator : public CObjectCreator
{
public:
    IObject* FactoryMethod() const override
    {
        return new CPlotHistogram();
    }
};
