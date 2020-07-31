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
        NO_ATTRIBUTE, SHOW_LINE,
        SHOW_SYMBOL, SHOW_BRUSH
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

    virtual void SetPaintAttribute( EPaintAttribute attribute, bool on ) = 0;
    virtual void SetLegendAttribute( ELegendAttribute attribute, bool on ) = 0;
    virtual void SetSamples( const QVector< QPointF > &points ) = 0;
    virtual void SetCurveAttribute( ECurveAttribute attribute, bool on ) = 0;
    virtual void SetPen( const QPen &pen ) = 0;
    virtual void SetBrush( const QBrush &brush ) = 0;
    virtual void SetBaseLine( double baseLine ) = 0;
    virtual void SetStyle( ECurveStyle style ) = 0;
    virtual void SetSymbol( CSymbol symbol ) = 0;
    virtual void Attach( IDiagram *diagram ) = 0;
    virtual void SetTitle( QString title ) = 0;
    virtual ~ICurve(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
