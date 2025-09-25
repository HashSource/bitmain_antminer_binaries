
undefined4 cms_rek_cb(int param_1,int *param_2)

{
  if (param_1 != 3) {
    return 1;
  }
  EVP_PKEY_free(*(EVP_PKEY **)(*param_2 + 8));
  return 1;
}

