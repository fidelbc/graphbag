#include "graph_canvas.h"


#include "graph.h"
#include <QGraphicsRectItem>
#include "vertex.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QAction>

GraphCanvas::GraphCanvas( double x=-100, double y=-100, double w=200, double h=200 )
  : QGraphicsRectItem( x, y, w, h ), move_mode( false )
{
  setBrush( QBrush(QColor(0, 0, 255, 127)) );
    
  Vertex * vx = new Vertex( 0.0, 0.0, 20.0, this );

  g=new Graph();

  g->add_vertex( vx );

}
  
void GraphCanvas::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{

  QPointF pos(mouseEvent->pos());
    
  if( mouseEvent->button()==Qt::LeftButton){

    if( !move_mode ){
      Vertex * vx  = new Vertex( 0, 0, 20, this );
      
      vx->setPos( pos.x(), pos.y() );
	
      g->add_vertex( vx );
    }
  }else if( mouseEvent -> button() == Qt::RightButton ){
    QGraphicsRectItem::mousePressEvent( mouseEvent );  
      
  }


}


void GraphCanvas::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;
  QAction * circleLayout = menu.addAction( "Circle Layout" );
  QAction * moveMode = new QAction("Move", &menu);
  moveMode->setCheckable( true );
  moveMode->setChecked( move_mode );
  menu.addAction( moveMode );
       
  QAction *selectedAction = menu.exec(event->screenPos());

  if( selectedAction == circleLayout ){

    g->circle_layout();

  }else if( selectedAction == moveMode ){

    move_mode = !move_mode;
    g->set_movable( move_mode );
       
  }

}

void GraphCanvas::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	   QWidget * widget ){
  QGraphicsRectItem::paint( painter, option, widget );
    
  // // QPen old_pen( pen() );
    
  // // QPen new_pen(Qt::SolidLine);
  // // QColor new_color(Qt::lightGray);
  // // new_color.setAlpha( 100 );
  // // new_pen.setColor( new_color );
  // // new_pen.setWidth( 2 );

  // // setPen( new_pen );
    
  // // QRectF r(rect());
    
  // // int x= (int)r.x();
  // // int y= (int)r.y();
  // // int height= (int)r.height();
  // // int width= (int)r.width();
      

  // // for( int h= 0; h < width; h+=20 )
  // //   painter->drawLine( x+h, y, x+h, y+height);

  // // for( int v= 0; v < height; v+=20 )
  // //   painter->drawLine( x, y+v, x+width, y+v);

  // // painter->drawRect(-5,-5,10,10);


  // // setPen( old_pen );

}
