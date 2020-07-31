/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Marker.h"
#include <qwt_plot_marker.h>

#ifdef __cplusplus
extern "C"{
#endif

class CPlotMarker : public IMarker
{
    QwtPlotMarker *m_marker;
public:
    CPlotMarker();
    void SetXValue( double ) override;
    void SetYValue( double ) override;
    void SetValue( double, double ) override;
    void SetValue( QPointF ) override;
    void SetLineStyle( ELineStyle ) override;
    void SetLinePen( QPen ) override;
    void SetSymbol( CSymbol ) override;
    void SetLabel( QString ) override;
    void SetLabelAlignment( Qt::Alignment ) override;
    void SetLabelOrientation( Qt::Orientation ) override;
    void SetSpacing( int ) override;
    void SetTitle( QString ) override;
    void Attach( IDiagram * ) override;
    ~CPlotMarker();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
