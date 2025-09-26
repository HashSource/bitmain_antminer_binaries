
int32_t main(int argc,char **argv)

{
  undefined4 uVar1;
  _Bool _Var2;
  int32_t iVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  char **argv_local;
  int argc_local;
  char time_stamp_16 [48];
  char response_msg [100];
  char time_stamp [48];
  char tmp1 [2048];
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
  sigaction handler;
  _Bool is_pt1_7;
  int _send_result__7;
  int error_info_7;
  int error_no_7;
  _Bool is_pt1_6;
  int _send_result__6;
  int error_info_6;
  int error_no_6;
  _Bool is_pt1_5;
  int _send_result__5;
  int error_info_5;
  int error_no_5;
  _Bool is_pt1_4;
  int _send_result__4;
  int error_info_4;
  int error_no_4;
  _Bool is_pt1_3;
  int _send_result__3;
  int error_info_3;
  int error_no_3;
  _Bool is_pt1_2;
  int _send_result__2;
  int error_info_2;
  int error_no_2;
  _Bool is_pt1_1;
  int _send_result__1;
  int error_info_1;
  int error_no_1;
  _Bool is_pt1;
  int _send_result_;
  int error_info;
  int error_no;
  uint32_t i;
  _Bool ret;
  int _result__7;
  int _result__6;
  int _result__5;
  int _result__4;
  int _result__3;
  int _result__2;
  int _result__1;
  int _result_;
  
  handler.sa_flags = 0;
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x4b391;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x4b435;
  sigaction(0xb,(sigaction *)&handler,(sigaction *)&segvhandler);
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x4b435;
  sigaction(7,(sigaction *)&handler,(sigaction *)&bushandler);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: build version information::  %s.\n\n","main",
         "version: 2cbff4a193ca16eb0aa2363a52d8e76db948458d commit: 2023-08-02 15:03:49 build: 2023-08-02 15:04:56"
        );
  snprintf(tmp1,0x800,"build version information::  %s.\n",
           "version: 2cbff4a193ca16eb0aa2363a52d8e76db948458d commit: 2023-08-02 15:03:49 build: 2023-08-02 15:04:56"
          );
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: author information::  %s.\n\n","main",
         "author: yinghai.li      email: yinghai.li@bitmaincorp.com");
  snprintf(tmp1,0x800,"author information::  %s.\n",
           "author: yinghai.li      email: yinghai.li@bitmaincorp.com");
  log_to_file(tmp1,time_stamp);
  if (argc == 2) {
    g_user_chain = atoi(argv[1]);
    printf("force to use chain %d\n",g_user_chain);
    if (3 < g_user_chain) {
      printf("chain ID error, should < 3");
      return -1;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: user chain ID %d\n","main",g_user_chain);
    snprintf(tmp1,0x800,"user chain ID %d",g_user_chain);
    log_to_file(tmp1,time_stamp);
  }
  fpgaval = 0;
  fpga_read(0,&fpgaval);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: FPGA hardware ver:%x\n","main",fpgaval);
  snprintf(tmp1,0x800,"FPGA hardware ver:%x",fpgaval);
  log_to_file(tmp1,time_stamp);
  _Var2 = prepare_platform_environment();
  if (!_Var2) {
    return 0;
  }
  _Var2 = save_software_commit_id();
  if (!_Var2) {
    return 0;
  }
  _Var2 = prepare_local_config_information();
  if (!_Var2) {
    return 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: prepare_local_config_information\n","main");
  builtin_strncpy(tmp1,"prepare_local_config_information",0x20);
  tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  _Var2 = prepare_pattern();
  if (!_Var2) {
    return 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: prepare_pattern\n","main");
  builtin_strncpy(tmp1,"prepare_pattern",0x10);
  log_to_file(tmp1,time_stamp);
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
  lcd_show(1,"Check Power");
  lcd_show(2,"Please wait");
  lcd_show(2,"a few minutes");
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Check power, please wait a few minutes\n","main");
  builtin_strncpy(tmp1,"Check power, please wait a few minutes",0x27);
  log_to_file(tmp1,time_stamp);
  g_power_version = power_need_open();
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: g_power_version:%d\n","main",g_power_version);
  snprintf(tmp1,0x800,"g_power_version:%d",g_power_version);
  log_to_file(tmp1,time_stamp);
  _Var2 = prepare_test_process();
  if (!_Var2) {
    return 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: prepare_test_process\n","main");
  builtin_strncpy(tmp1,"prepare_test_process",0x14);
  tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  do {
    while (((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun != true &&
           (gFind_test_standard != true))) {
      _Var2 = scan_code_from_hashboard();
      if (_Var2) {
        if (((Local_Config_Information->Test_Info).Factory_Mode == false) ||
           (_Var2 = prepare_test_standard(), _Var2)) {
          print_local_config_after_parse_MES_system_information();
          gFind_test_standard = true;
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Find test std");
          lcd_show(2,"Insert Board");
          lcd_show(3,"Press Start Key");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: found test standard, Press Start Key to Begin Test\n","main");
          builtin_strncpy(tmp1,"found test standard, Press Start Key to Begin Te",0x30);
          tmp1[0x30] = 's';
          tmp1[0x31] = 't';
          tmp1[0x32] = '\0';
          log_to_file(tmp1,time_stamp);
          break;
        }
        gScanCodeGun_data_ready = '\0';
      }
      else {
        gFind_test_standard = false;
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: got user input \n","main");
    builtin_strncpy(tmp1,"got user input ",0x10);
    log_to_file(tmp1,time_stamp);
    lcd_clear_result();
    lcd_show(0,"Start Test");
    while (_Var2 = check_chain(), !_Var2) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"No Hashboard");
      lcd_show(2,"Insert Board 1st");
      lcd_show(3,"Press Start Key");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Didn\'t detect hashboard\n","main");
      builtin_strncpy(tmp1,"Didn\'t detect hashboard",0x18);
      log_to_file(tmp1,time_stamp);
      do {
        iVar3 = read_ipreport_key_val();
      } while (iVar3 != 0);
    }
    gScanCodeGun_data_ready = '\0';
    gFind_test_standard = false;
    _Var2 = read_board_info_from_eeprom();
    if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) goto LAB_0004bf7a;
    if (!_Var2) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"eeprom/pic error");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: can\'t decode eeprom data, maybe pic lost firmware\n","main");
      builtin_strncpy(tmp1,"can\'t decode eeprom data, maybe pic lost firmwar",0x30);
      tmp1[0x30] = 'e';
      tmp1[0x31] = '\0';
      log_to_file(tmp1,time_stamp);
      if (g_user_chain != 0xff) {
        lcd_show(2,"try PT1 again");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: try do PT1 with scan gun\n","main");
        builtin_strncpy(tmp1,"try do PT1 with scan gun",0x18);
        tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        return -1;
      }
      lcd_show(3,"try another board");
      gScanCodeGun_data_ready = '\0';
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: try another hash board\n","main");
      uVar1 = tmp1._20_4_;
      builtin_strncpy(tmp1,"try another hash board",0x17);
      tmp1[0x17] = SUB41(uVar1,3);
      log_to_file(tmp1,time_stamp);
      goto LAB_0004de38;
    }
    if (((Local_Config_Information->Test_Info).Factory_Mode == false) ||
       (_Var2 = prepare_test_standard(), _Var2)) {
      print_local_config_after_parse_MES_system_information();
      gFind_test_standard = true;
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Find test");
      lcd_show(2,"standard");
      lcd_show(3,"Press Start Key");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: found test standard, Press Start Key to Begin Test\n","main");
      builtin_strncpy(tmp1,"found test standard, Press Start Key to Begin Te",0x30);
      tmp1[0x30] = 's';
      tmp1[0x31] = 't';
      tmp1[0x32] = '\0';
      log_to_file(tmp1,time_stamp);
LAB_0004bf7a:
      iVar4 = strcmp(Local_Config_Information->Test_Process,"PT1");
      if (iVar4 == 0) {
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
        _result_ = get_pt1_test_permission(board_sn,response_msg);
        if (_result_ == 0) {
          _result_ = Single_Board_PT1_Test();
          memset(time_stamp,0,100);
          memset(response_msg,0,100);
          uVar7 = _result_;
          if (_result_ == 0U) {
            uVar7 = 1;
          }
          uVar5 = (undefined1)uVar7;
          if (_result_ != 0U) {
            uVar5 = false;
          }
          iVar4 = send_pt1_test_result
                            (board_sn,(_Bool)uVar5,_result_ & 0xff,(int)(_result_ & 0xff00U) >> 8,
                             time_stamp,response_msg);
          if (iVar4 == 0) {
            print_time_stamp(time_stamp_16,0x30);
            printf("%s ",time_stamp_16);
            uVar7 = _result_;
            if (_result_ == 0U) {
              uVar7 = 1;
            }
            bVar6 = (byte)uVar7;
            if (_result_ != 0U) {
              bVar6 = 0;
            }
            printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn,&DAT_001d35bc,
                   (uint)bVar6);
            uVar7 = _result_;
            if (_result_ == 0U) {
              uVar7 = 1;
            }
            bVar6 = (byte)uVar7;
            if (_result_ != 0U) {
              bVar6 = 0;
            }
            snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn,&DAT_001d35bc,
                     (uint)bVar6);
            log_to_file(tmp1,time_stamp_16);
          }
          else if (iVar4 != 0x1234) {
            print_time_stamp(time_stamp_16,0x30);
            printf("%s ",time_stamp_16);
            uVar7 = _result_;
            if (_result_ == 0U) {
              uVar7 = 1;
            }
            bVar6 = (byte)uVar7;
            if (_result_ != 0U) {
              bVar6 = 0;
            }
            printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",board_sn,
                   &DAT_001d35bc,(uint)bVar6,response_msg);
            uVar7 = _result_;
            if (_result_ == 0U) {
              uVar7 = 1;
            }
            bVar6 = (byte)uVar7;
            if (_result_ != 0U) {
              bVar6 = 0;
            }
            snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",board_sn,
                     &DAT_001d35bc,(uint)bVar6,response_msg);
            log_to_file(tmp1,time_stamp_16);
            lcd_clear_result();
            lcd_show(0,"send mes failed");
            memset(lcd_data,0,0x10);
            snprintf(lcd_data,0x10,"%s",response_msg);
            lcd_show(1,lcd_data);
            if ((iVar4 != 1) && (iVar4 != -2)) {
              save_mes_submit_result(true,time_stamp);
            }
          }
        }
        else {
          print_time_stamp(time_stamp_16,0x30);
          printf("%s ",time_stamp_16);
          printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",board_sn,
                 &DAT_001d35bc,response_msg);
          snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",board_sn,
                   &DAT_001d35bc,response_msg);
          log_to_file(tmp1,time_stamp_16);
          lcd_clear_result();
          lcd_show(0,"mes disallowed");
          memset(lcd_data_1,0,0x10);
          snprintf(lcd_data_1,0x10,"%s",response_msg);
          lcd_show(1,lcd_data_1);
        }
        gFind_test_result = (uint8_t)_result_;
      }
      else {
        iVar4 = strcmp(Local_Config_Information->Test_Process,"PT1new");
        if (iVar4 == 0) {
          start_new_log("PT1new",sn.board_sn,(Local_Config_Information->Hash_Board).Miner_Type,
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
          _result__1 = get_pt1_test_permission(board_sn_1,response_msg);
          if (_result__1 == 0) {
            _result__1 = Single_Board_PT1_New_Test();
            memset(time_stamp,0,100);
            memset(response_msg,0,100);
            uVar7 = _result__1;
            if (_result__1 == 0U) {
              uVar7 = 1;
            }
            uVar5 = (undefined1)uVar7;
            if (_result__1 != 0U) {
              uVar5 = false;
            }
            iVar4 = send_pt1_test_result
                              (board_sn_1,(_Bool)uVar5,_result__1 & 0xff,
                               (int)(_result__1 & 0xff00U) >> 8,time_stamp,response_msg);
            if (iVar4 == 0) {
              print_time_stamp(time_stamp_16,0x30);
              printf("%s ",time_stamp_16);
              uVar7 = _result__1;
              if (_result__1 == 0U) {
                uVar7 = 1;
              }
              bVar6 = (byte)uVar7;
              if (_result__1 != 0U) {
                bVar6 = 0;
              }
              printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_1,"PT1new",
                     (uint)bVar6);
              uVar7 = _result__1;
              if (_result__1 == 0U) {
                uVar7 = 1;
              }
              bVar6 = (byte)uVar7;
              if (_result__1 != 0U) {
                bVar6 = 0;
              }
              snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_1,"PT1new",
                       (uint)bVar6);
              log_to_file(tmp1,time_stamp_16);
            }
            else if (iVar4 != 0x1234) {
              print_time_stamp(time_stamp_16,0x30);
              printf("%s ",time_stamp_16);
              uVar7 = _result__1;
              if (_result__1 == 0U) {
                uVar7 = 1;
              }
              bVar6 = (byte)uVar7;
              if (_result__1 != 0U) {
                bVar6 = 0;
              }
              printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",
                     board_sn_1,"PT1new",(uint)bVar6,response_msg);
              uVar7 = _result__1;
              if (_result__1 == 0U) {
                uVar7 = 1;
              }
              bVar6 = (byte)uVar7;
              if (_result__1 != 0U) {
                bVar6 = 0;
              }
              snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",
                       board_sn_1,"PT1new",(uint)bVar6,response_msg);
              log_to_file(tmp1,time_stamp_16);
              lcd_clear_result();
              lcd_show(0,"send mes failed");
              memset(lcd_data_2,0,0x10);
              snprintf(lcd_data_2,0x10,"%s",response_msg);
              lcd_show(1,lcd_data_2);
              if ((iVar4 != 1) && (iVar4 != -2)) {
                save_mes_submit_result(true,time_stamp);
              }
            }
          }
          else {
            print_time_stamp(time_stamp_16,0x30);
            printf("%s ",time_stamp_16);
            printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",board_sn_1,
                   "PT1new",response_msg);
            snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",board_sn_1,
                     "PT1new",response_msg);
            log_to_file(tmp1,time_stamp_16);
            lcd_clear_result();
            lcd_show(0,"mes disallowed");
            memset(lcd_data_3,0,0x10);
            snprintf(lcd_data_3,0x10,"%s",response_msg);
            lcd_show(1,lcd_data_3);
          }
          gFind_test_result = (uint8_t)_result__1;
        }
        else {
          iVar4 = strcmp(Local_Config_Information->Test_Process,"PT1+");
          if (iVar4 == 0) {
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
            _result__2 = get_pt1_test_permission(board_sn_2,response_msg);
            if (_result__2 == 0) {
              _result__2 = Single_Board_PT1_Plus_Test();
              memset(time_stamp,0,100);
              memset(response_msg,0,100);
              uVar7 = _result__2;
              if (_result__2 == 0U) {
                uVar7 = 1;
              }
              uVar5 = (undefined1)uVar7;
              if (_result__2 != 0U) {
                uVar5 = false;
              }
              iVar4 = send_pt1_test_result
                                (board_sn_2,(_Bool)uVar5,_result__2 & 0xff,
                                 (int)(_result__2 & 0xff00U) >> 8,time_stamp,response_msg);
              if (iVar4 == 0) {
                print_time_stamp(time_stamp_16,0x30);
                printf("%s ",time_stamp_16);
                uVar7 = _result__2;
                if (_result__2 == 0U) {
                  uVar7 = 1;
                }
                bVar6 = (byte)uVar7;
                if (_result__2 != 0U) {
                  bVar6 = 0;
                }
                printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_2,&DAT_001d3720,
                       (uint)bVar6);
                uVar7 = _result__2;
                if (_result__2 == 0U) {
                  uVar7 = 1;
                }
                bVar6 = (byte)uVar7;
                if (_result__2 != 0U) {
                  bVar6 = 0;
                }
                snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_2,&DAT_001d3720,
                         (uint)bVar6);
                log_to_file(tmp1,time_stamp_16);
              }
              else if (iVar4 != 0x1234) {
                print_time_stamp(time_stamp_16,0x30);
                printf("%s ",time_stamp_16);
                uVar7 = _result__2;
                if (_result__2 == 0U) {
                  uVar7 = 1;
                }
                bVar6 = (byte)uVar7;
                if (_result__2 != 0U) {
                  bVar6 = 0;
                }
                printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",
                       board_sn_2,&DAT_001d3720,(uint)bVar6,response_msg);
                uVar7 = _result__2;
                if (_result__2 == 0U) {
                  uVar7 = 1;
                }
                bVar6 = (byte)uVar7;
                if (_result__2 != 0U) {
                  bVar6 = 0;
                }
                snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",
                         board_sn_2,&DAT_001d3720,(uint)bVar6,response_msg);
                log_to_file(tmp1,time_stamp_16);
                lcd_clear_result();
                lcd_show(0,"send mes failed");
                memset(lcd_data_4,0,0x10);
                snprintf(lcd_data_4,0x10,"%s",response_msg);
                lcd_show(1,lcd_data_4);
                if ((iVar4 != 1) && (iVar4 != -2)) {
                  save_mes_submit_result(true,time_stamp);
                }
              }
            }
            else {
              print_time_stamp(time_stamp_16,0x30);
              printf("%s ",time_stamp_16);
              printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",board_sn_2,
                     &DAT_001d3720,response_msg);
              snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",board_sn_2,
                       &DAT_001d3720,response_msg);
              log_to_file(tmp1,time_stamp_16);
              lcd_clear_result();
              lcd_show(0,"mes disallowed");
              memset(lcd_data_5,0,0x10);
              snprintf(lcd_data_5,0x10,"%s",response_msg);
              lcd_show(1,lcd_data_5);
            }
            gFind_test_result = (uint8_t)_result__2;
          }
          else {
            iVar4 = strcmp(Local_Config_Information->Test_Process,"PT2");
            if (iVar4 == 0) {
              start_new_log("PT2",sn.board_sn,(Local_Config_Information->Hash_Board).Miner_Type,
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
              _result__3 = get_pt2_test_permission(board_sn_3,response_msg);
              if (_result__3 == 0) {
                _result__3 = Single_Board_PT2_Test();
                memset(time_stamp,0,100);
                memset(response_msg,0,100);
                uVar7 = _result__3;
                if (_result__3 == 0U) {
                  uVar7 = 1;
                }
                uVar5 = (undefined1)uVar7;
                if (_result__3 != 0U) {
                  uVar5 = false;
                }
                iVar4 = send_pt2_test_result
                                  (board_sn_3,(_Bool)uVar5,_result__3 & 0xff,
                                   (int)(_result__3 & 0xff00U) >> 8,time_stamp,response_msg);
                if (iVar4 == 0) {
                  print_time_stamp(time_stamp_16,0x30);
                  printf("%s ",time_stamp_16);
                  uVar7 = _result__3;
                  if (_result__3 == 0U) {
                    uVar7 = 1;
                  }
                  bVar6 = (byte)uVar7;
                  if (_result__3 != 0U) {
                    bVar6 = 0;
                  }
                  printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_3,&DAT_001d3728,
                         (uint)bVar6);
                  uVar7 = _result__3;
                  if (_result__3 == 0U) {
                    uVar7 = 1;
                  }
                  bVar6 = (byte)uVar7;
                  if (_result__3 != 0U) {
                    bVar6 = 0;
                  }
                  snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_3,&DAT_001d3728,
                           (uint)bVar6);
                  log_to_file(tmp1,time_stamp_16);
                }
                else if (iVar4 != 0x1234) {
                  print_time_stamp(time_stamp_16,0x30);
                  printf("%s ",time_stamp_16);
                  uVar7 = _result__3;
                  if (_result__3 == 0U) {
                    uVar7 = 1;
                  }
                  bVar6 = (byte)uVar7;
                  if (_result__3 != 0U) {
                    bVar6 = 0;
                  }
                  printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",
                         board_sn_3,&DAT_001d3728,(uint)bVar6,response_msg);
                  uVar7 = _result__3;
                  if (_result__3 == 0U) {
                    uVar7 = 1;
                  }
                  bVar6 = (byte)uVar7;
                  if (_result__3 != 0U) {
                    bVar6 = 0;
                  }
                  snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",
                           board_sn_3,&DAT_001d3728,(uint)bVar6,response_msg);
                  log_to_file(tmp1,time_stamp_16);
                  lcd_clear_result();
                  lcd_show(0,"send mes failed");
                  memset(lcd_data_6,0,0x10);
                  snprintf(lcd_data_6,0x10,"%s",response_msg);
                  lcd_show(1,lcd_data_6);
                  if ((iVar4 != 1) && (iVar4 != -2)) {
                    save_mes_submit_result(false,time_stamp);
                  }
                }
              }
              else {
                print_time_stamp(time_stamp_16,0x30);
                printf("%s ",time_stamp_16);
                printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",board_sn_3
                       ,&DAT_001d3728,response_msg);
                snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",board_sn_3
                         ,&DAT_001d3728,response_msg);
                log_to_file(tmp1,time_stamp_16);
                lcd_clear_result();
                lcd_show(0,"mes disallowed");
                memset(lcd_data_7,0,0x10);
                snprintf(lcd_data_7,0x10,"%s",response_msg);
                lcd_show(1,lcd_data_7);
              }
              gFind_test_result = (uint8_t)_result__3;
            }
            else {
              iVar4 = strcmp(Local_Config_Information->Test_Process,"SWEEP");
              if (iVar4 == 0) {
                start_new_log("SWEEP",sn.board_sn,(Local_Config_Information->Hash_Board).Miner_Type,
                              (Local_Config_Information->Hash_Board).Board_Name);
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
                _result__4 = get_pt2_test_permission(board_sn_4,response_msg);
                if (_result__4 == 0) {
                  _result__4 = Single_Board_Sweep_Test();
                  memset(time_stamp,0,100);
                  memset(response_msg,0,100);
                  uVar7 = _result__4;
                  if (_result__4 == 0U) {
                    uVar7 = 1;
                  }
                  uVar5 = (undefined1)uVar7;
                  if (_result__4 != 0U) {
                    uVar5 = false;
                  }
                  iVar4 = send_pt2_test_result
                                    (board_sn_4,(_Bool)uVar5,_result__4 & 0xff,
                                     (int)(_result__4 & 0xff00U) >> 8,time_stamp,response_msg);
                  if (iVar4 == 0) {
                    print_time_stamp(time_stamp_16,0x30);
                    printf("%s ",time_stamp_16);
                    uVar7 = _result__4;
                    if (_result__4 == 0U) {
                      uVar7 = 1;
                    }
                    bVar6 = (byte)uVar7;
                    if (_result__4 != 0U) {
                      bVar6 = 0;
                    }
                    printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_4,"SWEEP",
                           (uint)bVar6);
                    uVar7 = _result__4;
                    if (_result__4 == 0U) {
                      uVar7 = 1;
                    }
                    bVar6 = (byte)uVar7;
                    if (_result__4 != 0U) {
                      bVar6 = 0;
                    }
                    snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_4,"SWEEP",
                             (uint)bVar6);
                    log_to_file(tmp1,time_stamp_16);
                  }
                  else if (iVar4 != 0x1234) {
                    print_time_stamp(time_stamp_16,0x30);
                    printf("%s ",time_stamp_16);
                    uVar7 = _result__4;
                    if (_result__4 == 0U) {
                      uVar7 = 1;
                    }
                    bVar6 = (byte)uVar7;
                    if (_result__4 != 0U) {
                      bVar6 = 0;
                    }
                    printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",
                           board_sn_4,"SWEEP",(uint)bVar6,response_msg);
                    uVar7 = _result__4;
                    if (_result__4 == 0U) {
                      uVar7 = 1;
                    }
                    bVar6 = (byte)uVar7;
                    if (_result__4 != 0U) {
                      bVar6 = 0;
                    }
                    snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",
                             board_sn_4,"SWEEP",(uint)bVar6,response_msg);
                    log_to_file(tmp1,time_stamp_16);
                    lcd_clear_result();
                    lcd_show(0,"send mes failed");
                    memset(lcd_data_8,0,0x10);
                    snprintf(lcd_data_8,0x10,"%s",response_msg);
                    lcd_show(1,lcd_data_8);
                    if ((iVar4 != 1) && (iVar4 != -2)) {
                      save_mes_submit_result(false,time_stamp);
                    }
                  }
                }
                else {
                  print_time_stamp(time_stamp_16,0x30);
                  printf("%s ",time_stamp_16);
                  printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                         board_sn_4,"SWEEP",response_msg);
                  snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",
                           board_sn_4,"SWEEP",response_msg);
                  log_to_file(tmp1,time_stamp_16);
                  lcd_clear_result();
                  lcd_show(0,"mes disallowed");
                  memset(lcd_data_9,0,0x10);
                  snprintf(lcd_data_9,0x10,"%s",response_msg);
                  lcd_show(1,lcd_data_9);
                }
                gFind_test_result = (uint8_t)_result__4;
                sweep_exit();
              }
              else {
                iVar4 = strcmp(Local_Config_Information->Test_Process,"PT3");
                if (iVar4 == 0) {
                  start_new_log("PT3",sn.board_sn,(Local_Config_Information->Hash_Board).Miner_Type,
                                (Local_Config_Information->Hash_Board).Board_Name);
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
                  _result__5 = get_pt2_test_permission(board_sn_5,response_msg);
                  if (_result__5 == 0) {
                    _result__5 = Single_Board_PT3_Test();
                    memset(time_stamp,0,100);
                    memset(response_msg,0,100);
                    uVar7 = _result__5;
                    if (_result__5 == 0U) {
                      uVar7 = 1;
                    }
                    uVar5 = (undefined1)uVar7;
                    if (_result__5 != 0U) {
                      uVar5 = false;
                    }
                    iVar4 = send_pt2_test_result
                                      (board_sn_5,(_Bool)uVar5,_result__5 & 0xff,
                                       (int)(_result__5 & 0xff00U) >> 8,time_stamp,response_msg);
                    if (iVar4 == 0) {
                      print_time_stamp(time_stamp_16,0x30);
                      printf("%s ",time_stamp_16);
                      uVar7 = _result__5;
                      if (_result__5 == 0U) {
                        uVar7 = 1;
                      }
                      bVar6 = (byte)uVar7;
                      if (_result__5 != 0U) {
                        bVar6 = 0;
                      }
                      printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_5,
                             &DAT_001d3734,(uint)bVar6);
                      uVar7 = _result__5;
                      if (_result__5 == 0U) {
                        uVar7 = 1;
                      }
                      bVar6 = (byte)uVar7;
                      if (_result__5 != 0U) {
                        bVar6 = 0;
                      }
                      snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_5,
                               &DAT_001d3734,(uint)bVar6);
                      log_to_file(tmp1,time_stamp_16);
                    }
                    else if (iVar4 != 0x1234) {
                      print_time_stamp(time_stamp_16,0x30);
                      printf("%s ",time_stamp_16);
                      uVar7 = _result__5;
                      if (_result__5 == 0U) {
                        uVar7 = 1;
                      }
                      bVar6 = (byte)uVar7;
                      if (_result__5 != 0U) {
                        bVar6 = 0;
                      }
                      printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n","main",
                             board_sn_5,&DAT_001d3734,(uint)bVar6,response_msg);
                      uVar7 = _result__5;
                      if (_result__5 == 0U) {
                        uVar7 = 1;
                      }
                      bVar6 = (byte)uVar7;
                      if (_result__5 != 0U) {
                        bVar6 = 0;
                      }
                      snprintf(tmp1,0x800,"SN:%s  %s result:%d send failed to mes, response_msg:%s",
                               board_sn_5,&DAT_001d3734,(uint)bVar6,response_msg);
                      log_to_file(tmp1,time_stamp_16);
                      lcd_clear_result();
                      lcd_show(0,"send mes failed");
                      memset(lcd_data_10,0,0x10);
                      snprintf(lcd_data_10,0x10,"%s",response_msg);
                      lcd_show(1,lcd_data_10);
                      if ((iVar4 != 1) && (iVar4 != -2)) {
                        save_mes_submit_result(false,time_stamp);
                      }
                    }
                  }
                  else {
                    print_time_stamp(time_stamp_16,0x30);
                    printf("%s ",time_stamp_16);
                    printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                           board_sn_5,&DAT_001d3734,response_msg);
                    snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",
                             board_sn_5,&DAT_001d3734,response_msg);
                    log_to_file(tmp1,time_stamp_16);
                    lcd_clear_result();
                    lcd_show(0,"mes disallowed");
                    memset(lcd_data_11,0,0x10);
                    snprintf(lcd_data_11,0x10,"%s",response_msg);
                    lcd_show(1,lcd_data_11);
                  }
                  gFind_test_result = (uint8_t)_result__5;
                  sweep_exit();
                }
                else {
                  iVar4 = strcmp(Local_Config_Information->Test_Process,"PT1&PT3");
                  if (iVar4 == 0) {
                    start_new_log("PT1",sn.board_sn,
                                  (Local_Config_Information->Hash_Board).Miner_Type,
                                  (Local_Config_Information->Hash_Board).Board_Name);
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
                    _result__6 = get_pt1_test_permission(board_sn_6,response_msg);
                    if (_result__6 == 0) {
                      _result__6 = Single_Board_PT1_New_Test();
                      memset(time_stamp,0,100);
                      memset(response_msg,0,100);
                      uVar7 = _result__6;
                      if (_result__6 == 0U) {
                        uVar7 = 1;
                      }
                      uVar5 = (undefined1)uVar7;
                      if (_result__6 != 0U) {
                        uVar5 = false;
                      }
                      iVar4 = send_pt1_test_result
                                        (board_sn_6,(_Bool)uVar5,_result__6 & 0xff,
                                         (int)(_result__6 & 0xff00U) >> 8,time_stamp,response_msg);
                      if (iVar4 == 0) {
                        print_time_stamp(time_stamp_16,0x30);
                        printf("%s ",time_stamp_16);
                        uVar7 = _result__6;
                        if (_result__6 == 0U) {
                          uVar7 = 1;
                        }
                        bVar6 = (byte)uVar7;
                        if (_result__6 != 0U) {
                          bVar6 = 0;
                        }
                        printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_6,"PT1new",
                               (uint)bVar6);
                        uVar7 = _result__6;
                        if (_result__6 == 0U) {
                          uVar7 = 1;
                        }
                        bVar6 = (byte)uVar7;
                        if (_result__6 != 0U) {
                          bVar6 = 0;
                        }
                        snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_6,"PT1new",
                                 (uint)bVar6);
                        log_to_file(tmp1,time_stamp_16);
                      }
                      else if (iVar4 != 0x1234) {
                        print_time_stamp(time_stamp_16,0x30);
                        printf("%s ",time_stamp_16);
                        uVar7 = _result__6;
                        if (_result__6 == 0U) {
                          uVar7 = 1;
                        }
                        bVar6 = (byte)uVar7;
                        if (_result__6 != 0U) {
                          bVar6 = 0;
                        }
                        printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n",
                               "main",board_sn_6,"PT1new",(uint)bVar6,response_msg);
                        uVar7 = _result__6;
                        if (_result__6 == 0U) {
                          uVar7 = 1;
                        }
                        bVar6 = (byte)uVar7;
                        if (_result__6 != 0U) {
                          bVar6 = 0;
                        }
                        snprintf(tmp1,0x800,
                                 "SN:%s  %s result:%d send failed to mes, response_msg:%s",
                                 board_sn_6,"PT1new",(uint)bVar6,response_msg);
                        log_to_file(tmp1,time_stamp_16);
                        lcd_clear_result();
                        lcd_show(0,"send mes failed");
                        memset(lcd_data_12,0,0x10);
                        snprintf(lcd_data_12,0x10,"%s",response_msg);
                        lcd_show(1,lcd_data_12);
                        if ((iVar4 != 1) && (iVar4 != -2)) {
                          save_mes_submit_result(true,time_stamp);
                        }
                      }
                    }
                    else {
                      print_time_stamp(time_stamp_16,0x30);
                      printf("%s ",time_stamp_16);
                      printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                             board_sn_6,"PT1new",response_msg);
                      snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",
                               board_sn_6,"PT1new",response_msg);
                      log_to_file(tmp1,time_stamp_16);
                      lcd_clear_result();
                      lcd_show(0,"mes disallowed");
                      memset(lcd_data_13,0,0x10);
                      snprintf(lcd_data_13,0x10,"%s",response_msg);
                      lcd_show(1,lcd_data_13);
                    }
                    gFind_test_result = (uint8_t)_result__6;
                    if (gFind_test_result == '\0') {
                      start_new_log("PT3",sn.board_sn,
                                    (Local_Config_Information->Hash_Board).Miner_Type,
                                    (Local_Config_Information->Hash_Board).Board_Name);
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
                      _result__7 = get_pt2_test_permission(board_sn_7,response_msg);
                      if (_result__7 == 0) {
                        _result__7 = Single_Board_PT3_Test();
                        memset(time_stamp,0,100);
                        memset(response_msg,0,100);
                        uVar7 = _result__7;
                        if (_result__7 == 0U) {
                          uVar7 = 1;
                        }
                        uVar5 = (undefined1)uVar7;
                        if (_result__7 != 0U) {
                          uVar5 = false;
                        }
                        iVar4 = send_pt2_test_result
                                          (board_sn_7,(_Bool)uVar5,_result__7 & 0xff,
                                           (int)(_result__7 & 0xff00U) >> 8,time_stamp,response_msg)
                        ;
                        if (iVar4 == 0) {
                          print_time_stamp(time_stamp_16,0x30);
                          printf("%s ",time_stamp_16);
                          uVar7 = _result__7;
                          if (_result__7 == 0U) {
                            uVar7 = 1;
                          }
                          bVar6 = (byte)uVar7;
                          if (_result__7 != 0U) {
                            bVar6 = 0;
                          }
                          printf("%s: SN:%s %s result:%d send ok to mes\n","main",board_sn_7,
                                 &DAT_001d3734,(uint)bVar6);
                          uVar7 = _result__7;
                          if (_result__7 == 0U) {
                            uVar7 = 1;
                          }
                          bVar6 = (byte)uVar7;
                          if (_result__7 != 0U) {
                            bVar6 = 0;
                          }
                          snprintf(tmp1,0x800,"SN:%s %s result:%d send ok to mes",board_sn_7,
                                   &DAT_001d3734,(uint)bVar6);
                          log_to_file(tmp1,time_stamp_16);
                        }
                        else if (iVar4 != 0x1234) {
                          print_time_stamp(time_stamp_16,0x30);
                          printf("%s ",time_stamp_16);
                          uVar7 = _result__7;
                          if (_result__7 == 0U) {
                            uVar7 = 1;
                          }
                          bVar6 = (byte)uVar7;
                          if (_result__7 != 0U) {
                            bVar6 = 0;
                          }
                          printf("%s: SN:%s  %s result:%d send failed to mes, response_msg:%s\n",
                                 "main",board_sn_7,&DAT_001d3734,(uint)bVar6,response_msg);
                          uVar7 = _result__7;
                          if (_result__7 == 0U) {
                            uVar7 = 1;
                          }
                          bVar6 = (byte)uVar7;
                          if (_result__7 != 0U) {
                            bVar6 = 0;
                          }
                          snprintf(tmp1,0x800,
                                   "SN:%s  %s result:%d send failed to mes, response_msg:%s",
                                   board_sn_7,&DAT_001d3734,(uint)bVar6,response_msg);
                          log_to_file(tmp1,time_stamp_16);
                          lcd_clear_result();
                          lcd_show(0,"send mes failed");
                          memset(lcd_data_14,0,0x10);
                          snprintf(lcd_data_14,0x10,"%s",response_msg);
                          lcd_show(1,lcd_data_14);
                          if ((iVar4 != 1) && (iVar4 != -2)) {
                            save_mes_submit_result(false,time_stamp);
                          }
                        }
                      }
                      else {
                        print_time_stamp(time_stamp_16,0x30);
                        printf("%s ",time_stamp_16);
                        printf("%s: SN:%s %s test is disallowed by MES, response_msg:%s\n","main",
                               board_sn_7,&DAT_001d3734,response_msg);
                        snprintf(tmp1,0x800,"SN:%s %s test is disallowed by MES, response_msg:%s",
                                 board_sn_7,&DAT_001d3734,response_msg);
                        log_to_file(tmp1,time_stamp_16);
                        lcd_clear_result();
                        lcd_show(0,"mes disallowed");
                        memset(lcd_data_15,0,0x10);
                        snprintf(lcd_data_15,0x10,"%s",response_msg);
                        lcd_show(1,lcd_data_15);
                      }
                      gFind_test_result = (uint8_t)_result__7;
                      sweep_exit();
                    }
                  }
                  else {
                    iVar4 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
                    if (iVar4 == 0) {
                      Single_Board_Reset_Low_Test();
                    }
                    else {
                      lcd_clear_result();
                      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                      lcd_show(1,"Test Process");
                      lcd_show(2,"error");
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
      printf("%s: build version information::  %s.\n\n","main",
             "version: 2cbff4a193ca16eb0aa2363a52d8e76db948458d commit: 2023-08-02 15:03:49 build: 2023-08-02 15:04:56"
            );
      snprintf(tmp1,0x800,"build version information::  %s.\n",
               "version: 2cbff4a193ca16eb0aa2363a52d8e76db948458d commit: 2023-08-02 15:03:49 build: 2023-08-02 15:04:56"
              );
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: author information::  %s.\n\n","main",
             "author: yinghai.li      email: yinghai.li@bitmaincorp.com");
      snprintf(tmp1,0x800,"author information::  %s.\n",
               "author: yinghai.li      email: yinghai.li@bitmaincorp.com");
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: TEST OVER...\n","main");
      builtin_strncpy(tmp1,"TEST OVER...",0xc);
      tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      gCheck_chain_status = true;
      if (g_user_chain == 0xff) {
LAB_0004de38:
        gCheck_chain_status = true;
        while (gCheck_chain_status != false) {
          check_whether_hashboard_plug_in_again();
          if (gHashBoard_plug_in_again != false) {
            sleep(1);
            display_main_page();
            gCheck_chain_status = false;
            gHashBoard_plug_in_again = false;
          }
        }
      }
      return 0;
    }
    gScanCodeGun_data_ready = '\0';
  } while( true );
}

