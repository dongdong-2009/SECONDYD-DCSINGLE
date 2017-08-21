#include "dialog_quit_success.h"
#include "ui_dialog_quit_success.h"
#include "globalhmi.h"

dialog_quit_success::dialog_quit_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_quit_success)
{
    ui->setupUi(this);
}

dialog_quit_success::~dialog_quit_success()
{
    delete ui;
}

void dialog_quit_success::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_quit_success::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_quit_success::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);

}

void dialog_quit_success::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_quit_success::update_page_info()
{

}

void dialog_quit_success::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_QUIT_SUCCESS)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_quit_success::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}

