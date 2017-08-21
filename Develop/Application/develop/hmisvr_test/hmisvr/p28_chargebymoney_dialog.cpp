#include "p28_chargebymoney_dialog.h"
#include "ui_p28_chargebymoney_dialog.h"
#include "globalhmi.h"

p28_chargebymoney_dialog::p28_chargebymoney_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p28_chargebymoney_dialog)
{
    ui->setupUi(this);
}

p28_chargebymoney_dialog::~p28_chargebymoney_dialog()
{
    delete ui;
}

static char money_number[5]={};
static int  money_number_write;
static BOOL user_defined_flg;
static int  money_number_temp;
static BOOL money_err_flg;
static int  elec_energy_temp;

void p28_chargebymoney_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    number_ptbn_press();
}

void p28_chargebymoney_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p28_chargebymoney_dialog::number_ptbn_press()
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

void p28_chargebymoney_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p28_chargebymoney_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p28_chargebymoney_dialog::update_page_info()
{
    ui->lbl_temp_choose->setText(money_number);

    if(language_num == 1)
    {
          if(money_err_flg)
          {
             ui->lbl_speaker->setText(QString::fromUtf8("请选择1至100之间任意数字!"));
          }
          else
          {
              ui->lbl_speaker->setText(QString::fromUtf8("请输入您所需的充电金额!"));
          }
    }
    else  if(language_num == 2)
    {
          if(money_err_flg)
          {
             ui->lbl_speaker->setText("Choose random numbers between 1 to 100 !");
          }
          else
          {
              ui->lbl_speaker->setText("Please enter the charging money you need !");
          }
    }

    if(money_number_temp)
    {
          ui->lbl_temp_choose->setFocus();
    }
    else
    {
          ui->lbl_temp_choose->clearFocus();
    }
}

void p28_chargebymoney_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGEBYMONEY)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p28_chargebymoney_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p28dlg();
    //delete p28_dlg;
    //p28_dlg = NULL;
}

void p28_chargebymoney_dialog::on_pbtn_num0_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='0';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num1_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='1';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num2_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='2';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num3_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='3';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num4_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='4';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num5_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='5';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num6_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='6';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num7_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='7';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num8_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='8';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_num9_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write >=MAX_PASSWD_LEN)
        {
           money_number_write=MAX_PASSWD_LEN;
        }else{
           money_number[money_number_write++]='9';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_dot_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( money_number_write >=MAX_PASSWD_LEN)
        {
            money_number_write=MAX_PASSWD_LEN;
        }else{
            money_number[money_number_write++]='.';
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_delete_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(money_number_write>0)
        {
            money_number_write--;
            money_number[money_number_write]=0;
        }
        else
        {
            money_number_write=0;
        }
    }
}

void p28_chargebymoney_dialog::on_pbtn_5YUAN_clicked()
{
    elec_energy_temp=5;
    UINT8 data=5;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p28_chargebymoney_dialog::on_pbtn_10YUAN_clicked()
{
    elec_energy_temp=10;
    UINT8 data=10;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p28_chargebymoney_dialog::on_pbtn_15YUAN_clicked()
{
    elec_energy_temp=15;
    UINT8 data=15;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p28_chargebymoney_dialog::on_pbtn_othersYUAN_clicked()
{
    user_defined_flg = TRUE;
}

void p28_chargebymoney_dialog::on_pbtn_return_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p28_chargebymoney_dialog::on_pbtn_sure_clicked()
{
    money_number_temp = atof(money_number);
    if(money_number_temp<0 || money_number_temp>100)
    {
        money_err_flg = TRUE;
        money_number_write = 0;
        memset(money_number,0,sizeof(money_number));
        return;
    }

    UINT8 data = money_number_temp;
    ErrMsg("$$$$$$[%d]\n",data);
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_MONEY_TYPE,(INT8 *)(&data),sizeof(data));

    hmi_page_index = PAGEINDEX_CHARGELINK;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}



