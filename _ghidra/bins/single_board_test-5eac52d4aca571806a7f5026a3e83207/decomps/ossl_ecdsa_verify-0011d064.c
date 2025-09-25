
int ossl_ecdsa_verify(undefined4 param_1,uchar *param_2,int param_3,uchar *param_4,size_t param_5,
                     EC_KEY *param_6)

{
  ECDSA_SIG *pEVar1;
  size_t sVar2;
  int iVar3;
  uchar *ptr;
  int iVar4;
  ECDSA_SIG *local_24;
  uchar *local_20;
  uchar *local_1c [2];
  
  local_1c[0] = (uchar *)0x0;
  local_20 = param_4;
  local_24 = ECDSA_SIG_new();
  if (local_24 != (ECDSA_SIG *)0x0) {
    pEVar1 = d2i_ECDSA_SIG(&local_24,&local_20,param_5);
    if ((pEVar1 == (ECDSA_SIG *)0x0) ||
       (sVar2 = i2d_ECDSA_SIG(local_24,local_1c), ptr = local_1c[0], param_5 != sVar2)) {
      iVar4 = -1;
      ptr = local_1c[0];
    }
    else {
      iVar4 = -1;
      iVar3 = memcmp(param_4,local_1c[0],param_5);
      if (iVar3 == 0) {
        iVar4 = ECDSA_do_verify(param_2,param_3,local_24,param_6);
        ptr = local_1c[0];
      }
    }
    CRYPTO_free(ptr);
    ECDSA_SIG_free(local_24);
    return iVar4;
  }
  return -1;
}

