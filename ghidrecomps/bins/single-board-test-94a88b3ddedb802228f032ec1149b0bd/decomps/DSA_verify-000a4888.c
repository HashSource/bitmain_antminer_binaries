
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  ASN1_VALUE *pAVar1;
  size_t __n;
  int iVar2;
  DSA_SIG *local_24;
  uchar *local_20;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  local_20 = sigbuf;
  local_24 = DSA_SIG_new();
  if (local_24 == (DSA_SIG *)0x0) {
    iVar2 = -1;
  }
  else {
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)&local_24,&local_20,siglen,DAT_000a4914);
    if (pAVar1 == (ASN1_VALUE *)0x0) {
      iVar2 = -1;
    }
    else {
      __n = ASN1_item_i2d((ASN1_VALUE *)local_24,&local_1c,DAT_000a4914);
      if ((siglen == __n) && (iVar2 = memcmp(sigbuf,local_1c,__n), iVar2 == 0)) {
        iVar2 = DSA_do_verify(dgst,dgst_len,local_24,dsa);
      }
      else {
        iVar2 = -1;
      }
      if (0 < (int)__n) {
        OPENSSL_cleanse(local_1c,__n);
        CRYPTO_free(local_1c);
      }
    }
    DSA_SIG_free(local_24);
  }
  return iVar2;
}

