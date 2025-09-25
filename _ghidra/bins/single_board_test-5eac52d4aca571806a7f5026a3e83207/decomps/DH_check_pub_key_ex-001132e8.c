
uint DH_check_pub_key_ex(DH *param_1,BIGNUM *param_2)

{
  uint uVar1;
  int local_c [2];
  
  local_c[0] = 0;
  uVar1 = DH_check_pub_key(param_1,param_2,local_c);
  if (uVar1 != 0) {
    if (local_c[0] << 0x1f < 0) {
      ERR_put_error(5,0x7b,0x7c,"crypto/dh/dh_check.c",0xab);
    }
    if (local_c[0] << 0x1e < 0) {
      ERR_put_error(5,0x7b,0x7b,"crypto/dh/dh_check.c",0xad);
    }
    if (local_c[0] << 0x1d < 0) {
      ERR_put_error(5,0x7b,0x7a,"crypto/dh/dh_check.c",0xaf);
    }
    uVar1 = (uint)(local_c[0] == 0);
  }
  return uVar1;
}

