#include "p20_setpara_sub1_dialog.h"
#include "ui_p20_setpara_sub1_dialog.h"
#include "globalhmi.h"

p20_setpara_sub1_dialog::p20_setpara_sub1_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p20_setpara_sub1_dialog)
{
    ui->setupUi(this);
}

p20_setpara_sub1_dialog::~p20_setpara_sub1_dialog()
{
    delete ui;
}

void p20_setpara_sub1_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p20_setpara_sub1_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p20_setpara_sub1_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p20_setpara_sub1_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p20_setpara_sub1_dialog::update_page_info()
{

}

void p20_setpara_sub1_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPARASUB1)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p20_setpara_sub1_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p20dlg();

}
