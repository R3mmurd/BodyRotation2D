# ifndef CANVAS_H
# define CANVAS_H

# include <QWidget>
# include <QTimer>
# include <QTime>

# include <body.H>

class Canvas : public QWidget
{
  Q_OBJECT

  QList<Body> body_list;

  QTime time;

  QTimer timer;

  bool running;

private slots:
  void update_time();

protected:
  void paintEvent(QPaintEvent *);

  void keyPressEvent(QKeyEvent *);

public:
  explicit Canvas(QWidget * parent = 0);
};

# endif // CANVAS_H
