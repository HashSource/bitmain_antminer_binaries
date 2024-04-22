
undefined4 EC_GROUP_set_curve_GF2m(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x18) == (code *)0x0) {
    ERR_put_error(0x10,0xb0,0x42,DAT_000a11f8,0x1be);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x18))();
  }
  return uVar1;
}

