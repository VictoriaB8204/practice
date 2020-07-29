/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#include "PlotMarker.h"

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

CPlotMarker::CPlotMarker()
{
    m_marker = new QwtPlotMarker();
}

void CPlotMarker::SetXValue( double x )
{
    m_marker->setXValue( x );
}

void CPlotMarker::SetYValue( double y )
{
    m_marker->setYValue( y );
}

void CPlotMarker::SetValue( double x, double y )
{
    m_marker->setValue( x, y );
}

void CPlotMarker::SetValue( QPointF point )
{
    m_marker->setValue( point );
}

void CPlotMarker::SetLineStyle( ELineStyle style )
{
    m_marker->setLineStyle( QwtPlotMarker::LineStyle(style) );
}

void CPlotMarker::SetLinePen( QPen pen )
{
    m_marker->setLinePen( pen );
}

void CPlotMarker::SetSymbol( CSymbol symbol )
{
    m_marker->setSymbol( symbol.ToQwtSymbol() );
}

void CPlotMarker::SetLabel( QString string )
{
    m_marker->setLabel( string );
}

void CPlotMarker::SetLabelAlignment( Qt::Alignment alignment )
{
    m_marker->setLabelAlignment( alignment );
}

void CPlotMarker::SetLabelOrientation( Qt::Orientation orientation )
{
    m_marker->setLabelOrientation( orientation );
};

void CPlotMarker::SetSpacing( int spacing )
{
    m_marker->setSpacing( spacing );
}

void CPlotMarker::Attach( CPlot *plot )
{
    m_marker->attach( plot->ToQwtPlot() );
}

CPlotMarker::~CPlotMarker()
{
    delete [] m_marker;
}
