/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "MarkerCreator.h"
#include "PlotMarker.h"

class CPlotMarkerCreator : public CMarkerCreator
{
public:
    IMarker* FactoryMethod() const override
    {
        return new CPlotMarker();
    }
};
