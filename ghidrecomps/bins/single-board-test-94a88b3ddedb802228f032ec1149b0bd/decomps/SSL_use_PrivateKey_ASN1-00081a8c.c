
int SSL_use_PrivateKey_ASN1(int pk,SSL *ssl,uchar *d,long len)

{
  EVP_PKEY *pkey;
  int iVar1;
  uchar *local_14;
  
  local_14 = d;
  pkey = d2i_PrivateKey(pk,(EVP_PKEY **)0x0,&local_14,len);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xca,0xd,DAT_00081af4,0x166);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xc9,0x41,DAT_00081af4,299);
      iVar1 = 0;
    }
    else {
      iVar1 = ssl_set_pkey(ssl->cert,pkey);
    }
    EVP_PKEY_free(pkey);
  }
  return iVar1;
}

