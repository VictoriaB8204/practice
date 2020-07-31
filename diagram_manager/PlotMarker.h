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
    void SetXValue( double xValue ) override;
    void SetYValue( double yValue ) override;
    void SetValue( double x, double y ) override;
    void SetValue( QPointF point ) override;
    void SetLineStyle( ELineStyle style ) override;
    void SetLinePen( QPen pen ) override;
    void SetSymbol( CSymbol symbol ) override;
    void SetLabel( QString string ) override;
    void SetLabelAlignment( Qt::Alignment alignment ) override;
    void SetLabelOrientation( Qt::Orientation orientation ) override;
    void SetSpacing( int spacimg ) override;
    void SetTitle( QString title ) override;
    void Attach( IDiagram *diagram ) override;
    ~CPlotMarker();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
