
void custom_ext_free_old_cb_wrap
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  if ((code *)param_5[2] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000e5eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_5[2])(param_1,param_2,param_4,*param_5);
    return;
  }
  return;
}

