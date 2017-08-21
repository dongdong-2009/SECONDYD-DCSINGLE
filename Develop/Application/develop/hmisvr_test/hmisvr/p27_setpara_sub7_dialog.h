#ifndef P27_SETPARA_SUB7_DIALOG_H
#define P27_SETPARA_SUB7_DIALOG_H

#include <QDialog>

namespace Ui {
class p27_setpara_sub7_dialog;
}

class p27_setpara_sub7_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p27_setpara_sub7_dialog(QWidget *parent = 0);
    ~p27_setpara_sub7_dialog();
    
private:
    Ui::p27_setpara_sub7_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p27dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P27_SETPARA_SUB7_DIALOG_H
