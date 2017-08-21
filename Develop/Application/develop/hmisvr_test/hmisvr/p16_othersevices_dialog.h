#ifndef P16_OTHERSEVICES_DIALOG_H
#define P16_OTHERSEVICES_DIALOG_H

#include <QDialog>

namespace Ui {
class p16_othersevices_dialog;
}

class p16_othersevices_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p16_othersevices_dialog(QWidget *parent = 0);
    ~p16_othersevices_dialog();
    
private:
    Ui::p16_othersevices_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p16dlg();
    
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_ptn_return_clicked();
};

#endif // P16_OTHERSEVICES_DIALOG_H
