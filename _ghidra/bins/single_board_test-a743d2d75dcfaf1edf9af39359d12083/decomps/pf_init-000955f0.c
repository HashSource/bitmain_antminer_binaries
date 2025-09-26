
_Bool pf_init(uint32_t chain)

{
  _Bool _Var1;
  uint32_t chain_local;
  char tmp42 [256];
  
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
    builtin_strncpy(tmp42," init fpga faile",0x10);
    tmp42[0x10] = 'd';
    tmp42[0x11] = '\n';
    tmp42[0x12] = '\0';
    puts(tmp42);
    _Var1 = false;
  }
  return _Var1;
}

