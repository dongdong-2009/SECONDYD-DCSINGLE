#ifndef P08_CARPASSWD_DIALOG_H
#define P08_CARPASSWD_DIALOG_H

#include <QDialog>

namespace Ui {
class p08_carpasswd_dialog;
}

class p08_carpasswd_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p08_carpasswd_dialog(QWidget *parent = 0);
    ~p08_carpasswd_dialog();

private:
    Ui::p08_carpasswd_dialog *ui;

private:
    QTimer *timer;

private:
    unsigned char card_passwd_write;
    char card_passwd[17];
    char card_passwd_display[17];

private:
    void update_page_info(void);
    void update_hmi_page_index(void);
    int  judge_passwd_NULL();
    void number_press();

signals:
    void signal_exit_p08dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_pbtn_return_clicked();
    void on_pbtn_sure_clicked();
    void on_pbtn_delete_clicked();

    void on_pbtn_num0_clicked();

    void on_pbtn_num1_clicked();
    void on_pbtn_num2_clicked();
    void on_pbtn_num3_clicked();
    void on_pbtn_num4_clicked();
    void on_pbtn_num5_clicked();

    void on_pbtn_num6_clicked();
    void on_pbtn_num7_clicked();
    void on_pbtn_num8_clicked();
    void on_pbtn_num9_clicked();

    void on_pbtn_dot_clicked();

};

#endif // P08_CARPASSWD_DIALOG_H
