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

class CPlot : public IDiagram
{
    QwtPlot *m_plot;

public:
    CPlot();
    void SetAxisTitle( EAxis, QString ) override;
    void SetAxisScale( EAxis, double, double, double ) override;
    void SetTitle( QString ) override;
    void SetFooter( QString ) override;
    void SetBackground( Qt::GlobalColor ) override;
    void SetAxisMaxMinor( EAxis, int ) override;
    void SetAxisMaxMajor( EAxis, int ) override;
    void SetGrid( QPen ) override;
    void SetLegend( ELegendPosition ) override;
    void SetMagnifier( Qt::MouseButton ) override;
    void SetPanner( Qt::MouseButton ) override;
    QwtPlot* SetWidget() override;
    QwtPlot* SetParent() override;
    ~CPlot();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
