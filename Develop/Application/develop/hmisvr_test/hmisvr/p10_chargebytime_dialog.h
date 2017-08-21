#ifndef P10_CHARGEBYTIME_DIALOG_H
#define P10_CHARGEBYTIME_DIALOG_H

#include <QDialog>

namespace Ui {
class p10_chargebytime_dialog;
}

class p10_chargebytime_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p10_chargebytime_dialog(QWidget *parent = 0);
    ~p10_chargebytime_dialog();

private:
    Ui::p10_chargebytime_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

    void number_ptbn_press();

signals:
    void signal_exit_p10dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

    void on_pbtn_return_clicked();
    void on_pbtn_sure_clicked();
    void on_pbtn_othersmin_clicked();
    void on_pbtn_120min_clicked();
    void on_pbtn_60min_clicked();
    void on_pbtn_30min_clicked();

    void on_pbtn_delete_clicked();
    //void on_pbtn_dec_point_clicked();
    void on_pbtn_dot_clicked();

    void on_pbtn_num9_clicked();
    void on_pbtn_num8_clicked();
    void on_pbtn_num7_clicked();
    void on_pbtn_num6_clicked();
    void on_pbtn_num5_clicked();
    void on_pbtn_num4_clicked();
    void on_pbtn_num3_clicked();
    void on_pbtn_num2_clicked();
    void on_pbtn_num1_clicked();
    void on_pbtn_num0_clicked();
};

#endif // P10_CHARGEBYTIME_DIALOG_H
