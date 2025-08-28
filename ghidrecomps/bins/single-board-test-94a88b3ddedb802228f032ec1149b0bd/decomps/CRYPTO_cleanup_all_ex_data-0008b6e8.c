
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRYPTO_cleanup_all_ex_data(void)

{
  if (impl == (undefined1 *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xc9);
    if (impl == (undefined1 *)0x0) {
      impl = impl_default;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xcc);
  }
  (**(code **)(impl + 4))();
  return;
}

