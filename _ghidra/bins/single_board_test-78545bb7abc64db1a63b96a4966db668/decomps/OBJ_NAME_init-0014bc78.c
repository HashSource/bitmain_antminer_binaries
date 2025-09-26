
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OBJ_NAME_init(void)

{
  int iVar1;
  
  iVar1 = CRYPTO_THREAD_run_once(&init,0x14bb75);
  if (iVar1 != 0) {
    iVar1 = o_names_init_ossl_ret_;
  }
  return iVar1;
}

