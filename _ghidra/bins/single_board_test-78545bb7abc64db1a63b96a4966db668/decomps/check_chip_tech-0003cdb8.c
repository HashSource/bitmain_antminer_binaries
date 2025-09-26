
_Bool check_chip_tech(_Bool is_pt1)

{
  _Bool _Var1;
  int iVar2;
  char *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  _Bool is_pt1_local;
  char time_stamp [48];
  char tmp1 [256];
  char chip_tech [2] [3];
  
  if (!is_pt1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Local_Config_Information->Hash_Board.Board_Name %s, eeprom_ctx.data.board_name %s\n"
           ,"check_chip_tech",(Local_Config_Information->Hash_Board).Board_Name,0x21baead);
    snprintf(tmp1,0x100,
             "Local_Config_Information->Hash_Board.Board_Name %s, eeprom_ctx.data.board_name %s",
             (Local_Config_Information->Hash_Board).Board_Name,0x21baead);
    log_to_file(tmp1,time_stamp);
    iVar2 = strcmp((Local_Config_Information->Hash_Board).Board_Name,eeprom_ctx.data.board_name);
    if (iVar2 != 0) {
      return false;
    }
  }
  chip_tech[0][0] = '\0';
  chip_tech[0][1] = '\0';
  chip_tech[0][2] = '\0';
  chip_tech[1][0] = '\0';
  chip_tech[1][1] = '\0';
  chip_tech[1][2] = '\0';
  _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
  if (_Var1) {
    strncpy(chip_tech[0],qr_code.chip_marking + 4,2);
    strncpy(chip_tech[1],qr_code.chip_marking + 10,2);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : check chip tech : chip_tech[0] %s, chip_tech[1] %s\n","check_chip_tech",chip_tech,
           chip_tech + 1);
    snprintf(tmp1,0x100,"check chip tech : chip_tech[0] %s, chip_tech[1] %s",chip_tech,chip_tech + 1
            );
    log_to_file(tmp1,time_stamp);
  }
  else if (is_pt1) {
    strncpy(chip_tech[0],qr_code.hashboard_ctrl_code + 5,3);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : check chip tech : chip_tech[0] %s\n","check_chip_tech",chip_tech);
    snprintf(tmp1,0x100,"check chip tech : chip_tech[0] %s",chip_tech);
    log_to_file(tmp1,time_stamp);
  }
  else {
    strncpy(chip_tech[0],(char *)(eeprom_ctx.data.field_2.raw + 0x45),3);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : check chip tech : chip_tech[0] %s\n","check_chip_tech",chip_tech);
    snprintf(tmp1,0x100,"check chip tech : chip_tech[0] %s",chip_tech);
    log_to_file(tmp1,time_stamp);
  }
  pcVar3 = strstr((Local_Config_Information->Hash_Board).Board_Name,"70501");
  if ((pcVar3 == (char *)0x0) &&
     (pcVar3 = strstr((Local_Config_Information->Hash_Board).Board_Name,"70503"),
     pcVar3 == (char *)0x0)) {
    pcVar3 = strstr((Local_Config_Information->Hash_Board).Board_Name,"70502");
    if (pcVar3 == (char *)0x0) {
      uVar4 = 1;
    }
    else {
      _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
      if (_Var1) {
        pcVar3 = strstr(chip_tech[0],"PM");
        if ((pcVar3 == (char *)0x0) || (pcVar3 = strstr(chip_tech[1],"PM"), pcVar3 == (char *)0x0))
        {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
      }
      else {
        pcVar3 = strstr(chip_tech[0],"PM");
        bVar5 = pcVar3 != (char *)0x0;
        if (bVar5) {
          pcVar3 = (char *)0x1;
        }
        uVar4 = SUB41(pcVar3,0);
        if (!bVar5) {
          uVar4 = 0;
        }
      }
    }
  }
  else {
    _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
    if (_Var1) {
      pcVar3 = strstr(chip_tech[0],"PA");
      if ((((pcVar3 == (char *)0x0) && (pcVar3 = strstr(chip_tech[0],"PB"), pcVar3 == (char *)0x0))
          && ((pcVar3 = strstr(chip_tech[0],"PF"), pcVar3 == (char *)0x0 &&
              (pcVar3 = strstr(chip_tech[0],"PM"), pcVar3 == (char *)0x0)))) ||
         (((pcVar3 = strstr(chip_tech[1],"PA"), pcVar3 == (char *)0x0 &&
           (pcVar3 = strstr(chip_tech[1],"PB"), pcVar3 == (char *)0x0)) &&
          ((pcVar3 = strstr(chip_tech[0],"PF"), pcVar3 == (char *)0x0 &&
           (pcVar3 = strstr(chip_tech[0],"PM"), pcVar3 == (char *)0x0)))))) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      pcVar3 = strstr(chip_tech[0],"PA");
      if ((((pcVar3 == (char *)0x0) && (pcVar3 = strstr(chip_tech[0],"PB"), pcVar3 == (char *)0x0))
          && (pcVar3 = strstr(chip_tech[0],"PF"), pcVar3 == (char *)0x0)) &&
         (pcVar3 = strstr(chip_tech[0],"PM"), pcVar3 == (char *)0x0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
  }
  return (_Bool)uVar4;
}

