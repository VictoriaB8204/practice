/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Diagram.h"
#include "Symbol.h"

#ifdef __cplusplus
extern "C"{
#endif

class IMarker
{
public:
    enum ELineStyle { NO_LINE, H_LINE, V_LINE, CROSS };

    virtual void SetXValue( double ) = 0;
    virtual void SetYValue( double ) = 0;
    virtual void SetValue( double, double ) = 0;
    virtual void SetValue( QPointF ) = 0;
    virtual void SetLineStyle( ELineStyle ) = 0;
    virtual void SetLinePen( QPen ) = 0;
    virtual void SetSymbol( CSymbol ) = 0;
    virtual void SetLabel( QString ) = 0;
    virtual void SetLabelAlignment( Qt::Alignment ) = 0;
    virtual void SetLabelOrientation( Qt::Orientation ) = 0;
    virtual void SetSpacing( int );
    virtual void Attach( IDiagram * ) = 0;
    virtual void SetTitle( QString ) = 0;
    virtual ~IMarker(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
