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

#include<cmath>

#include<QDebug>

class Vertex : public QGraphicsEllipseItem
{

public:

  Vertex( double x, double y, double r=20.0, QGraphicsItem * parent=0 )
    : QGraphicsEllipseItem( x-r/2, y-r/2, r, r, parent ), radius( r ),
      label(this), show_label( true )
  {

    setFlag( QGraphicsItem::ItemIsMovable, true );
    setFlag( QGraphicsItem::ItemIsSelectable, false );

    pen_color.setRgb( 88, 61, 164 );
    brush_color.setRgb( 154, 204, 50 );
    selected_brush_color.setRgb(204, 154, 50 );

    QPen pen(Qt::SolidLine);
    pen.setColor( Qt::black );
    pen.setWidth( 2 );

    setPen( pen );

    QBrush brush( brush_color );
    setBrush( brush );
    
    id = ++vx_number;
  }


  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
    
  }


  void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());

    QGraphicsEllipseItem::mouseReleaseEvent( mouseEvent );  

  }

  void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	     QWidget * widget ){

    Q_UNUSED( widget );

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);
    
    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
      gradient.setCenter(3, 3);
      gradient.setFocalPoint(3, 3);
      gradient.setColorAt(1, QColor(Qt::yellow).light(120));
      gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    }else if(option->state & QStyle::State_Selected) {
      gradient.setColorAt(0, Qt::red);
      gradient.setColorAt(1, Qt::darkRed);
    } else {
      gradient.setColorAt(0, Qt::yellow);
      gradient.setColorAt(1, Qt::darkYellow);
    }
    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
    

    // if (option->state & QStyle::State_Selected) {

    //   setBrush( selected_brush_color  );
    // } else {
    //   setBrush( brush_color  );
    // }


    
    // QGraphicsEllipseItem::paint( painter, option, widget );
    
    if( show_label ){
      painter->setPen(Qt::black);
      painter -> drawText(rect(), Qt::AlignCenter, QString::number( id ) );
    }


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
  QColor selected_brush_color;
  QGraphicsTextItem label;
  static int vx_number;
  int id;
  bool show_label;

};

int Vertex::vx_number = 0;

class QGraph : public QList<Vertex *>{

public:

  void add_vertex( Vertex * v ){

    if( v && ! contains( v ))
      append( v );

  }

  void erase_vertex( Vertex * v ){
    int index = indexOf( v );
    if( index > -1 ){
      removeAt( index );
    }
  }

  void circle_layout( double r= 100.0 ){

    int n=size();
    
    double PI=3.1415926535;
    
    for( int i=0; i<n; i++ ){
      double x= r*sin( (2*PI*i)/n);
      double y= -r*cos( (2*PI*i)/n);
      at(i)->setPos( x,y );
    }

  }

  void set_movable( bool b ){

    for (int i = 0; i < size(); ++i) {
      at(i)->setFlag( QGraphicsItem::ItemIsMovable, b);
      at(i)->setFlag( QGraphicsItem::ItemIsSelectable, !b );
    }
  }

};



class GraphCanvas : public QGraphicsRectItem
{

public:

  GraphCanvas( double x=-100, double y=-100, double w=200, double h=200 )
    : QGraphicsRectItem( x, y, w, h ), label( this ), move_mode( true )
  {
    setBrush( Qt::darkBlue );
    
    //setAcceptHoverEvents( true );

    label.setPlainText( "No mouse." );

    Vertex * vx = new Vertex( 0, 0, 20.0, this );

    g.add_vertex( vx );

  }
  
  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QPointF pos(mouseEvent->pos());
    
    if( mouseEvent->button()==Qt::LeftButton){

      if( move_mode ){
	Vertex * vx  = new Vertex( 0, 0, 20, this );
      
	vx->setPos( pos.x(), pos.y() );
	
	g.add_vertex( vx );
      }else{
	
	QGraphicsRectItem::mousePressEvent( mouseEvent );  

      }
    }else if( mouseEvent -> button() == Qt::RightButton ){
      QGraphicsRectItem::mousePressEvent( mouseEvent );  
      
    }
  }


 void contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
 {
     QMenu menu;
     QAction * circleLayout = menu.addAction( "Circle Layout" );
     QAction * moveMode = new QAction("Move", &menu);
     moveMode->setCheckable( true );
     moveMode->setChecked( move_mode );
     menu.addAction( moveMode );
       
     QAction *selectedAction = menu.exec(event->screenPos());

     if( selectedAction == circleLayout ){

       g.circle_layout();

     }else if( selectedAction == moveMode ){

       move_mode = !move_mode;
       g.set_movable( move_mode );
       
     }

 }

  void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
	     QWidget * widget ){
    QGraphicsRectItem::paint( painter, option, widget );
    
    // // QPen old_pen( pen() );
    
    // // QPen new_pen(Qt::SolidLine);
    // // QColor new_color(Qt::lightGray);
    // // new_color.setAlpha( 100 );
    // // new_pen.setColor( new_color );
    // // new_pen.setWidth( 2 );

    // // setPen( new_pen );
    
    // // QRectF r(rect());
    
    // // int x= (int)r.x();
    // // int y= (int)r.y();
    // // int height= (int)r.height();
    // // int width= (int)r.width();
      

    // // for( int h= 0; h < width; h+=20 )
    // //   painter->drawLine( x+h, y, x+h, y+height);

    // // for( int v= 0; v < height; v+=20 )
    // //   painter->drawLine( x, y+v, x+width, y+v);

    // // painter->drawRect(-5,-5,10,10);


    // // setPen( old_pen );

  }

private:

  QGraphicsTextItem label;
  QGraph g;
  bool move_mode;
  

};

class GraphScene : public  QGraphicsScene
{
  
public:

  GraphScene( QGraphicsView *parent )
    : QGraphicsScene( parent )
  {
    
    gc = new GraphCanvas(-200, -200, 500, 500 );

    gc->setPos( -100, -100 );

    addItem( gc );
    
  }

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {
    
    QGraphicsScene::mousePressEvent( mouseEvent );  

  }

  void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * mouseEvent )
  {

    QGraphicsScene::mouseDoubleClickEvent( mouseEvent );  
      
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
    setDragMode(QGraphicsView::RubberBandDrag );
  }

  void mousePressEvent ( QMouseEvent * event )
  {

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
 
  
  scene.addLine(-10,0,10,0);
  scene.addLine(0,10,0,-10);

  view.show();
  return app.exec();
}
