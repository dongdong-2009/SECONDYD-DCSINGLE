#ifndef P28_CHARGEBYMONEY_DIALOG_H
#define P28_CHARGEBYMONEY_DIALOG_H

#include <QDialog>

namespace Ui {
class p28_chargebymoney_dialog;
}

class p28_chargebymoney_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p28_chargebymoney_dialog(QWidget *parent = 0);
    ~p28_chargebymoney_dialog();

private:
    Ui::p28_chargebymoney_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

    void number_ptbn_press();

signals:
    void signal_exit_p28dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_pbtn_return_clicked();
    void on_pbtn_sure_clicked();

    void on_pbtn_othersYUAN_clicked();
    void on_pbtn_15YUAN_clicked();
    void on_pbtn_10YUAN_clicked();
    void on_pbtn_5YUAN_clicked();

    //void on_pbtn_delete_clicked();
    //void on_pbtn_dec_point_clicked();
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

    void on_pbtn_dot_clicked();
    void on_pbtn_delete_clicked();
};

#endif // P28_CHARGEBYMONEY_DIALOG_H
