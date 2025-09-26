
_Bool write_dac(uint8_t which_chain,uint8_t which_dac,uint8_t which_reg,uint8_t *data,
               int32_t data_length)

{
  int32_t iVar1;
  _Bool _Var2;
  uint8_t *data_local;
  uint8_t which_reg_local;
  uint8_t which_dac_local;
  uint8_t which_chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  int32_t i;
  uint8_t dac_addr;
  
  if (which_dac == '\x01') {
    iVar1 = pic_write_iic(which_chain,'H',which_reg,data,data_length);
    if (iVar1 == data_length) {
      _Var2 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: write dac: %d, register:%d, fail.\n","write_dac",1,(uint)which_reg);
      snprintf(tmp1,0x800,"write dac: %d, register:%d, fail.",1,(uint)which_reg);
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t support DAC: %d\n","write_dac",(uint)which_dac);
    snprintf(tmp1,0x800,"Don\'t support DAC: %d",(uint)which_dac);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

