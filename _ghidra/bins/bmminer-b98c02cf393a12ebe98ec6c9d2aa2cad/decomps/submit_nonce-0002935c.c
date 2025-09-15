
uint submit_nonce(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = new_nonce_isra_10(*(undefined4 *)(param_1 + 0x24),param_3,param_3,param_4,param_4);
  if (uVar1 != 0) {
    *(undefined4 *)(param_2 + 0x4c) = param_3;
    regen_hash(param_2);
    if (*(int *)(param_2 + 0xdc) == 0) {
      submit_tested_work(param_1,param_2);
      if (opt_benchfile == 0) {
        return uVar1;
      }
      uVar2 = (uint)opt_benchfile_display;
      if (uVar2 == 0) {
        return uVar1;
      }
      benchfile_dspwork(param_2,param_3);
      return uVar2;
    }
  }
  inc_hw_errors(param_1);
  return 0;
}

