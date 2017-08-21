#include "dialog_module_monitor.h"
#include "ui_dialog_module_monitor.h"
#include "globalhmi.h"

dialog_module_monitor::dialog_module_monitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_module_monitor)
{
    ui->setupUi(this);
}

dialog_module_monitor::~dialog_module_monitor()
{
    delete ui;
}

void dialog_module_monitor::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_module_monitor::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_module_monitor::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_module_monitor::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_module_monitor::update_page_info()
{

}

void dialog_module_monitor::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_MODULE_MONITOR)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_module_monitor::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();

}