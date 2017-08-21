#ifndef P24_SERVICE_CHOOSE_DIALOG_H
#define P24_SERVICE_CHOOSE_DIALOG_H

#include <QDialog>

namespace Ui {
class p24_service_choose_dialog;
}

class p24_service_choose_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p24_service_choose_dialog(QWidget *parent = 0);
    ~p24_service_choose_dialog();

private:
    Ui::p24_service_choose_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p24dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_pbtn_cancel_clicked();
    void on_pbtn_charge_clicked();

};

#endif // P24_SERVICE_CHOOSE_DIALOG_H
