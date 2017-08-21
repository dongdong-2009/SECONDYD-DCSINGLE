#include "dialog_waiting_payoff.h"
#include "ui_dialog_waiting_payoff.h"
#include "globalhmi.h"

dialog_waiting_payoff::dialog_waiting_payoff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_waiting_payoff)
{
    ui->setupUi(this);
}

dialog_waiting_payoff::~dialog_waiting_payoff()
{
    delete ui;
}

void dialog_waiting_payoff::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_waiting_payoff::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_waiting_payoff::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);

}

void dialog_waiting_payoff::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_waiting_payoff::update_page_info()
{

}

void dialog_waiting_payoff::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_WAITING_PAYOFF)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_waiting_payoff::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}

