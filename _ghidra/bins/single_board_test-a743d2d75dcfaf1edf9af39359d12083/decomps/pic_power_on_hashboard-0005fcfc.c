
_Bool pic_power_on_hashboard(int chain)

{
  char *pcVar1;
  int32_t iVar2;
  int iVar3;
  int chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t i;
  
  chain_reset_low(chain);
  usleep(1000000);
  if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
     ((pcVar1 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56601"),
      pcVar1 == (char *)0x0 ||
      (pcVar1 = strstr((Local_Config_Information->Hash_Board).Miner_Type,"HHB56611"),
      pcVar1 == (char *)0x0)))) {
    iVar2 = enable_dc_dc((uint8_t)chain);
    if (iVar2 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: PIC power on ok\n","pic_power_on_hashboard");
      builtin_strncpy(tmp1,"PIC power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar2 = enable_dc_dc((uint8_t)chain);
      if (iVar2 != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: PIC_EN enable fail\n","pic_power_on_hashboard");
        builtin_strncpy(tmp1,"PIC_EN enable fa",0x10);
        tmp1[0x10] = 'i';
        tmp1[0x11] = 'l';
        tmp1[0x12] = '\0';
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: PIC power on ok\n","pic_power_on_hashboard");
      builtin_strncpy(tmp1,"PIC power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  usleep(1000000);
  iVar3 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
  if (iVar3 != 0) {
    chain_reset_high(chain);
    usleep(300000);
    chain_reset_low(chain);
    usleep(1000000);
    chain_reset_high(chain);
    usleep(300000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: fpga reset one more time\n","pic_power_on_hashboard");
    builtin_strncpy(tmp1,"fpga reset one more time",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return true;
}

