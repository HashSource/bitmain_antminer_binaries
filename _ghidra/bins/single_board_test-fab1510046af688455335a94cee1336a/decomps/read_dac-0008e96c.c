
_Bool read_dac(uint8_t which_chain,uint8_t which_dac,uint8_t which_reg,uint8_t *data,
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
  uint8_t dac_addr;
  int32_t i;
  
  if (which_dac == '\x01') {
    iVar1 = pic_read_iic(which_chain,'H',which_reg,data,data_length);
    if (iVar1 == data_length) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: dac: %d, register 0x%02x data is:\n","read_dac",1,(uint)which_reg);
      snprintf(tmp1,0x800,"dac: %d, register 0x%02x data is:",1,(uint)which_reg);
      log_to_file(tmp1,time_stamp);
      for (i = 0; i < data_length; i = i + 1) {
        printf("0x%02x",(uint)data[i]);
      }
      putchar(10);
      _Var2 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chain: %d, dac_addr: 0x%02x, data_length = %d, fail.\n","read_dac",
             (uint)which_chain,0x48,data_length);
      snprintf(tmp1,0x800,"chain: %d, dac_addr: 0x%02x, data_length = %d, fail.",(uint)which_chain,
               0x48,data_length);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: read dac: %d, register: 0x%02x, fail.\n","read_dac",1,(uint)which_reg);
      snprintf(tmp1,0x800,"read dac: %d, register: 0x%02x, fail.",1,(uint)which_reg);
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t support DAC: %d\n","read_dac",(uint)which_dac);
    snprintf(tmp1,0x800,"Don\'t support DAC: %d",(uint)which_dac);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

