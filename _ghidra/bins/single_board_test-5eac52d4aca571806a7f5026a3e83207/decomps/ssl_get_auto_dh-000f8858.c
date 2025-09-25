
DH * ssl_get_auto_dh(int param_1)

{
  DH *dh;
  BIGNUM *a;
  int iVar1;
  BIGNUM *a_00;
  int iVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x404) + 0xc) == 2) {
    iVar2 = 0x50;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
    if ((*(uint *)(iVar2 + 0x14) & 0x14) == 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x264);
      if (iVar2 == 0) {
        return (DH *)0x0;
      }
      iVar2 = EVP_PKEY_security_bits(*(undefined4 *)(iVar2 + 4));
    }
    else if (*(int *)(iVar2 + 0x38) == 0x100) {
      iVar2 = 0x80;
    }
    else {
      iVar2 = 0x50;
    }
  }
  dh = DH_new();
  if (dh != (DH *)0x0) {
    a = BN_new();
    if ((a != (BIGNUM *)0x0) && (iVar1 = BN_set_word(a,2), iVar1 != 0)) {
      iVar1 = ssl_get_security_level_bits(param_1,0);
      if (iVar1 < iVar2) {
        iVar1 = iVar2;
      }
      if (iVar1 < 0xc0) {
        if (iVar1 < 0x98) {
          if (iVar1 < 0x80) {
            if (iVar1 < 0x70) {
              a_00 = (BIGNUM *)BN_get_rfc2409_prime_1024(0);
            }
            else {
              a_00 = (BIGNUM *)BN_get_rfc3526_prime_2048();
            }
          }
          else {
            a_00 = (BIGNUM *)BN_get_rfc3526_prime_3072(0);
          }
        }
        else {
          a_00 = (BIGNUM *)BN_get_rfc3526_prime_4096(0);
        }
      }
      else {
        a_00 = (BIGNUM *)BN_get_rfc3526_prime_8192(0);
      }
      if ((a_00 != (BIGNUM *)0x0) && (iVar2 = DH_set0_pqg(dh,a_00,0,a), iVar2 != 0)) {
        return dh;
      }
      DH_free(dh);
      BN_free(a_00);
      BN_free(a);
      return (DH *)0x0;
    }
    DH_free(dh);
    BN_free(a);
  }
  return (DH *)0x0;
}

