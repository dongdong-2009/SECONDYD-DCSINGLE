#include "p07_swingcard_dialog.h"
#include "ui_p07_swingcard_dialog.h"
#include "globalhmi.h"

p07_swingcard_dialog::p07_swingcard_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p07_swingcard_dialog)
{
    ui->setupUi(this);
}

p07_swingcard_dialog::~p07_swingcard_dialog()
{
    delete ui;
}

static int add_num = 0;
static int Timer = 0;

void p07_swingcard_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p07_swingcard_dialog::init_page_val()
{
    add_num=0;
    Timer=30;//120
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

}

void p07_swingcard_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p07_swingcard_dialog::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

void p07_swingcard_dialog::update_page_info()
{
    ui->label_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->label_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

    ui->ptn_return->setStyleSheet("QPushButton{border-image: url(:/new/prefix/pic_resource/otherwidget/return.png);}\
                                QPushButton:pressed{border-image: url(:/new/prefix/pic_resource/otherwidget/return_press.png);}");
    add_num++;
    if(add_num==20)
    {
        add_num=0;
        Timer--;
        if(Timer<=0)
        {
            Timer = 0;
            //hmi_button_dn_num=CANCEL_BUTTON;
            //API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                               //sizeof(hmi_button_dn_num));
            hmi_page_index = PAGEINDEX_MAIN;
            API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

        }
    }

    ui->label_countdown_time->setText(QString::number(Timer,'f',0));
}

void p07_swingcard_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SWINGCARD)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p07_swingcard_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p07dlg();
    //delete p07_dlg;
    //p07_dlg = NULL;
}

void p07_swingcard_dialog::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p07_swingcard_dialog::on_ptn_success_clicked()
{
    hmi_page_index = PAGEINDEX_CARDPASSWD;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p07_swingcard_dialog::on_ptn_fail_clicked()
{
    hmi_page_index = PAGEINDEX_CARDERRREASON;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
