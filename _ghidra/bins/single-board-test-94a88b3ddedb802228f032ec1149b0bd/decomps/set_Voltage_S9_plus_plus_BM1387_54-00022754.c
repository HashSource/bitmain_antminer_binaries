
undefined4 set_Voltage_S9_plus_plus_BM1387_54(byte param_1,byte param_2)

{
  char cVar1;
  char cVar2;
  FILE *__stream;
  undefined4 uVar3;
  int local_c;
  
  local_c = 0;
  printf("voltage1 = %d\n",(uint)param_2);
  if ((char)param_2 < '\0') {
    printf("\n--- %s voltage1(%d) > 127 \n\n","set_Voltage_S9_plus_plus_BM1387_54",(uint)param_2);
    uVar3 = 0;
  }
  else if (param_2 == T9_18_chain_voltage[param_1]) {
    uVar3 = 1;
  }
  else {
    T9_18_chain_voltage[param_1] = param_2;
    while (local_c < 3) {
      pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
      T9_plus_write_pic_iic(0,0,0,param_1,0x55);
      T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
      T9_plus_write_pic_iic(0,0,0,param_1,7);
      T9_plus_write_pic_iic(0,0,0,param_1,0x10);
      T9_plus_write_pic_iic(0,0,0,param_1,param_2);
      T9_plus_write_pic_iic(0,0,0,param_1,0);
      T9_plus_write_pic_iic(0,0,0,param_1,0);
      T9_plus_write_pic_iic(0,0,0,param_1,(char)((ushort)(param_2 + 0x17) >> 8));
      T9_plus_write_pic_iic(0,0,0,param_1,(char)(param_2 + 0x17));
      usleep(400000);
      cVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      cVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
      if ((cVar1 == '\x10') && (cVar2 == '\x01')) {
        printf("\n--- %s ok!\n\n","set_Voltage_S9_plus_plus_BM1387_54");
        AT24C02_save_voltage(param_1,param_2);
        sleep(5);
        return 1;
      }
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: %s failed on Chain[%d]!\n\n","driver-bitmain.c",0x176b,
                  "set_Voltage_S9_plus_plus_BM1387_54",(uint)param_1);
        }
        fclose(__stream);
      }
      sleep(1);
      local_c = local_c + 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

