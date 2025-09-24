
void OSSL_STORE_register_loader(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ossl_store_init_once();
  if (iVar1 == 0) {
    return;
  }
  ossl_store_register_loader_int(param_1);
  return;
}

