#ifndef P23_SETPARA_SUB4_DIALOG_H
#define P23_SETPARA_SUB4_DIALOG_H

#include <QDialog>

namespace Ui {
class p23_setpara_sub4_dialog;
}

class p23_setpara_sub4_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p23_setpara_sub4_dialog(QWidget *parent = 0);
    ~p23_setpara_sub4_dialog();
    
private:
    Ui::p23_setpara_sub4_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p23dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P23_SETPARA_SUB4_DIALOG_H
