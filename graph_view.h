#ifndef GRAPH_VIEW_H
#define GRAPH_VIEW_H

#include <QGraphicsView>

class QMouseEvent;

class GraphView :
  public QGraphicsView
{

public:
  GraphView();

  void mousePressEvent ( QMouseEvent * event );

};

#endif
