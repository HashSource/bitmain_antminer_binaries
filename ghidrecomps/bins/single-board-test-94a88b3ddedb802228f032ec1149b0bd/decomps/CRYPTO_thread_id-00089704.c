
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong CRYPTO_thread_id(void)

{
  ulong uVar1;
  
  if (*(code **)(DAT_00089718 + 0x1c) == (code *)0x0) {
    uVar1 = (*(code *)PTR_getpid_00194314)();
    return uVar1;
  }
  uVar1 = (**(code **)(DAT_00089718 + 0x1c))();
  return uVar1;
}

