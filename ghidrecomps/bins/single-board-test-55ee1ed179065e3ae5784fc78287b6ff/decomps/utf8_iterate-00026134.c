
byte * utf8_iterate(byte *param_1,uint *param_2)

{
  int iVar1;
  uint local_10;
  int local_c;
  
  if (*param_1 != 0) {
    local_c = utf8_check_first(*param_1);
    if (local_c < 1) {
      param_1 = (byte *)0x0;
    }
    else {
      if (local_c == 1) {
        local_10 = (uint)*param_1;
      }
      else {
        iVar1 = utf8_check_full(param_1,local_c,&local_10);
        if (iVar1 == 0) {
          return (byte *)0x0;
        }
      }
      if (param_2 != (uint *)0x0) {
        *param_2 = local_10;
      }
      param_1 = param_1 + local_c;
    }
  }
  return param_1;
}

