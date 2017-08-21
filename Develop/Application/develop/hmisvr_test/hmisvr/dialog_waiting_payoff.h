#ifndef DIALOG_WAITING_PAYOFF_H
#define DIALOG_WAITING_PAYOFF_H

#include <QDialog>

namespace Ui {
class dialog_waiting_payoff;
}

class dialog_waiting_payoff : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_waiting_payoff(QWidget *parent = 0);
    ~dialog_waiting_payoff();

private:
    Ui::dialog_waiting_payoff *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

};

#endif // DIALOG_WAITING_PAYOFF_H
