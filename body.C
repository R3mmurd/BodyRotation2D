#include <body.H>

void Body::add_child(const Body & body) noexcept
{
  children_list.push_back(body);
}

void Body::update(float dt) noexcept
{
  rot_angle += rot_speed * dt;

  if (rot_angle >= 360)
    {
      rot_angle -= 360;
    }

  rot_angle_respect_parent += rot_speed_respect_parent * dt;

  if (rot_angle_respect_parent >= 360)
    {
      rot_angle_respect_parent -= 360;
    }

  for (Body& child : children_list)
    {
      child.update(dt);
    }
}

void Body::draw(QPainter& painter) const noexcept
{
  painter.setBrush(color);

  QTransform transform_a = painter.transform();

  QTransform transform = transform_a;

  if (parent != nullptr)
    {
      transform.rotate(-rot_angle_respect_parent);
      transform.translate(distance_with_parent, 0);
      transform.rotate(rot_angle_respect_parent);
    }
  else
    {
      transform.translate(position.x(), position.y());
    }

  transform.scale(scale, scale);
  transform.rotate(rot_angle);

  painter.setTransform(transform);

  painter.drawEllipse(QPoint(0, 0), 20, 20);
  painter.setPen(Qt::yellow);
  painter.drawLine(QPoint(0, 0), QPoint(30, 0));

  transform.rotate(-rot_angle);
  painter.setTransform(transform);

  for (const Body & child : children_list)
    {
      child.draw(painter);
    }

  painter.setTransform(transform_a);
}

