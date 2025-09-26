
undefined4 ciphersuite_cb(void *param_1,size_t param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_60 [84];
  
  if (0x4f < (int)param_2) {
    ERR_put_error(0x14,0x26e,0xb9,"ssl/ssl_ciph.c",0x503);
    return 0;
  }
  memcpy(auStack_60,param_1,param_2);
  auStack_60[param_2] = 0;
  iVar1 = ssl3_get_cipher_by_std_name();
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x26e,0xb9,"ssl/ssl_ciph.c",0x50c);
    uVar2 = 0;
  }
  else {
    iVar1 = OPENSSL_sk_push(param_3,iVar1);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x26e,0x44,"ssl/ssl_ciph.c",0x511);
      return 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

