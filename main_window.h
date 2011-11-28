#include <QMainWindow>

class QToolButton;
class QButtonGroup;

class GraphView;

class mainWindow : public QMainWindow 
{
  Q_OBJECT;
 public:
  mainWindow();
  
  void createActions();
  
  void createMenus();
  
  void createToolbars();
  
  public slots:
  ;
  void modeGroupClicked( int m );

  private:

  GraphView * view;
  QMenu * fileMenu;
  QAction * openAct;
  QAction * saveAct;
  QAction * exitAct;
  QToolButton * addVtxBut;
  QToolButton * addEdgBut;
  QToolButton * movVtxBut;
  QToolButton * selVtxBut;
  QButtonGroup * modeGroup;
  QToolBar * graphToolBar;

};
