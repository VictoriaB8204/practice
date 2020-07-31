/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Symbol.h"
#include "Diagram.h"

#ifdef __cplusplus
extern "C"{
#endif

class ICurve
{
public:
    enum ECurveAttribute { INVERTED, FITTED  };

    enum ELegendAttribute
    {
        NO_ATTRIBUTE, SHOW_LINE, SHOW_SYMBOL, SHOW_BRUSH
    };

    enum EPaintAttribute
    {
        CLIP_POLYGONS, FILTER_POINTS,
        MINIMIZE_MEMORY, IMAGE_BUFFER
    };
    enum ECurveStyle {
        NO_CURVE = -1, LINES, STICKS, STEPS,
        DOTS, USER_CURVE = 100
    };

    virtual void SetPaintAttribute( EPaintAttribute, bool ) = 0;
    virtual void SetLegendAttribute( ELegendAttribute, bool ) = 0;
    virtual void SetSamples( const QVector< QPointF > & ) = 0;
    virtual void SetCurveAttribute( ECurveAttribute, bool ) = 0;
    virtual void SetPen( const QPen & ) = 0;
    virtual void SetBrush( const QBrush & ) = 0;
    virtual void SetBaseLine( double ) = 0;
    virtual void SetStyle( ECurveStyle ) = 0;
    virtual void SetSymbol( CSymbol ) = 0;
    virtual void Attach( IDiagram * ) = 0;
    virtual void SetTitle( QString ) = 0;
    virtual ~ICurve(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
