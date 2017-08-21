/* filename.c(.cpp)/.h(.hpp)
** 文件功能简述
**
** 错误反馈：andy2003du1984@163.com
**
** 作者：
**	杜鹏(Andrew)	07/06/2013
**	商业软件，保留一切权利
** 修改：
**
** 中国合浦新能源有限公司(potevio) 07/06/2013
** http://www.potevio-sh.com
*/
#ifndef GUI_H_
#define GUI_H_

/*
 * button
 */



#define NO_BUTTON  	 		        (0)
#define CANCEL_BUTTON  	 		    (1)
#define OK_BUTTON   			    (2)
#define RETURN_BUTTON               (3)

#define CARD_INQUIRY_BUTTON         (4)
#define CARD_UNLOCK_BUTTON          (5)
#define DEVICE_INFO_BUTTON          (6)
#define CHARGE_PRICE_BUTTON         (7)
#define APP_DOWNLOAD_BUTTON         (8)
#define QRCODE_CHARGE_BUTTON        (9)
#define OTHER_SERVICE_BUTTON        (10)
#define SETPARA_BUTTON              (11)

#define CHARGE_MONITOR_BUTTON       (12)
#define BATTERY_INFO_BUTTON         (13)
#define STOP_CHARGE_BUTTON          (14)


/*
 * for WB  Test
 */

#define INS_BUTTON   (1)
#define OUT_BUTTON   (2)
#define DECT_BUTTON   (3)
#define DOOR_BUTTON   (4)
#define GUN_BUTTON   (5)

#define V12_BUTTON   (6)
#define V24_BUTTON   (7)
#define FAN_BUTTON   (8)
#define LED_BUTTON   (9)

#define ERR_BUTTON   (10)
#define IDEL_BUTTON   (11)
#define RUN_BUTTON   (12)
#define GO_BUTTON   (13)

/*
 * page
 */
#define PAGEINDEX_MAIN     		(0)
//#define PAGEINDEX_PASSWD 		(1)
#define PAGEINDEX_QRCODE        		(2)
#define PAGEINDEX_CHARGELINK     	    (3)
#define PAGEINDEX_CHARGESTART		    (4)
#define PAGEINDEX_CHARGEINFO          	(5)
#define PAGEINDEX_CHARGEOFF          	(6)

#define PAGEINDEX_SWINGCARD	            (7)
#define PAGEINDEX_CARDPASSWD    		(8)
#define PAGEINDEX_CHARGETYPECHOOSE      (9)
#define PAGEINDEX_CHARGEBYTIME          (10)
#define PAGEINDEX_CHARGEBYENERGY		(11)
#define PAGEINDEX_CARDPAYOFF    		(12)
#define PAGEINDEX_CARDUNLOCK           	(13)

#define PAGEINDEX_DEVICEINFO            (14)
#define PAGEINDEX_CHARGEPRICE           (15)
#define PAGEINDEX_OTHERSEVICES          (16)
#define PAGEINDEX_APPDOWNLOAD           (17)
#define PAGEINDEX_CARDINQUERY        	(18)

#define PAGEINDEX_SETPARAPASSWD       	(19)
#define PAGEINDEX_SETPARASUB1           (20)
#define PAGEINDEX_SETPARASUB2		    (21)
#define PAGEINDEX_SETPARASUB3			(22)
#define PAGEINDEX_SETPARASUB4		    (23)
#define PAGEINDEX_SETPARASUB5           (24)
#define PAGEINDEX_SETPARASUB6           (25)
#define PAGEINDEX_SETPARASUB7           (26)
#define PAGEINDEX_CHARGEBYMONEY         (27)

#define PAGEINDEX_CARDNUMBER 		    (30)
#define PAGEINDEX_DIFFCARD              (31)
#define PAGEINDEX_DEVICEERROR			(32)
#define PAGEINDEX_ORDER     			(33)
#define PAGEINDEX_CARDERRREASON			(34)
#define PAGEINDEX_ENDWORD               (35)
#define PAGEINDEX_CHARGERECODE          (36)

#define PAGEINDEX_SERVICECHOOSE         (37)

#define PAGEINDEX_FAIL_START_RESON       (38)
#define PAGEINDEX_LOCAL_CHARGE_RECODE    (39)
#define PAGEINDEX_REMOTE_UNLOAD_RECODE   (40)

#define PAGEINDEX_MODULE_MONITOR         (41)
#define PAGEINDEX_MODULE_ERR_INFO        (42)
#define PAGEINDEX_MODULE_OUTPUT          (43)

#define PAGEINDEX_SWINGCARD_ERR          (44)
#define PAGEINDEX_WAIT_SWINGCARD         (45)
#define PAGEINDEX_STOPING_STUB           (46)
#define PAGEINDEX_WAITING_PAYOFF         (47)
#define PAGEINDEX_QUIT_SUCCESS           (48)

#define PAGEINDEX_NET_ERR                (49)
/*
#define PAGEINDEX_CHARGEBYHAND    (30)
#define PAGEINDEX_CHARGLISTEN    (31)
#define PAGEINDEX_MOUDLEERR    (32)
#define PAGEINDEX_MOUDLEOUTPUT    (33)
#define PAGEINDEX_BOOKSERVICE    (34)

#define PAGEINDEX_JUDGE_CONTINUE    (35)
#define PAGEINDEX_CHARGELINK_ERR          	(36)
#define PAGEINDEX_END          	(37)
#define PAGEINDEX_DIFFERENT_CARD          	(38)
#define PAGEINDEX_PULLGUN          	(39)
#define PAGEINDEX_BACK          	(40)
#define PAGEINDEX_CHECKCARD          	(41)
#define PAGEINDEX_GUNSELECT          	(42)
#define PAGEINDEX_CHARINFOR           (43)
#define PAGEINDEX_HISTORY_NET           (44)
#define PAGEINDEX_FIRST_ERR           (45)
#define PAGEINDEX_HISTORY_CHOOSE (46)
#define PAGEINDEX_PASSWD_APP (47)
#define PAGEINDEX_CARNUM (48)
#define PAGEINDEX_CONTACTOR_CHOOSE (49)

#define PAGEINDEX_CHARGECHECK (50)
*/
#endif




