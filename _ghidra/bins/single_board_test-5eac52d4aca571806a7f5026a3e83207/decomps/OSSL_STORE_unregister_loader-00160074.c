
void OSSL_STORE_unregister_loader(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ossl_store_init_once();
  if (iVar1 != 0) {
    ossl_store_unregister_loader_int(param_1);
    return;
  }
  return;
}

