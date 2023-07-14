#ifndef S21_CALC_V2_SRC_HEADERS_CREDIT_H
#define S21_CALC_V2_SRC_HEADERS_CREDIT_H

#include <QDialog>

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

private slots:
  void on_count_button_clicked();

private:
  Ui::Credit *ui;
  void Annuity();
  void Differentiated();
};

#endif // S21_CALC_V2_SRC_HEADERS_CREDIT_H
