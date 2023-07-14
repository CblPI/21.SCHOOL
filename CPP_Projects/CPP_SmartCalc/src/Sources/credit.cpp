#include "../Headers/credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

void Credit::Annuity() {
  QString monthPay, total, overPayment;
  double per, payTime, creditRate, creditSize, o_v, K, i, A;
  int dateType = ui->combo_box_time->currentIndex();
  payTime = (ui->spin_box_time->value());
  if (dateType == 1) {
    payTime = payTime * 12;
  }
  creditRate = (ui->spin_box_prc->value());
  i = creditRate / 12 / 100;
  creditSize = (ui->sum_button->value());
  if ((creditSize) && (payTime) && (creditRate)) {
    K = i * (pow((1 + i), payTime)) / (pow((1 + i), payTime) - 1);
    A = K * creditSize;
    o_v = A * payTime;
    per = o_v - creditSize;
    monthPay = QString::number(A, 'f', 2);
    total = QString::number(o_v, 'f', 2);
    overPayment = QString::number(per, 'f', 2);
    ui->line_edit_per_mon->setText(monthPay);
    ui->line_edit_total->setText(total);
    ui->line_edit_over->setText(overPayment);
  }
}

void Credit::Differentiated() {
  QString monthPay, total, overPayment;
  double payTime, creditRate, creditSize, o_v, b, Sn_0, p, plat_0;
  payTime = (ui->spin_box_time->value());
  int dateType = ui->combo_box_time->currentIndex();
  if (dateType == 1) {
    payTime = payTime * 12;
  }
  creditRate = (ui->spin_box_prc->value());
  creditSize = (ui->sum_button->value());
  if ((creditSize != 0) && (payTime != 0) && (creditRate != 0)) {
    b = creditSize / payTime;
    Sn_0 = creditSize - (b * 0);
    p = Sn_0 * (creditRate / 100) / 12;
    plat_0 = b + p;
    monthPay = QString::number(plat_0, 'f', 2);
    if (payTime > 1) {
      double Sn_1 = creditSize - (b * (payTime - 1));
      double p_1 = Sn_1 * (creditRate / 100) / 12;
      double plat_1 = b + p_1;
      QString monthPay_1 = QString::number(plat_1, 'f', 2);
      monthPay += " ... " + monthPay_1;
    }
    ui->line_edit_per_mon->setText(monthPay);
    double plat_x = 0;
    for (int j = 0; j < payTime; j++) {
      double Sn_x = creditSize - (b * (j));
      double p_x = Sn_x * (creditRate / 100) / 12;
      plat_x = plat_x + b + p_x;
    }
    o_v = plat_x;
    total = QString::number(o_v, 'f', 2);
    ui->line_edit_total->setText(total);
    double per = o_v - creditSize;
    overPayment = QString::number(per, 'f', 2);
    ui->line_edit_over->setText(overPayment);
  }
}

void Credit::on_count_button_clicked() {
  if ((ui->radio_button_ann->isChecked())) {
    Annuity();
  }
  if ((ui->radio_button_diff->isChecked())) {
    Differentiated();
  }
}
