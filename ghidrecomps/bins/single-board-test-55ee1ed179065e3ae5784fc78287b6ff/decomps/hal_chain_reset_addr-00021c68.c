
undefined4 hal_chain_reset_addr(int param_1)

{
  undefined4 uVar1;
  int local_c;
  
  if (conf_loaded == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      if (*(int *)(chains + local_c * 0x10) == param_1) {
        return *(undefined4 *)(chains + local_c * 0x10 + 0xc);
      }
    }
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

