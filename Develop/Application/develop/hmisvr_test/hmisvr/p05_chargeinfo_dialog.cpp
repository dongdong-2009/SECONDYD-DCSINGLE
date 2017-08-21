#include "p05_chargeinfo_dialog.h"
#include "ui_p05_chargeinfo_dialog.h"
#include "globalhmi.h"

p05_chargeinfo_dialog::p05_chargeinfo_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p05_chargeinfo_dialog)
{
    ui->setupUi(this);
}

p05_chargeinfo_dialog::~p05_chargeinfo_dialog()
{
    delete ui;
}


void p05_chargeinfo_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void p05_chargeinfo_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

    ui->frame_charinfo->move(0,82);
    ui->frame_battary_info->move(0,800);
}

void p05_chargeinfo_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p05_chargeinfo_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p05_chargeinfo_dialog::update_page_info()
{

    for(int carstat_pnumber = 1; carstat_pnumber < 11; carstat_pnumber ++)
    {
        QString carstat_str = QString("%1%2%3").arg("QLabel{border-image: url(:/carcharstat/pic_resource/car/carstat (").arg(carstat_pnumber).arg(".png));}");

        ui->label_carstat->setStyleSheet(carstat_str);

        timedelay_msec(100);

        if(hmi_page_index != PAGEINDEX_CHARGEINFO)
        {
            break;
        }
    }


}

void p05_chargeinfo_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGEINFO)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p05_chargeinfo_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");

    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

    timer->stop();
    emit signal_exit_p05dlg();
    //printf("************ exit_page_dlg() exceled ,%s************\n",__FILE__);
    //delete p05_dlg;
    //p05_dlg = NULL;
}

void p05_chargeinfo_dialog::on_ptn_battery_clicked()
{
    ui->frame_charinfo->move(0,800);
    ui->frame_battary_info->move(0,82);

    ui->ptn_monitor->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/charge_monitor_2.png);" );
    ui->ptn_battery->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/battery_1.png);" );
}

void p05_chargeinfo_dialog::on_ptn_stop_clicked()
{
    hmi_page_index = PAGEINDEX_CARDPAYOFF;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    ui->ptn_monitor->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/charge_monitor_2.png);" );
    ui->ptn_battery->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/battery_2.png);" );
    ui->ptn_stop->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/stop_charge_1.png);" );
}

void p05_chargeinfo_dialog::on_ptn_monitor_clicked()
{
    ui->frame_charinfo->move(0,82);
    ui->frame_battary_info->move(0,800);

    ui->ptn_monitor->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/charge_monitor_1.png);" );
    ui->ptn_battery->setStyleSheet ( "border-image: url(:/new/prefix/pic_resource/chargeinfo/battery_2.png);" );
}
