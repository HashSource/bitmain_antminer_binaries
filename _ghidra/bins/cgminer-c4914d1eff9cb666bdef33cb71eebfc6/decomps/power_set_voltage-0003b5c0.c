
uint8_t power_set_voltage(power_info_t *power,uint8_t da_value)

{
  _Bool _Var1;
  uint8_t uVar2;
  FILE *pFVar3;
  int iVar4;
  uint8_t da_value_local;
  power_info_t *power_local;
  FILE *pFile;
  FILE *pFile_1;
  uint8_t ret;
  
  _Var1 = is_T11();
  if (_Var1) {
    if (power->chain_num == 0xff) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: error! power info is not correct, please check!\n","power.c",
                  0x235,"power_set_voltage");
        }
        fclose(pFVar3);
      }
      uVar2 = 0xff;
    }
    else {
      iVar4 = set_pic_da_value(power->chain_num,da_value);
      uVar2 = (uint8_t)iVar4;
    }
  }
  else if (power->chain_num == 0xff) {
    _Var1 = power_is_support_cmd_package();
    if (_Var1) {
      power_set_da_value(da_value);
      uVar2 = '\0';
    }
    else {
      uVar2 = power_set_da_value_simple(da_value);
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: error! power info is not correct, please check!\n","power.c",0x240
                ,"power_set_voltage");
      }
      fclose(pFVar3);
    }
    uVar2 = 0xff;
  }
  return uVar2;
}

