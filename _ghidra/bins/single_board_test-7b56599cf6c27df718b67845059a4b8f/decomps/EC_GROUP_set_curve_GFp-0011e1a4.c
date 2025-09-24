
undefined4 EC_GROUP_set_curve_GFp(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x18) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011e14e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x18))();
    return uVar1;
  }
  ERR_put_error(0x10,0x124,0x42,"crypto/ec/ec_lib.c",0x200);
  return 0;
}

