
undefined4 ssl_cert_type(X509 *param_1,EVP_PKEY *param_2)

{
  EVP_PKEY *pubkey;
  int iVar1;
  undefined4 uVar2;
  
  pubkey = param_2;
  if ((param_2 == (EVP_PKEY *)0x0) && (pubkey = X509_get_pubkey(param_1), pubkey == (EVP_PKEY *)0x0)
     ) {
    uVar2 = 0xffffffff;
    goto LAB_0006d63a;
  }
  iVar1 = pubkey->type;
  if (iVar1 == 6) {
    uVar2 = 0;
  }
  else if (iVar1 == 0x74) {
    uVar2 = 2;
  }
  else if (iVar1 == 0x198) {
    uVar2 = 5;
  }
  else if (iVar1 == 0x32c || iVar1 == 0x352) {
    uVar2 = 6;
  }
  else if (iVar1 == 0x32b || iVar1 == 0x353) {
    uVar2 = 7;
  }
  else if ((param_1 == (X509 *)0x0) || (iVar1 != 0x1c && iVar1 != 0x398)) {
LAB_0006d644:
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = X509_certificate_type(param_1,pubkey);
    if (iVar1 << 0x17 < 0) {
      uVar2 = 3;
    }
    else {
      if (-1 < iVar1 << 0x16) goto LAB_0006d644;
      uVar2 = 4;
    }
  }
  if (param_2 != (EVP_PKEY *)0x0) {
    return uVar2;
  }
LAB_0006d63a:
  EVP_PKEY_free(pubkey);
  return uVar2;
}

