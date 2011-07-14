///////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify	 //
// it under the terms of the GNU General Public License as published by	 //
// the Free Software Foundation, either version 3 of the License, or	 //
// (at your option) any later version.					 //
//   									 //
// This program is distributed in the hope that it will be useful,	 //
// but WITHOUT ANY WARRANTY; without even the implied warranty of	 //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	 //
// GNU General Public License for more details.				 //
// 									 //
// You should have received a copy of the GNU General Public License	 //
// along with this program.  If not, see <http://www.gnu.org/licenses/>. //
///////////////////////////////////////////////////////////////////////////
 
#include <QtGui>

#include "graph_view.h"
#include "graph_scene.h"



int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

  GraphView view;

  GraphScene scene( &view );

  view.setScene( &scene );
 
  
  scene.addLine(-10,0,10,0);
  scene.addLine(0,10,0,-10);

  view.show();
  return app.exec();
}
