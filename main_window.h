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
  void circleLayoutClicked();

  private:

  GraphView * view;
  QMenu * fileMenu;
  QAction * openAct;
  QAction * saveAct;
  QAction * exitAct;
  QToolButton * addVtxBtn;
  QToolButton * addEdgBtn;
  QToolButton * movVtxBtn;
  QToolButton * selVtxBtn;
  QToolButton * cirLayBtn;
  QButtonGroup * modeGroup;
  QToolBar * graphToolBar;

};
