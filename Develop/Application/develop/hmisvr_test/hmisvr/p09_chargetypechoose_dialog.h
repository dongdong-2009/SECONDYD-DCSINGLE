#ifndef P09_CHARGETYPECHOOSE_DIALOG_H
#define P09_CHARGETYPECHOOSE_DIALOG_H

#include <QDialog>

namespace Ui {
class p09_chargetypechoose_dialog;
}

class p09_chargetypechoose_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p09_chargetypechoose_dialog(QWidget *parent = 0);
    ~p09_chargetypechoose_dialog();

private:
    Ui::p09_chargetypechoose_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_exit_p09dlg();

private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        void on_pbtn_cancel_clicked();
        void on_pbtn_auto_clicked();
        void on_pbtn_byenergy_clicked();
        void on_pbtn_bytime_clicked();
        void on_pbtn_bymoney_clicked();
        void on_pbtn_return_clicked();
};

#endif // P09_CHARGETYPECHOOSE_DIALOG_H
