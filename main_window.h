#include <QMainWindow>

#include <QMenu>
#include <QAction>

#include "graph_scene.h"
#include "graph_view.h"

class mainWindow : public QMainWindow 
{

 public:
  mainWindow(){

    view = new GraphView();
    
    scene= new GraphScene( view );
    
    view->setScene( scene );
    
    setCentralWidget( view );
    
    //view->show();

    resize(550,550);

    scene->addLine(-10,0,10,0);
    scene->addLine(0,10,0,-10);
    
    createActions();
    createMenus();


  }

  void createActions(){

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    
  }

  void createMenus(){

    fileMenu = menuBar()->addMenu("File");

    //fileMenu->addAction(newAct);
    //fileMenu->addAction(openAct);
    //fileMenu->addAction(saveAct);
    fileMenu->addAction( exitAct );
    
  }

  GraphView * view;
  GraphScene * scene;
  QMenu * fileMenu;
  QAction * exitAct;

};
