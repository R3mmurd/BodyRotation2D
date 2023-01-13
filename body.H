#ifndef BODY_H
#define BODY_H

#include <QPoint>
#include <QColor>
#include <QPainter>
#include <QList>

class Body
{
public:
  Body* parent{nullptr};

  QList<Body> children_list;

  QPointF position{0.f, 0.f};

  QColor color{0, 0, 0};

  float rot_angle{0.f};
  float rot_speed{0.f};

  float rot_angle_respect_parent{0.f};
  float rot_speed_respect_parent{0.f};

  float distance_with_parent{0.f};

  float scale{1.f};

  Body() = default;

  void add_child(const Body& body) noexcept;

  void update(float dt) noexcept;

  void draw(QPainter& paiter) const noexcept;
};

#endif // BODY_H

