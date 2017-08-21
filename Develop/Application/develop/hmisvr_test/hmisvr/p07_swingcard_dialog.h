#ifndef P07_SWINGCARD_DIALOG_H
#define P07_SWINGCARD_DIALOG_H

#include <QDialog>

namespace Ui {
class p07_swingcard_dialog;
}

class p07_swingcard_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p07_swingcard_dialog(QWidget *parent = 0);
    ~p07_swingcard_dialog();
    
private:
    Ui::p07_swingcard_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p07dlg();
    
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        
        void on_ptn_return_clicked();
        void on_ptn_success_clicked();
        void on_ptn_fail_clicked();
};

#endif // P07_SWINGCARD_DIALOG_H
