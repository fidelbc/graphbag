#include "main_window.h"

#include <QMainWindow>

#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QToolButton>


#include <QDebug>

#include "graph_view.h"

mainWindow::mainWindow(){

  view = new GraphView();
  view->setMode( GraphView::VTX_ADD );
    
  setCentralWidget( view );
    
  //view->show();

  resize(550,550);

  createActions();
  createMenus();
  createToolbars();

  setWindowTitle("gbag");

}

void mainWindow::createActions(){

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
     
  // addVtxAct= new QAction(QIcon(":/icons/add_vertex.png"), tr("Add Vertex"), this);
  // addEdgAct= new QAction(QIcon(":/icons/add_edge.png"), tr("Add Edge"), this );
  // movVtxAct= new QAction(QIcon(":/icons/move_vertex.png"), tr("Move Vertex"), this );

}

void mainWindow::createMenus(){

  fileMenu = menuBar()->addMenu(tr("&File"));

  //fileMenu->addAction(newAct);
  fileMenu->addAction(openAct);
  fileMenu->addAction(saveAct);
    
  fileMenu->addSeparator();
    
  fileMenu->addAction( exitAct );
    
}

void mainWindow::createToolbars(){

  graphToolBar = addToolBar( "Graph" );

  graphToolBar->addAction( openAct );
  graphToolBar->addAction( saveAct );

  graphToolBar->addSeparator();

  //Graph Tools
  addVtxBtn= new QToolButton;
  addVtxBtn->setCheckable( true );
  addVtxBtn->setChecked( true );
  addVtxBtn->setIcon( QIcon(":/icons/add_vertex.png") );
  addEdgBtn= new QToolButton;
  addEdgBtn->setCheckable( true );
  addEdgBtn->setIcon( QIcon(":/icons/add_edge.png") );
  movVtxBtn= new QToolButton;
  movVtxBtn->setCheckable( true );
  movVtxBtn->setIcon( QIcon(":/icons/move_vertex.png") );
  selVtxBtn= new QToolButton;
  selVtxBtn->setCheckable( true );
  selVtxBtn->setIcon( QIcon(":/icons/sel_vertex.png") );
  

  modeGroup= new QButtonGroup( this );
  modeGroup->addButton( addVtxBtn, int(GraphView::VTX_ADD) );
  modeGroup->addButton( addEdgBtn, int(GraphView::EDG_ADD) );
  modeGroup->addButton( movVtxBtn, int(GraphView::MOVE ) );
  modeGroup->addButton( selVtxBtn, int(GraphView::SELECT ) );
  connect( modeGroup, SIGNAL(buttonClicked(int)),
	   this, SLOT(modeGroupClicked(int)));

  graphToolBar->addWidget( addVtxBtn );
  graphToolBar->addWidget( addEdgBtn );
  graphToolBar->addWidget( movVtxBtn );
  graphToolBar->addWidget( selVtxBtn );

  graphToolBar->addSeparator();

  //Layout tools:
  cirLayBtn = new QToolButton;
  cirLayBtn->setIcon( QIcon(":/icons/circle_layout.png") );
  connect( cirLayBtn, SIGNAL(clicked()),
	   this, SLOT( circleLayoutClicked()));

  graphToolBar->addWidget( cirLayBtn );

}

void mainWindow::modeGroupClicked( int m )
{
  view->setMode(GraphView::Mode(m));
}

void mainWindow::circleLayoutClicked( )
{
  
  view->circleLayout();

}
