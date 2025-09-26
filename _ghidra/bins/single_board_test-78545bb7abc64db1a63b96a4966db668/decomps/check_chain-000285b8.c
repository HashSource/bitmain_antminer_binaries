
/* WARNING: Unknown calling convention */

_Bool check_chain(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  _Bool _Var3;
  char *pcVar4;
  char time_stamp [48];
  char tmp1 [256];
  bitmain_sys_capability_t info;
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","check_chain");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  get_system_capability(&info);
  if (g_user_chain == 0xff) {
    if (info.board_num == 0) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"No Hashboard");
      lcd_show(2,"No Scan code gun");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Don\'t detect hashboard and scan code gun\n","check_chain");
      builtin_strncpy(tmp1,"Don\'t detect hashboard and scan code gun",0x28);
      tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      gHashBoard_plug_in = false;
      _Var3 = false;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : info.board_num = %d\n","check_chain",info.board_num);
      snprintf(tmp1,0x100,"info.board_num = %d",info.board_num);
      log_to_file(tmp1,time_stamp);
      uVar2 = info.board_num;
      if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) {
        if (info.board_num == 2) {
          gChain = info.board[0].board_id;
          gHashBoard_plug_in = true;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : gChain = %d\n","check_chain",gChain);
          snprintf(tmp1,0x100,"gChain = %d",gChain);
          log_to_file(tmp1,time_stamp);
          gCode_gun_chain = info.board[info.board_num - 1].board_id;
          if (gCode_gun_chain == 3) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : gCode_gun_chain = %d\n","check_chain",gCode_gun_chain);
            snprintf(tmp1,0x100,"gCode_gun_chain = %d",gCode_gun_chain);
            log_to_file(tmp1,time_stamp);
            _Var3 = true;
          }
          else {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"Scan code gun");
            lcd_show(2,"don\'t plug on");
            lcd_show(3,"J4");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Scan code gun don\'t plug on J4\n","check_chain");
            builtin_strncpy(tmp1,"Scan code gun don\'t plug on J4",0x1f);
            log_to_file(tmp1,time_stamp);
            gHashBoard_plug_in = false;
            _Var3 = false;
          }
        }
        else {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Only support");
          lcd_show(2,"one Hashboard");
          lcd_show(2,"one Code gun");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Only support one Hashboard and one Code gun\n","check_chain");
          builtin_strncpy(tmp1,"Only support one Hashboard and one Code gun",0x2c);
          log_to_file(tmp1,time_stamp);
          gHashBoard_plug_in = false;
          _Var3 = false;
        }
      }
      else {
        do {
          uVar1 = uVar2;
          i = uVar1 - 1;
          if (i < 0) {
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"check chain fail");
            lcd_show(2,"no Hashboard");
            gHashBoard_plug_in = false;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            if (info.board_num == 0) {
              pcVar4 = "no chain connnected";
            }
            else {
              pcVar4 = "J4 used as scan gun";
            }
            printf("%s : not found hashboard, %s\n","check_chain",pcVar4);
            if (info.board_num == 0) {
              pcVar4 = "no chain connnected";
            }
            else {
              pcVar4 = "J4 used as scan gun";
            }
            snprintf(tmp1,0x100,"not found hashboard, %s",pcVar4);
            log_to_file(tmp1,time_stamp);
            return false;
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : boardID %d\n","check_chain",info.board[uVar1 - 1].board_id);
          snprintf(tmp1,0x100,"boardID %d",info.board[uVar1 - 1].board_id);
          log_to_file(tmp1,time_stamp);
          uVar2 = i;
        } while (info.board[uVar1 - 1].board_id == 3);
        if (i < 1) {
          gChain = info.board[uVar1 - 1].board_id;
          gHashBoard_plug_in = true;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : gChain = %d\n","check_chain",gChain);
          snprintf(tmp1,0x100,"gChain = %d",gChain);
          log_to_file(tmp1,time_stamp);
          _Var3 = true;
        }
        else {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Only support");
          lcd_show(2,"one Hashboard");
          gHashBoard_plug_in = false;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Only support one Hashboard\n","check_chain");
          builtin_strncpy(tmp1,"Only support one Hashboard",0x1b);
          log_to_file(tmp1,time_stamp);
          _Var3 = false;
        }
      }
    }
  }
  else {
    _Var3 = check_specific_chain(g_user_chain);
  }
  return _Var3;
}

