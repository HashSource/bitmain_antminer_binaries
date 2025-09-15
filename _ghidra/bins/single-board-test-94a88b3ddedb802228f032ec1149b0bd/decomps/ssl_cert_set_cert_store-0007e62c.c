
undefined4 ssl_cert_set_cert_store(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x14c);
  if (param_3 == 0) {
    piVar1 = (int *)(param_1 + 0x150);
  }
  if ((X509_STORE *)*piVar1 != (X509_STORE *)0x0) {
    X509_STORE_free((X509_STORE *)*piVar1);
  }
  *piVar1 = param_2;
  if (param_4 != 0 && param_2 != 0) {
    CRYPTO_add_lock((int *)(param_2 + 0x44),1,0xb,"ssl_cert.c",0x4e7);
  }
  return 1;
}

