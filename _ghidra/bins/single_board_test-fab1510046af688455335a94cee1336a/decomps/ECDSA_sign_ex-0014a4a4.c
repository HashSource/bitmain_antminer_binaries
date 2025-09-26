
int ECDSA_sign_ex(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,BIGNUM *kinv,BIGNUM *rp,
                 EC_KEY *eckey)

{
  int iVar1;
  ECDSA_SIG *sig_00;
  uint uVar2;
  uchar *local_1c [2];
  
  local_1c[0] = sig;
  RAND_seed(dgst,dgstlen);
  iVar1 = ecdsa_check(eckey);
  if ((iVar1 != 0) &&
     (sig_00 = (ECDSA_SIG *)(**(code **)(*(int *)(iVar1 + 0xc) + 4))(dgst,dgstlen,kinv,rp,eckey),
     sig_00 != (ECDSA_SIG *)0x0)) {
    uVar2 = i2d_ECDSA_SIG(sig_00,local_1c);
    *siglen = uVar2;
    ECDSA_SIG_free(sig_00);
    return 1;
  }
  *siglen = 0;
  return 0;
}

