
EVP_PKEY * PEM_read_bio_PrivateKey(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  char *__s1;
  int iVar1;
  X509_SIG *a;
  size_t len;
  PKCS8_PRIV_KEY_INFO *pPVar2;
  EVP_PKEY *pEVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  char *local_438;
  uchar *local_434;
  uchar *local_430;
  long local_42c;
  char acStack_428 [1028];
  
  local_438 = (char *)0x0;
  local_434 = (uchar *)0x0;
  local_430 = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio_secmem(&local_430,&local_42c,&local_438,"ANY PRIVATE KEY",bp,cb,u);
  __s1 = local_438;
  if (iVar1 == 0) {
    return (EVP_PKEY *)0x0;
  }
  local_434 = local_430;
  iVar1 = strcmp(local_438,"PRIVATE KEY");
  if (iVar1 == 0) {
    pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_434,local_42c);
    if (pPVar2 != (PKCS8_PRIV_KEY_INFO *)0x0) {
      pEVar3 = EVP_PKCS82PKEY(pPVar2);
      if (x != (EVP_PKEY **)0x0) {
        EVP_PKEY_free(*x);
        *x = pEVar3;
      }
      PKCS8_PRIV_KEY_INFO_free(pPVar2);
joined_r0x00146c12:
      if (pEVar3 != (EVP_PKEY *)0x0) goto LAB_00146b90;
    }
  }
  else {
    iVar1 = strcmp(__s1,"ENCRYPTED PRIVATE KEY");
    if (iVar1 == 0) {
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_434,local_42c);
      if (a != (X509_SIG *)0x0) {
        if (cb == (undefined1 *)0x0) {
          len = PEM_def_callback(acStack_428,0x400,0,u);
        }
        else {
          len = (*(code *)cb)(acStack_428,0x400,0);
        }
        if ((int)len < 0) {
          ERR_put_error(9,0x7b,0x68,"crypto/pem/pem_pkey.c",0x40);
          pEVar3 = (EVP_PKEY *)0x0;
          X509_SIG_free(a);
          goto LAB_00146b90;
        }
        pPVar2 = PKCS8_decrypt(a,acStack_428,len);
        X509_SIG_free(a);
        OPENSSL_cleanse(acStack_428,len);
        if (pPVar2 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar3 = EVP_PKCS82PKEY(pPVar2);
          if (x != (EVP_PKEY **)0x0) {
            EVP_PKEY_free(*x);
            *x = pEVar3;
          }
          PKCS8_PRIV_KEY_INFO_free(pPVar2);
          goto joined_r0x00146c12;
        }
      }
    }
    else {
      iVar1 = pem_check_suffix(__s1,"PRIVATE KEY");
      if (((0 < iVar1) &&
          (pEVar4 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,local_438,iVar1),
          pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(int *)(pEVar4 + 0x60) != 0)) {
        pEVar3 = d2i_PrivateKey(*(int *)pEVar4,x,&local_434,local_42c);
        goto joined_r0x00146c12;
      }
    }
  }
  pEVar3 = (EVP_PKEY *)0x0;
  ERR_put_error(9,0x7b,0xd,"crypto/pem/pem_pkey.c",0x58);
LAB_00146b90:
  CRYPTO_secure_free(local_438,"crypto/pem/pem_pkey.c",0x5a);
  CRYPTO_secure_clear_free(local_430,local_42c,"crypto/pem/pem_pkey.c",0x5b);
  return pEVar3;
}

