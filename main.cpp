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

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>


#include<QDebug>

class Vertex : public QGraphicsEllipseItem
{

public:

  Vertex( double x, double y, double r=20.0, QGraphicsItem * parent=0 )
    : QGraphicsEllipseItem( x-r/2, y-r/2, r, r, parent ), radius( r )
  {

    //setPos( x, y );
    
    qDebug() << "Creating vertex at: (" << x << ", " << y << ")."<<endl;

    setFlag( QGraphicsItem::ItemIsMovable, true );

    //setFlag( QGraphicsItem::ItemIsSelectable, true );

    pen_color.setRgb( 88, 61, 164 );
    brush_color.setRgb( 154, 204, 50 );

    QPen pen(Qt::SolidLine);
    pen.setColor( Qt::black );
    pen.setWidth( 2 );

    setPen( pen );
    
    //QRadialGradient gradient(x, y, radius, x, y);
    //gradient.setColorAt(1, brush_color );
    //gradient.setColorAt(0, QColor::fromRgbF(0, 0, 0, 1));
    QBrush brush( Qt::darkGreen );
    setBrush( brush );

  }


  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
      
    qDebug() << "Press in Vertex.";
    qDebug() <<"\tpos: " << mouseEvent->pos();
    qDebug() <<"\tscene_pos: "<< mouseEvent->scenePos();
    qDebug() <<"\tItem currently at pos: " << this->pos();
    qDebug() <<"\tItem currently at scene_pos: "<< this->scenePos();

    qDebug();
    
    QGraphicsEllipseItem::mousePressEvent( mouseEvent );  

  }


  void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
      
    qDebug() << "Release in Vertex.";
    qDebug() <<"\tpos: " << mouseEvent->pos();
    qDebug() <<"\tscene_pos: "<< mouseEvent->scenePos();
    qDebug() <<"\tItem currently at pos: " << this->pos();
    qDebug() <<"\tItem currently at scene_pos: "<< this->scenePos();

    qDebug();
    
    QGraphicsEllipseItem::mouseReleaseEvent( mouseEvent );  

  }


  enum { Type = UserType + 1 };

  int type() const
  {
    return Type;
  }

private:

  double radius;
  QColor pen_color;
  QColor brush_color;


};

class GraphCanvas : public QGraphicsRectItem
{

public:

  GraphCanvas( double x=-100, double y=-100, double w=200, double h=200 )
    : QGraphicsRectItem( x, y, w, h ), label( this )
  {
    setBrush( QColor(173, 241, 174, 200) );
    
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, true );

    setAcceptHoverEvents( true );

    label.setPlainText( "No mouse." );

  }

  void hoverEnterEvent ( QGraphicsSceneHoverEvent * event ){

    QString temp;
    QTextStream text_stream(&temp);

    double x= event->pos().x();
    double y= event->pos().y();

    text_stream << "(" << x << "," << y << ")";
      
    label.setPlainText( temp );

  }

  void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event ){

    QString temp;
    QTextStream text_stream(&temp);

    double x= event->pos().x();
    double y= event->pos().y();

    text_stream << "(" << x << "," << y << ")";
      
    label.setPlainText( temp );

  }


  void hoverMoveEvent ( QGraphicsSceneHoverEvent * event ){

    QString temp;
    QTextStream text_stream(&temp);

    double x= event->pos().x();
    double y= event->pos().y();

    text_stream << "(" << x << "," << y << ")";
      
    label.setPlainText( temp );

  }


  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
      
    qDebug() << "Press in GraphCanvas.";
    qDebug() <<"\tpos: " << pos;
    qDebug() <<"\tscene_pos: "<< scene_pos;
    qDebug() <<"\tItem currently at pos: " << this->pos();
    qDebug() <<"\tItem currently at scene_pos: "<< scenePos();

    qDebug();
    
    ///if( itemAt( scene_pos ) ){
      
    //      QGraphicsScene::mousePressEvent( mouseEvent );  
      
      //}else{
      
    Vertex* vx = new Vertex( pos.x(), pos.y(), 20.0, this );
      
    //addItem( vx );
      //}


    QGraphicsRectItem::mousePressEvent( mouseEvent );  

  }

  QGraphicsTextItem label;


};

class GraphScene : public  QGraphicsScene
{
  
public:

  GraphScene( QGraphicsView *parent )
    : QGraphicsScene( parent )
  {
    
    gc = new GraphCanvas(-200, -200, 300, 300 );

    gc->setPos( -50, -50 );

    addItem( gc );
    
  }

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {
    
    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
    QPoint screen_pos( mouseEvent->screenPos());
      
    qDebug() << "Press in Scene.";
    qDebug() <<"\tpos: " << pos;
    qDebug() <<"\tscene_pos: "<< scene_pos;
    qDebug() <<"\tscreen_pos: "<< screen_pos;
    
    qDebug();

    if( itemAt( scene_pos ) ){
      
      QGraphicsScene::mousePressEvent( mouseEvent );  
      
    }


  }

  GraphCanvas * gc;

};

class GraphView :
  public QGraphicsView
{

public:
  GraphView(): QGraphicsView()
  {
    setRenderHint(QPainter::Antialiasing);
  }

  void mousePressEvent ( QMouseEvent * event )
  {


    QPoint pos(event->pos());

    qDebug() << "Press in View.";
    qDebug() << "\tpos: "<< pos;

    QGraphicsView::mousePressEvent( event );  

  }

};


int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

  GraphView view;

  GraphScene scene( &view );

  view.setScene( &scene );
 
  
  scene.addLine(-100,0,0,0);
  scene.addLine(0,0,100,0);

  scene.addLine(0,-100,0,0);
  scene.addLine(0,-100,0,100);
  


  view.show();
  return app.exec();
}
