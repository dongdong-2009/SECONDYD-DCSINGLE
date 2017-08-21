#ifndef P25_SETPARA_SUB5_DIALOG_H
#define P25_SETPARA_SUB5_DIALOG_H

#include <QDialog>

namespace Ui {
class p25_setpara_sub5_dialog;
}

class p25_setpara_sub5_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p25_setpara_sub5_dialog(QWidget *parent = 0);
    ~p25_setpara_sub5_dialog();
    
private:
    Ui::p25_setpara_sub5_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p25dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P25_SETPARA_SUB5_DIALOG_H
