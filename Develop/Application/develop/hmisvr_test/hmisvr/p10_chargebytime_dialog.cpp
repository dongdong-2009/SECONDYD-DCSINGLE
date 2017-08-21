#include "p10_chargebytime_dialog.h"
#include "ui_p10_chargebytime_dialog.h"
#include "globalhmi.h"

p10_chargebytime_dialog::p10_chargebytime_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p10_chargebytime_dialog)
{
    ui->setupUi(this);
}

p10_chargebytime_dialog::~p10_chargebytime_dialog()
{
    delete ui;
}

static char time_number[5]={};
static int  time_number_write;
static BOOL user_defined_flg;
static int  time_number_temp;
BOOL   time_err_flg;

void p10_chargebytime_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    number_ptbn_press();
}

void p10_chargebytime_dialog::number_ptbn_press()
{

    QPushButton* array[12]={0};
    array[0] = ui->pbtn_num0;
    array[1] = ui->pbtn_num1;
    array[2] = ui->pbtn_num2;
    array[3] = ui->pbtn_num3;
    array[4] = ui->pbtn_num4;
    array[5] = ui->pbtn_num5;
    array[6] = ui->pbtn_num6;
    array[7] = ui->pbtn_num7;
    array[8] = ui->pbtn_num8;
    array[9] = ui->pbtn_num9;
    array[10] = ui->pbtn_dot;
    array[11] = ui->pbtn_delete;

    int num = 0;
    for(num = 0; num < 12;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/new/prefix/pic_resource/otherwidget/number_press.png);}\
                                  QPushButton:pressed{border-image: url(:/new/prefix/pic_resource/otherwidget/number.png);}");
    }
}

void p10_chargebytime_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p10_chargebytime_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p10_chargebytime_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p10_chargebytime_dialog::update_page_info()
{
    ui->lbl_time_chose->setText(time_number);

    if(language_num == 1)
    {
          if(time_err_flg)
          {
             ui->lbl_speaker->setText(QString::fromUtf8("请选择1至180之间任意数字!"));
          }
          else
          {
              ui->lbl_speaker->setText(QString::fromUtf8("请输入您所需的充电时间!"));
          }
    }
    else  if(language_num == 2)
    {
          if(time_err_flg)
          {
             ui->lbl_speaker->setText("Choose random numbers between 1 to 100 !");
          }
          else
          {
              ui->lbl_speaker->setText("Please enter the charging time you need !");
          }
    }

    if(time_number_temp)
    {
          ui->lbl_time_chose->setFocus();
    }
    else
    {
          ui->lbl_time_chose->clearFocus();
    }
}

void p10_chargebytime_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGEBYTIME)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p10_chargebytime_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p10dlg();
    //delete p10_dlg;
    //p10_dlg = NULL;
}

void p10_chargebytime_dialog::on_pbtn_num0_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='0';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num1_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='1';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num2_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='2';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num3_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='3';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num4_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='4';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num5_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='5';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num6_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='6';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num7_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='7';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num8_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='8';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_num9_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='9';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_dot_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( time_number_write >=MAX_PASSWD_LEN)
        {
            time_number_write=MAX_PASSWD_LEN;
        }else{
            time_number[time_number_write++]='.';
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_delete_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(time_number_write>0)
        {
            time_number_write--;
            time_number[time_number_write]=0;
        }
        else
        {
            time_number_write=0;
        }
    }
}

void p10_chargebytime_dialog::on_pbtn_30min_clicked()
{
    time_number_temp=30;
    UINT8 data=30;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p10_chargebytime_dialog::on_pbtn_60min_clicked()
{
    time_number_temp=60;
    UINT8 data=60;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p10_chargebytime_dialog::on_pbtn_120min_clicked()
{
    time_number_temp=120;
    UINT8 data=120;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p10_chargebytime_dialog::on_pbtn_othersmin_clicked()
{
    user_defined_flg = TRUE;
}

void p10_chargebytime_dialog::on_pbtn_return_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p10_chargebytime_dialog::on_pbtn_sure_clicked()
{
    time_number_temp = atof(time_number);
    if(time_number_temp<0 || time_number_temp>100)
    {
        time_err_flg = TRUE;
        time_number_write = 0;
        memset(time_number,0,sizeof(time_number));
        return;
    }

    UINT8 data = time_number_temp;
    //ErrMsg("$$$$$$[%d]\n",data);
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    hmi_page_index = PAGEINDEX_CHARGELINK;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

