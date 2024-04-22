
undefined4 get_next_c_map(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = minimum_c_map(*(undefined4 *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  else {
    uVar1 = tree_successor(**(undefined4 **)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14);
  }
  return uVar1;
}

