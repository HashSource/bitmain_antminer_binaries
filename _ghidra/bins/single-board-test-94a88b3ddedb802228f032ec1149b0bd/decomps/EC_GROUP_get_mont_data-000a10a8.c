
undefined4 EC_GROUP_get_mont_data(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x34) < 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xac);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

