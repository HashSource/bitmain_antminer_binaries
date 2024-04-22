
uint pkey_gost_ctrl(EVP_PKEY_CTX *param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  uint *puVar1;
  void *__dest;
  int iVar2;
  EVP_MD *pEVar3;
  
  pEVar3 = param_4;
  puVar1 = (uint *)EVP_PKEY_CTX_get_data(param_1);
  if (param_2 == 7) {
    return 1;
  }
  if (param_2 < 8) {
    if (param_2 == 2) {
      if (param_3 < 2) {
        return 1;
      }
      if (param_3 == 2) {
        return puVar1[3];
      }
      if (param_3 == 3) {
        puVar1[3] = 1;
        return 1;
      }
    }
    else if (param_2 < 3) {
      if (param_2 == 1) {
        iVar2 = EVP_MD_type(param_4);
        if (iVar2 == 0x329) {
          puVar1[1] = (uint)param_4;
          return 1;
        }
        ERR_GOST_error(0x7d,0x6c,DAT_000df7e8,0x52,pEVar3);
        return 0;
      }
    }
    else if (param_2 < 6) {
      return 1;
    }
  }
  else {
    if (param_2 < 0xc) {
      if (8 < param_2) {
        return 1;
      }
      __dest = CRYPTO_malloc(param_3,DAT_000df7e8,0x6d);
      puVar1[2] = (uint)__dest;
      memcpy(__dest,param_4,param_3);
      return 1;
    }
    if (param_2 == 0xd) {
      param_4->type = puVar1[1];
      return 1;
    }
    if (param_2 == 0x1001) {
      *puVar1 = param_3;
      return 1;
    }
  }
  return 0xfffffffe;
}

