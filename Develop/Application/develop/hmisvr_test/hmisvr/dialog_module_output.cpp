#include "dialog_module_output.h"
#include "ui_dialog_module_output.h"
#include "globalhmi.h"

dialog_module_output::dialog_module_output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_module_output)
{
    ui->setupUi(this);
}

dialog_module_output::~dialog_module_output()
{
    delete ui;
}

void dialog_module_output::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}

void dialog_module_output::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_module_output::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
    // init_page_val();
    // ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_module_output::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_module_output::update_page_info()
{

}

void dialog_module_output::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_MODULE_OUTPUT)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_module_output::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}
