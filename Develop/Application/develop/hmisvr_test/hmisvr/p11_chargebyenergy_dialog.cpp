#include "p11_chargebyenergy_dialog.h"
#include "ui_p11_chargebyenergy_dialog.h"
#include "globalhmi.h"

p11_chargebyenergy_dialog::p11_chargebyenergy_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p11_chargebyenergy_dialog)
{
    ui->setupUi(this);
}

p11_chargebyenergy_dialog::~p11_chargebyenergy_dialog()
{
    delete ui;
}

static char energy_number[5]={};
static int  energy_number_write;
static BOOL user_defined_flg;
static int  elec_energy_temp;
BOOL   energy_err_flg;

void p11_chargebyenergy_dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void p11_chargebyenergy_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    number_ptbn_press();
}

void p11_chargebyenergy_dialog::number_ptbn_press()
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

void p11_chargebyenergy_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p11_chargebyenergy_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p11_chargebyenergy_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p11_chargebyenergy_dialog::update_page_info()
{
    ui->lbl_temp_choose->setText(energy_number);

    if(language_num == 1)
    {
          if(energy_err_flg)
          {
             ui->lbl_speaker->setText(QString::fromUtf8(" 请选择1至100之间任意数字! "));
          }
          else
          {
              ui->lbl_speaker->setText(QString::fromUtf8(" 请输入您所需的充电度数! "));
          }
    }
    else  if(language_num == 2)
    {
          if(energy_err_flg)
          {
             ui->lbl_speaker->setText("Choose random numbers between 1 to 100 !");
          }
          else
          {
              ui->lbl_speaker->setText("Please enter the charging degree you need !");
          }
    }

    if(elec_energy_temp)
    {
          ui->lbl_temp_choose->setFocus();
    }
    else
    {
          ui->lbl_temp_choose->clearFocus();
    }
}

void p11_chargebyenergy_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CHARGEBYENERGY)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void p11_chargebyenergy_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p11dlg();
    //delete p11_dlg;
    //p11_dlg = NULL;
}

void p11_chargebyenergy_dialog::on_pbtn_num0_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='0';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num1_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='1';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num2_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='2';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num3_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='3';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num4_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='4';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num5_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='5';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num6_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='6';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num7_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='7';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num8_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='8';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_num9_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='9';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_dot_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if( energy_number_write >=MAX_PASSWD_LEN)
        {
            energy_number_write=MAX_PASSWD_LEN;
        }else{
            energy_number[energy_number_write++]='.';
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_delete_clicked()
{
    if(TRUE == user_defined_flg)
    {
        if(energy_number_write>0)
        {
            energy_number_write--;
            energy_number[energy_number_write]=0;
        }
        else
        {
            energy_number_write=0;
        }
    }
}

void p11_chargebyenergy_dialog::on_pbtn_5KWH_clicked()
{
    elec_energy_temp=5;
    UINT8 data=5;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p11_chargebyenergy_dialog::on_pbtn_10KWH_clicked()
{
    elec_energy_temp=10;
    UINT8 data=10;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p11_chargebyenergy_dialog::on_pbtn_15KWH_clicked()
{
    elec_energy_temp=15;
    UINT8 data=15;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p11_chargebyenergy_dialog::on_pbtn_othersKWH_clicked()
{
    user_defined_flg = TRUE;
}

void p11_chargebyenergy_dialog::on_pbtn_return_clicked()
{
    hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

void p11_chargebyenergy_dialog::on_pbtn_sure_clicked()
{
    elec_energy_temp = atof(energy_number);
    if(elec_energy_temp<0 || elec_energy_temp>100)
    {
        energy_err_flg = TRUE;
        energy_number_write = 0;
        memset(energy_number,0,sizeof(energy_number));
        return;
    }

    UINT8 data = elec_energy_temp;
    //ErrMsg("$$$$$$[%d]\n",data);
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_ENERGY_TYPE,(INT8 *)(&data),sizeof(data));

    hmi_page_index = PAGEINDEX_CHARGELINK;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}





