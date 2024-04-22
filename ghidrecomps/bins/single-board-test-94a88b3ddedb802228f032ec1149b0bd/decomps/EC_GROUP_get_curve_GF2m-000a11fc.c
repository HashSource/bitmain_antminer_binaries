
undefined4 EC_GROUP_get_curve_GF2m(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x1c) == (code *)0x0) {
    ERR_put_error(0x10,0xac,0x42,DAT_000a1228,0x1c9);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x1c))();
  }
  return uVar1;
}

