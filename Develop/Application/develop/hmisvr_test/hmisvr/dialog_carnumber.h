#ifndef DIALOG_CARNUMBER_H
#define DIALOG_CARNUMBER_H

#include <QDialog>

namespace Ui {
class dialog_carnumber;
}

class dialog_carnumber : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_carnumber(QWidget *parent = 0);
    ~dialog_carnumber();
    
private:
    Ui::dialog_carnumber *ui;
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

#endif // DIALOG_CARNUMBER_H
