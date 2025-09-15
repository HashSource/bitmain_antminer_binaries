
undefined4 find_c_map(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = find_c_rb(*param_1,param_2);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      get_raw_clib_object(*(undefined4 *)(iVar1 + 0x14),param_3);
      uVar2 = 1;
    }
  }
  return uVar2;
}

