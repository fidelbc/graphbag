#include "graph.h"

#include<cmath>

#include "vertex.h"

void Graph::add_vertex( Vertex * v ){

  if( v && ! contains( v ))
    append( v );

}

void Graph::erase_vertex( Vertex * v ){
  int index = indexOf( v );
  if( index > -1 ){
    removeAt( index );
  }
}

void Graph::circle_layout( double r ){

  int n=size();
    
  double PI=3.1415926535;
  for( int i=0; i<n; i++ ){
    double x= r*sin( (2*PI*i)/n);
    double y= -r*cos( (2*PI*i)/n);
    at(i)->setPos( x,y );
  }

}

void Graph::set_movable( bool b ){

  for (int i = 0; i < size(); ++i) {
    at(i)->setFlag( QGraphicsItem::ItemIsMovable, b);
    at(i)->setFlag( QGraphicsItem::ItemIsSelectable, !b );
  }
}
