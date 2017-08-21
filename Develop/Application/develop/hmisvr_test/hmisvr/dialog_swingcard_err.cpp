#include "dialog_swingcard_err.h"
#include "ui_dialog_swingcard_err.h"
#include "globalhmi.h"

dialog_swingcard_err::dialog_swingcard_err(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_swingcard_err)
{
    ui->setupUi(this);
}

dialog_swingcard_err::~dialog_swingcard_err()
{
    delete ui;
}

void dialog_swingcard_err::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_swingcard_err::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_swingcard_err::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);

}

void dialog_swingcard_err::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_swingcard_err::update_page_info()
{

}

void dialog_swingcard_err::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SWINGCARD_ERR)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_swingcard_err::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}

