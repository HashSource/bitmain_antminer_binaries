
undefined4 EC_GROUP_get_curve(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x1c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00127d5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x1c))();
    return uVar1;
  }
  ERR_put_error(0x10,0x123,0x42,"crypto/ec/ec_lib.c",0x20a);
  return 0;
}

