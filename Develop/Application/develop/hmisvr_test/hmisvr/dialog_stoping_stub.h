#ifndef DIALOG_STOPING_STUB_H
#define DIALOG_STOPING_STUB_H

#include <QDialog>

namespace Ui {
class dialog_stoping_stub;
}

class dialog_stoping_stub : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_stoping_stub(QWidget *parent = 0);
    ~dialog_stoping_stub();

private:
    Ui::dialog_stoping_stub *ui;

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

#endif // DIALOG_STOPING_STUB_H
