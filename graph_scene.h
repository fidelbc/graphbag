#ifndef GRAPH_SCENE_H
#define GRAPH_SCENE_H


class GraphCanvas;
#include <QGraphicsScene>

class GraphScene : public  QGraphicsScene
{
  
public:

  GraphScene( QGraphicsView *parent );

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent );

  GraphCanvas * gc;

};

#endif
