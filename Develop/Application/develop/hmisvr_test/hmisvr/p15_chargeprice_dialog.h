#ifndef P15_CHARGEPRICE_DIALOG_H
#define P15_CHARGEPRICE_DIALOG_H

#include <QDialog>

namespace Ui {
class p15_chargeprice_dialog;
}

class p15_chargeprice_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p15_chargeprice_dialog(QWidget *parent = 0);
    ~p15_chargeprice_dialog();
    
private:
    Ui::p15_chargeprice_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p15dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_ptn_return_clicked();
};

#endif // P15_CHARGEPRICE_DIALOG_H
