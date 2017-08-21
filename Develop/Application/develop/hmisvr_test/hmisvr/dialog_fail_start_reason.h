#ifndef DIALOG_FAIL_START_REASON_H
#define DIALOG_FAIL_START_REASON_H

#include <QDialog>

namespace Ui {
class dialog_fail_start_reason;
}

class dialog_fail_start_reason : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_fail_start_reason(QWidget *parent = 0);
    ~dialog_fail_start_reason();
    
private:
    Ui::dialog_fail_start_reason *ui;

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

#endif // DIALOG_FAIL_START_REASON_H
