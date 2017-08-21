#include "p17_appdownload_dialog.h"
#include "ui_p17_appdownload_dialog.h"
#include "globalhmi.h"

p17_appdownload_dialog::p17_appdownload_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p17_appdownload_dialog)
{
    ui->setupUi(this);
}

p17_appdownload_dialog::~p17_appdownload_dialog()
{
    delete ui;
}

void p17_appdownload_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p17_appdownload_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p17_appdownload_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p17_appdownload_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p17_appdownload_dialog::update_page_info()
{

}

void p17_appdownload_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_APPDOWNLOAD)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p17_appdownload_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p17dlg();
    //printf("************ exit_page_dlg() exceled ,%s************\n",__FILE__);
    //delete p17_dlg;
    //p17_dlg = NULL;
}
void p17_appdownload_dialog::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
