
X509_ALGOR * PKCS5_pbe_set(int alg,int iter,uchar *salt,int saltlen)

{
  X509_ALGOR *algor;
  int iVar1;
  
  algor = X509_ALGOR_new();
  if (algor == (X509_ALGOR *)0x0) {
    ERR_put_error(0xd,0xca,0x41,DAT_000bd494,0x86);
  }
  else {
    iVar1 = PKCS5_pbe_set0_algor(algor,alg,iter,salt,saltlen);
    if (iVar1 == 0) {
      X509_ALGOR_free(algor);
      algor = (X509_ALGOR *)0x0;
    }
  }
  return algor;
}

