
EVP_PKEY * PEM_read_bio_PrivateKey(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  char *__s1;
  int iVar1;
  X509_SIG *a;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  char *local_430;
  uchar *local_42c;
  uchar *local_428;
  size_t local_424;
  char acStack_420 [1028];
  
  local_430 = (char *)0x0;
  local_42c = (uchar *)0x0;
  local_428 = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio(&local_428,(long *)&local_424,&local_430,"ANY PRIVATE KEY",bp,cb,u);
  __s1 = local_430;
  if (iVar1 == 0) {
    return (EVP_PKEY *)0x0;
  }
  local_42c = local_428;
  iVar1 = strcmp(local_430,"PRIVATE KEY");
  if (iVar1 == 0) {
    p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_42c,local_424);
joined_r0x00160eb0:
    if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
      pEVar2 = EVP_PKCS82PKEY(p8);
      if (x != (EVP_PKEY **)0x0) {
        if (*x != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(*x);
        }
        *x = pEVar2;
      }
      PKCS8_PRIV_KEY_INFO_free(p8);
LAB_00160e56:
      if (pEVar2 != (EVP_PKEY *)0x0) goto LAB_00160e5a;
    }
  }
  else {
    iVar1 = strcmp(__s1,"ENCRYPTED PRIVATE KEY");
    if (iVar1 == 0) {
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_42c,local_424);
      if (a != (X509_SIG *)0x0) {
        if (cb == (undefined1 *)0x0) {
          iVar1 = PEM_def_callback(acStack_420,0x400,0,u);
        }
        else {
          iVar1 = (*(code *)cb)(acStack_420,0x400,0,u);
        }
        if (iVar1 < 1) {
          ERR_put_error(9,0x7b,0x68,"pem_pkey.c",0x75);
          pEVar2 = (EVP_PKEY *)0x0;
          X509_SIG_free(a);
          goto LAB_00160e5a;
        }
        p8 = PKCS8_decrypt(a,acStack_420,iVar1);
        X509_SIG_free(a);
        goto joined_r0x00160eb0;
      }
    }
    else {
      iVar1 = pem_check_suffix(__s1,"PRIVATE KEY");
      if (((0 < iVar1) &&
          (pEVar3 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,local_430,iVar1),
          pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(int *)(pEVar3 + 0x5c) != 0)) {
        pEVar2 = d2i_PrivateKey(*(int *)pEVar3,x,&local_42c,local_424);
        goto LAB_00160e56;
      }
    }
  }
  pEVar2 = (EVP_PKEY *)0x0;
  ERR_put_error(9,0x7b,0xd,"pem_pkey.c",0x8d);
LAB_00160e5a:
  CRYPTO_free(local_430);
  OPENSSL_cleanse(local_428,local_424);
  CRYPTO_free(local_428);
  return pEVar2;
}

