
_Bool pf_init(uint32_t chain)

{
  _Bool _Var1;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  
  _Var1 = init_fpga();
  if (_Var1) {
    _Var1 = pf_check_specific_chain(chain);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s :  init fpga failed\n\n","pf_init");
    builtin_strncpy(tmp1," init fpga faile",0x10);
    tmp1[0x10] = 'd';
    tmp1[0x11] = '\n';
    tmp1[0x12] = '\0';
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

