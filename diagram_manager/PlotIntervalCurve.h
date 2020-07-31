/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalObject.h"
#include <qwt_plot_intervalcurve.h>

#ifdef __cplusplus
extern "C"{
#endif

class CPlotIntervalCurve : public IIntervalObject
{
    QwtPlotIntervalCurve *m_curve;
public:
    CPlotIntervalCurve();
    void SetTitle ( QString ) override;
    void SetSamples( QVector< CIntervalSample > ) override;
    void SetPen( const QPen & ) override;
    void SetBrush( const QBrush & ) override;
    void SetStyle( ECurveStyle ) override;
    void Attach( IDiagram * ) override;
    ~CPlotIntervalCurve();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
