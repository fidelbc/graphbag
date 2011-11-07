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

#include "graph_scene.h"

#include <QGraphicsScene>

#include <QDebug>

#include "graph.h"
//#include <QGraphicsRectItem>
#include "vertex.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QAction>

#include "misc.h"

#include <cmath>


//#include "graph_canvas.h"

GraphScene::GraphScene( QGraphicsView *parent )
  : QGraphicsScene( (QObject *) parent )
{
  init_graph();
  // gc = new GraphCanvas(-200, -200, 500, 500 );
  // gc->setPos( -100, -100 );
  // addItem( gc );
}

void GraphScene::init_graph()
{
  g=new Graph();
    
  int n=12;
  double r=150;

  QList<Vertex *> vxs;
  for( int i=0; i< n; i++ )
    vxs.append( new Vertex( 0.0, 0.0, 20.0  ) );

  double PI=3.1415926535;
  for( int i=0; i<n; i++ ){
    double x= r*sin( (2*PI*i)/n);
    double y= -r*cos( (2*PI*i)/n);
    vxs.at(i) -> setPos( x, y );
    g->add_vertex( vxs.at(i) );
  }

  for( int i=0; i<n; i++ ){
    g->add_edge( vxs.at(i), vxs.at(mod(i+1,n) ) );
    g->add_edge( vxs.at(i), vxs.at(mod(i-1,n) ) );
  }

}

void GraphScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
  qDebug() << "MPE in gs: forwarding event.";

  QPointF pos(mouseEvent->pos());
    
  if( mouseEvent->button()==Qt::LeftButton){

    if( !move_mode ){
      Vertex * vx  = new Vertex( 0.0, 0.0, 20.0 );
      
      vx->setPos( pos.x(), pos.y() );
	
      g->add_vertex( vx );
    }
  }else if( mouseEvent -> button() == Qt::RightButton ){
    QGraphicsScene::mousePressEvent( mouseEvent );        
  }

  qDebug() << "MPE in gs: flow controll back!";
}

void GraphScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
  qDebug() << "MRE in gs: forwarding event.";
  QGraphicsScene::mouseReleaseEvent( mouseEvent );  
  qDebug() << "MRE in gs: flow controll back!";

}

void GraphScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent )
{

  QGraphicsScene::mouseDoubleClickEvent( mouseEvent );  
      
}

void GraphScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
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
    g->set_selectable( !move_mode );
       
  }

}

void GraphScene::setMode( Mode m ){

  current_mode = m;
  
  qDebug() << "Mode set to: " << m;

}
