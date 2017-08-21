#ifndef DIALOG_WAIT_SWINGCARD_H
#define DIALOG_WAIT_SWINGCARD_H

#include <QDialog>

namespace Ui {
class dialog_wait_swingcard;
}

class dialog_wait_swingcard : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_wait_swingcard(QWidget *parent = 0);
    ~dialog_wait_swingcard();

private:
    Ui::dialog_wait_swingcard *ui;

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

#endif // DIALOG_WAIT_SWINGCARD_H
