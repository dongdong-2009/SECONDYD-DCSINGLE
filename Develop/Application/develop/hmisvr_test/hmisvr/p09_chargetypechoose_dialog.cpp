#include "p09_chargetypechoose_dialog.h"
#include "ui_p09_chargetypechoose_dialog.h"
#include "globalhmi.h"

p09_chargetypechoose_dialog::p09_chargetypechoose_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p09_chargetypechoose_dialog)
{
    ui->setupUi(this);
}

p09_chargetypechoose_dialog::~p09_chargetypechoose_dialog()
{
    delete ui;
}

void p09_chargetypechoose_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p09_chargetypechoose_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p09_chargetypechoose_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p09_chargetypechoose_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p09_chargetypechoose_dialog::update_page_info()
{
    ui->label_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->label_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void p09_chargetypechoose_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGETYPECHOOSE)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p09_chargetypechoose_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p09dlg();
    //printf("************ exit_page_dlg() exceled ,%s************\n",__FILE__);
    //delete p09_dlg;
    //p09_dlg = NULL;
}

void p09_chargetypechoose_dialog::on_pbtn_cancel_clicked()
{
    hmi_page_index = PAGEINDEX_SWINGCARD;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p09_chargetypechoose_dialog::on_pbtn_auto_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGELINK;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p09_chargetypechoose_dialog::on_pbtn_byenergy_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGEBYENERGY;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p09_chargetypechoose_dialog::on_pbtn_bytime_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGEBYTIME;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p09_chargetypechoose_dialog::on_pbtn_bymoney_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGEBYMONEY;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p09_chargetypechoose_dialog::on_pbtn_return_clicked()
{
    hmi_page_index = PAGEINDEX_SWINGCARD;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

