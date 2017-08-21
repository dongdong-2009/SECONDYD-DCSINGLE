#ifndef DIALOG_QUIT_SUCCESS_H
#define DIALOG_QUIT_SUCCESS_H

#include <QDialog>

namespace Ui {
class dialog_quit_success;
}

class dialog_quit_success : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_quit_success(QWidget *parent = 0);
    ~dialog_quit_success();

private:
    Ui::dialog_quit_success *ui;

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

#endif // DIALOG_QUIT_SUCCESS_H
