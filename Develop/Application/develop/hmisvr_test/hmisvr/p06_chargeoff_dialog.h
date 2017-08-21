#ifndef P06_CHARGEOFF_DIALOG_H
#define P06_CHARGEOFF_DIALOG_H

#include <QDialog>

namespace Ui {
class p06_chargeoff_dialog;
}

class p06_chargeoff_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p06_chargeoff_dialog(QWidget *parent = 0);
    ~p06_chargeoff_dialog();
    
private:
    Ui::p06_chargeoff_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p06dlg();
    
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);


        //void on_ptn_return_clicked();
        void on_ptn_return_clicked();
};

#endif // P06_CHARGEOFF_DIALOG_H
