
undefined4
insert_c_map(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x1f5;
  }
  else {
    uVar1 = insert_c_rb(*param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

