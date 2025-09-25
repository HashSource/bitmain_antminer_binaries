
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_new(void)

{
  int iVar1;
  ENGINE *obj;
  
  iVar1 = CRYPTO_THREAD_run_once(&engine_lock_init,0x121a29);
  if (((iVar1 != 0) && (do_engine_lock_init_ossl_ret_ != 0)) &&
     (obj = (ENGINE *)CRYPTO_zalloc(0x70,"crypto/engine/eng_lib.c",0x22), obj != (ENGINE *)0x0)) {
    DataMemoryBarrier(0x1b);
    *(undefined4 *)(obj + 0x50) = 1;
    DataMemoryBarrier(0x1b);
    iVar1 = CRYPTO_new_ex_data(10,obj,(CRYPTO_EX_DATA *)(obj + 0x58));
    if (iVar1 == 0) {
      CRYPTO_free(obj);
      obj = (ENGINE *)0x0;
    }
    return obj;
  }
  ERR_put_error(0x26,0x7a,0x41,"crypto/engine/eng_lib.c",0x23);
  return (ENGINE *)0x0;
}

