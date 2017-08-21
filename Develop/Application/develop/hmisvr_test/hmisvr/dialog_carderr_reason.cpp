#include "dialog_carderr_reason.h"
#include "ui_dialog_carderr_reason.h"
#include "globalhmi.h"

dialog_carderr_reason::dialog_carderr_reason(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_carderr_reason)
{
    ui->setupUi(this);
}

dialog_carderr_reason::~dialog_carderr_reason()
{
    delete ui;
}


void dialog_carderr_reason::changeEvent(QEvent *e)
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

void dialog_carderr_reason::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
}


void dialog_carderr_reason::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_carderr_reason::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void dialog_carderr_reason::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

char err_flag = 0;
void dialog_carderr_reason::update_page_info()
{
   if(language_num == 1)
    {
         API_Read_DB_Nbyte(PL_CARD_UNUSE_FLAG,&err_flag,sizeof(err_flag));
         switch(err_flag)
         {
             case 1:
                ui->label_check->setText(QString::fromUtf8("ÍøÂç̉́³£"));
                break;
             case 2:
                ui->label_check->setText(QString::fromUtf8("¸Ă¿¨Î̃È¨Ï̃"));
                break;
             case 3:
                ui->label_check->setText(QString::fromUtf8("¼øÈ¨³¬Ê±"));
                break;
             case 4:
                ui->label_check->setText(QString::fromUtf8("Óà¶î²»×ă"));
                break;
             case 5:
                ui->label_check->setText(QString::fromUtf8("´æÔÚÎ´½áƠË¼ÇÂ¼"));
                break;
             case 6:
                ui->label_check->setText(QString::fromUtf8("×®Í£ÓĂ"));
                break;
             default:
                ui->label_check->setText(QString::fromUtf8("ƠưÔÚÑéÖ¤,ÇëÉÔº̣"));
                break;

         }
    }
    else  if(language_num == 2)
    {
          ui->label_check->setText("Please waiting for checking the card");
    }
    else
    {

    }
}

void dialog_carderr_reason::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_CARDERRREASON)
    {
        exit_page_dlg();
    }
    else
    {

    }

}

void dialog_carderr_reason::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg();

    //delete carderr_reason_dlg;
    //carderr_reason_dlg = NULL;
}

void dialog_carderr_reason::on_ptn_return_clicked()
{
    hmi_page_index = PAGEINDEX_SWINGCARD;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
}
