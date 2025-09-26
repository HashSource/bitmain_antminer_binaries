
_Bool set_dac53401_voltage(uint8_t which_chain,uint32_t voltage_N)

{
  _Bool _Var1;
  uint32_t voltage_N_local;
  uint8_t which_chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t data [2];
  uint32_t N;
  
  data[0] = (uint8_t)((voltage_N << 2) >> 8);
  data[1] = (uint8_t)(voltage_N << 2);
  _Var1 = write_dac(which_chain,'\x01','!',data,2);
  if (!_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: fail\n","set_dac53401_voltage");
    builtin_strncpy(tmp1,"fail",4);
    tmp1[4] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return _Var1;
}

