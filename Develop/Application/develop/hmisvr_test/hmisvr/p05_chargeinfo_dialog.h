#ifndef P05_CHARGEINFO_DIALOG_H
#define P05_CHARGEINFO_DIALOG_H

#include <QDialog>

namespace Ui {
class p05_chargeinfo_dialog;
}

class p05_chargeinfo_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p05_chargeinfo_dialog(QWidget *parent = 0);
    ~p05_chargeinfo_dialog();

private:
    Ui::p05_chargeinfo_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p05dlg();

private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);

        void on_ptn_battery_clicked();
        void on_ptn_stop_clicked();

        void on_ptn_monitor_clicked();

};

#endif // P05_CHARGEINFO_DIALOG_H
