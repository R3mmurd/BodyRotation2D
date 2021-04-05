# ifndef BODY_H
# define BODY_H

# include <QPoint>
# include <QColor>
# include <QPainter>
# include <QList>

class Body
{
public:
  Body * parent;

  QList<Body> children_list;

  QPoint position;

  QColor color;

  double rot_angle;
  double rot_speed;

  double rot_angle_respect_parent;
  double rot_speed_respect_parent;

  double distance_with_parent;

  double scale;

  Body();

  void add_child(const Body &);

  void compute_new_angle(const unsigned long long &);

  void compute_new_angle_respect_parent(const unsigned long long &);

  void draw(QPainter &, const unsigned long long &);
};

#endif // BODY_H

