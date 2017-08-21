#ifndef DIALOG_ORDER_H
#define DIALOG_ORDER_H

#include <QDialog>

namespace Ui {
class dialog_order;
}

class dialog_order : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_order(QWidget *parent = 0);
    ~dialog_order();
    
private:
    Ui::dialog_order *ui;

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

#endif // DIALOG_ORDER_H
