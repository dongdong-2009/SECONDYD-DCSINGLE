#include "p26_setpara_sub6_dialog.h"
#include "ui_p26_setpara_sub6_dialog.h"
#include "globalhmi.h"

p26_setpara_sub6_dialog::p26_setpara_sub6_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p26_setpara_sub6_dialog)
{
    ui->setupUi(this);
}

p26_setpara_sub6_dialog::~p26_setpara_sub6_dialog()
{
    delete ui;
}

void p26_setpara_sub6_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p26_setpara_sub6_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p26_setpara_sub6_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p26_setpara_sub6_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p26_setpara_sub6_dialog::update_page_info()
{

}

void p26_setpara_sub6_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPARASUB6)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p26_setpara_sub6_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p26dlg();

}
