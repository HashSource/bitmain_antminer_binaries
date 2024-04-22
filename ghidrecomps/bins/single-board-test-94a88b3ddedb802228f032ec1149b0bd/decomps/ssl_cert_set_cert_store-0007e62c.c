
undefined4 ssl_cert_set_cert_store(int param_1,X509_STORE *param_2,int param_3,int param_4)

{
  X509_STORE **ppXVar1;
  
  ppXVar1 = (X509_STORE **)(param_1 + 0x14c);
  if (param_3 == 0) {
    ppXVar1 = (X509_STORE **)(param_1 + 0x150);
  }
  if (*ppXVar1 != (X509_STORE *)0x0) {
    X509_STORE_free(*ppXVar1);
  }
  *ppXVar1 = param_2;
  if (param_4 != 0 && param_2 != (X509_STORE *)0x0) {
    CRYPTO_add_lock(&param_2->references,1,0xb,DAT_0007e66c,0x4e7);
  }
  return 1;
}

