#ifndef DIALOG_CARDERR_REASON_H
#define DIALOG_CARDERR_REASON_H

#include <QDialog>

namespace Ui {
class dialog_carderr_reason;
}

class dialog_carderr_reason : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_carderr_reason(QWidget *parent = 0);
    ~dialog_carderr_reason();

protected:
    void changeEvent(QEvent*);

private:
    Ui::dialog_carderr_reason *ui;

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
    void on_ptn_return_clicked();
};

#endif // DIALOG_CARDERR_REASON_H
