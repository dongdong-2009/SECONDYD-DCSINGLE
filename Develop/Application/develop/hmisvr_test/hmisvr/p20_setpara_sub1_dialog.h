#ifndef P20_SETPARA_SUB1_DIALOG_H
#define P20_SETPARA_SUB1_DIALOG_H

#include <QDialog>

namespace Ui {
class p20_setpara_sub1_dialog;
}

class p20_setpara_sub1_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p20_setpara_sub1_dialog(QWidget *parent = 0);
    ~p20_setpara_sub1_dialog();
    
private:
    Ui::p20_setpara_sub1_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p20dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P20_SETPARA_SUB1_DIALOG_H
