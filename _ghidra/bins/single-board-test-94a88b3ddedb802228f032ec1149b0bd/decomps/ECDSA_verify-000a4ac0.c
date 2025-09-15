
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  size_t __n;
  int iVar2;
  ECDSA_SIG *local_24;
  uchar *local_20;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  local_20 = sig;
  local_24 = ECDSA_SIG_new();
  if (local_24 == (ECDSA_SIG *)0x0) {
    iVar2 = -1;
  }
  else {
    pEVar1 = d2i_ECDSA_SIG(&local_24,&local_20,siglen);
    if (pEVar1 == (ECDSA_SIG *)0x0) {
      iVar2 = -1;
    }
    else {
      __n = i2d_ECDSA_SIG(local_24,&local_1c);
      if ((__n == siglen) && (iVar2 = memcmp(sig,local_1c,__n), pEVar1 = local_24, iVar2 == 0)) {
        iVar2 = ecdsa_check(eckey);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = (**(code **)(*(int *)(iVar2 + 0xc) + 0xc))(dgst,dgstlen,pEVar1,eckey);
        }
      }
      else {
        iVar2 = -1;
      }
      if (0 < (int)__n) {
        OPENSSL_cleanse(local_1c,__n);
        CRYPTO_free(local_1c);
      }
    }
    ECDSA_SIG_free(local_24);
  }
  return iVar2;
}

