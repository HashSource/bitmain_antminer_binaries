
int pkey_dh_derive(int param_1,uchar *param_2,int *param_3)

{
  size_t len;
  uchar *key;
  int iVar1;
  DH *dh;
  BIGNUM *pub_key;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    ERR_put_error(5,0x70,0x6c,DAT_00100820,0x1b4);
    iVar2 = 0;
  }
  else {
    dh = *(DH **)(*(int *)(param_1 + 8) + 0x14);
    pub_key = *(BIGNUM **)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x14);
    if (*(char *)(iVar2 + 0x20) == '\x01') {
      if (param_2 == (uchar *)0x0) {
        iVar2 = DH_size(dh);
        *param_3 = iVar2;
        iVar2 = 1;
      }
      else {
        iVar2 = DH_compute_key(param_2,pub_key,dh);
        if (-1 < iVar2) {
          *param_3 = iVar2;
          iVar2 = 1;
        }
      }
    }
    else if (*(char *)(iVar2 + 0x20) == '\x02') {
      iVar1 = *(int *)(iVar2 + 0x34);
      if ((iVar1 != 0) && (*(int *)(iVar2 + 0x24) != 0)) {
        if (param_2 == (uchar *)0x0) {
          *param_3 = iVar1;
          return 1;
        }
        if (iVar1 == *param_3) {
          len = DH_size(dh);
          key = (uchar *)CRYPTO_malloc(len,DAT_00100820,0x1d0);
          if (key != (uchar *)0x0) {
            iVar1 = DH_compute_key_padded(key,pub_key,dh);
            if ((iVar1 < 1) ||
               (iVar1 = DH_KDF_X9_42(param_2,*param_3,key,len,*(undefined4 *)(iVar2 + 0x24),
                                     *(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x30),
                                     *(undefined4 *)(iVar2 + 0x28)), iVar1 == 0)) {
              iVar1 = 0;
            }
            else {
              iVar1 = 1;
              *param_3 = *(int *)(iVar2 + 0x34);
            }
            OPENSSL_cleanse(key,len);
            CRYPTO_free(key);
            return iVar1;
          }
        }
      }
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  return iVar2;
}

