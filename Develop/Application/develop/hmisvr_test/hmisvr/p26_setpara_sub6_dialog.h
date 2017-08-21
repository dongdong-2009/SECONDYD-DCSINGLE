#ifndef P26_SETPARA_SUB6_DIALOG_H
#define P26_SETPARA_SUB6_DIALOG_H

#include <QDialog>

namespace Ui {
class p26_setpara_sub6_dialog;
}

class p26_setpara_sub6_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p26_setpara_sub6_dialog(QWidget *parent = 0);
    ~p26_setpara_sub6_dialog();
    
private:
    Ui::p26_setpara_sub6_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p26dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
};

#endif // P26_SETPARA_SUB6_DIALOG_H
