#ifndef DIALOG_NET_ERR_H
#define DIALOG_NET_ERR_H

#include <QDialog>

namespace Ui {
class dialog_net_err;
}

class dialog_net_err : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_net_err(QWidget *parent = 0);
    ~dialog_net_err();

private:
    Ui::dialog_net_err *ui;

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

#endif // DIALOG_NET_ERR_H
