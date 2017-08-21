#include "p14_deviceinfo_dialog.h"
#include "ui_p14_deviceinfo_dialog.h"
#include "globalhmi.h"

p14_deviceinfo_dialog::p14_deviceinfo_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p14_deviceinfo_dialog)
{
    ui->setupUi(this);
}

p14_deviceinfo_dialog::~p14_deviceinfo_dialog()
{
    delete ui;
}


void p14_deviceinfo_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p14_deviceinfo_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p14_deviceinfo_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p14_deviceinfo_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p14_deviceinfo_dialog::update_page_info()
{

}

void p14_deviceinfo_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_DEVICEINFO)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p14_deviceinfo_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p14dlg();
    //printf("************ exit_page_dlg() exceled ,%s************\n",__FILE__);
    //delete p14_dlg;
    //p14_dlg = NULL;
}

void p14_deviceinfo_dialog::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
