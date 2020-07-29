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
    void SetAxisTitle( EAxis axis, QString string ) override;
    void SetAxisScale( EAxis axis, double min, double max, double step ) override;
    void SetTitle( QString string ) override;
    void SetFooter( QString string ) override;
    void SetAxisMaxMinor( EAxis axis , int maxMinor ) override;
    void SetAxisMaxMajor( EAxis axis, int maxMajor ) override;
    void InsertLegend( ELegendPosition position ) override;
    void SetMagnifier( Qt::MouseButton button ) override;
    void SetPanner( Qt::MouseButton button ) override;
    QwtPlot* SetWidget() override;
    QwtPlot* SetParent() override;
    ~CPlot();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
