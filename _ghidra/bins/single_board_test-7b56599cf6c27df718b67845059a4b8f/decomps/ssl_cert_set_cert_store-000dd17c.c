
undefined4 ssl_cert_set_cert_store(int param_1,int param_2,int param_3,int param_4)

{
  X509_STORE *v;
  int *piVar1;
  
  if (param_3 == 0) {
    v = *(X509_STORE **)(param_1 + 0xec);
    piVar1 = (int *)(param_1 + 0xec);
  }
  else {
    piVar1 = (int *)(param_1 + 0xe8);
    v = *(X509_STORE **)(param_1 + 0xe8);
  }
  X509_STORE_free(v);
  *piVar1 = param_2;
  if (param_4 != 0 && param_2 != 0) {
    X509_STORE_up_ref(param_2);
  }
  return 1;
}

