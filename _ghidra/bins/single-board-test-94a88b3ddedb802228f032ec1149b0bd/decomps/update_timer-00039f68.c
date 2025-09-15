
undefined4 update_timer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_14 [2];
  
  if (*(int *)(param_1 + 0xb4) != 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      local_14[0] = -1;
    }
    else {
      multi_timeout_part_1(param_1,local_14);
      if (-1 < local_14[0]) {
        iVar2 = *(int *)(param_1 + 0x44);
        if ((*(int *)(iVar2 + 0xc) == *(int *)(param_1 + 0xbc)) &&
           (*(int *)(iVar2 + 0x10) == *(int *)(param_1 + 0xc0))) {
          return 0;
        }
        uVar1 = *(undefined4 *)(iVar2 + 0x10);
        *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 *)(param_1 + 0xc0) = uVar1;
        uVar1 = (**(code **)(param_1 + 0xb4))(param_1,local_14[0],*(undefined4 *)(param_1 + 0xb8));
        return uVar1;
      }
    }
    if ((*(int *)(param_1 + 0xbc) != 0) || (*(int *)(param_1 + 0xc0) != 0)) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0xc0) = 0;
      uVar1 = (**(code **)(param_1 + 0xb4))(param_1,0xffffffff,*(undefined4 *)(param_1 + 0xb8));
      return uVar1;
    }
  }
  return 0;
}

