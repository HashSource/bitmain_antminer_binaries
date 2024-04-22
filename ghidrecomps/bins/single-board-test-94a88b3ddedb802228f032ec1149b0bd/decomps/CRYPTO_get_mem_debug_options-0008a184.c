
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long CRYPTO_get_mem_debug_options(void)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(DAT_0008a190 + 0x10);
  if (pcVar1 != (code *)0x0) {
    pcVar1 = (code *)(*pcVar1)();
  }
  return (long)pcVar1;
}

