#include "p22_setpara_sub3_dialog.h"
#include "ui_p22_setpara_sub3_dialog.h"
#include "globalhmi.h"

p22_setpara_sub3_dialog::p22_setpara_sub3_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p22_setpara_sub3_dialog)
{
    ui->setupUi(this);
}

p22_setpara_sub3_dialog::~p22_setpara_sub3_dialog()
{
    delete ui;
}

void p22_setpara_sub3_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p22_setpara_sub3_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p22_setpara_sub3_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p22_setpara_sub3_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p22_setpara_sub3_dialog::update_page_info()
{

}

void p22_setpara_sub3_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPARASUB3)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p22_setpara_sub3_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p22dlg();

}
