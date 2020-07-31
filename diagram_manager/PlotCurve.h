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
    void SetPaintAttribute( EPaintAttribute attribute, bool on = true ) override;
    void SetLegendAttribute( ELegendAttribute attribute, bool on = true ) override;
    void SetSamples( const QVector< QPointF > &point ) override;
    void SetCurveAttribute( ECurveAttribute attribute, bool on = true ) override;
    void SetPen( const QPen &pen ) override;
    void SetBrush( const QBrush &brush ) override;
    void SetBaseLine( double baseLine ) override;
    void SetStyle( ECurveStyle style ) override;
    void SetSymbol( CSymbol symbol ) override;
    void SetTitle( QString title ) override;
    void Attach( IDiagram *diagram ) override;
    ~CPlotCurve();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
