
void opt_register_table(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  iVar1 = opt_count;
  if (param_2 == 0) {
    iVar2 = param_1[1];
    if (iVar2 == 0x10) {
      return;
    }
  }
  else {
    local_34 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_30 = 8;
    local_1c = param_2;
    add_opt(&local_34);
    iVar2 = param_1[1];
    if (iVar2 == 0x10) goto LAB_0004e4d2;
  }
  do {
    while (iVar2 == 8) {
      opt_register_table(*param_1,param_1[6]);
      iVar2 = param_1[8];
      param_1 = param_1 + 7;
      if (iVar2 == 0x10) goto LAB_0004e4d0;
    }
    check_opt(param_1);
    add_opt(param_1);
    iVar2 = param_1[8];
    param_1 = param_1 + 7;
  } while (iVar2 != 0x10);
LAB_0004e4d0:
  if (param_2 == 0) {
    return;
  }
LAB_0004e4d2:
  *(int *)(opt_table + iVar1 * 0x1c + 0x14) = opt_count - iVar1;
  return;
}

