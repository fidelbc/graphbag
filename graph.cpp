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

#include "graph.h"

#include<cmath>

#include "vertex.h"
#include "edge.h"

void Graph::add_vertex( Vertex * v ){

  if( v && ! contains( v ))
    append( v );

}

void Graph::add_edge( Vertex * u, Vertex * v ){
  
  if( u && v && (u != v))
    new  Edge( u, v, v->parentItem() );
  
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
  for (int i = 0; i < size(); ++i)
    at(i)->setFlag( QGraphicsItem::ItemIsMovable, b);
}


void Graph::set_selectable( bool b ){
  for (int i = 0; i < size(); ++i) 
    at(i)->setFlag( QGraphicsItem::ItemIsSelectable, b);
}
