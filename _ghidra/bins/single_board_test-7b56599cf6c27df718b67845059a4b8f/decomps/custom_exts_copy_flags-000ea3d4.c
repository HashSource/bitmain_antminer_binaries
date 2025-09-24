
undefined4
custom_exts_copy_flags(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  if (param_2[1] != 0) {
    uVar3 = 0;
    puVar2 = (undefined2 *)*param_2;
    do {
      uVar3 = uVar3 + 1;
      iVar1 = custom_ext_find(param_1,*(undefined4 *)(puVar2 + 2),*puVar2,0,param_4);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(puVar2 + 6);
      }
      puVar2 = puVar2 + 0x12;
    } while (uVar3 < (uint)param_2[1]);
  }
  return 1;
}

