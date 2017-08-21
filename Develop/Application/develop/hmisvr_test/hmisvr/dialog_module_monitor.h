#ifndef DIALOG_MODULE_MONITOR_H
#define DIALOG_MODULE_MONITOR_H

#include <QDialog>

namespace Ui {
class dialog_module_monitor;
}

class dialog_module_monitor : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_module_monitor(QWidget *parent = 0);
    ~dialog_module_monitor();
    
private:
    Ui::dialog_module_monitor *ui;

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
};

#endif // DIALOG_MODULE_MONITOR_H
