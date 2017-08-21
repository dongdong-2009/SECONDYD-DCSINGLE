#ifndef DIALOG_SWINGCARD_ERR_H
#define DIALOG_SWINGCARD_ERR_H

#include <QDialog>

namespace Ui {
class dialog_swingcard_err;
}

class dialog_swingcard_err : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_swingcard_err(QWidget *parent = 0);
    ~dialog_swingcard_err();

private:
    Ui::dialog_swingcard_err *ui;

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

#endif // DIALOG_SWINGCARD_ERR_H
