#include "dialog_chargerecode.h"
#include "ui_dialog_chargerecode.h"
#include "globalhmi.h"

dialog_chargerecode::dialog_chargerecode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_chargerecode)
{
    ui->setupUi(this);
}

dialog_chargerecode::~dialog_chargerecode()
{
    delete ui;
}

void dialog_chargerecode::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_chargerecode::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_chargerecode::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_chargerecode::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void dialog_chargerecode::update_page_info()
{

}

void dialog_chargerecode::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGERECODE)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_chargerecode::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();
}



void dialog_chargerecode::on_ptn_local_recode_clicked()
{
    hmi_page_index = PAGEINDEX_LOCAL_CHARGE_RECODE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void dialog_chargerecode::on_ptn_remote_recode_clicked()
{
    hmi_page_index = PAGEINDEX_REMOTE_UNLOAD_RECODE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void dialog_chargerecode::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_SERVICECHOOSE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
