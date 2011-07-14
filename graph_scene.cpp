#include "graph_scene.h"

#include<QGraphicsScene>
#include "graph_canvas.h"

GraphScene::GraphScene( QGraphicsView *parent )
  : QGraphicsScene( (QObject *) parent )
{
    
  gc = new GraphCanvas(-200, -200, 500, 500 );

  gc->setPos( -100, -100 );

  addItem( gc );
}

void GraphScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    
  QGraphicsScene::mousePressEvent( mouseEvent );  

}

void GraphScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent )
{

  QGraphicsScene::mouseDoubleClickEvent( mouseEvent );  
      
}

