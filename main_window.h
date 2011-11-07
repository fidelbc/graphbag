#include <QMainWindow>

#include <QMenu>
#include <QAction>

#include <QDebug>

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
    createToolbars();

    setWindowTitle("gbag");

  }

  void createActions(){

    exitAct = new QAction(tr("E&xit"), this);
    //exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    openAct = new QAction(QIcon(":/icons/document-open.png"), tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Open an existing file"));
    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    
    saveAct = new QAction(QIcon(":/icons/document-save.png"), tr("&Save"), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save the document to disk"));
    //connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
     
    addVtxAct= new QAction(QIcon(":/icons/add_vertex.png"), tr("Add Vertex"), this);
    addEdgAct= new QAction(QIcon(":/icons/add_edge.png"), tr("Add Edge"), this );
    movVtxAct= new QAction(QIcon(":/icons/move_vertex.png"), tr("Move Vertex"), this );

  }

  void createMenus(){

    fileMenu = menuBar()->addMenu(tr("&File"));

    //fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    
    fileMenu->addSeparator();
    
    fileMenu->addAction( exitAct );
    
  }

  void createToolbars(){

    graphToolBar = addToolBar( "Graph" );

    graphToolBar->addAction( openAct );
    graphToolBar->addAction( saveAct );

    graphToolBar->addSeparator();

    graphToolBar->addAction( addVtxAct);
    graphToolBar->addAction( addEdgAct);
    graphToolBar->addAction( movVtxAct);

  }

  GraphView * view;
  GraphScene * scene;
  QMenu * fileMenu;
  QAction * openAct;
  QAction * saveAct;
  QAction * exitAct;
  QAction * addVtxAct;
  QAction * addEdgAct;
  QAction * movVtxAct;
  QToolBar * graphToolBar;

};
