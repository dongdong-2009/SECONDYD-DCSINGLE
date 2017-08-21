#include "globalhmi.h"

int Inibuf_init ( char* storebuf,int storebuf_len,const char* setvalue )
{
	int minlen=0;
	int setvaluelen=0;
	if ( storebuf==NULL||storebuf_len==0 )
	{
		return FALSE;
	}
	memset ( storebuf,0,storebuf_len );
	setvaluelen=strlen ( setvalue );
	minlen= ( storebuf_len<setvaluelen ) ?storebuf_len:setvaluelen;
	memcpy ( storebuf,setvalue,minlen );
	return TRUE;
}

void timedelay_msec ( unsigned int msec )
{
	QTime dieTime = QTime::currentTime().addMSecs ( msec );
	while ( QTime::currentTime() < dieTime )
	{
		QCoreApplication::processEvents ( QEventLoop::AllEvents, 100 );
	}

}


class main_dialog*                    main_dlg;
class p02_qrcode_dialog*              p02_dlg;          //
class p03_chargelink_dialog*          p03_dlg;          //
class p04_chargestart_dialog*         p04_dlg;          //
class p05_chargeinfo_dialog*          p05_dlg;          //
class p06_chargeoff_dialog*           p06_dlg;          //

class p07_swingcard_dialog*           p07_dlg;          //
class p08_carpasswd_dialog*           p08_dlg;          //
class p09_chargetypechoose_dialog*    p09_dlg;          //
class p10_chargebytime_dialog*        p10_dlg;          //
class p11_chargebyenergy_dialog*      p11_dlg;          //
class p12_cardpayoff_dialog*          p12_dlg;          //
class p13_cardunlock_dialog*          p13_dlg;          //

class p14_deviceinfo_dialog*          p14_dlg;          //
class p15_chargeprice_dialog*         p15_dlg;          //
class p16_othersevices_dialog*        p16_dlg;          //
class p17_appdownload_dialog*         p17_dlg;          //
class p18_cardinquery_dialog*         p18_dlg;          //

class p19_setpara_passwd_dialog*      p19_dlg;          //
class p20_setpara_sub1_dialog*        p20_dlg;          //
class p21_setpara_sub2_dialog*        p21_dlg;          //
class p22_setpara_sub3_dialog*        p22_dlg;          //
class p23_setpara_sub4_dialog*        p23_dlg;          //
class p24_service_choose_dialog*      p24_dlg;
class p25_setpara_sub5_dialog*        p25_dlg;
class p26_setpara_sub6_dialog*        p26_dlg;
class p27_setpara_sub7_dialog*        p27_dlg;
class p28_chargebymoney_dialog*       p28_dlg;

class dialog_carnumber*               carnumber_dlg;            //
class dialog_diff_card*               diff_card_dlg;            //
class dialog_deviceerror*             deviceerror_dlg;          //
class dialog_order*                   order_dlg;                //
class dialog_carderr_reason*          carderr_reason_dlg;       //
class dialog_endword*                 endword_dlg;              //
class dialog_chargerecode*            chargerecode_dlg;        //

class dialog_fail_start_reason*       fail_start_reason_dlg;
class dialog_local_charge_recode*     local_charge_recode_dlg;
class dialog_remote_unload_recode*    remote_unload_recode_dlg;

class dialog_module_monitor*          module_monitor_dlg;
class dialog_module_err_info*         module_err_info_dlg;
class dialog_module_output*           module_output_dlg;

class dialog_swingcard_err*           swingcard_err_dlg;
class dialog_wait_swingcard *         wait_swingcard_dlg;
class dialog_stoping_stub*            stoping_stub_dlg;

class dialog_waiting_payoff*          waiting_payoff_dlg;
class dialog_quit_success *           quit_success_dlg;
class dialog_net_err*                 net_err_dlg;

INT8     hmilev  = HMI_LOG_LEV;
void     ( *API_DB_Initial ) ();
INT16    ( *API_Read_DB_Nbyte ) ( UINT32 label,void* Data,UINT16 n );
INT16    ( *API_Write_DB_Nbyte ) ( UINT32 label,void* Data,UINT16 n );

int      language_num = 1;

UINT8    hmi_page_index;
UINT8    hmi_button_dn_num = 0;

char     Section_name[BUFFERLEN_32];
char     Key_name[BUFFERLEN_32];
char     Tempor_name[256];

char     Set_paswd[17];
char     phonenum[25];
char     phonenum_2[25];
char     code[25];
char     websize[100];
char     appdownloadas[100];


INT8     main_card_sn[16+1] = {0};

const char*   config_path="/usr/config/syssetting.ini";



