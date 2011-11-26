#ifndef GRAPH_SCENE_H
#define GRAPH_SCENE_H

class Graph;
class QPainter;
#include <QGraphicsScene>

class GraphScene : public  QGraphicsScene
{
public:
  GraphScene( QGraphicsView *parent );

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif
