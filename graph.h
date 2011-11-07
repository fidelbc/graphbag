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

#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
class Vertex;
class Edge;

class Graph : public QList<Vertex *>{
public:

  void add_vertex( Vertex * v );

  void add_edge( Vertex * u, Vertex * v );

  void erase_vertex( Vertex * v );

  void circle_layout( double r= 100.0 );

  void set_movable( bool b );

  void set_selectable( bool b );
};

#endif
