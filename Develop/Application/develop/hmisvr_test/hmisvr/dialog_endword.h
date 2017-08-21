#ifndef DIALOG_ENDWORD_H
#define DIALOG_ENDWORD_H

#include <QDialog>

namespace Ui {
class dialog_endword;
}

class dialog_endword : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_endword(QWidget *parent = 0);
    ~dialog_endword();
    
private:
    Ui::dialog_endword *ui;

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

#endif // DIALOG_ENDWORD_H
