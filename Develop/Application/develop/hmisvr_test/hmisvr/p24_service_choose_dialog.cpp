#include "p24_service_choose_dialog.h"
#include "ui_p24_service_choose_dialog.h"
#include "globalhmi.h"

p24_service_choose_dialog::p24_service_choose_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p24_service_choose_dialog)
{
    ui->setupUi(this);
}

p24_service_choose_dialog::~p24_service_choose_dialog()
{
    delete ui;
}

void p24_service_choose_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p24_service_choose_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

}

void p24_service_choose_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p24_service_choose_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p24_service_choose_dialog::update_page_info()
{

}

void p24_service_choose_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SERVICECHOOSE)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p24_service_choose_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p24dlg();
    //delete p24_dlg;
    //p24_dlg = NULL;
}
void p24_service_choose_dialog::on_pbtn_cancel_clicked()
{
    hmi_page_index = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p24_service_choose_dialog::on_pbtn_charge_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

