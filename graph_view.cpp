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

#include "graph_view.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenu>
#include <QContextMenuEvent>

//#include "graph_scene.h"
#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include "misc.h"
#include <cmath>

#include <QDebug>

GraphView::GraphView(): QGraphicsView()
{
  setRenderHint(QPainter::Antialiasing);
  setDragMode(QGraphicsView::RubberBandDrag );

  QGraphicsScene * gscene=new QGraphicsScene( this );
    
  setScene( gscene );
  
  gscene->addLine(-10,0,10,0);
  gscene->addLine(0,10,0,-10);

  init_graph();

}

void GraphView::init_graph()
{
  g=new Graph();
    
  int n=12;
  double r=150;

  QList<Vertex *> vxs;
  for( int i=0; i< n; i++ ){
    Vertex * v = new Vertex( 0.0, 0.0, 20.0 );
    vxs.append( v );
    (this->scene())->addItem( v );
  }

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

  qDebug() << "i_g";

}


void GraphView::mousePressEvent ( QMouseEvent * event )
{
  
  qDebug() << "MPE in gv: forwarding event.";

  QGraphicsView::mousePressEvent( event );  

  qDebug() << "MPE in gv: flow controll back!";

}

void GraphView::mouseReleaseEvent ( QMouseEvent * event )
{
  
  qDebug() << "MRE in gv: forwarding event.";

  QGraphicsView::mouseReleaseEvent( event );  

  qDebug() << "MRE in gv: flow controll back!";

}

void GraphView::contextMenuEvent(QContextMenuEvent *event)
{
  QMenu menu;
  QAction * circleLayout = menu.addAction( "Circle Layout" );
  QAction * moveMode = new QAction("Move", &menu);

  moveMode->setCheckable( true );
  moveMode->setChecked( move_mode );
  menu.addAction( moveMode );
       
  QAction *selectedAction = menu.exec(event->pos());

  if( selectedAction == circleLayout ){

    g->circle_layout();

  }else if( selectedAction == moveMode ){

    move_mode = !move_mode;
    g->set_movable( move_mode );
    g->set_selectable( !move_mode );
       
  }
}

void GraphView::setMode( Mode m ){

  current_mode = m;
  
  qDebug() << "Mode set to: " << m;

}

