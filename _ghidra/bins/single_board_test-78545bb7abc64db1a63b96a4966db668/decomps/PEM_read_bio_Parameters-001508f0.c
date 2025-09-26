
EVP_PKEY * PEM_read_bio_Parameters(BIO *bp,EVP_PKEY **x)

{
  int iVar1;
  EVP_PKEY *pkey;
  char *local_20;
  uchar *local_1c;
  uchar *local_18;
  long local_14;
  
  local_20 = (char *)0x0;
  local_1c = (uchar *)0x0;
  local_18 = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio(&local_18,&local_14,&local_20,"PARAMETERS",bp,(undefined1 *)0x0,
                             (void *)0x0);
  if (iVar1 == 0) {
    return (EVP_PKEY *)0x0;
  }
  local_1c = local_18;
  iVar1 = pem_check_suffix(local_20,"PARAMETERS");
  if ((0 < iVar1) && (pkey = EVP_PKEY_new(), pkey != (EVP_PKEY *)0x0)) {
    iVar1 = EVP_PKEY_set_type_str(pkey,local_20,iVar1);
    if ((iVar1 != 0) &&
       ((*(code **)(pkey->ameth + 0x3c) != (code *)0x0 &&
        (iVar1 = (**(code **)(pkey->ameth + 0x3c))(pkey,&local_1c,local_14), iVar1 != 0)))) {
      if (x != (EVP_PKEY **)0x0) {
        EVP_PKEY_free(*x);
        *x = pkey;
      }
      goto LAB_00150970;
    }
    EVP_PKEY_free(pkey);
  }
  pkey = (EVP_PKEY *)0x0;
  ERR_put_error(9,0x8c,0xd,"crypto/pem/pem_pkey.c",0x9a);
LAB_00150970:
  CRYPTO_free(local_20);
  CRYPTO_free(local_18);
  return pkey;
}

