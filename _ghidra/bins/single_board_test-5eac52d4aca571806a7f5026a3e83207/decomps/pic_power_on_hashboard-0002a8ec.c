
/* WARNING: Unknown calling convention */

_Bool pic_power_on_hashboard(void)

{
  int32_t iVar1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t i;
  
  chain_reset_low(gChain);
  usleep(1000000);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    iVar1 = enable_dc_dc((uint8_t)gChain);
    if (iVar1 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC power on ok\n","pic_power_on_hashboard");
      builtin_strncpy(tmp1,"PIC power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar1 = enable_dc_dc((uint8_t)gChain);
      if (iVar1 != 0) {
        gHistory_Result[gPattern_test_counter].pic_ok = false;
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"PIC Power on");
        lcd_show(2,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : PIC_EN enable fail\n","pic_power_on_hashboard");
        builtin_strncpy(tmp1,"PIC_EN enable fa",0x10);
        tmp1[0x10] = 'i';
        tmp1[0x11] = 'l';
        tmp1[0x12] = '\0';
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC power on ok\n","pic_power_on_hashboard");
      builtin_strncpy(tmp1,"PIC power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  usleep(1000000);
  iVar2 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
  if (iVar2 != 0) {
    chain_reset_high(gChain);
    usleep(300000);
    chain_reset_low(gChain);
    usleep(1000000);
    chain_reset_high(gChain);
    usleep(300000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fpga reset one more time\n","pic_power_on_hashboard");
    builtin_strncpy(tmp1,"fpga reset one more time",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return true;
}

