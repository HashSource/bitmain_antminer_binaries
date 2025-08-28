
/* WARNING: Removing unreachable block (ram,0x00097b44) */

void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined **ppuVar2;
  
  _init(param_1);
  iVar1 = 0;
  ppuVar2 = &__frame_dummy_init_array_entry;
  do {
    iVar1 = iVar1 + 1;
    (*(code *)*ppuVar2)(param_1,param_2,param_3);
    ppuVar2 = ppuVar2 + 1;
  } while (iVar1 != 1);
  return;
}

