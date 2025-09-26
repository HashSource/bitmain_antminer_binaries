
undefined4 pkey_tls1_prf_ctrl(int param_1,int param_2,size_t param_3,void *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 0x1001) {
    if (-1 < (int)param_3) {
      if (puVar2[1] != 0) {
        CRYPTO_clear_free(puVar2[1],puVar2[2],"crypto/kdf/tls1_prf.c",0x45,param_4);
      }
      OPENSSL_cleanse(puVar2 + 3,puVar2[0x103]);
      puVar2[0x103] = 0;
      iVar1 = CRYPTO_memdup(param_4,param_3,"crypto/kdf/tls1_prf.c",0x48);
      puVar2[1] = iVar1;
      if (iVar1 != 0) {
        puVar2[2] = param_3;
        return 1;
      }
    }
  }
  else {
    if (param_2 != 0x1002) {
      if (param_2 != 0x1000) {
        return 0xfffffffe;
      }
      *puVar2 = param_4;
      return 1;
    }
    if (param_4 == (void *)0x0 || param_3 == 0) {
      return 1;
    }
    if ((-1 < (int)param_3) && ((int)param_3 <= 0x400 - puVar2[0x103])) {
      memcpy((void *)((int)puVar2 + puVar2[0x103] + 0xc),param_4,param_3);
      puVar2[0x103] = param_3 + puVar2[0x103];
      return 1;
    }
  }
  return 0;
}

