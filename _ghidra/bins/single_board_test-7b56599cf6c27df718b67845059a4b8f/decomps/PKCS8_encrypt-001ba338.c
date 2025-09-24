
X509_SIG *
PKCS8_encrypt(int pbe_nid,EVP_CIPHER *cipher,char *pass,int passlen,uchar *salt,int saltlen,int iter
             ,PKCS8_PRIV_KEY_INFO *p8)

{
  int iVar1;
  X509_ALGOR *a;
  X509_SIG *pXVar2;
  
  if (pbe_nid == -1) {
    a = PKCS5_pbe2_set(cipher,iter,salt,saltlen);
  }
  else {
    iVar1 = EVP_PBE_find(1,pbe_nid,(int *)0x0,(int *)0x0,(undefined1 **)0x0);
    if (iVar1 == 0) {
      ERR_clear_error();
      a = PKCS5_pbe_set(pbe_nid,iter,salt,saltlen);
    }
    else {
      a = PKCS5_pbe2_set_iv(cipher,iter,salt,saltlen,(uchar *)0x0,pbe_nid);
    }
  }
  if (a == (X509_ALGOR *)0x0) {
    ERR_put_error(0x23,0x7d,0xd,"crypto/pkcs12/p12_p8e.c",0x20);
    pXVar2 = (X509_SIG *)0x0;
  }
  else {
    pXVar2 = (X509_SIG *)PKCS8_set0_pbe(pass,passlen,p8,a);
    if (pXVar2 == (X509_SIG *)0x0) {
      X509_ALGOR_free(a);
    }
  }
  return pXVar2;
}

