
int pkey_dh_derive(int param_1,uchar *param_2,int *param_3)

{
  uchar *key;
  int iVar1;
  DH *dh;
  int iVar2;
  int iVar3;
  BIGNUM *pub_key;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    ERR_put_error(5,0x70,0x6c,"crypto/dh/dh_pmeth.c",0x1ac);
    return 0;
  }
  dh = *(DH **)(*(int *)(param_1 + 8) + 0x18);
  pub_key = *(BIGNUM **)(*(int *)(*(int *)(param_1 + 0xc) + 0x18) + 0x14);
  if (*(char *)(iVar3 + 0x28) == '\x01') {
    if (param_2 == (uchar *)0x0) {
      iVar3 = DH_size(dh);
      *param_3 = iVar3;
      return 1;
    }
    if (*(int *)(iVar3 + 0x10) == 0) {
      iVar3 = DH_compute_key(param_2,pub_key,dh);
    }
    else {
      iVar3 = DH_compute_key_padded(param_2,pub_key,dh);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    *param_3 = iVar3;
    return 1;
  }
  if (*(char *)(iVar3 + 0x28) == '\x02') {
    iVar2 = *(int *)(iVar3 + 0x3c);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 0x2c) == 0) {
      return 0;
    }
    if (param_2 == (uchar *)0x0) {
      *param_3 = iVar2;
      return 1;
    }
    if (iVar2 == *param_3) {
      iVar2 = DH_size(dh);
      key = (uchar *)CRYPTO_malloc(iVar2,"crypto/dh/dh_pmeth.c",0x1ce);
      if (((key == (uchar *)0x0) || (iVar1 = DH_compute_key_padded(key,pub_key,dh), iVar1 < 1)) ||
         (iVar1 = DH_KDF_X9_42(param_2,*param_3,key,iVar2,*(undefined4 *)(iVar3 + 0x2c),
                               *(undefined4 *)(iVar3 + 0x34),*(undefined4 *)(iVar3 + 0x38),
                               *(undefined4 *)(iVar3 + 0x30)), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
        *param_3 = *(int *)(iVar3 + 0x3c);
      }
      CRYPTO_clear_free(key,iVar2,"crypto/dh/dh_pmeth.c",0x1da);
      return iVar1;
    }
  }
  return 0;
}

