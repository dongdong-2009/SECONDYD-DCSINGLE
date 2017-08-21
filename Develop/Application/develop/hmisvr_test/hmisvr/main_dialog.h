#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>

namespace Ui
{
class main_dialog;
}

class main_dialog : public QDialog
{
	Q_OBJECT

  public:
	explicit main_dialog ( QWidget* parent = 0 );
	~main_dialog();

  protected:
	void changeEvent ( QEvent* e );

  private:
	Ui::main_dialog* ui;

	QTimer* timer;
	QTimer* timer_ss1;
	QTimer* timer_ss2;

	void init_main_dlg ( void );
	void init_database ( void );
	void check_hmi_page_index ( void );

  private slots:

	void timer_handle ( void );
	void start_timer ( void );
	//void on_pbtn_language_clicked();
	//void on_pbtn_setpara_clicked();

	//void call_p01_dlg(void);
	void call_p02_dlg ( void );
	void call_p03_dlg ( void );
	void call_p04_dlg ( void );
	void call_p05_dlg ( void );
	void call_p06_dlg ( void );

	void call_p07_dlg ( void );
	void call_p08_dlg ( void );
	void call_p09_dlg ( void );
	void call_p10_dlg ( void );
	void call_p11_dlg ( void );
	void call_p12_dlg ( void );
	void call_p13_dlg ( void );

	void call_p14_dlg ( void );
	void call_p15_dlg ( void );
	void call_p16_dlg ( void );
	void call_p17_dlg ( void );
	void call_p18_dlg ( void );

	void call_p19_dlg ( void );
	void call_p20_dlg ( void );
	void call_p21_dlg ( void );
	void call_p22_dlg ( void );
	void call_p23_dlg ( void );

	void call_p24_dlg ( void );
	void call_p25_dlg ( void );
	void call_p26_dlg ( void );
	void call_p27_dlg ( void );
	void call_p28_dlg ( void );

	void call_carnumber_dlg ( void );
	void call_diff_card_dlg();
	void call_deviceerror_dlg ( void );
	void call_order_dlg ( void );
	void call_carderr_reason_dlg ( void );
	void call_endword_dlg();
	void call_chargerecode_dlg();

	void call_fail_start_reason_dlg();
	void call_local_charge_recode_dlg ( void );
	void call_remote_unload_recode_dlg ( void );

	void call_module_monitor_dlg ( void );
	void call_module_err_info_dlg();
	void call_module_output_dlg();

    void call_swingcard_err_dlg();
	void call_wait_swingcard_dlg ( void );
	void call_stoping_stub_dlg ( void );

	void call_waiting_payoff_dlg ( void );
	void call_quit_success_dlg();
	void call_net_err_dlg();
	/*
	    void call_dlg_2(void);
	    void cal_dlg_01();
	    void call_err_dlg(void);
	    void call_book_dlg(void);
	    void call_money_left_dlg(void);
	    void call_link_err_dlg();
	    void call_end_dlg();
	    void call_firsterr_dlg();
	    void call_diff_card_dlg();
	    void call_pull_gun();
	    void call_back(void);
	    void call_history_dlg();
	    void call_checkcard_dlg(void);
	    void call_his_choose_dlg();
	    void call_passwd_app_dlg();
	    void call_carnum_dlg();
	    void call_charcheck_dlg();
	    void call_handset_dlg();
	    void call_moudle_output_dlg();
	    void call_moudle_err_dlg();
	    void call_contactor_choose_dlg();

	*/


	void on_pbtn_card_inquiry_clicked();

	//  void on_pbtn_qrcode_charge_clicked();

	void on_pbtn_card_charge_clicked();

	void on_pbtn_card_unlock_clicked();

	void on_pbtn_device_info_clicked();

	void on_pbtn_charge_price_clicked();

	void on_pbtn_app_download_clicked();

	void on_pbtn_setpara_clicked();

	void setframe_screensr1_up();

	void setframe_screensr2_up();

    void on_pbtn_screensaver1_clicked();

    void on_pbtn_screensaver2_clicked();

  signals:
	void signal_enable_p01dlg_timer();
	void signal_enable_p02dlg_timer();
	void signal_enable_p03dlg_timer();
	void signal_enable_p04dlg_timer();
	void signal_enable_p05dlg_timer();
	void signal_enable_p06dlg_timer();
	void signal_enable_p07dlg_timer();
	void signal_enable_p08dlg_timer();
	void signal_enable_p09dlg_timer();
	void signal_enable_p10dlg_timer();

	void signal_enable_p11dlg_timer();
	void signal_enable_p12dlg_timer();
	void signal_enable_p13dlg_timer();
	void signal_enable_p14dlg_timer();
	void signal_enable_p15dlg_timer();
	void signal_enable_p16dlg_timer();
	void signal_enable_p17dlg_timer();
	void signal_enable_p18dlg_timer();
	void signal_enable_p19dlg_timer();
	void signal_enable_p20dlg_timer();

	void signal_enable_p21dlg_timer();
	void signal_enable_p22dlg_timer();
	void signal_enable_p23dlg_timer();
	void signal_enable_p24dlg_timer();
	void signal_enable_p25dlg_timer();
	void signal_enable_p26dlg_timer();
	void signal_enable_p27dlg_timer();
	void signal_enable_p28dlg_timer();

	void signal_enable_cardnumber_timer();
	void signal_enable_diffcard_timer();
	void signal_enable_deviceerror_timer();
	void signal_enable_order_timer();
	void signal_enable_carderr_reason_timer();
	void signal_enable_endword_timer();
	void signal_enable_chargerecode_timer();

	void signal_enable_failstart_timer();
	void signal_enable_localcharge_timer();
	void signal_enable_remotecharge_timer();

	void signal_enable_modulemonitor_timer();
	void signal_enable_moduleerr_timer();
	void signal_enable_moduleout_timer();

    void signal_enable_swingcard_err_timer();
	void signal_enable_wait_swingcard_timer();
	void signal_enable_stoping_stub_timer();

	void signal_enable_waiting_payoff_timer();
	void signal_enable_quit_success_timer();
	void signal_enable_net_err_timer();
	/*
	    void signal_enable_money_left_timer();

	    void signal_enable_p24dlg_timer();
	    void signal_enable_p25dlg_timer();
	    void signal_enable_p21dlg_timer();
	    void signal_enable_dlg01_timer();
	    void signal_enable_dlg_2_timer();
	    void signal_enable_err_timer();
	    void signal_enable_book_timer();
	    void signal_enable_link_err_timer();
	    void signal_enable_end_timer();
	    void signal_enable_firsterr_timer();
	    void signal_enable_diff_card_timer();
	    void signal_enable_checkcard_timer();
	    void signal_enable_pull_gun_timer();
	    void signal_enable_back_timer();
	    void signal_enable_historydlg_timer();
	    void signal_enable_his_choose_timer();
	    void signal_enable_passwd_app_timer();
	    void signal_enable_carnum_timer();
	    void signal_enable_listen_timer();
	    void signal_enable_handset_timer();
	    void signal_enable_moudle_err_timer();
	    void signal_enable_moudle_output_timer();
	    void signal_enable_contactor_choose_timer();
	*/
};

#endif // MAIN_DIALOG_H
