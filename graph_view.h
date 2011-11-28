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

#ifndef GRAPH_VIEW_H
#define GRAPH_VIEW_H

#include <QGraphicsView>
#include <QStack>

class QMouseEvent;

class Graph;
class Vertex;

class GraphView :
  public QGraphicsView
{

 public:
  GraphView();

  void init_grid( int x=-200, int y=-200, int w=400, int h=400, int dx=10, int dy=10 );
  
  void init_graph();

  void mousePressEvent ( QMouseEvent * event );
  
  void mouseReleaseEvent ( QMouseEvent * event );
  
  //  void contextMenuEvent ( QContextMenuEvent * event );

  enum Mode { VTX_ADD, EDG_ADD, MOVE, SELECT };

  void setMode( Mode m );
  
  void circleLayout();

private:

  Graph * g;
  bool move_mode;  
  Mode current_mode;
  QStack<Vertex *> * selected_vxs;


};

#endif
