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

#ifndef GRAPH_CANVAS_H
#define GRAPH_CANVAS_H

#include <QGraphicsRectItem>

class Graph;
class QPainter;

class GraphCanvas : public QGraphicsRectItem
{

public:

  GraphCanvas( double x, double y, double w, double h );
  
  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

  void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	     QWidget * widget );

private:
  Graph * g;
  bool move_mode;  

};


#endif
