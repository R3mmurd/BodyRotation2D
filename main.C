#include <QApplication>
#include <canvas.H>

int main(int argc, char * argv[])
{
  QApplication app(argc, argv);
  Canvas canvas;
  canvas.show();
  return app.exec();
}
