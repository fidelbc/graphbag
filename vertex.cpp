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

#include "vertex.h"

#include<QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

#include "edge.h"

#include <QDebug>

Vertex::Vertex( double x, double y, double r=20.0, QGraphicsItem * parent=0 )
  : QGraphicsEllipseItem( x-r/2, y-r/2, r, r, parent ), radius( r ),
    label(this), show_label( true )
{

  setZValue( 50.0 );
  setFlag(ItemSendsGeometryChanges);
  setFlag( QGraphicsItem::ItemIsMovable, false );
  setFlag( QGraphicsItem::ItemIsSelectable, true );
 
  pen_color.setRgb( 88, 61, 164 );
  brush_color.setRgb( 154, 204, 50 );
  selected_brush_color.setRgb(204, 154, 50 );

  QPen pen(Qt::SolidLine);
  pen.setColor( Qt::black );
  pen.setWidth( 2 );

  setPen( pen );

  QBrush brush( brush_color );
  setBrush( brush );
    
  id = ++vx_number;
}


void Vertex::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{

  QPointF pos(mouseEvent->pos());
  QPointF scene_pos( mouseEvent->scenePos());


  QGraphicsEllipseItem::mousePressEvent( mouseEvent );  
}


void Vertex::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{

  QPointF pos(mouseEvent->pos());
  QPointF scene_pos( mouseEvent->scenePos());

  QGraphicsEllipseItem::mouseReleaseEvent( mouseEvent );  
    
  update();

}

void Vertex::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	   QWidget * widget ){

  Q_UNUSED( widget );

  painter->setPen(Qt::NoPen);
  painter->setBrush(Qt::darkGray);
  painter->drawEllipse(-7, -7, 20, 20);
    
  QRadialGradient gradient(-3, -3, 10);
  if (option->state & QStyle::State_Sunken) {
    gradient.setCenter(3, 3);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(Qt::yellow).light(120));
    gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
  }else if(option->state & QStyle::State_Selected) {
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::darkRed);
  }else{
    gradient.setColorAt(0, Qt::yellow);
    gradient.setColorAt(1, Qt::darkYellow);
  }
  painter->setBrush(gradient);
  painter->setPen(QPen(Qt::black, 0));
  painter->drawEllipse(-10, -10, 20, 20);
    

  // if (option->state & QStyle::State_Selected) {

  //   setBrush( selected_brush_color  );
  // } else {
  //   setBrush( brush_color  );
  // }


    
  // QGraphicsEllipseItem::paint( painter, option, widget );
    
  if( show_label ){
    painter->setPen(Qt::black);
    painter -> drawText(rect(), Qt::AlignCenter, QString::number( id ) );
  }


}

void Vertex::add_edge( Edge * e ){

  edges.append( e );

}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{



  switch (change) {
  case ItemPositionHasChanged:
    foreach (Edge * e, edges)
      e->adjust();

    break;
  default:
    break;
  };
  
  return QGraphicsItem::itemChange(change, value);
}


int Vertex::type() const
{
  return Type;
}

int Vertex::vx_number = 0;
