#include "dialog_local_charge_recode.h"
#include "ui_dialog_local_charge_recode.h"
#include "globalhmi.h"
dialog_local_charge_recode::dialog_local_charge_recode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_local_charge_recode)
{
    ui->setupUi(this);
}

dialog_local_charge_recode::~dialog_local_charge_recode()
{
    delete ui;
}

void dialog_local_charge_recode::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}

void dialog_local_charge_recode::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_local_charge_recode::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_local_charge_recode::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_local_charge_recode::update_page_info()
{

}

void dialog_local_charge_recode::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_LOCAL_CHARGE_RECODE)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_local_charge_recode::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}

void dialog_local_charge_recode::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGERECODE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
