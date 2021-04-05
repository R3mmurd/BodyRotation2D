# include <canvas.H>

Canvas::Canvas(QWidget * parent)
  : QWidget(parent), running(false)
{
  Body body;

  body.position.setX(350);
  body.position.setY(350);
  body.scale = 2.0;
  body.rot_angle = 45;
  body.rot_speed = 10;

  body_list.push_back(body);

  Body & root = body_list.back();

  body.parent = &root;
  body.distance_with_parent = 80;
  body.scale = 0.25;
  body.color = QColor(255, 0, 0);
  body.rot_angle = 0;
  body.rot_angle_respect_parent = 0;
  body.rot_speed = 30;
  body.rot_speed_respect_parent = 40;

  root.add_child(body);

  Body & child_1 = root.children_list.back();

  body.parent = &child_1;
  body.distance_with_parent = 50;
  body.scale = 0.5;
  body.color = QColor(0, 0, 255);
  body.rot_angle = 0;
  body.rot_angle_respect_parent = 0;
  body.rot_speed = 50;
  body.rot_speed_respect_parent = 60;

  child_1.add_child(body);

  body.parent = &root;
  body.distance_with_parent = 130;
  body.scale = 0.5;
  body.color = QColor(0, 255, 0);
  body.rot_angle = 0;
  body.rot_angle_respect_parent = 0;
  body.rot_speed = 20;
  body.rot_speed_respect_parent = 15;

  root.add_child(body);

  Body & child_2 = root.children_list.back();

  body.parent = &child_2;
  body.distance_with_parent = 50;
  body.scale = 0.5;
  body.color = QColor(100, 255, 255);
  body.rot_angle = 0;
  body.rot_angle_respect_parent = 0;
  body.rot_speed = 35;
  body.rot_speed_respect_parent = 25;

  child_2.add_child(body);

  body.parent = &child_2;
  body.distance_with_parent = 30;
  body.scale = 0.25;
  body.color = QColor(255, 255, 100);
  body.rot_angle = 0;
  body.rot_angle_respect_parent = 90;
  body.rot_speed = 75;
  body.rot_speed_respect_parent = 65;

  child_2.add_child(body);

  resize(700, 700);

  connect(&timer, SIGNAL(timeout()), this, SLOT(update_time()));
  timer.setInterval(33);
}

void Canvas::update_time()
{
  repaint();
}

void Canvas::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), Qt::black);

  int dt = time.elapsed();

  for (Body & body : body_list)
    body.draw(painter, dt);

  time.start();
}

void Canvas::keyPressEvent(QKeyEvent *)
{
  if (running)
    {
      timer.stop();
      running = false;
    }
  else
    {
      running = true;
      timer.start();
      time.start();
    }
}

