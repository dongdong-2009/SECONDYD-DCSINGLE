#ifndef DIALOG_REMOTE_UNLOAD_RECODE_H
#define DIALOG_REMOTE_UNLOAD_RECODE_H

#include <QDialog>

namespace Ui {
class dialog_remote_unload_recode;
}

class dialog_remote_unload_recode : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_remote_unload_recode(QWidget *parent = 0);
    ~dialog_remote_unload_recode();
    
private:
    Ui::dialog_remote_unload_recode *ui;

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

#endif // DIALOG_REMOTE_UNLOAD_RECODE_H
