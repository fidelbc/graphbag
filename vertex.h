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

#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsEllipseItem>

class QGraphicsSceneMouseEvent;
class QPainter;
class Edge;

class Vertex : public QGraphicsEllipseItem
{

public:

  Vertex( double x, double y, double r, QGraphicsItem * parent );

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );


  void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	     QWidget * widget );

  enum { Type = UserType + 1 };

  int type() const;

  void add_edge( Edge * e );

  QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:

  double radius;
  QColor pen_color;
  QColor brush_color;
  QColor selected_brush_color;
  QGraphicsTextItem label;
  static int vx_number;
  int id;
  bool show_label;

  QList<Edge *> edges;

};

#endif
