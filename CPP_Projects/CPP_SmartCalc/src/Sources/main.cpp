#include <QApplication>

#include "../Headers/mainwindow.h"

int main(int argc, char *argv[]) {
  setlocale(LC_NUMERIC, "C");
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
