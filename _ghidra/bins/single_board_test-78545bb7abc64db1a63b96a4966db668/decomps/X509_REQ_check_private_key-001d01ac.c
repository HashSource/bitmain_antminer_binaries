
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  EVP_PKEY *a;
  int iVar1;
  
  a = X509_REQ_get_pubkey(x509);
  iVar1 = EVP_PKEY_cmp(a,pkey);
  switch(iVar1) {
  case 0:
    ERR_put_error(0xb,0x90,0x74,"crypto/x509/x509_req.c",0x5e);
    EVP_PKEY_free(a);
    return 0;
  case 1:
    iVar1 = 1;
    break;
  case -2:
    iVar1 = EVP_PKEY_id(pkey);
    if (iVar1 == 0x198) {
      iVar1 = 0;
      ERR_put_error(0xb,0x90,0x10,"crypto/x509/x509_req.c",0x66);
    }
    else {
      iVar1 = EVP_PKEY_id(pkey);
      if (iVar1 != 0x1c) {
        ERR_put_error(0xb,0x90,0x75,"crypto/x509/x509_req.c",0x72);
        EVP_PKEY_free(a);
        return 0;
      }
      iVar1 = 0;
      ERR_put_error(0xb,0x90,0x72,"crypto/x509/x509_req.c",0x6e);
    }
    break;
  case -1:
    ERR_put_error(0xb,0x90,0x73,"crypto/x509/x509_req.c",0x61);
    EVP_PKEY_free(a);
    return 0;
  default:
    iVar1 = 0;
  }
  EVP_PKEY_free(a);
  return iVar1;
}

