#ifndef DIALOG_LOCAL_CHARGE_RECODE_H
#define DIALOG_LOCAL_CHARGE_RECODE_H

#include <QDialog>

namespace Ui {
class dialog_local_charge_recode;
}

class dialog_local_charge_recode : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_local_charge_recode(QWidget *parent = 0);
    ~dialog_local_charge_recode();
    
private:
    Ui::dialog_local_charge_recode *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_ptn_return_clicked();
};

#endif // DIALOG_LOCAL_CHARGE_RECODE_H
