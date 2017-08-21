#ifndef P18_CARDINQUERY_DIALOG_H
#define P18_CARDINQUERY_DIALOG_H

#include <QDialog>

namespace Ui {
class p18_cardinquery_dialog;
}

class p18_cardinquery_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p18_cardinquery_dialog(QWidget *parent = 0);
    ~p18_cardinquery_dialog();
    
private:
    Ui::p18_cardinquery_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p18dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);


    void on_ptn_return_clicked();
};

#endif // P18_CARDINQUERY_DIALOG_H
