
void ASYNC_cleanup_thread(void)

{
  int iVar1;
  
  iVar1 = OPENSSL_init_crypto(0x100,0,0);
  if (iVar1 == 0) {
    return;
  }
  async_delete_thread_state();
  return;
}

