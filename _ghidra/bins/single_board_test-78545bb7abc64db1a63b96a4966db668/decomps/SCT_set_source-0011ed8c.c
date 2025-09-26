
undefined4 SCT_set_source(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (param_2 == 2) {
    uVar1 = SCT_set_log_entry_type(param_1,1);
    return uVar1;
  }
  if ((param_2 != 3) && (param_2 != 1)) {
    return 1;
  }
  uVar1 = SCT_set_log_entry_type(param_1,0);
  return uVar1;
}

