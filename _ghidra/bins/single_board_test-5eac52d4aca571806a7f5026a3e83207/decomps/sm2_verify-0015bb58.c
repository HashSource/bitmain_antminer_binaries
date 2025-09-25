
undefined4 sm2_verify(uchar *param_1,int param_2,uchar *param_3,size_t param_4,undefined4 param_5)

{
  ECDSA_SIG *pEVar1;
  size_t sVar2;
  int iVar3;
  BIGNUM *a;
  undefined4 uVar4;
  ECDSA_SIG *local_24;
  uchar *local_20;
  uchar *local_1c;
  
  local_24 = (ECDSA_SIG *)0x0;
  local_1c = (uchar *)0x0;
  local_20 = param_3;
  local_24 = ECDSA_SIG_new();
  if (local_24 == (ECDSA_SIG *)0x0) {
    uVar4 = 0xffffffff;
    ERR_put_error(0x35,0x6c,0x41,"crypto/sm2/sm2_sign.c",0x1c4);
    a = (BIGNUM *)0x0;
  }
  else {
    pEVar1 = d2i_ECDSA_SIG(&local_24,&local_20,param_4);
    if (pEVar1 == (ECDSA_SIG *)0x0) {
      uVar4 = 0xffffffff;
      ERR_put_error(0x35,0x6c,0x68,"crypto/sm2/sm2_sign.c",0x1c8);
      a = (BIGNUM *)0x0;
    }
    else {
      sVar2 = i2d_ECDSA_SIG(local_24,&local_1c);
      if ((param_4 == sVar2) && (iVar3 = memcmp(param_3,local_1c,param_4), iVar3 == 0)) {
        a = BN_bin2bn(param_1,param_2,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) {
          uVar4 = 0xffffffff;
          ERR_put_error(0x35,0x6c,3,"crypto/sm2/sm2_sign.c",0x1d4);
        }
        else {
          uVar4 = sm2_sig_verify(param_5,local_24,a);
        }
      }
      else {
        uVar4 = 0xffffffff;
        ERR_put_error(0x35,0x6c,0x68,"crypto/sm2/sm2_sign.c",0x1ce);
        a = (BIGNUM *)0x0;
      }
    }
  }
  CRYPTO_free(local_1c);
  BN_free(a);
  ECDSA_SIG_free(local_24);
  return uVar4;
}

