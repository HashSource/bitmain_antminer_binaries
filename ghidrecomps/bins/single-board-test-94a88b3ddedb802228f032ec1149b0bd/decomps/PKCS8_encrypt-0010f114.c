
X509_SIG *
PKCS8_encrypt(int pbe_nid,EVP_CIPHER *cipher,char *pass,int passlen,uchar *salt,int saltlen,int iter
             ,PKCS8_PRIV_KEY_INFO *p8)

{
  X509_SIG *a;
  int iVar1;
  X509_ALGOR *algor;
  ASN1_OCTET_STRING *pAVar2;
  
  a = X509_SIG_new();
  if (a == (X509_SIG *)0x0) {
    ERR_put_error(0x23,0x7d,0x41,DAT_0010f1f0,0x49);
  }
  else {
    if (pbe_nid == -1) {
      algor = PKCS5_pbe2_set(cipher,iter,salt,saltlen);
    }
    else {
      iVar1 = EVP_PBE_find(1,pbe_nid,(int *)0x0,(int *)0x0,(undefined1 **)0x0);
      if (iVar1 == 0) {
        ERR_clear_error();
        algor = PKCS5_pbe_set(pbe_nid,iter,salt,saltlen);
      }
      else {
        algor = PKCS5_pbe2_set_iv(cipher,iter,salt,saltlen,(uchar *)0x0,pbe_nid);
      }
    }
    if (algor == (X509_ALGOR *)0x0) {
      ERR_put_error(0x23,0x7d,0xd,DAT_0010f1f0,0x56);
    }
    else {
      X509_ALGOR_free(a->algor);
      a->algor = algor;
      ASN1_STRING_free(a->digest);
      pAVar2 = PKCS12_item_i2d_encrypt(algor,DAT_0010f1ec,pass,passlen,p8,1);
      a->digest = pAVar2;
      if (pAVar2 != (ASN1_OCTET_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x7d,0x67,DAT_0010f1f0,0x60);
    }
  }
  X509_SIG_free(a);
  return (X509_SIG *)0x0;
}

