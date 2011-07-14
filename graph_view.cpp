#include "graph_view.h"

#include <QGraphicsView>

GraphView::GraphView(): QGraphicsView()
{
  setRenderHint(QPainter::Antialiasing);
  setDragMode(QGraphicsView::RubberBandDrag );
}

void GraphView::mousePressEvent ( QMouseEvent * event )
{

  QGraphicsView::mousePressEvent( event );  

}
