#ifndef P21_SETPARA_SUB2_DIALOG_H
#define P21_SETPARA_SUB2_DIALOG_H

#include <QDialog>

namespace Ui {
class p21_setpara_sub2_dialog;
}

class p21_setpara_sub2_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p21_setpara_sub2_dialog(QWidget *parent = 0);
    ~p21_setpara_sub2_dialog();

private:
    Ui::p21_setpara_sub2_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p21dlg();

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

    //void number_press(void);
};

#endif // P21_SETPARA_SUB2_DIALOG_H
