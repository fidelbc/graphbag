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

#include "graph_scene.h"

#include <QGraphicsScene>

#include <QDebug>

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
  qDebug() << "MPE in gs: forwarding event.";
  QGraphicsScene::mousePressEvent( mouseEvent );  
  qDebug() << "MPE in gs: flow controll back!";
}

void GraphScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
  qDebug() << "MRE in gs: forwarding event.";
  QGraphicsScene::mouseReleaseEvent( mouseEvent );  
  qDebug() << "MRE in gs: flow controll back!";

}

void GraphScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent )
{

  QGraphicsScene::mouseDoubleClickEvent( mouseEvent );  
      
}

