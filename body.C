# include <body.H>

Body::Body()
  : parent(nullptr), position(0, 0), color(255, 255, 255), rot_angle(0.0),
    rot_speed(0.0), rot_angle_respect_parent(0.0),
    rot_speed_respect_parent(0.0), distance_with_parent(0.0),
    scale(1.0)
{
  // Empty
}

void Body::add_child(const Body & body)
{
  children_list.push_back(body);
}

void Body::compute_new_angle(const unsigned long long & dt)
{
  rot_angle += rot_speed * dt / 1000;

  if (rot_angle >= 360)
    rot_angle -= 360;
}

void Body::compute_new_angle_respect_parent(const unsigned long long & dt)
{
  rot_angle_respect_parent += rot_speed_respect_parent * dt / 1000;

  if (rot_angle_respect_parent >= 360)
    rot_angle_respect_parent -= 360;
}

void Body::draw(QPainter & painter, const unsigned long long & dt)
{
  painter.setBrush(color);

  compute_new_angle(dt);
  compute_new_angle_respect_parent(dt);

  QMatrix matrix_a = painter.matrix();

  QMatrix matrix = matrix_a;

  if (parent)
    {
      matrix.rotate(-rot_angle_respect_parent);
      matrix.translate(distance_with_parent, 0);
      matrix.rotate(rot_angle_respect_parent);
    }
  else
    matrix.translate(position.x(), position.y());

  matrix.scale(scale, scale);
  matrix.rotate(rot_angle);

  painter.setMatrix(matrix);

  painter.drawEllipse(QPoint(0, 0), 20, 20);
  painter.setPen(Qt::yellow);
  painter.drawLine(QPoint(0, 0), QPoint(30, 0));

  matrix.rotate(-rot_angle);
  painter.setMatrix(matrix);

  for (Body & child : children_list)
    child.draw(painter, dt);

  painter.setMatrix(matrix_a);
}

