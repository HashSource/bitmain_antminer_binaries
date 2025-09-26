
uint DH_check_params_ex(undefined4 param_1)

{
  uint uVar1;
  int local_c [2];
  
  local_c[0] = 0;
  uVar1 = DH_check_params(param_1,local_c);
  if (uVar1 != 0) {
    if (local_c[0] << 0x1f < 0) {
      ERR_put_error(5,0x7a,0x75,"crypto/dh/dh_check.c",0x1f);
    }
    if (local_c[0] << 0x1c < 0) {
      ERR_put_error(5,0x7a,0x78,"crypto/dh/dh_check.c",0x21);
    }
    uVar1 = (uint)(local_c[0] == 0);
  }
  return uVar1;
}

