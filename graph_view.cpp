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


  QGraphicsScene * gscene=new QGraphicsScene( this );
    
  setScene( gscene );
  
  gscene->addLine(-10,0,10,0);
  gscene->addLine(0,10,0,-10);

  init_grid();

  init_graph();

  selected_vxs= new QStack<Vertex *>;

}

void GraphView::init_grid( int x, int y, int w, int h, int dx, int dy )
{
  QGraphicsScene * s=scene();

  for( int ix= x; ix<= x+w; ix+=dx )
    s->addLine( ix, y, ix, y+h, QPen(Qt::gray) );
  for( int iy= y; iy<= y+h; iy+=dy )
    s->addLine( x, iy, x+w, iy, QPen(Qt::gray) );
}

void GraphView::init_graph()
{
  g=new Graph();

  QGraphicsScene * s=scene();
    
  int n=12;
  double r=150;

  QList<Vertex *> vxs;
  for( int i=0; i< n; i++ ){
    Vertex * v = new Vertex( 0.0, 0.0, 20.0 );
    vxs.append( v );
    s->addItem( v );
  }

  double PI=3.1415926535;
  for( int i=0; i<n; i++ ){
    double x= r*sin( (2*PI*i)/n);
    double y= -r*cos( (2*PI*i)/n);
    vxs.at(i) -> setPos( x, y );
    g->add_vertex( vxs.at(i) );
  }

  for( int i=0; i<n; i++ ){
    Edge * e;
    e=g->add_edge( vxs.at(i), vxs.at(mod(i+1,n) ) );
    s->addItem( e );
    e=g->add_edge( vxs.at(i), vxs.at(mod(i-1,n) ) );
    s->addItem( e );
  }

}


void GraphView::mousePressEvent ( QMouseEvent * event )
{

  Vertex * vx;
  QGraphicsScene * s=scene();
  
  if( event -> button() == Qt::LeftButton ){
    switch( current_mode ){
    case VTX_ADD:
      vx = new Vertex( 0, 0, 20 );
      vx->setPos( mapToScene(event->pos()) );
      g->add_vertex( vx );
      s->addItem( vx );
      event->accept();
      break;
    case EDG_ADD:
      vx=qgraphicsitem_cast<Vertex *>( itemAt( event->pos() ));
      if( vx ){
	QGraphicsView::mousePressEvent( event );  
	if( selected_vxs->size() == 1 ){
	  Vertex * u = selected_vxs->pop();
	  if( u != vx ){
	     Edge * e=g->add_edge( vx, u );
	     s->addItem( e );
	  }
	  qDebug()<< "Vx selected: " << (vx->isSelected());
	  vx->setSelected( false );
	  qDebug()<< "Vx selected: " << (vx->isSelected());
	}else if( selected_vxs->size() == 0 ){
	  selected_vxs->push(vx);
	}else{
	  qDebug()<<"Did not expect this, clearin selection...";
	  selected_vxs->clear();
	}
	
      }
      //event->accept();
      break;
    case MOVE:
      QGraphicsView::mousePressEvent( event );  
      break;
    case SELECT:
      QGraphicsView::mousePressEvent( event );  
      break;
    default:
      qDebug() << "Nothing to do here!";
      ;
      
    }
  }



}

void GraphView::mouseReleaseEvent ( QMouseEvent * event )
{
  QGraphicsView::mouseReleaseEvent( event );  

  Vertex * vx;
  if( event -> button() == Qt::LeftButton ){
    switch( current_mode ){
    case VTX_ADD:
      break;
    case EDG_ADD:
      vx=qgraphicsitem_cast<Vertex *>( itemAt( event->pos() ));
      if( vx ){
	qDebug()<< "Vx selected: " << (vx->isSelected());
	if( selected_vxs->size() == 0 )
	  vx->setSelected(false );
	qDebug()<< "Vx selected: " << (vx->isSelected());
      }
      //event->accept();
      break;
    case MOVE:
      break;
    case SELECT:
      break;
    default:
      ;
      
    }
  }

  //  qDebug() << "MRE in gv: flow controll back!";

}

// void GraphView::contextMenuEvent(QContextMenuEvent *event)
// {
//   Q_UNUSED( event );

//   QMenu menu;
//   QAction * circleLayout = menu.addAction( "Circle Layout" );
//   QAction * moveMode = new QAction("Move", &menu);

//   moveMode->setCheckable( true );
//   moveMode->setChecked( move_mode );
//   menu.addAction( moveMode );
       
//   QAction *selectedAction = menu.exec( QCursor::pos() );

//   if( selectedAction == circleLayout ){

//     g->circle_layout();

//   }else if( selectedAction == moveMode ){
//     setMode( MOVE );       
//   }
// }

void GraphView::setMode( Mode m ){

  switch( m ){
  case VTX_ADD:
    g->set_movable(false);
    g->set_selectable(false);
    setDragMode(QGraphicsView::NoDrag);
    break;
  case EDG_ADD:
    g->set_movable(false);
    g->set_selectable(true);
    setDragMode(QGraphicsView::NoDrag);
    break;
  case MOVE:
    g->set_movable(true);
    g->set_selectable(false);
    setDragMode(QGraphicsView::NoDrag);
    break;
  case SELECT:
    g->set_movable(false);
    g->set_selectable(true);
    setDragMode(QGraphicsView::RubberBandDrag );
    break;
  default:
    ;
    
  }
  
  selected_vxs->clear();
  current_mode = m;
}

