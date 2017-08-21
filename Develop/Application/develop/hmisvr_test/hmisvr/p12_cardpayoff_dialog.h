#ifndef P12_CARDPAYOFF_DIALOG_H
#define P12_CARDPAYOFF_DIALOG_H

#include <QDialog>

namespace Ui {
class p12_cardpayoff_dialog;
}

class p12_cardpayoff_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p12_cardpayoff_dialog(QWidget *parent = 0);
    ~p12_cardpayoff_dialog();

private:
    Ui::p12_cardpayoff_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p12dlg();

private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        void on_ptn_success_clicked();
        void on_ptn_fail_clicked();
        void on_ptn_return_clicked();
};

#endif // P12_CARDPAYOFF_DIALOG_H
