
undefined4 md_new(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = EVP_MD_CTX_new();
  if (iVar1 != 0) {
    BIO_set_init(param_1,1);
    BIO_set_data(param_1,iVar1);
    return 1;
  }
  return 0;
}

