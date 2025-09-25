
int * file_find(int *param_1,undefined4 param_2)

{
  int iVar1;
  X509_NAME *x;
  ulong uVar2;
  int *piVar3;
  
  iVar1 = OSSL_STORE_SEARCH_get_type(param_2);
  if (iVar1 == 1) {
    piVar3 = (int *)0x1;
    if (param_1 != (int *)0x0) {
      if (*param_1 != 2) {
        ERR_put_error(0x2c,0x8a,0x77,"crypto/store/loader_file.c",0x3d8);
        return (int *)0x0;
      }
      x = (X509_NAME *)OSSL_STORE_SEARCH_get0_name(param_2);
      uVar2 = X509_NAME_hash(x);
      BIO_snprintf((char *)(param_1 + 6),9,"%08lx",uVar2);
    }
  }
  else {
    piVar3 = param_1;
    if (param_1 != (int *)0x0) {
      piVar3 = (int *)0x0;
      ERR_put_error(0x2c,0x8a,0x78,"crypto/store/loader_file.c",0x3e4);
    }
  }
  return piVar3;
}

