
undefined4 EC_KEY_set_method(int *param_1,int param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(code **)(*param_1 + 0xc) != (code *)0x0) {
    (**(code **)(*param_1 + 0xc))();
  }
  ENGINE_finish((ENGINE *)param_1[1]);
  UNRECOVERED_JUMPTABLE = *(code **)(param_2 + 8);
  *param_1 = param_2;
  param_1[1] = 0;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00119a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar1;
  }
  return 1;
}

