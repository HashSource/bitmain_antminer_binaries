
void do_store_init_ossl_(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = OPENSSL_init_crypto(0,0,0,in_r3,in_r3);
  if ((iVar1 != 0) && (iVar1 = ossl_store_file_loader_init(), iVar1 != 0)) {
    iVar1 = 1;
  }
  do_store_init_ossl_ret_ = iVar1;
  return;
}

