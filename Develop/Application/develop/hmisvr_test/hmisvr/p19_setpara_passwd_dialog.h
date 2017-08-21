#ifndef P19_SETPARA_PASSWD_DIALOG_H
#define P19_SETPARA_PASSWD_DIALOG_H

#include <QDialog>

namespace Ui {
class p19_setpara_passwd_dialog;
}

class p19_setpara_passwd_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p19_setpara_passwd_dialog(QWidget *parent = 0);
    ~p19_setpara_passwd_dialog();
    
private:
    Ui::p19_setpara_passwd_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p19dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

    void on_ptn_return_clicked();
    void on_ptn_success_clicked();
};

#endif // P19_SETPARA_PASSWD_DIALOG_H
