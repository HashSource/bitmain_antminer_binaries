
/* WARNING: Unknown calling convention */

_Bool prepare_test_standard(void)

{
  Hash_Board *pHVar1;
  Hash_Board *pHVar2;
  byte bVar3;
  _Bool _Var4;
  Hash_Board *miner_type;
  char time_stamp [48];
  char tmp1 [2048];
  char chip_technology [4];
  char bom_version [4];
  char hw_version [4];
  
  hw_version[0] = '\0';
  hw_version[1] = '\0';
  hw_version[2] = '\0';
  hw_version[3] = '\0';
  bom_version[0] = '\0';
  bom_version[1] = '\0';
  bom_version[2] = '\0';
  bom_version[3] = '\0';
  chip_technology[0] = '\0';
  chip_technology[1] = '\0';
  chip_technology[2] = '\0';
  chip_technology[3] = '\0';
  substr(qr_code.hashboard_ctrl_code,0,3,hw_version);
  substr(qr_code.hashboard_ctrl_code,3,2,bom_version);
  substr(qr_code.hashboard_ctrl_code,5,2,chip_technology);
  miner_type = &Local_Config_Information->Hash_Board;
  pHVar1 = &Local_Config_Information->Hash_Board;
  pHVar2 = &Local_Config_Information->Hash_Board;
  bVar3 = get_chip_bin(&qr_code);
  _Var4 = find_test_standard_position
                    (miner_type->Miner_Type,pHVar1->Board_Name,pHVar2->Asic_Type,hw_version,
                     bom_version,chip_technology,qr_code.chip_ftversion,(uint)bVar3);
  if (_Var4) {
    gFind_test_standard = true;
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Find test");
    lcd_show(2,"standard");
    lcd_show(3,"Press Start Key");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: find test standard, Press Start Key to Begin Test\n","prepare_test_standard");
    builtin_strncpy(tmp1,"find test standard, Press Start Key to Begin Tes",0x30);
    tmp1[0x30] = 't';
    tmp1[0x31] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    gFind_test_standard = false;
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Can\'t find");
    lcd_show(2,"test standard");
    lcd_show(3,"please re-scan");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Can\'t find test standard\n","prepare_test_standard");
    builtin_strncpy(tmp1,"Can\'t find test standard",0x18);
    tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  return _Var4;
}

