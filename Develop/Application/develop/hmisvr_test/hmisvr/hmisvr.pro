#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T20:53:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hmisvr
TEMPLATE = app


SOURCES += main.cpp\
        main_dialog.cpp \
    p03_chargelink_dialog.cpp \
    p04_chargestart_dialog.cpp \
    p05_chargeinfo_dialog.cpp \
    p06_chargeoff_dialog.cpp \
    p07_swingcard_dialog.cpp \
    p08_carpasswd_dialog.cpp \
    p09_chargetypechoose_dialog.cpp \
    p10_chargebytime_dialog.cpp \
    p11_chargebyenergy_dialog.cpp \
    p12_cardpayoff_dialog.cpp \
    p13_cardunlock_dialog.cpp \
    p14_deviceinfo_dialog.cpp \
    p15_chargeprice_dialog.cpp \
    p16_othersevices_dialog.cpp \
    p17_appdownload_dialog.cpp \
    p18_cardinquery_dialog.cpp \
    p19_setpara_passwd_dialog.cpp \
    p20_setpara_sub1_dialog.cpp \
    p21_setpara_sub2_dialog.cpp \
    p22_setpara_sub3_dialog.cpp \
    dialog_diff_card.cpp \
    dialog_deviceerror.cpp \
    dialog_order.cpp \
    dialog_carderr_reason.cpp \
    dialog_endword.cpp \
    dialog_chargerecode.cpp \
    dialog_carnumber.cpp \
    p23_setpara_sub4_dialog.cpp \
    p02_qrcode_dialog.cpp \
	globalhmi.cpp \ 
    p24_service_choose_dialog.cpp \
    dialog_remote_unload_recode.cpp \
    dialog_local_charge_recode.cpp \
    dialog_fail_start_reason.cpp \
    p25_setpara_sub5_dialog.cpp \
    p26_setpara_sub6_dialog.cpp \
    p27_setpara_sub7_dialog.cpp \
    p28_chargebymoney_dialog.cpp \
    dialog_module_monitor.cpp \
    dialog_module_err_info.cpp \
    dialog_module_output.cpp \
    dialog_swingcard_err.cpp \
    dialog_wait_swingcard.cpp \
    dialog_stoping_stub.cpp \
    dialog_waiting_payoff.cpp \
    dialog_quit_success.cpp \
    dialog_net_err.cpp

HEADERS  += main_dialog.h \
    p03_chargelink_dialog.h \
    p04_chargestart_dialog.h \
    p05_chargeinfo_dialog.h \
    p06_chargeoff_dialog.h \
    p07_swingcard_dialog.h \
    p08_carpasswd_dialog.h \
    p09_chargetypechoose_dialog.h \
    p10_chargebytime_dialog.h \
    p11_chargebyenergy_dialog.h \
    p12_cardpayoff_dialog.h \
    p13_cardunlock_dialog.h \
    p14_deviceinfo_dialog.h \
    p15_chargeprice_dialog.h \
    p16_othersevices_dialog.h \
    p17_appdownload_dialog.h \
    p18_cardinquery_dialog.h \
    p19_setpara_passwd_dialog.h \
    p20_setpara_sub1_dialog.h \
    p21_setpara_sub2_dialog.h \
    p22_setpara_sub3_dialog.h \
    dialog_diff_card.h \
    dialog_deviceerror.h \
    dialog_order.h \
    dialog_carderr_reason.h \
    dialog_endword.h \
    dialog_chargerecode.h \
    dialog_carnumber.h \
    p23_setpara_sub4_dialog.h \
    p02_qrcode_dialog.h \
	globalhmi.h \ 
    p24_service_choose_dialog.h \
    dialog_remote_unload_recode.h \
    dialog_local_charge_recode.h \
    dialog_fail_start_reason.h \
    p25_setpara_sub5_dialog.h \
    p26_setpara_sub6_dialog.h \
    p27_setpara_sub7_dialog.h \
    p28_chargebymoney_dialog.h \
    dialog_module_monitor.h \
    dialog_module_err_info.h \
    dialog_module_output.h \
    dialog_swingcard_err.h \
    dialog_wait_swingcard.h \
    dialog_stoping_stub.h \
    dialog_waiting_payoff.h \
    dialog_quit_success.h \
    dialog_net_err.h

FORMS    += main_dialog.ui \
    p03_chargelink_dialog.ui \
    p04_chargestart_dialog.ui \
    p05_chargeinfo_dialog.ui \
    p06_chargeoff_dialog.ui \
    p07_swingcard_dialog.ui \
    p08_carpasswd_dialog.ui \
    p09_chargetypechoose_dialog.ui \
    p10_chargebytime_dialog.ui \
    p11_chargebyenergy_dialog.ui \
    p12_cardpayoff_dialog.ui \
    p13_cardunlock_dialog.ui \
    p14_deviceinfo_dialog.ui \
    p15_chargeprice_dialog.ui \
    p16_othersevices_dialog.ui \
    p17_appdownload_dialog.ui \
    p18_cardinquery_dialog.ui \
    p19_setpara_passwd_dialog.ui \
    p20_setpara_sub1_dialog.ui \
    p21_setpara_sub2_dialog.ui \
    p22_setpara_sub3_dialog.ui \
    dialog_diff_card.ui \
    dialog_deviceerror.ui \
    dialog_order.ui \
    dialog_carderr_reason.ui \
    dialog_endword.ui \
    dialog_chargerecode.ui \
    dialog_carnumber.ui \
    p23_setpara_sub4_dialog.ui \
    p02_qrcode_dialog.ui \
    p24_service_choose_dialog.ui \
    dialog_remote_unload_recode.ui \
    dialog_local_charge_recode.ui \
    dialog_fail_start_reason.ui \
    p25_setpara_sub5_dialog.ui \
    p26_setpara_sub6_dialog.ui \
    p27_setpara_sub7_dialog.ui \
    p28_chargebymoney_dialog.ui \
    dialog_module_monitor.ui \
    dialog_module_err_info.ui \
    dialog_module_output.ui \
    dialog_swingcard_err.ui \
    dialog_wait_swingcard.ui \
    dialog_stoping_stub.ui \
    dialog_waiting_payoff.ui \
    dialog_quit_success.ui \
    dialog_net_err.ui

RESOURCES += \
    hmisvr.qrc
INCLUDEPATH += /usr/local/qwt-arm/include \
    $(SECONDYD_DCSINGLE_INC_RUNTIME_DIR)
LIBS += -L"/usr/local/qwt-arm/lib" \
    -L $(SECONDYD_DCSINGLE_LIB_RUNTIME_DIR)\
    -lsem \
    -linireadwrite \
    -ldl

    
