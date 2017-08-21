#ifndef DIALOG_CHARGERECODE_H
#define DIALOG_CHARGERECODE_H

#include <QDialog>

namespace Ui {
class dialog_chargerecode;
}

class dialog_chargerecode : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_chargerecode(QWidget *parent = 0);
    ~dialog_chargerecode();
    
private:
    Ui::dialog_chargerecode *ui;

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
    void on_ptn_local_recode_clicked();
    void on_ptn_remote_recode_clicked();
    void on_ptn_return_clicked();
};

#endif // DIALOG_CHARGERECODE_H
