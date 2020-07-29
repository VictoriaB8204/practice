/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "DiagramCreator.h"
#include "Plot.h"

class CPlotCreator : public CDiagramCreator
{
public:
    IDiagram* FactoryMethod() const override
    {
        return new CPlot();
    }
};
