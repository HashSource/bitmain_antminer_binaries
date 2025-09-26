
undefined4 pubkey_cb(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 3) {
    EVP_PKEY_free(*(EVP_PKEY **)(*param_2 + 8));
    return 1;
  }
  if (param_1 != 5) {
    return 1;
  }
  iVar1 = *param_2;
  EVP_PKEY_free(*(EVP_PKEY **)(iVar1 + 8));
  *(undefined4 *)(iVar1 + 8) = 0;
  ERR_set_mark();
  iVar1 = x509_pubkey_decode((undefined4 *)(iVar1 + 8),iVar1);
  if (iVar1 != -1) {
    ERR_pop_to_mark();
    return 1;
  }
  return 0;
}

