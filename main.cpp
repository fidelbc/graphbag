#include <QtGui>

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>

#include<iostream>

using namespace std;

void print_pointf( QPointF * p ){

  cout <<"(" << p->x() << ", " << p->y() << ")";

}

void print_point( QPoint * p ){

  cout <<"(" << p->x() << ", " << p->y() << ")";

}

class GraphScene : public  QGraphicsScene
{
  
public:

  GraphScene( QGraphicsView *parent )
    : QGraphicsScene( parent )
  {}

  void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )
  {
    
    QPointF pos(mouseEvent->pos());
    QPointF scene_pos( mouseEvent->scenePos());
    QPoint screen_pos( mouseEvent->screenPos());
      
    cout << "Press in Scene."<< endl;
    cout <<"\tpos: ";print_pointf( &pos );cout<<endl;
    cout <<"\tscene_pos: ";print_pointf( &scene_pos );cout<<endl;
    cout <<"\tscreen_pos: ";print_point( &screen_pos );cout<<endl;

    QGraphicsScene::mousePressEvent( mouseEvent );  

    double r=10;

    QGraphicsEllipseItem * vx = new QGraphicsEllipseItem( scene_pos.x()-r/2, scene_pos.y()-r/2, r, r );

    vx-> setFlag( QGraphicsItem::ItemIsMovable, true );

    addItem( vx );

  }

};

class GraphView :
  public QGraphicsView
{

public:
  

  void mousePressEvent ( QMouseEvent * event )
  {


    QPoint pos(event->pos());

    cout << "Press in View." << endl;
    cout << "\tpos:"; print_point( &pos );  cout<<endl;

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

  //int n =10;
  QGraphicsEllipseItem * vx = new QGraphicsEllipseItem( 10.0, 10.0, 10.0, 10.0 );

  scene.addItem( vx );
  
  scene.addLine(-100,0,0,0);
  scene.addLine(0,0,100,0);

  scene.addLine(0,-100,0,0);
  scene.addLine(0,-100,0,100);
  


  view.show();
  return app.exec();
}
