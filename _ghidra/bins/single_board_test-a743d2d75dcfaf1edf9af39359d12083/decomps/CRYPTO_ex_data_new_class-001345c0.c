
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_ex_data_new_class(void)

{
  int iVar1;
  
  if ((undefined4 *)impl == (undefined4 *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xc9);
    if ((undefined4 *)impl == (undefined4 *)0x0) {
      impl = impl_default;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xcc);
  }
  iVar1 = (**(code **)impl)();
  return iVar1;
}

