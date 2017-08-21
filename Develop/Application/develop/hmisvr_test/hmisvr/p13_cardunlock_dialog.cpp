#include "p13_cardunlock_dialog.h"
#include "ui_p13_cardunlock_dialog.h"
#include "globalhmi.h"

p13_cardunlock_dialog::p13_cardunlock_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p13_cardunlock_dialog)
{
    ui->setupUi(this);
}

p13_cardunlock_dialog::~p13_cardunlock_dialog()
{
    delete ui;
}

void p13_cardunlock_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p13_cardunlock_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p13_cardunlock_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p13_cardunlock_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p13_cardunlock_dialog::update_page_info()
{

   ui->label_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
   ui->label_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void p13_cardunlock_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CARDUNLOCK)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p13_cardunlock_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p13dlg();

}

void p13_cardunlock_dialog::on_ptn_return_clicked()
{
    //hmi_button_dn_num=RETURN_BUTTON;
    //API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
    //                          sizeof(hmi_button_dn_num));


    hmi_page_index = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
