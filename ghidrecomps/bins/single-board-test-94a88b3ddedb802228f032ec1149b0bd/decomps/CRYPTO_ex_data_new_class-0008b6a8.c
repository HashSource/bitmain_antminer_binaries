
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_ex_data_new_class(void)

{
  int iVar1;
  code **ppcVar2;
  
  iVar1 = DAT_0008b6dc;
  ppcVar2 = *(code ***)(DAT_0008b6dc + 4);
  if (ppcVar2 == (code **)0x0) {
    CRYPTO_lock(9,2,DAT_0008b6e0,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b6e4;
    }
    CRYPTO_lock(10,2,DAT_0008b6e0,0xcc);
    ppcVar2 = *(code ***)(iVar1 + 4);
  }
  iVar1 = (**ppcVar2)();
  return iVar1;
}

