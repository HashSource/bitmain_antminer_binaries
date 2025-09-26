
undefined4 ossl_store_init_once(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CRYPTO_THREAD_run_once(&store_init,0x16daa1);
  if ((iVar1 == 0) || (uVar2 = 1, do_store_init_ossl_ret_ == 0)) {
    ERR_put_error(0x2c,0x70,0x41,"crypto/store/store_init.c",0x18);
    uVar2 = 0;
  }
  return uVar2;
}

