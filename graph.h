#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
class Vertex;

class Graph : public QList<Vertex *>{
public:

  void add_vertex( Vertex * v );

  void erase_vertex( Vertex * v );

  void circle_layout( double r= 100.0 );

  void set_movable( bool b );
};

#endif
