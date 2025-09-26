
undefined4 ASYNC_get_current_job(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = OPENSSL_init_crypto(0x100,0,0,in_r3,in_r3);
  if ((iVar1 != 0) && (iVar1 = async_get_ctx(), iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 4);
  }
  return 0;
}

