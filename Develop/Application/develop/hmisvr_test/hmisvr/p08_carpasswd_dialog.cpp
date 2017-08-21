#include "p08_carpasswd_dialog.h"
#include "ui_p08_carpasswd_dialog.h"
#include "globalhmi.h"

p08_carpasswd_dialog::p08_carpasswd_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p08_carpasswd_dialog)
{
    ui->setupUi(this);
}

p08_carpasswd_dialog::~p08_carpasswd_dialog()
{
    delete ui;
}

#define DISPLAY_PASSWD                  //make the passwd visible user input;
static UINT8 passwd_diplaytype_num;
//static UINT8 passwd_true = 0;
//static char err_flag = 0;

void p08_carpasswd_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    number_press();
}

void p08_carpasswd_dialog::init_page_val()
{
    card_passwd_write = 0;
    memset(card_passwd,0,sizeof(card_passwd));

    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p08_carpasswd_dialog::number_press()
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
    // array[12] = ui->pbtn_go;
    // array[13] = ui->pbtn_ok;

    int num = 0;
    for(num = 0; num < 12;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/new/prefix/pic_resource/otherwidget/number_press.png);}\
                                  QPushButton:pressed{border-image: url(:/new/prefix/pic_resource/otherwidget/number.png);}");
    }

}

void p08_carpasswd_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}

void p08_carpasswd_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p08_carpasswd_dialog::update_page_info()
{
    ui->label_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->label_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

    //passwd information display
    DebugMsg(hmilev,8,"card_passwd[%s][%d]\n",card_passwd,card_passwd_write);
    memset(card_passwd_display,0,sizeof(card_passwd_display));
    #ifdef DISPLAY_PASSWD
    strcpy(card_passwd_display,card_passwd);
    #else
    memset(card_passwd_display,'*',card_passwd_write);
    #endif
    ui->label_passwd->setText(card_passwd_display);

    //card detailed information
    BOOL get_maincard_flag = FALSE;
    float leftmoney = 0;
    API_Read_DB_Nbyte(PL_GETMAINCARD_FLAG,(INT8 *)(&get_maincard_flag),sizeof(get_maincard_flag));
    if(get_maincard_flag==TRUE)
    {
        API_Read_DB_Nbyte(PL_MAINCARD_SN,(INT8 *)(&main_card_sn),sizeof(main_card_sn));
        //ui->label_card_num->setText(main_card_sn);
        // ErrMsg("$$$$$$$$$[%s]\n",main_card_sn);

        API_Read_DB_Nbyte(PL_MAINCARD_LEFTMONEY,&leftmoney,sizeof(leftmoney));
        //ui->label_money->setText(QString::number(leftmoney,'f',2));
    }

    if(language_num == 1)
    {
        //API_Read_DB_Nbyte(PL_Account_Money_use_FLAG,(char*)&error_value,sizeof(error_value));
    }
    else  if(language_num == 2)
    {

    }
    else
    {

    }

}

void p08_carpasswd_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CARDPASSWD)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p08_carpasswd_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p08dlg();
    //delete p08_dlg;
    //p08_dlg = NULL;
}

void p08_carpasswd_dialog::on_pbtn_num0_clicked()
{
    if( card_passwd_write >=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='0';
    }
}

void p08_carpasswd_dialog::on_pbtn_num1_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='1';
    }
    //ErrMsg(card_passwd);
}

void p08_carpasswd_dialog::on_pbtn_num2_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='2';
    }
}

void p08_carpasswd_dialog::on_pbtn_num3_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='3';
    }
}

void p08_carpasswd_dialog::on_pbtn_num4_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='4';
    }
}

void p08_carpasswd_dialog::on_pbtn_num5_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='5';
    }
}

void p08_carpasswd_dialog::on_pbtn_num6_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='6';
    }
}

void p08_carpasswd_dialog::on_pbtn_num7_clicked()
{

    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='7';
    }
}

void p08_carpasswd_dialog::on_pbtn_num8_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='8';
    }
}

void p08_carpasswd_dialog::on_pbtn_num9_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='9';
    }
}

void p08_carpasswd_dialog::on_pbtn_dot_clicked()
{
    if(card_passwd_write>=MAX_PASSWD_LEN)
    {
        card_passwd_write=MAX_PASSWD_LEN;
    }else{
        card_passwd[card_passwd_write++]='.';
    }
}

void p08_carpasswd_dialog::on_pbtn_delete_clicked()
{
    if(card_passwd_write>0)
    {
        card_passwd_write--;
        card_passwd[card_passwd_write]=0;
    }
    else
    {
        card_passwd_write=0;
    }
}

void p08_carpasswd_dialog::on_pbtn_return_clicked()
{
    hmi_page_index = PAGEINDEX_SWINGCARD;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}

int p08_carpasswd_dialog::judge_passwd_NULL()
{
    if(0 == card_passwd_write)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void p08_carpasswd_dialog::on_pbtn_sure_clicked()
{
    if(passwd_diplaytype_num == judge_passwd_NULL())
    {

    }
    else
    {
        hmi_page_index = PAGEINDEX_CHARGETYPECHOOSE;
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    }
}


