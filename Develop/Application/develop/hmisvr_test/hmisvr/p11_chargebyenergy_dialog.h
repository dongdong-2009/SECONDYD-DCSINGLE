#ifndef P11_CHARGEBYENERGY_DIALOG_H
#define P11_CHARGEBYENERGY_DIALOG_H

#include <QDialog>

namespace Ui {
class p11_chargebyenergy_dialog;
}

class p11_chargebyenergy_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p11_chargebyenergy_dialog(QWidget *parent = 0);
    ~p11_chargebyenergy_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p11_chargebyenergy_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);
    void changeEvent();

signals:
    void signal_exit_p11dlg();

private slots:

    void init_page_dlg(void);
    void number_ptbn_press(void);

    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

    void on_pbtn_return_clicked();
    void on_pbtn_sure_clicked();

    void on_pbtn_othersKWH_clicked();
    //void on_pbtn_20KWH_clicked();
    void on_pbtn_15KWH_clicked();
    void on_pbtn_10KWH_clicked();
    void on_pbtn_5KWH_clicked();

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

#endif // P11_CHARGEBYENERGY_DIALOG_H
