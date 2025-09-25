
undefined4 sm2_sign(uchar *param_1,int param_2,uchar *param_3,int *param_4,undefined4 param_5)

{
  BIGNUM *a;
  ECDSA_SIG *sig;
  int iVar1;
  undefined4 uVar2;
  uchar *local_1c [2];
  
  local_1c[0] = param_3;
  a = BN_bin2bn(param_1,param_2,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    uVar2 = 0xffffffff;
    ERR_put_error(0x35,0x69,3,"crypto/sm2/sm2_sign.c",0x1a3);
    sig = (ECDSA_SIG *)0x0;
  }
  else {
    sig = (ECDSA_SIG *)sm2_sig_gen(param_5,a);
    iVar1 = i2d_ECDSA_SIG(sig,local_1c);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
      ERR_put_error(0x35,0x69,0x44,"crypto/sm2/sm2_sign.c",0x1ab);
    }
    else {
      uVar2 = 1;
      *param_4 = iVar1;
    }
  }
  ECDSA_SIG_free(sig);
  BN_free(a);
  return uVar2;
}

