//     Copyright 2011 Fidel Barrera-Cruz

//     This file is part of graphbag.

//     Graphbag is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.

//     Graphbag is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.

//     You should have received a copy of the GNU General Public License
//     along with graphbag.  If not, see <http://www.gnu.org/licenses/>.

#include "edge.h"

#include<QGraphicsLineItem>
#include "vertex.h"
#include<QPen>

#include <QDebug>

Edge::Edge( Vertex * t, Vertex * h, QGraphicsItem * parent = 0 )
  : QGraphicsLineItem( parent )
{
  
  setZValue( 25.0 );
  
  head = h;
  tail = t;

  head-> add_edge( this );
  tail-> add_edge( this );
  
  QPen pen(Qt::SolidLine);
  pen.setColor( Qt::black );
  pen.setWidth( 2 );
    
  setPen( pen );
    
  setLine( QLineF( head->pos(), tail->pos() ) );

}

void Edge::adjust()
{
  if (!head || !tail)
    return;

  prepareGeometryChange();

  setLine( QLineF( head->pos(), tail->pos() ) );

  update();

}

