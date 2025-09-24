
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  DSA_SIG *pDVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  DSA_SIG *local_24;
  uchar *local_20;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  local_20 = sigbuf;
  local_24 = DSA_SIG_new();
  if (local_24 == (DSA_SIG *)0x0) {
    iVar4 = -1;
  }
  else {
    pDVar1 = d2i_DSA_SIG(&local_24,&local_20,siglen);
    if (pDVar1 == (DSA_SIG *)0x0) {
      siglen = -1;
      iVar4 = -1;
      puVar3 = local_1c;
    }
    else {
      iVar2 = i2d_DSA_SIG(local_24,&local_1c);
      puVar3 = local_1c;
      if (siglen == iVar2) {
        iVar4 = -1;
        iVar2 = memcmp(sigbuf,local_1c,siglen);
        if (iVar2 == 0) {
          iVar4 = DSA_do_verify(dgst,dgst_len,local_24,dsa);
          puVar3 = local_1c;
        }
      }
      else {
        iVar4 = -1;
        siglen = iVar2;
      }
    }
    CRYPTO_clear_free(puVar3,siglen,"crypto/dsa/dsa_asn1.c",0x98);
    DSA_SIG_free(local_24);
  }
  return iVar4;
}

