
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY *a;
  
  if (x509 == (X509_REQ *)0x0) {
    a = (EVP_PKEY *)0x0;
  }
  else {
    a = (EVP_PKEY *)x509->req_info;
    if (a != (EVP_PKEY *)0x0) {
      a = X509_PUBKEY_get((X509_PUBKEY *)(a->pkey).rsa);
    }
  }
  iVar1 = EVP_PKEY_cmp(a,pkey);
  switch(iVar1) {
  case 0:
    ERR_put_error(0xb,0x90,0x74,DAT_0010b580,0x83);
    iVar1 = 0;
    break;
  case 1:
    iVar1 = 1;
    break;
  case -2:
    if (pkey->type == 0x198) {
      ERR_put_error(0xb,0x90,0x10,DAT_0010b580,0x8b);
      iVar1 = 0;
      break;
    }
    if (pkey->type != 0x1c) {
      ERR_put_error(0xb,0x90,0x75,DAT_0010b580,0x97);
      iVar1 = 0;
      break;
    }
    ERR_put_error(0xb,0x90,0x72,DAT_0010b580,0x93);
  default:
    iVar1 = 0;
    break;
  case -1:
    ERR_put_error(0xb,0x90,0x73,DAT_0010b580,0x86);
    iVar1 = 0;
  }
  EVP_PKEY_free(a);
  return iVar1;
}

