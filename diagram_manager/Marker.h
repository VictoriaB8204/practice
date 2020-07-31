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
    enum ELineStyle
    {
        NO_LINE, H_LINE,
        V_LINE, CROSS
    };

    virtual void SetXValue( double xValue ) = 0;
    virtual void SetYValue( double yValue ) = 0;
    virtual void SetValue( double x, double y ) = 0;
    virtual void SetValue( QPointF point ) = 0;
    virtual void SetLineStyle( ELineStyle style ) = 0;
    virtual void SetLinePen( QPen pen ) = 0;
    virtual void SetSymbol( CSymbol symbol ) = 0;
    virtual void SetLabel( QString string ) = 0;
    virtual void SetLabelAlignment( Qt::Alignment alignment ) = 0;
    virtual void SetLabelOrientation( Qt::Orientation orientation ) = 0;
    virtual void SetSpacing( int spacing );
    virtual void Attach( IDiagram *diagram ) = 0;
    virtual void SetTitle( QString title ) = 0;
    virtual ~IMarker(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
