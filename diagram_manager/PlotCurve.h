/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Curve.h"
#include <qwt_plot_curve.h>

#ifdef __cplusplus
extern "C"{
#endif

class CPlotCurve : public ICurve
{
    QwtPlotCurve *m_curve;
public:
    CPlotCurve();
    void SetPaintAttribute( EPaintAttribute, bool on = true ) override;
    void SetLegendAttribute( ELegendAttribute, bool on = true ) override;
    void SetSamples( const QVector< QPointF > & ) override;
    void SetCurveAttribute( ECurveAttribute, bool on = true ) override;
    void SetPen( const QPen & ) override;
    void SetBrush( const QBrush & ) override;
    void SetBaseLine( double ) override;
    void SetStyle( ECurveStyle ) override;
    void SetSymbol( CSymbol ) override;
    void SetTitle( QString ) override;
    void Attach( IDiagram * ) override;
    ~CPlotCurve();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
