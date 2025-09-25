
int flush_eeprom_data(float *matrix,int chain)

{
  _Bool _Var1;
  int iVar2;
  int chain_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 *ctx;
  eeprom_v1 eeprom_tmp;
  _Bool temp;
  
  _Var1 = build_eeprom_data_pt2(true,&g_rt,matrix);
  if (_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : customer repair mode no need write eeprom, test success\n","flush_eeprom_data");
    builtin_strncpy(tmp1,"customer repair mode no need write eeprom, test success",0x38);
    log_to_file(tmp1,time_stamp);
    iVar2 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : build eeprom data failed\n","flush_eeprom_data");
    builtin_strncpy(tmp1,"build eeprom data failed",0x18);
    tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  return iVar2;
}

