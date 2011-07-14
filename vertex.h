#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsEllipseItem>

class QGraphicsSceneMouseEvent;
class QPainter;



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

private:

  double radius;
  QColor pen_color;
  QColor brush_color;
  QColor selected_brush_color;
  QGraphicsTextItem label;
  static int vx_number;
  int id;
  bool show_label;

};

#endif
