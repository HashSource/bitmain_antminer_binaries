
int X509_PUBKEY_get0(int param_1)

{
  EVP_PKEY *local_c;
  
  local_c = (EVP_PKEY *)0x0;
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
    if (*(int *)(param_1 + 8) != 0) {
      return *(int *)(param_1 + 8);
    }
    x509_pubkey_decode(&local_c,param_1);
    if (local_c != (EVP_PKEY *)0x0) {
      ERR_put_error(0xb,0x77,0x44,"crypto/x509/x_pubkey.c",0xa2);
      EVP_PKEY_free(local_c);
      return 0;
    }
  }
  return 0;
}

