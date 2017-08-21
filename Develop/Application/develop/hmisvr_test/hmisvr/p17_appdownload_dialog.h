#ifndef P17_APPDOWNLOAD_DIALOG_H
#define P17_APPDOWNLOAD_DIALOG_H

#include <QDialog>

namespace Ui {
class p17_appdownload_dialog;
}

class p17_appdownload_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p17_appdownload_dialog(QWidget *parent = 0);
    ~p17_appdownload_dialog();
    
private:
    Ui::p17_appdownload_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p17dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_ptn_return_clicked();
};

#endif // P17_APPDOWNLOAD_DIALOG_H
