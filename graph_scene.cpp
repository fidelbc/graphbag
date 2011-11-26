#include "graph_scene.h"

#include <QGraphicsScene>

#include "graph.h"
#include "vertex.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>


GraphScene::GraphScene( QGraphicsView *parent )
  : QGraphicsScene( (QObject *) parent )
{
}

void GraphScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
  QGraphicsScene::mousePressEvent( mouseEvent );        
}

void GraphScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
  QGraphicsScene::mouseReleaseEvent( mouseEvent );  
}

void GraphScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent )
{
  QGraphicsScene::mouseDoubleClickEvent( mouseEvent );  
}
