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

#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsLineItem>

class Vertex;

class Edge: public QGraphicsLineItem{

 public:
  Edge( Vertex * h, Vertex * t, QGraphicsItem * parent=0 );

  void adjust();

  enum { Type = UserType + 2 };

  int type() const;

 private:

  Vertex * head;
  Vertex * tail;
};

#endif
