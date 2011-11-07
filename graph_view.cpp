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

#include "graph_view.h"

#include <QGraphicsView>

#include <QDebug>

GraphView::GraphView(): QGraphicsView()
{
  setRenderHint(QPainter::Antialiasing);
  setDragMode(QGraphicsView::RubberBandDrag );
}

void GraphView::mousePressEvent ( QMouseEvent * event )
{
  
  qDebug() << "MPE in gv: forwarding event.";

  QGraphicsView::mousePressEvent( event );  

  qDebug() << "MPE in gv: flow controll back!";

}

void GraphView::mouseReleaseEvent ( QMouseEvent * event )
{
  
  qDebug() << "MRE in gv: forwarding event.";

  QGraphicsView::mouseReleaseEvent( event );  

  qDebug() << "MRE in gv: flow controll back!";

}
