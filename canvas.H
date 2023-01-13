#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QElapsedTimer>
#include <QTimer>

#include <body.H>

class Canvas : public QWidget
{
  Q_OBJECT

  QList<Body> body_list;

  QElapsedTimer elapsed_timer;
  QTimer timer;

  bool running;

private slots:
  void step();

protected:
  void update(float dt);

  void draw(QPainter& painter);

  void paintEvent(QPaintEvent *);

  void keyPressEvent(QKeyEvent *);

public:
  explicit Canvas(QWidget * parent = 0);
};

#endif // CANVAS_H
