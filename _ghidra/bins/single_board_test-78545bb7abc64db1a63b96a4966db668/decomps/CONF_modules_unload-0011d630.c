
void CONF_modules_unload(int all)

{
  int iVar1;
  int *ptr;
  undefined4 *ptr_00;
  int iVar2;
  bool bVar3;
  
  CONF_modules_finish();
  iVar1 = OPENSSL_sk_num(supported_modules);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    if (all == 0) {
      do {
        while ((ptr = (int *)OPENSSL_sk_value(supported_modules,iVar1), 0 < ptr[4] || (*ptr == 0)))
        {
          bVar3 = iVar1 == 0;
          iVar1 = iVar1 + -1;
          if (bVar3) goto LAB_0011d698;
        }
        OPENSSL_sk_delete(supported_modules,iVar1);
        DSO_free((DSO *)*ptr);
        CRYPTO_free((void *)ptr[1]);
        CRYPTO_free(ptr);
        bVar3 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar3);
    }
    else {
      do {
        ptr_00 = (undefined4 *)OPENSSL_sk_value(supported_modules,iVar1);
        iVar2 = iVar1 + -1;
        OPENSSL_sk_delete(supported_modules,iVar1);
        DSO_free((DSO *)*ptr_00);
        CRYPTO_free((void *)ptr_00[1]);
        CRYPTO_free(ptr_00);
        iVar1 = iVar2;
      } while (iVar2 != -1);
    }
  }
LAB_0011d698:
  iVar1 = OPENSSL_sk_num(supported_modules);
  if (iVar1 == 0) {
    OPENSSL_sk_free(supported_modules);
    supported_modules = 0;
  }
  return;
}

