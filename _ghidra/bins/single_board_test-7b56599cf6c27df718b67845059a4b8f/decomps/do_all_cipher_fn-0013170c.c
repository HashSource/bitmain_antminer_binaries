
void do_all_cipher_fn(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 4) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00131720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[1])(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),0,*param_2);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0013172e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2[1])(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*param_2);
  return;
}

