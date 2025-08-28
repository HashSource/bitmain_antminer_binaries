
void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  _init(param_1);
  puVar2 = (undefined4 *)0x11620;
  iVar1 = 0;
  do {
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + 1;
    (*(code *)*puVar2)(param_1,param_2,param_3,(code *)*puVar2,param_4);
  } while (iVar1 != 1);
  return;
}

