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

#include <QtGui>

#include "main_window.h"




int main(int argc, char **argv)
{
  
  Q_INIT_RESOURCE(graphbag);

  QApplication app(argc, argv);
  //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  mainWindow m;

  m.show();

  return app.exec();
}
