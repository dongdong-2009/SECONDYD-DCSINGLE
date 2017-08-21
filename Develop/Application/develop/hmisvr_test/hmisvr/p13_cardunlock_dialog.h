#ifndef P13_CARDUNLOCK_DIALOG_H
#define P13_CARDUNLOCK_DIALOG_H

#include <QDialog>

namespace Ui {
class p13_cardunlock_dialog;
}

class p13_cardunlock_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p13_cardunlock_dialog(QWidget *parent = 0);
    ~p13_cardunlock_dialog();
    
private:
    Ui::p13_cardunlock_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p13dlg();
    
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);

        void on_ptn_return_clicked();

};

#endif // P13_CARDUNLOCK_DIALOG_H
