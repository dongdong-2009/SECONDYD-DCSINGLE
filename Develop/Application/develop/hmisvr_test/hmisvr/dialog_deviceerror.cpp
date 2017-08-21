#include "dialog_deviceerror.h"
#include "ui_dialog_deviceerror.h"
#include "globalhmi.h"
dialog_deviceerror::dialog_deviceerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_deviceerror)
{
    ui->setupUi(this);
}

dialog_deviceerror::~dialog_deviceerror()
{
    delete ui;
}

void dialog_deviceerror::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_deviceerror::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_deviceerror::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_deviceerror::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_deviceerror::update_page_info()
{

}

void dialog_deviceerror::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_DEVICEERROR)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_deviceerror::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();

}


