
void savelog_nonce(int param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined local_14;
  
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  regen_hash();
  if (*(int *)(param_1 + 0xdc) == 0) {
    local_14 = 0;
    local_18 = param_2;
    cg_savelogwork(param_1,&local_18);
  }
  return;
}

