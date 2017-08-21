#ifndef P22_SETPARA_SUB3_DIALOG_H
#define P22_SETPARA_SUB3_DIALOG_H

#include <QDialog>

namespace Ui {
class p22_setpara_sub3_dialog;
}

class p22_setpara_sub3_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p22_setpara_sub3_dialog(QWidget *parent = 0);
    ~p22_setpara_sub3_dialog();
    
private:
    Ui::p22_setpara_sub3_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p22dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P22_SETPARA_SUB3_DIALOG_H
