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
