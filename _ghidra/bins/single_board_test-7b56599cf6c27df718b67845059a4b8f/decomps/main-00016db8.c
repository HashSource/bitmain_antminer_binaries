
/* WARNING: Removing unreachable block (ram,0x00017930) */

int32_t main(int argc,char **argv)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  undefined1 uVar6;
  byte bVar7;
  int32_t iVar8;
  uint uVar9;
  char *pcVar10;
  bool bVar11;
  char **argv_local;
  int argc_local;
  char time_stamp_27 [48];
  char response_msg [100];
  char time_stamp [48];
  char tmp1 [256];
  char lcd_data_17 [16];
  char lcd_data_16 [16];
  char board_sn_8 [20];
  char lcd_data_15 [16];
  char lcd_data_14 [16];
  char board_sn_7 [20];
  char lcd_data_13 [16];
  char lcd_data_12 [16];
  char board_sn_6 [20];
  char lcd_data_11 [16];
  char lcd_data_10 [16];
  char board_sn_5 [20];
  char lcd_data_9 [16];
  char lcd_data_8 [16];
  char board_sn_4 [20];
  char lcd_data_7 [16];
  char lcd_data_6 [16];
  char board_sn_3 [20];
  char lcd_data_5 [16];
  char lcd_data_4 [16];
  char board_sn_2 [20];
  char lcd_data_3 [16];
  char lcd_data_2 [16];
  char board_sn_1 [20];
  char lcd_data_1 [16];
  char lcd_data [16];
  char board_sn [20];
  uint32_t fpgaval;
  sigaction sa;
  sigaction handler;
  _Bool is_pt1_8;
  int _send_result__8;
  int error_info_8;
  int error_no_8;
  int _result__8;
  _Bool is_pt1_7;
  int _send_result__7;
  int error_info_7;
  int error_no_7;
  int _result__7;
  _Bool is_pt1_6;
  int _send_result__6;
  int error_info_6;
  int error_no_6;
  int _result__6;
  _Bool is_pt1_5;
  int _send_result__5;
  int error_info_5;
  int error_no_5;
  int _result__5;
  _Bool is_pt1_4;
  int _send_result__4;
  int error_info_4;
  int error_no_4;
  int _result__4;
  _Bool is_pt1_3;
  int _send_result__3;
  int error_info_3;
  int error_no_3;
  int _result__3;
  _Bool is_pt1_2;
  int _send_result__2;
  int error_info_2;
  int error_no_2;
  int _result__2;
  _Bool is_pt1_1;
  int _send_result__1;
  int error_info_1;
  int error_no_1;
  int _result__1;
  _Bool is_pt1;
  int _send_result_;
  int error_info;
  int error_no;
  int _result_;
  uint32_t i;
  _Bool ret;
  
  handler.sa_flags = 0;
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x16b39;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  sigaction(0xb,(sigaction *)&handler,(sigaction *)&crashhandler);
  sigaction(4,(sigaction *)&handler,(sigaction *)&crashhandler);
  sigaction(8,(sigaction *)&handler,(sigaction *)&crashhandler);
  sa.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x16b25;
  sigemptyset((sigset_t *)&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(0xd,(sigaction *)&sa,(sigaction *)0x0);
  iVar3 = access("/mnt/card",0);
  if (iVar3 != 0) {
    system("rm -r /mnt");
    system("ln -s /tmp  /mnt");
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : build version information::  %s.\n\n","main",
         "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
        );
  snprintf(tmp1,0x100,"build version information::  %s.\n",
           "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
          );
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : author information::  %s.\n\n","main",
         "author: harlay      email: harlay.liu@bitmain.com");
  snprintf(tmp1,0x100,"author information::  %s.\n",
           "author: harlay      email: harlay.liu@bitmain.com");
  log_to_file(tmp1,time_stamp);
  if (argc == 2) {
    g_user_chain = atoi(argv[1]);
    printf("force to use chain %d\n",g_user_chain);
    if (3 < g_user_chain) {
      if (g_user_chain == 0x70) {
        create_midstate_bin();
      }
      printf("chain ID error, should < 3");
      return -1;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : user chain ID %d\n","main",g_user_chain);
    snprintf(tmp1,0x100,"user chain ID %d",g_user_chain);
    log_to_file(tmp1,time_stamp);
  }
  if (2 < argc) {
    g_user_chain = atoi(argv[1]);
    memset(&g_pt1,0,0xb0);
    if (3 < argc) {
      pcVar10 = argv[3];
      sVar4 = strlen(argv[3]);
      memcpy(g_pt1.board_sn,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input board_sn %s\n","main",0xa296a8);
      snprintf(tmp1,0x100,"input board_sn %s",0xa296a8);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[4];
      sVar4 = strlen(argv[4]);
      memcpy(g_pt1.chip_die,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input chip_die %s\n","main",0xa2963c);
      snprintf(tmp1,0x100,"input chip_die %s",0xa2963c);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[5];
      sVar4 = strlen(argv[5]);
      memcpy(g_pt1.chip_marking,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input chip_marking %s\n","main",0xa2964c);
      snprintf(tmp1,0x100,"input chip_marking %s",0xa2964c);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[6];
      sVar4 = strlen(argv[6]);
      memcpy(g_pt1.chip_ftversion,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input chip_ftversion %s\n","main",0xa2965c);
      snprintf(tmp1,0x100,"input chip_ftversion %s",0xa2965c);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[7];
      sVar4 = strlen(argv[7]);
      memcpy(g_pt1.chip_tech,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input chip_tech %s\n","main",0xa2969c);
      snprintf(tmp1,0x100,"input chip_tech %s",0xa2969c);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[8];
      sVar4 = strlen(argv[8]);
      memcpy(g_pt1.board_name,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input board_name %s\n","main",0xa2969f);
      snprintf(tmp1,0x100,"input board_name %s",0xa2969f);
      log_to_file(tmp1,time_stamp);
      pcVar10 = argv[9];
      sVar4 = strlen(argv[9]);
      memcpy(&g_pt1,pcVar10,sVar4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input factory_job %s\n","main",&g_pt1);
      snprintf(tmp1,0x100,"input factory_job %s",&g_pt1);
      log_to_file(tmp1,time_stamp);
      g_pt1.chip_bin = atoi(argv[10]);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input chip_bin %d\n","main",g_pt1.chip_bin);
      snprintf(tmp1,0x100,"input chip_bin %d",g_pt1.chip_bin);
      log_to_file(tmp1,time_stamp);
    }
  }
  start_upload_logs();
  fpgaval = 0;
  fpga_read(0,&fpgaval);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : FPGA hardware ver:%x\n","main",fpgaval);
  snprintf(tmp1,0x100,"FPGA hardware ver:%x",fpgaval);
  log_to_file(tmp1,time_stamp);
  _Var2 = prepare_platform_environment();
  if (_Var2) {
    _Var2 = prepare_local_config_information();
    if (_Var2) {
      _Var2 = prepare_pattern();
      if (_Var2) {
        iVar3 = strncmp(Local_Config_Information->Test_Process,"PT2",3);
        if (((iVar3 == 0) ||
            (iVar3 = strncmp(Local_Config_Information->Test_Process,"PT3",3), iVar3 == 0)) ||
           (iVar3 = strncmp(Local_Config_Information->Test_Process,"SWEEP",5), iVar3 == 0)) {
          _Var2 = fan_protect_check();
          if (!_Var2) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : pt2 test,fan speed err,exit.\n","main");
            builtin_strncpy(tmp1,"pt2 test,fan speed err,exit.",0x1c);
            tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
            log_to_file(tmp1,time_stamp);
            return 0;
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : fan speed ok.\n","main");
          builtin_strncpy(tmp1,"fan speed ok",0xc);
          tmp1[0xc] = '.';
          tmp1[0xd] = '\0';
          log_to_file(tmp1,time_stamp);
        }
        bitmain_power_off();
        lcd_common_show("Read Power Ver",(char *)0x0,(char *)0x0);
        g_apw_power_version = bitmain_power_version();
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : g_apw_power_version:%d\n","main",g_apw_power_version);
        snprintf(tmp1,0x100,"g_apw_power_version:%d",g_apw_power_version);
        log_to_file(tmp1,time_stamp);
        if (g_apw_power_version == 0) {
          lcd_common_show("Power version","err",(char *)0x0);
          bitmain_power_off();
          iVar8 = 0xc;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : enable power calibration.\n","main");
          builtin_strncpy(tmp1,"enable power calibration.",0x1a);
          log_to_file(tmp1,time_stamp);
          _Var2 = enable_power_calibration();
          if (!_Var2) {
            lcd_common_show("Power is not","calibrated",(char *)0x0);
            iVar3 = strcmp(Local_Config_Information->Test_Process,"PT2");
            if (((iVar3 == 0) ||
                (iVar3 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar3 == 0)) ||
               (iVar3 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar3 == 0)) {
              bitmain_power_off();
              return 0xc;
            }
          }
          bitmain_power_off();
          _Var2 = prepare_test_process();
          if (_Var2) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : prepare_test_process\n","main");
            builtin_strncpy(tmp1,"prepare_test_process",0x14);
            tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
            log_to_file(tmp1,time_stamp);
            save_software_commit_id();
            bitmain_power_off();
            do {
              if (((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun != true) &&
                 (gFind_test_standard != true)) {
                gScanCodeGun_data_ready = '\x03';
                iVar3 = strcmp(Local_Config_Information->Test_Process,"PT2");
                if (((iVar3 == 0) ||
                    (((iVar3 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar3 == 0 ||
                      (iVar3 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar3 == 0))
                     || (iVar3 = strcmp(Local_Config_Information->Test_Process,"DropLevel"),
                        iVar3 == 0)))) &&
                   ((Local_Config_Information->Test_Info).Factory_Mode != false)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Customer repair mode, use level stored in eeprom\n","main");
                  builtin_strncpy(tmp1,"Customer repair mode, use level stored in eeprom",0x30);
                  tmp1._48_2_ = tmp1._48_2_ & 0xff00;
                  log_to_file(tmp1,time_stamp);
                }
                print_local_config_after_parse_MES_system_information();
                gFind_test_standard = true;
                lcd_common_show("Find test std","Insert Board","Press Start Key");
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : found test standard, Press Start Key to Begin Test\n","main");
                builtin_strncpy(tmp1,"found test standard, Press Start Key to Begin Te",0x30);
                tmp1[0x30] = 's';
                tmp1[0x31] = 't';
                tmp1[0x32] = '\0';
                log_to_file(tmp1,time_stamp);
              }
              iVar8 = read_ipreport_key_val();
              if (iVar8 == 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : got user input \n","main");
                builtin_strncpy(tmp1,"got user input ",0x10);
                log_to_file(tmp1,time_stamp);
                lcd_clear_result();
                lcd_show(0,"Start Test");
                g_droplevel = false;
                while (_Var2 = check_chain(), !_Var2) {
                  lcd_clear_result();
                  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                  lcd_show(1,"No Hashboard");
                  lcd_show(2,"Insert Board 1st");
                  lcd_show(3,"Press Start Key");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Didn\'t detect hashboard\n","main");
                  builtin_strncpy(tmp1,"Didn\'t detect hashboard",0x18);
                  log_to_file(tmp1,time_stamp);
                  do {
                    iVar8 = read_ipreport_key_val();
                  } while (iVar8 != 0);
                }
                gScanCodeGun_data_ready = '\0';
                gFind_test_standard = false;
                _Var2 = read_board_info_from_eeprom();
                if (_Var2) {
                  print_local_config_after_parse_MES_system_information();
                  gFind_test_standard = true;
                  lcd_common_show("Find test","standard","Press Start Key");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : found test standard, Press Start Key to Begin Test\n","main");
                  builtin_strncpy(tmp1,"found test standard, Press Start Key to Begin Te",0x30);
                  tmp1[0x30] = 's';
                  tmp1[0x31] = 't';
                  tmp1[0x32] = '\0';
                  log_to_file(tmp1,time_stamp);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : build version information::  %s.\n\n","main",
                         "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
                        );
                  snprintf(tmp1,0x100,"build version information::  %s.\n",
                           "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
                          );
                  log_to_file(tmp1,time_stamp);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : author information::  %s.\n\n","main",
                         "author: harlay      email: harlay.liu@bitmain.com");
                  snprintf(tmp1,0x100,"author information::  %s.\n",
                           "author: harlay      email: harlay.liu@bitmain.com");
                  log_to_file(tmp1,time_stamp);
                  set_env_temp(0xffff);
                  iVar3 = strcmp(Local_Config_Information->Test_Process,"PT1");
                  if (iVar3 == 0) {
                    memset(response_msg,0,100);
                    memset(time_stamp,0,100);
                    board_sn[0] = '\0';
                    board_sn[1] = '\0';
                    board_sn[2] = '\0';
                    board_sn[3] = '\0';
                    board_sn[4] = '\0';
                    board_sn[5] = '\0';
                    board_sn[6] = '\0';
                    board_sn[7] = '\0';
                    board_sn[8] = '\0';
                    board_sn[9] = '\0';
                    board_sn[10] = '\0';
                    board_sn[0xb] = '\0';
                    board_sn[0xc] = '\0';
                    board_sn[0xd] = '\0';
                    board_sn[0xe] = '\0';
                    board_sn[0xf] = '\0';
                    board_sn[0x10] = '\0';
                    board_sn[0x11] = '\0';
                    board_sn[0x12] = '\0';
                    board_sn[0x13] = '\0';
                    strncpy(board_sn,sn.board_sn,0x14);
                    iVar3 = get_pt1_test_permission(board_sn,response_msg);
                    if (iVar3 == 0) {
                      uVar5 = Single_Board_PT1_Test();
                      memset(time_stamp,0,100);
                      memset(response_msg,0,100);
                      uVar9 = uVar5;
                      if (uVar5 == 0) {
                        uVar9 = 1;
                      }
                      uVar6 = (undefined1)uVar9;
                      if (uVar5 != 0) {
                        uVar6 = false;
                      }
                      iVar3 = send_pt1_test_result
                                        (board_sn,(_Bool)uVar6,uVar5 & 0xff,
                                         (int)(uVar5 & 0xff00) >> 8,time_stamp,response_msg);
                      if (iVar3 == 0) {
                        print_time_stamp(time_stamp_27,0x30);
                        printf("%s ",time_stamp_27);
                        uVar9 = uVar5;
                        if (uVar5 == 0) {
                          uVar9 = 1;
                        }
                        bVar7 = (byte)uVar9;
                        if (uVar5 != 0) {
                          bVar7 = 0;
                        }
                        printf("%s : SN:%s %s result:%d send ok to mes\n","main",board_sn,
                               &DAT_001e21e0,(uint)bVar7);
                        bVar11 = uVar5 == 0;
                        if (bVar11) {
                          uVar5 = 1;
                        }
                        bVar7 = (byte)uVar5;
                        if (!bVar11) {
                          bVar7 = 0;
                        }
                        snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn,
                                 &DAT_001e21e0,(uint)bVar7);
                        log_to_file(tmp1,time_stamp_27);
                      }
                      else if (iVar3 != 0x1234) {
                        print_time_stamp(time_stamp_27,0x30);
                        printf("%s ",time_stamp_27);
                        uVar9 = uVar5;
                        if (uVar5 == 0) {
                          uVar9 = 1;
                        }
                        bVar7 = (byte)uVar9;
                        if (uVar5 != 0) {
                          bVar7 = 0;
                        }
                        printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n",
                               "main",board_sn,&DAT_001e21e0,(uint)bVar7,response_msg);
                        bVar11 = uVar5 == 0;
                        if (bVar11) {
                          uVar5 = 1;
                        }
                        bVar7 = (byte)uVar5;
                        if (!bVar11) {
                          bVar7 = 0;
                        }
                        snprintf(tmp1,0x100,
                                 "SN:%s  %s result:%d send failed to mes, response_msg:%s",board_sn,
                                 &DAT_001e21e0,(uint)bVar7,response_msg);
                        log_to_file(tmp1,time_stamp_27);
                        lcd_clear_result();
                        lcd_show(0,"send mes failed");
                        memset(lcd_data,0,0x10);
                        snprintf(lcd_data,0x10,"%s",response_msg);
                        lcd_show(1,lcd_data);
                        if ((iVar3 != 1) && (iVar3 != -2)) {
                          save_mes_submit_result(true,time_stamp);
                        }
                      }
                    }
                    else {
                      print_time_stamp(time_stamp_27,0x30);
                      printf("%s ",time_stamp_27);
                      printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                             board_sn,&DAT_001e21e0,response_msg);
                      snprintf(tmp1,0x100,"SN:%s %s test is disallowed by MES, response_msg:%s",
                               board_sn,&DAT_001e21e0,response_msg);
                      log_to_file(tmp1,time_stamp_27);
                      lcd_clear_result();
                      lcd_show(0,"mes disallowed");
                      memset(lcd_data_1,0,0x10);
                      snprintf(lcd_data_1,0x10,"%s",response_msg);
                      lcd_show(1,lcd_data_1);
                    }
                  }
                  else {
                    iVar3 = strcmp(Local_Config_Information->Test_Process,"PT1new");
                    if (iVar3 == 0) {
                      start_new_log("PT1new",sn.board_sn,
                                    (Local_Config_Information->Hash_Board).Miner_Type,
                                    (Local_Config_Information->Hash_Board).Board_Name);
                      memset(response_msg,0,100);
                      memset(time_stamp,0,100);
                      board_sn_1[0] = '\0';
                      board_sn_1[1] = '\0';
                      board_sn_1[2] = '\0';
                      board_sn_1[3] = '\0';
                      board_sn_1[4] = '\0';
                      board_sn_1[5] = '\0';
                      board_sn_1[6] = '\0';
                      board_sn_1[7] = '\0';
                      board_sn_1[8] = '\0';
                      board_sn_1[9] = '\0';
                      board_sn_1[10] = '\0';
                      board_sn_1[0xb] = '\0';
                      board_sn_1[0xc] = '\0';
                      board_sn_1[0xd] = '\0';
                      board_sn_1[0xe] = '\0';
                      board_sn_1[0xf] = '\0';
                      board_sn_1[0x10] = '\0';
                      board_sn_1[0x11] = '\0';
                      board_sn_1[0x12] = '\0';
                      board_sn_1[0x13] = '\0';
                      strncpy(board_sn_1,sn.board_sn,0x14);
                      iVar3 = get_pt1_test_permission(board_sn_1,response_msg);
                      if (iVar3 == 0) {
                        uVar5 = Single_Board_PT1_New_Test();
                        memset(time_stamp,0,100);
                        memset(response_msg,0,100);
                        uVar9 = uVar5;
                        if (uVar5 == 0) {
                          uVar9 = 1;
                        }
                        uVar6 = (undefined1)uVar9;
                        if (uVar5 != 0) {
                          uVar6 = false;
                        }
                        iVar3 = send_pt1_test_result
                                          (board_sn_1,(_Bool)uVar6,uVar5 & 0xff,
                                           (int)(uVar5 & 0xff00) >> 8,time_stamp,response_msg);
                        if (iVar3 == 0) {
                          print_time_stamp(time_stamp_27,0x30);
                          printf("%s ",time_stamp_27);
                          uVar9 = uVar5;
                          if (uVar5 == 0) {
                            uVar9 = 1;
                          }
                          bVar7 = (byte)uVar9;
                          if (uVar5 != 0) {
                            bVar7 = 0;
                          }
                          printf("%s : SN:%s %s result:%d send ok to mes\n","main",board_sn_1,
                                 "PT1new",(uint)bVar7);
                          bVar11 = uVar5 == 0;
                          if (bVar11) {
                            uVar5 = 1;
                          }
                          bVar7 = (byte)uVar5;
                          if (!bVar11) {
                            bVar7 = 0;
                          }
                          snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn_1,
                                   "PT1new",(uint)bVar7);
                          log_to_file(tmp1,time_stamp_27);
                        }
                        else if (iVar3 != 0x1234) {
                          print_time_stamp(time_stamp_27,0x30);
                          printf("%s ",time_stamp_27);
                          uVar9 = uVar5;
                          if (uVar5 == 0) {
                            uVar9 = 1;
                          }
                          bVar7 = (byte)uVar9;
                          if (uVar5 != 0) {
                            bVar7 = 0;
                          }
                          printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n",
                                 "main",board_sn_1,"PT1new",(uint)bVar7,response_msg);
                          bVar11 = uVar5 == 0;
                          if (bVar11) {
                            uVar5 = 1;
                          }
                          bVar7 = (byte)uVar5;
                          if (!bVar11) {
                            bVar7 = 0;
                          }
                          snprintf(tmp1,0x100,
                                   "SN:%s  %s result:%d send failed to mes, response_msg:%s",
                                   board_sn_1,"PT1new",(uint)bVar7,response_msg);
                          log_to_file(tmp1,time_stamp_27);
                          lcd_clear_result();
                          lcd_show(0,"send mes failed");
                          memset(lcd_data_2,0,0x10);
                          snprintf(lcd_data_2,0x10,"%s",response_msg);
                          lcd_show(1,lcd_data_2);
                          if ((iVar3 != 1) && (iVar3 != -2)) {
                            save_mes_submit_result(true,time_stamp);
                          }
                        }
                      }
                      else {
                        print_time_stamp(time_stamp_27,0x30);
                        printf("%s ",time_stamp_27);
                        printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                               board_sn_1,"PT1new",response_msg);
                        snprintf(tmp1,0x100,"SN:%s %s test is disallowed by MES, response_msg:%s",
                                 board_sn_1,"PT1new",response_msg);
                        log_to_file(tmp1,time_stamp_27);
                        lcd_clear_result();
                        lcd_show(0,"mes disallowed");
                        memset(lcd_data_3,0,0x10);
                        snprintf(lcd_data_3,0x10,"%s",response_msg);
                        lcd_show(1,lcd_data_3);
                      }
                    }
                    else {
                      iVar3 = strcmp(Local_Config_Information->Test_Process,"PT1+");
                      if (iVar3 == 0) {
                        memset(response_msg,0,100);
                        memset(time_stamp,0,100);
                        board_sn_2[0] = '\0';
                        board_sn_2[1] = '\0';
                        board_sn_2[2] = '\0';
                        board_sn_2[3] = '\0';
                        board_sn_2[4] = '\0';
                        board_sn_2[5] = '\0';
                        board_sn_2[6] = '\0';
                        board_sn_2[7] = '\0';
                        board_sn_2[8] = '\0';
                        board_sn_2[9] = '\0';
                        board_sn_2[10] = '\0';
                        board_sn_2[0xb] = '\0';
                        board_sn_2[0xc] = '\0';
                        board_sn_2[0xd] = '\0';
                        board_sn_2[0xe] = '\0';
                        board_sn_2[0xf] = '\0';
                        board_sn_2[0x10] = '\0';
                        board_sn_2[0x11] = '\0';
                        board_sn_2[0x12] = '\0';
                        board_sn_2[0x13] = '\0';
                        strncpy(board_sn_2,sn.board_sn,0x14);
                        iVar3 = get_pt1_test_permission(board_sn_2,response_msg);
                        if (iVar3 == 0) {
                          uVar5 = Single_Board_PT1_Plus_Test();
                          memset(time_stamp,0,100);
                          memset(response_msg,0,100);
                          uVar9 = uVar5;
                          if (uVar5 == 0) {
                            uVar9 = 1;
                          }
                          uVar6 = (undefined1)uVar9;
                          if (uVar5 != 0) {
                            uVar6 = false;
                          }
                          iVar3 = send_pt1_test_result
                                            (board_sn_2,(_Bool)uVar6,uVar5 & 0xff,
                                             (int)(uVar5 & 0xff00) >> 8,time_stamp,response_msg);
                          if (iVar3 == 0) {
                            print_time_stamp(time_stamp_27,0x30);
                            printf("%s ",time_stamp_27);
                            uVar9 = uVar5;
                            if (uVar5 == 0) {
                              uVar9 = 1;
                            }
                            bVar7 = (byte)uVar9;
                            if (uVar5 != 0) {
                              bVar7 = 0;
                            }
                            printf("%s : SN:%s %s result:%d send ok to mes\n","main",board_sn_2,
                                   &DAT_001e2344,(uint)bVar7);
                            bVar11 = uVar5 == 0;
                            if (bVar11) {
                              uVar5 = 1;
                            }
                            bVar7 = (byte)uVar5;
                            if (!bVar11) {
                              bVar7 = 0;
                            }
                            snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn_2,
                                     &DAT_001e2344,(uint)bVar7);
                            log_to_file(tmp1,time_stamp_27);
                          }
                          else if (iVar3 != 0x1234) {
                            print_time_stamp(time_stamp_27,0x30);
                            printf("%s ",time_stamp_27);
                            uVar9 = uVar5;
                            if (uVar5 == 0) {
                              uVar9 = 1;
                            }
                            bVar7 = (byte)uVar9;
                            if (uVar5 != 0) {
                              bVar7 = 0;
                            }
                            printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n",
                                   "main",board_sn_2,&DAT_001e2344,(uint)bVar7,response_msg);
                            bVar11 = uVar5 == 0;
                            if (bVar11) {
                              uVar5 = 1;
                            }
                            bVar7 = (byte)uVar5;
                            if (!bVar11) {
                              bVar7 = 0;
                            }
                            snprintf(tmp1,0x100,
                                     "SN:%s  %s result:%d send failed to mes, response_msg:%s",
                                     board_sn_2,&DAT_001e2344,(uint)bVar7,response_msg);
                            log_to_file(tmp1,time_stamp_27);
                            lcd_clear_result();
                            lcd_show(0,"send mes failed");
                            memset(lcd_data_4,0,0x10);
                            snprintf(lcd_data_4,0x10,"%s",response_msg);
                            lcd_show(1,lcd_data_4);
                            if ((iVar3 != 1) && (iVar3 != -2)) {
                              save_mes_submit_result(true,time_stamp);
                            }
                          }
                        }
                        else {
                          print_time_stamp(time_stamp_27,0x30);
                          printf("%s ",time_stamp_27);
                          printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n","main"
                                 ,board_sn_2,&DAT_001e2344,response_msg);
                          snprintf(tmp1,0x100,"SN:%s %s test is disallowed by MES, response_msg:%s",
                                   board_sn_2,&DAT_001e2344,response_msg);
                          log_to_file(tmp1,time_stamp_27);
                          lcd_clear_result();
                          lcd_show(0,"mes disallowed");
                          memset(lcd_data_5,0,0x10);
                          snprintf(lcd_data_5,0x10,"%s",response_msg);
                          lcd_show(1,lcd_data_5);
                        }
                      }
                      else {
                        iVar3 = strcmp(Local_Config_Information->Test_Process,"PT2");
                        if (iVar3 == 0) {
                          start_new_log("PT2",sn.board_sn,
                                        (Local_Config_Information->Hash_Board).Miner_Type,
                                        (Local_Config_Information->Hash_Board).Board_Name);
                          memset(response_msg,0,100);
                          memset(time_stamp,0,100);
                          board_sn_3[0] = '\0';
                          board_sn_3[1] = '\0';
                          board_sn_3[2] = '\0';
                          board_sn_3[3] = '\0';
                          board_sn_3[4] = '\0';
                          board_sn_3[5] = '\0';
                          board_sn_3[6] = '\0';
                          board_sn_3[7] = '\0';
                          board_sn_3[8] = '\0';
                          board_sn_3[9] = '\0';
                          board_sn_3[10] = '\0';
                          board_sn_3[0xb] = '\0';
                          board_sn_3[0xc] = '\0';
                          board_sn_3[0xd] = '\0';
                          board_sn_3[0xe] = '\0';
                          board_sn_3[0xf] = '\0';
                          board_sn_3[0x10] = '\0';
                          board_sn_3[0x11] = '\0';
                          board_sn_3[0x12] = '\0';
                          board_sn_3[0x13] = '\0';
                          strncpy(board_sn_3,sn.board_sn,0x14);
                          iVar3 = get_pt2_test_permission(board_sn_3,response_msg);
                          if (iVar3 == 0) {
                            uVar5 = Single_Board_PT2_Test();
                            memset(time_stamp,0,100);
                            memset(response_msg,0,100);
                            uVar9 = uVar5;
                            if (uVar5 == 0) {
                              uVar9 = 1;
                            }
                            uVar6 = (undefined1)uVar9;
                            if (uVar5 != 0) {
                              uVar6 = false;
                            }
                            iVar3 = send_pt2_test_result
                                              (board_sn_3,(_Bool)uVar6,uVar5 & 0xff,
                                               (int)(uVar5 & 0xff00) >> 8,time_stamp,response_msg);
                            if (iVar3 == 0) {
                              print_time_stamp(time_stamp_27,0x30);
                              printf("%s ",time_stamp_27);
                              uVar9 = uVar5;
                              if (uVar5 == 0) {
                                uVar9 = 1;
                              }
                              bVar7 = (byte)uVar9;
                              if (uVar5 != 0) {
                                bVar7 = 0;
                              }
                              printf("%s : SN:%s %s result:%d send ok to mes\n","main",board_sn_3,
                                     &DAT_001e1da8,(uint)bVar7);
                              bVar11 = uVar5 == 0;
                              if (bVar11) {
                                uVar5 = 1;
                              }
                              bVar7 = (byte)uVar5;
                              if (!bVar11) {
                                bVar7 = 0;
                              }
                              snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn_3,
                                       &DAT_001e1da8,(uint)bVar7);
                              log_to_file(tmp1,time_stamp_27);
                            }
                            else if (iVar3 != 0x1234) {
                              print_time_stamp(time_stamp_27,0x30);
                              printf("%s ",time_stamp_27);
                              uVar9 = uVar5;
                              if (uVar5 == 0) {
                                uVar9 = 1;
                              }
                              bVar7 = (byte)uVar9;
                              if (uVar5 != 0) {
                                bVar7 = 0;
                              }
                              printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                     ,"main",board_sn_3,&DAT_001e1da8,(uint)bVar7,response_msg);
                              bVar11 = uVar5 == 0;
                              if (bVar11) {
                                uVar5 = 1;
                              }
                              bVar7 = (byte)uVar5;
                              if (!bVar11) {
                                bVar7 = 0;
                              }
                              snprintf(tmp1,0x100,
                                       "SN:%s  %s result:%d send failed to mes, response_msg:%s",
                                       board_sn_3,&DAT_001e1da8,(uint)bVar7,response_msg);
                              log_to_file(tmp1,time_stamp_27);
                              lcd_clear_result();
                              lcd_show(0,"send mes failed");
                              memset(lcd_data_6,0,0x10);
                              snprintf(lcd_data_6,0x10,"%s",response_msg);
                              lcd_show(1,lcd_data_6);
                              if ((iVar3 != 1) && (iVar3 != -2)) {
                                save_mes_submit_result(false,time_stamp);
                              }
                            }
                          }
                          else {
                            print_time_stamp(time_stamp_27,0x30);
                            printf("%s ",time_stamp_27);
                            printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n",
                                   "main",board_sn_3,&DAT_001e1da8,response_msg);
                            snprintf(tmp1,0x100,
                                     "SN:%s %s test is disallowed by MES, response_msg:%s",
                                     board_sn_3,&DAT_001e1da8,response_msg);
                            log_to_file(tmp1,time_stamp_27);
                            lcd_clear_result();
                            lcd_show(0,"mes disallowed");
                            memset(lcd_data_7,0,0x10);
                            snprintf(lcd_data_7,0x10,"%s",response_msg);
                            lcd_show(1,lcd_data_7);
                          }
                        }
                        else {
                          iVar3 = strcmp(Local_Config_Information->Test_Process,"SWEEP");
                          if (iVar3 == 0) {
                            if (g_eeprom_version == 4) {
                              memset(response_msg,0,100);
                              memset(time_stamp,0,100);
                              board_sn_4[0] = '\0';
                              board_sn_4[1] = '\0';
                              board_sn_4[2] = '\0';
                              board_sn_4[3] = '\0';
                              board_sn_4[4] = '\0';
                              board_sn_4[5] = '\0';
                              board_sn_4[6] = '\0';
                              board_sn_4[7] = '\0';
                              board_sn_4[8] = '\0';
                              board_sn_4[9] = '\0';
                              board_sn_4[10] = '\0';
                              board_sn_4[0xb] = '\0';
                              board_sn_4[0xc] = '\0';
                              board_sn_4[0xd] = '\0';
                              board_sn_4[0xe] = '\0';
                              board_sn_4[0xf] = '\0';
                              board_sn_4[0x10] = '\0';
                              board_sn_4[0x11] = '\0';
                              board_sn_4[0x12] = '\0';
                              board_sn_4[0x13] = '\0';
                              strncpy(board_sn_4,sn.board_sn,0x14);
                              iVar3 = get_pt2_test_permission(board_sn_4,response_msg);
                              if (iVar3 == 0) {
                                uVar5 = Single_Board_PT2_Test();
                                memset(time_stamp,0,100);
                                memset(response_msg,0,100);
                                uVar9 = uVar5;
                                if (uVar5 == 0) {
                                  uVar9 = 1;
                                }
                                uVar6 = (undefined1)uVar9;
                                if (uVar5 != 0) {
                                  uVar6 = false;
                                }
                                iVar3 = send_pt2_test_result
                                                  (board_sn_4,(_Bool)uVar6,uVar5 & 0xff,
                                                   (int)(uVar5 & 0xff00) >> 8,time_stamp,
                                                   response_msg);
                                if (iVar3 == 0) {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  bVar7 = (byte)uVar9;
                                  if (uVar5 != 0) {
                                    bVar7 = 0;
                                  }
                                  printf("%s : SN:%s %s result:%d send ok to mes\n","main",
                                         board_sn_4,&DAT_001e1da8,(uint)bVar7);
                                  bVar11 = uVar5 == 0;
                                  if (bVar11) {
                                    uVar5 = 1;
                                  }
                                  bVar7 = (byte)uVar5;
                                  if (!bVar11) {
                                    bVar7 = 0;
                                  }
                                  snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn_4
                                           ,&DAT_001e1da8,(uint)bVar7);
                                  log_to_file(tmp1,time_stamp_27);
                                }
                                else if (iVar3 != 0x1234) {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  bVar7 = (byte)uVar9;
                                  if (uVar5 != 0) {
                                    bVar7 = 0;
                                  }
                                  printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                         ,"main",board_sn_4,&DAT_001e1da8,(uint)bVar7,response_msg);
                                  bVar11 = uVar5 == 0;
                                  if (bVar11) {
                                    uVar5 = 1;
                                  }
                                  bVar7 = (byte)uVar5;
                                  if (!bVar11) {
                                    bVar7 = 0;
                                  }
                                  snprintf(tmp1,0x100,
                                           "SN:%s  %s result:%d send failed to mes, response_msg:%s"
                                           ,board_sn_4,&DAT_001e1da8,(uint)bVar7,response_msg);
                                  log_to_file(tmp1,time_stamp_27);
                                  lcd_clear_result();
                                  lcd_show(0,"send mes failed");
                                  memset(lcd_data_8,0,0x10);
                                  snprintf(lcd_data_8,0x10,"%s",response_msg);
                                  lcd_show(1,lcd_data_8);
                                  if ((iVar3 != 1) && (iVar3 != -2)) {
                                    save_mes_submit_result(false,time_stamp);
                                  }
                                }
                              }
                              else {
                                print_time_stamp(time_stamp_27,0x30);
                                printf("%s ",time_stamp_27);
                                printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n",
                                       "main",board_sn_4,&DAT_001e1da8,response_msg);
                                snprintf(tmp1,0x100,
                                         "SN:%s %s test is disallowed by MES, response_msg:%s",
                                         board_sn_4,&DAT_001e1da8,response_msg);
                                log_to_file(tmp1,time_stamp_27);
                                lcd_clear_result();
                                lcd_show(0,"mes disallowed");
                                memset(lcd_data_9,0,0x10);
                                snprintf(lcd_data_9,0x10,"%s",response_msg);
                                lcd_show(1,lcd_data_9);
                              }
                            }
                            else {
                              memset(response_msg,0,100);
                              memset(time_stamp,0,100);
                              board_sn_5[0] = '\0';
                              board_sn_5[1] = '\0';
                              board_sn_5[2] = '\0';
                              board_sn_5[3] = '\0';
                              board_sn_5[4] = '\0';
                              board_sn_5[5] = '\0';
                              board_sn_5[6] = '\0';
                              board_sn_5[7] = '\0';
                              board_sn_5[8] = '\0';
                              board_sn_5[9] = '\0';
                              board_sn_5[10] = '\0';
                              board_sn_5[0xb] = '\0';
                              board_sn_5[0xc] = '\0';
                              board_sn_5[0xd] = '\0';
                              board_sn_5[0xe] = '\0';
                              board_sn_5[0xf] = '\0';
                              board_sn_5[0x10] = '\0';
                              board_sn_5[0x11] = '\0';
                              board_sn_5[0x12] = '\0';
                              board_sn_5[0x13] = '\0';
                              strncpy(board_sn_5,sn.board_sn,0x14);
                              iVar3 = get_pt2_test_permission(board_sn_5,response_msg);
                              if (iVar3 == 0) {
                                uVar5 = Single_Board_Sweep_Test();
                                memset(time_stamp,0,100);
                                memset(response_msg,0,100);
                                uVar9 = uVar5;
                                if (uVar5 == 0) {
                                  uVar9 = 1;
                                }
                                uVar6 = (undefined1)uVar9;
                                if (uVar5 != 0) {
                                  uVar6 = false;
                                }
                                iVar3 = send_pt2_test_result
                                                  (board_sn_5,(_Bool)uVar6,uVar5 & 0xff,
                                                   (int)(uVar5 & 0xff00) >> 8,time_stamp,
                                                   response_msg);
                                if (iVar3 == 0) {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  bVar7 = (byte)uVar9;
                                  if (uVar5 != 0) {
                                    bVar7 = 0;
                                  }
                                  printf("%s : SN:%s %s result:%d send ok to mes\n","main",
                                         board_sn_5,"SWEEP",(uint)bVar7);
                                  bVar11 = uVar5 == 0;
                                  if (bVar11) {
                                    uVar5 = 1;
                                  }
                                  bVar7 = (byte)uVar5;
                                  if (!bVar11) {
                                    bVar7 = 0;
                                  }
                                  snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",board_sn_5
                                           ,"SWEEP",(uint)bVar7);
                                  log_to_file(tmp1,time_stamp_27);
                                }
                                else if (iVar3 != 0x1234) {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  bVar7 = (byte)uVar9;
                                  if (uVar5 != 0) {
                                    bVar7 = 0;
                                  }
                                  printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                         ,"main",board_sn_5,"SWEEP",(uint)bVar7,response_msg);
                                  bVar11 = uVar5 == 0;
                                  if (bVar11) {
                                    uVar5 = 1;
                                  }
                                  bVar7 = (byte)uVar5;
                                  if (!bVar11) {
                                    bVar7 = 0;
                                  }
                                  snprintf(tmp1,0x100,
                                           "SN:%s  %s result:%d send failed to mes, response_msg:%s"
                                           ,board_sn_5,"SWEEP",(uint)bVar7,response_msg);
                                  log_to_file(tmp1,time_stamp_27);
                                  lcd_clear_result();
                                  lcd_show(0,"send mes failed");
                                  memset(lcd_data_10,0,0x10);
                                  snprintf(lcd_data_10,0x10,"%s",response_msg);
                                  lcd_show(1,lcd_data_10);
                                  if ((iVar3 != 1) && (iVar3 != -2)) {
                                    save_mes_submit_result(false,time_stamp);
                                  }
                                }
                              }
                              else {
                                print_time_stamp(time_stamp_27,0x30);
                                printf("%s ",time_stamp_27);
                                printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n",
                                       "main",board_sn_5,"SWEEP",response_msg);
                                snprintf(tmp1,0x100,
                                         "SN:%s %s test is disallowed by MES, response_msg:%s",
                                         board_sn_5,"SWEEP",response_msg);
                                log_to_file(tmp1,time_stamp_27);
                                lcd_clear_result();
                                lcd_show(0,"mes disallowed");
                                memset(lcd_data_11,0,0x10);
                                snprintf(lcd_data_11,0x10,"%s",response_msg);
                                lcd_show(1,lcd_data_11);
                              }
                              sweep_exit();
                            }
                          }
                          else {
                            iVar3 = strcmp(Local_Config_Information->Test_Process,"PT3");
                            if (iVar3 == 0) {
                              if (g_eeprom_version == 4) {
                                memset(response_msg,0,100);
                                memset(time_stamp,0,100);
                                board_sn_6[0] = '\0';
                                board_sn_6[1] = '\0';
                                board_sn_6[2] = '\0';
                                board_sn_6[3] = '\0';
                                board_sn_6[4] = '\0';
                                board_sn_6[5] = '\0';
                                board_sn_6[6] = '\0';
                                board_sn_6[7] = '\0';
                                board_sn_6[8] = '\0';
                                board_sn_6[9] = '\0';
                                board_sn_6[10] = '\0';
                                board_sn_6[0xb] = '\0';
                                board_sn_6[0xc] = '\0';
                                board_sn_6[0xd] = '\0';
                                board_sn_6[0xe] = '\0';
                                board_sn_6[0xf] = '\0';
                                board_sn_6[0x10] = '\0';
                                board_sn_6[0x11] = '\0';
                                board_sn_6[0x12] = '\0';
                                board_sn_6[0x13] = '\0';
                                strncpy(board_sn_6,sn.board_sn,0x14);
                                iVar3 = get_pt2_test_permission(board_sn_6,response_msg);
                                if (iVar3 == 0) {
                                  uVar5 = Single_Board_PT2_Test();
                                  memset(time_stamp,0,100);
                                  memset(response_msg,0,100);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  uVar6 = (undefined1)uVar9;
                                  if (uVar5 != 0) {
                                    uVar6 = false;
                                  }
                                  iVar3 = send_pt2_test_result
                                                    (board_sn_6,(_Bool)uVar6,uVar5 & 0xff,
                                                     (int)(uVar5 & 0xff00) >> 8,time_stamp,
                                                     response_msg);
                                  if (iVar3 == 0) {
                                    print_time_stamp(time_stamp_27,0x30);
                                    printf("%s ",time_stamp_27);
                                    uVar9 = uVar5;
                                    if (uVar5 == 0) {
                                      uVar9 = 1;
                                    }
                                    bVar7 = (byte)uVar9;
                                    if (uVar5 != 0) {
                                      bVar7 = 0;
                                    }
                                    printf("%s : SN:%s %s result:%d send ok to mes\n","main",
                                           board_sn_6,&DAT_001e1da8,(uint)bVar7);
                                    bVar11 = uVar5 == 0;
                                    if (bVar11) {
                                      uVar5 = 1;
                                    }
                                    bVar7 = (byte)uVar5;
                                    if (!bVar11) {
                                      bVar7 = 0;
                                    }
                                    snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",
                                             board_sn_6,&DAT_001e1da8,(uint)bVar7);
                                    log_to_file(tmp1,time_stamp_27);
                                  }
                                  else if (iVar3 != 0x1234) {
                                    print_time_stamp(time_stamp_27,0x30);
                                    printf("%s ",time_stamp_27);
                                    uVar9 = uVar5;
                                    if (uVar5 == 0) {
                                      uVar9 = 1;
                                    }
                                    bVar7 = (byte)uVar9;
                                    if (uVar5 != 0) {
                                      bVar7 = 0;
                                    }
                                    printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                           ,"main",board_sn_6,&DAT_001e1da8,(uint)bVar7,response_msg
                                          );
                                    bVar11 = uVar5 == 0;
                                    if (bVar11) {
                                      uVar5 = 1;
                                    }
                                    bVar7 = (byte)uVar5;
                                    if (!bVar11) {
                                      bVar7 = 0;
                                    }
                                    snprintf(tmp1,0x100,
                                             "SN:%s  %s result:%d send failed to mes, response_msg:%s"
                                             ,board_sn_6,&DAT_001e1da8,(uint)bVar7,response_msg);
                                    log_to_file(tmp1,time_stamp_27);
                                    lcd_clear_result();
                                    lcd_show(0,"send mes failed");
                                    memset(lcd_data_12,0,0x10);
                                    snprintf(lcd_data_12,0x10,"%s",response_msg);
                                    lcd_show(1,lcd_data_12);
                                    if ((iVar3 != 1) && (iVar3 != -2)) {
                                      save_mes_submit_result(false,time_stamp);
                                    }
                                  }
                                }
                                else {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n"
                                         ,"main",board_sn_6,&DAT_001e1da8,response_msg);
                                  snprintf(tmp1,0x100,
                                           "SN:%s %s test is disallowed by MES, response_msg:%s",
                                           board_sn_6,&DAT_001e1da8,response_msg);
                                  log_to_file(tmp1,time_stamp_27);
                                  lcd_clear_result();
                                  lcd_show(0,"mes disallowed");
                                  memset(lcd_data_13,0,0x10);
                                  snprintf(lcd_data_13,0x10,"%s",response_msg);
                                  lcd_show(1,lcd_data_13);
                                }
                              }
                              else {
                                memset(response_msg,0,100);
                                memset(time_stamp,0,100);
                                board_sn_7[0] = '\0';
                                board_sn_7[1] = '\0';
                                board_sn_7[2] = '\0';
                                board_sn_7[3] = '\0';
                                board_sn_7[4] = '\0';
                                board_sn_7[5] = '\0';
                                board_sn_7[6] = '\0';
                                board_sn_7[7] = '\0';
                                board_sn_7[8] = '\0';
                                board_sn_7[9] = '\0';
                                board_sn_7[10] = '\0';
                                board_sn_7[0xb] = '\0';
                                board_sn_7[0xc] = '\0';
                                board_sn_7[0xd] = '\0';
                                board_sn_7[0xe] = '\0';
                                board_sn_7[0xf] = '\0';
                                board_sn_7[0x10] = '\0';
                                board_sn_7[0x11] = '\0';
                                board_sn_7[0x12] = '\0';
                                board_sn_7[0x13] = '\0';
                                strncpy(board_sn_7,sn.board_sn,0x14);
                                iVar3 = get_pt2_test_permission(board_sn_7,response_msg);
                                if (iVar3 == 0) {
                                  uVar5 = Single_Board_PT3_Test();
                                  memset(time_stamp,0,100);
                                  memset(response_msg,0,100);
                                  uVar9 = uVar5;
                                  if (uVar5 == 0) {
                                    uVar9 = 1;
                                  }
                                  uVar6 = (undefined1)uVar9;
                                  if (uVar5 != 0) {
                                    uVar6 = false;
                                  }
                                  iVar3 = send_pt2_test_result
                                                    (board_sn_7,(_Bool)uVar6,uVar5 & 0xff,
                                                     (int)(uVar5 & 0xff00) >> 8,time_stamp,
                                                     response_msg);
                                  if (iVar3 == 0) {
                                    print_time_stamp(time_stamp_27,0x30);
                                    printf("%s ",time_stamp_27);
                                    uVar9 = uVar5;
                                    if (uVar5 == 0) {
                                      uVar9 = 1;
                                    }
                                    bVar7 = (byte)uVar9;
                                    if (uVar5 != 0) {
                                      bVar7 = 0;
                                    }
                                    printf("%s : SN:%s %s result:%d send ok to mes\n","main",
                                           board_sn_7,&DAT_001e1dac,(uint)bVar7);
                                    bVar11 = uVar5 == 0;
                                    if (bVar11) {
                                      uVar5 = 1;
                                    }
                                    bVar7 = (byte)uVar5;
                                    if (!bVar11) {
                                      bVar7 = 0;
                                    }
                                    snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",
                                             board_sn_7,&DAT_001e1dac,(uint)bVar7);
                                    log_to_file(tmp1,time_stamp_27);
                                  }
                                  else if (iVar3 != 0x1234) {
                                    print_time_stamp(time_stamp_27,0x30);
                                    printf("%s ",time_stamp_27);
                                    uVar9 = uVar5;
                                    if (uVar5 == 0) {
                                      uVar9 = 1;
                                    }
                                    bVar7 = (byte)uVar9;
                                    if (uVar5 != 0) {
                                      bVar7 = 0;
                                    }
                                    printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                           ,"main",board_sn_7,&DAT_001e1dac,(uint)bVar7,response_msg
                                          );
                                    bVar11 = uVar5 == 0;
                                    if (bVar11) {
                                      uVar5 = 1;
                                    }
                                    bVar7 = (byte)uVar5;
                                    if (!bVar11) {
                                      bVar7 = 0;
                                    }
                                    snprintf(tmp1,0x100,
                                             "SN:%s  %s result:%d send failed to mes, response_msg:%s"
                                             ,board_sn_7,&DAT_001e1dac,(uint)bVar7,response_msg);
                                    log_to_file(tmp1,time_stamp_27);
                                    lcd_clear_result();
                                    lcd_show(0,"send mes failed");
                                    memset(lcd_data_14,0,0x10);
                                    snprintf(lcd_data_14,0x10,"%s",response_msg);
                                    lcd_show(1,lcd_data_14);
                                    if ((iVar3 != 1) && (iVar3 != -2)) {
                                      save_mes_submit_result(false,time_stamp);
                                    }
                                  }
                                }
                                else {
                                  print_time_stamp(time_stamp_27,0x30);
                                  printf("%s ",time_stamp_27);
                                  printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n"
                                         ,"main",board_sn_7,&DAT_001e1dac,response_msg);
                                  snprintf(tmp1,0x100,
                                           "SN:%s %s test is disallowed by MES, response_msg:%s",
                                           board_sn_7,&DAT_001e1dac,response_msg);
                                  log_to_file(tmp1,time_stamp_27);
                                  lcd_clear_result();
                                  lcd_show(0,"mes disallowed");
                                  memset(lcd_data_15,0,0x10);
                                  snprintf(lcd_data_15,0x10,"%s",response_msg);
                                  lcd_show(1,lcd_data_15);
                                }
                                sweep_exit();
                              }
                            }
                            else {
                              iVar3 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
                              if (iVar3 == 0) {
                                Single_Board_Reset_Low_Test();
                              }
                              else {
                                iVar3 = strcmp(Local_Config_Information->Test_Process,"DropLevel");
                                if (iVar3 == 0) {
                                  start_new_log("DropLevel",sn.board_sn,
                                                (Local_Config_Information->Hash_Board).Miner_Type,
                                                (Local_Config_Information->Hash_Board).Board_Name);
                                  memset(response_msg,0,100);
                                  memset(time_stamp,0,100);
                                  board_sn_8[0] = '\0';
                                  board_sn_8[1] = '\0';
                                  board_sn_8[2] = '\0';
                                  board_sn_8[3] = '\0';
                                  board_sn_8[4] = '\0';
                                  board_sn_8[5] = '\0';
                                  board_sn_8[6] = '\0';
                                  board_sn_8[7] = '\0';
                                  board_sn_8[8] = '\0';
                                  board_sn_8[9] = '\0';
                                  board_sn_8[10] = '\0';
                                  board_sn_8[0xb] = '\0';
                                  board_sn_8[0xc] = '\0';
                                  board_sn_8[0xd] = '\0';
                                  board_sn_8[0xe] = '\0';
                                  board_sn_8[0xf] = '\0';
                                  board_sn_8[0x10] = '\0';
                                  board_sn_8[0x11] = '\0';
                                  board_sn_8[0x12] = '\0';
                                  board_sn_8[0x13] = '\0';
                                  strncpy(board_sn_8,sn.board_sn,0x14);
                                  iVar3 = get_pt2_test_permission(board_sn_8,response_msg);
                                  if (iVar3 == 0) {
                                    uVar5 = Single_Board_DropLevel_Test();
                                    memset(time_stamp,0,100);
                                    memset(response_msg,0,100);
                                    uVar9 = uVar5;
                                    if (uVar5 == 0) {
                                      uVar9 = 1;
                                    }
                                    uVar6 = (undefined1)uVar9;
                                    if (uVar5 != 0) {
                                      uVar6 = false;
                                    }
                                    iVar3 = send_pt2_test_result
                                                      (board_sn_8,(_Bool)uVar6,uVar5 & 0xff,
                                                       (int)(uVar5 & 0xff00) >> 8,time_stamp,
                                                       response_msg);
                                    if (iVar3 == 0) {
                                      print_time_stamp(time_stamp_27,0x30);
                                      printf("%s ",time_stamp_27);
                                      uVar9 = uVar5;
                                      if (uVar5 == 0) {
                                        uVar9 = 1;
                                      }
                                      bVar7 = (byte)uVar9;
                                      if (uVar5 != 0) {
                                        bVar7 = 0;
                                      }
                                      printf("%s : SN:%s %s result:%d send ok to mes\n","main",
                                             board_sn_8,"DropLevel",(uint)bVar7);
                                      bVar11 = uVar5 == 0;
                                      if (bVar11) {
                                        uVar5 = 1;
                                      }
                                      bVar7 = (byte)uVar5;
                                      if (!bVar11) {
                                        bVar7 = 0;
                                      }
                                      snprintf(tmp1,0x100,"SN:%s %s result:%d send ok to mes",
                                               board_sn_8,"DropLevel",(uint)bVar7);
                                      log_to_file(tmp1,time_stamp_27);
                                    }
                                    else if (iVar3 != 0x1234) {
                                      print_time_stamp(time_stamp_27,0x30);
                                      printf("%s ",time_stamp_27);
                                      uVar9 = uVar5;
                                      if (uVar5 == 0) {
                                        uVar9 = 1;
                                      }
                                      bVar7 = (byte)uVar9;
                                      if (uVar5 != 0) {
                                        bVar7 = 0;
                                      }
                                      printf("%s : SN:%s  %s result:%d send failed to mes, response_msg:%s\n"
                                             ,"main",board_sn_8,"DropLevel",(uint)bVar7,response_msg
                                            );
                                      bVar11 = uVar5 == 0;
                                      if (bVar11) {
                                        uVar5 = 1;
                                      }
                                      bVar7 = (byte)uVar5;
                                      if (!bVar11) {
                                        bVar7 = 0;
                                      }
                                      snprintf(tmp1,0x100,
                                               "SN:%s  %s result:%d send failed to mes, response_msg:%s"
                                               ,board_sn_8,"DropLevel",(uint)bVar7,response_msg);
                                      log_to_file(tmp1,time_stamp_27);
                                      lcd_clear_result();
                                      lcd_show(0,"send mes failed");
                                      memset(lcd_data_16,0,0x10);
                                      snprintf(lcd_data_16,0x10,"%s",response_msg);
                                      lcd_show(1,lcd_data_16);
                                      if ((iVar3 != 1) && (iVar3 != -2)) {
                                        save_mes_submit_result(false,time_stamp);
                                      }
                                    }
                                  }
                                  else {
                                    print_time_stamp(time_stamp_27,0x30);
                                    printf("%s ",time_stamp_27);
                                    printf("%s : SN:%s %s test is disallowed by MES, response_msg:%s\n"
                                           ,"main",board_sn_8,"DropLevel",response_msg);
                                    snprintf(tmp1,0x100,
                                             "SN:%s %s test is disallowed by MES, response_msg:%s",
                                             board_sn_8,"DropLevel",response_msg);
                                    log_to_file(tmp1,time_stamp_27);
                                    lcd_clear_result();
                                    lcd_show(0,"mes disallowed");
                                    memset(lcd_data_17,0,0x10);
                                    snprintf(lcd_data_17,0x10,"%s",response_msg);
                                    lcd_show(1,lcd_data_17);
                                  }
                                  sweep_exit();
                                }
                                else {
                                  lcd_common_show("Test Process","error",(char *)0x0);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : build version information::  %s.\n\n","main",
                         "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
                        );
                  snprintf(tmp1,0x100,"build version information::  %s.\n",
                           "version: ba3b5818273ddb65ee40f46cfa891ff80c6da00f commit: 2024-01-22 12:51:34 build: 2024-01-23 05:39:16"
                          );
                  log_to_file(tmp1,time_stamp);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : author information::  %s.\n\n","main",
                         "author: harlay      email: harlay.liu@bitmain.com");
                  snprintf(tmp1,0x100,"author information::  %s.\n",
                           "author: harlay      email: harlay.liu@bitmain.com");
                  log_to_file(tmp1,time_stamp);
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : TEST OVER...\n","main");
                  builtin_strncpy(tmp1,"TEST OVER...",0xc);
                  tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
                  log_to_file(tmp1,time_stamp);
                  submit_cur_log();
                  gCheck_chain_status = true;
                  if (g_user_chain != 0xff) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : g_user_chain:%d,exit test.\n","main",g_user_chain);
                    snprintf(tmp1,0x100,"g_user_chain:%d,exit test.",g_user_chain);
                    log_to_file(tmp1,time_stamp);
                    sleep(10);
                    return 0;
                  }
                }
                else {
                  lcd_clear_result();
                  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                  lcd_show(1,"eeprom/pic error");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : can\'t decode eeprom data, maybe pic lost firmware\n","main");
                  builtin_strncpy(tmp1,"can\'t decode eeprom data, maybe pic lost firmwar",0x30);
                  tmp1[0x30] = 'e';
                  tmp1[0x31] = '\0';
                  log_to_file(tmp1,time_stamp);
                  if (g_user_chain != 0xff) {
                    lcd_show(2,"try PT1 again");
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : try do PT1 with scan gun\n","main");
                    builtin_strncpy(tmp1,"try do PT1 with scan gun",0x18);
                    tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
                    log_to_file(tmp1,time_stamp);
                    return -1;
                  }
                  lcd_show(3,"try another board");
                  gScanCodeGun_data_ready = '\0';
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : try another hash board\n","main");
                  uVar1 = tmp1._20_4_;
                  builtin_strncpy(tmp1,"try another hash board",0x17);
                  tmp1[0x17] = SUB41(uVar1,3);
                  log_to_file(tmp1,time_stamp);
                  gCheck_chain_status = true;
                }
              }
              while (gCheck_chain_status != false) {
                check_whether_hashboard_plug_in_again();
                if (gHashBoard_plug_in_again != false) {
                  sleep(1);
                  display_main_page();
                  gCheck_chain_status = false;
                  gHashBoard_plug_in_again = false;
                }
              }
            } while( true );
          }
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 0;
    }
  }
  else {
    iVar8 = 0;
  }
  return iVar8;
}

