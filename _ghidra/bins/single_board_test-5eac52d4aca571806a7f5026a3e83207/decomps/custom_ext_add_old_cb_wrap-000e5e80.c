
undefined4
custom_ext_add_old_cb_wrap
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uStack00000004;
  undefined4 *in_stack_00000010;
  
  if ((code *)in_stack_00000010[1] != (code *)0x0) {
    uStack00000004 = *in_stack_00000010;
                    /* WARNING: Could not recover jumptable at 0x000e5e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)in_stack_00000010[1])(param_1,param_2,param_4,param_5);
    return uVar1;
  }
  return 1;
}

