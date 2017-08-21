#include "p03_chargelink_dialog.h"
#include "ui_p03_chargelink_dialog.h"
#include "globalhmi.h"

p03_chargelink_dialog::p03_chargelink_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p03_chargelink_dialog)
{
    ui->setupUi(this);
}

p03_chargelink_dialog::~p03_chargelink_dialog()
{
    delete ui;
}

void p03_chargelink_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}

void p03_chargelink_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p03_chargelink_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p03_chargelink_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p03_chargelink_dialog::update_page_info()
{

}

void p03_chargelink_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGELINK)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p03_chargelink_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p03dlg();
    //delete p03_dlg;
    //p03_dlg = NULL;
}

void p03_chargelink_dialog::on_ptn_success_clicked()
{
   hmi_page_index = PAGEINDEX_CHARGESTART;
   API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p03_chargelink_dialog::on_ptn_fail_clicked()
{
   hmi_page_index = PAGEINDEX_MAIN;
   API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p03_chargelink_dialog::on_ptn_return_clicked()
{
   hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
   API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
