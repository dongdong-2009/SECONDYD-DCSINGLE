#ifndef P02_QRCODE_DIALOG_H
#define P02_QRCODE_DIALOG_H

#include <QDialog>

namespace Ui {
class p02_qrcode_dialog;
}

class p02_qrcode_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p02_qrcode_dialog(QWidget *parent = 0);
    ~p02_qrcode_dialog();
    
private:
    Ui::p02_qrcode_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p02dlg();
    
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        
        void on_ptn_success_clicked();
        void on_ptn_return_clicked();
};

#endif // P02_QRCODE_DIALOG_H
