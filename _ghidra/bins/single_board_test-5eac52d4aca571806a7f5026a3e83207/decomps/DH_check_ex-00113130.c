
/* WARNING: Type propagation algorithm not settling */

uint DH_check_ex(DH *param_1)

{
  uint uVar1;
  int local_c [2];
  
  local_c[0] = 0;
  uVar1 = DH_check(param_1,local_c);
  if (uVar1 != 0) {
    if (local_c[0] << 0x1c < 0) {
      ERR_put_error(5,0x79,0x78,"crypto/dh/dh_check.c",0x51);
    }
    if (local_c[0] << 0x1b < 0) {
      ERR_put_error(5,0x79,0x77,"crypto/dh/dh_check.c",0x53);
    }
    if (local_c[0] << 0x1a < 0) {
      ERR_put_error(5,0x79,0x74,"crypto/dh/dh_check.c",0x55);
    }
    if (local_c[0] << 0x19 < 0) {
      ERR_put_error(5,0x79,0x73,"crypto/dh/dh_check.c",0x57);
    }
    if (local_c[0] << 0x1d < 0) {
      ERR_put_error(5,0x79,0x79,"crypto/dh/dh_check.c",0x59);
    }
    if (local_c[0] << 0x1f < 0) {
      ERR_put_error(5,0x79,0x75,"crypto/dh/dh_check.c",0x5b);
    }
    if (local_c[0] << 0x1e < 0) {
      ERR_put_error(5,0x79,0x76,"crypto/dh/dh_check.c",0x5d);
    }
    uVar1 = (uint)(local_c[0] == 0);
  }
  return uVar1;
}

