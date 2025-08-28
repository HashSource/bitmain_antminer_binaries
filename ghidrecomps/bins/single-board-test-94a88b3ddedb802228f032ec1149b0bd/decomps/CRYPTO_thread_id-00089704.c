
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong CRYPTO_thread_id(void)

{
  ulong uVar1;
  
  if (id_callback == (code *)0x0) {
    uVar1 = getpid();
    return uVar1;
  }
  uVar1 = (*id_callback)();
  return uVar1;
}

