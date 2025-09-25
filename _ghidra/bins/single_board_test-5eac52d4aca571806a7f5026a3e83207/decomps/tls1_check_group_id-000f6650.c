
undefined4 tls1_check_group_id(int param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  ushort *local_18;
  int iStack_14;
  
  if (param_2 == 0) {
    return 0;
  }
  if (((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210), iVar2 != 0)) {
    iVar2 = *(int *)(iVar2 + 0xc);
    if (iVar2 == 0x300c02b) {
      if (param_2 != 0x17) {
        return 0;
      }
    }
    else if (iVar2 != 0x300c02c || param_2 != 0x18) {
      return 0;
    }
  }
  if (param_3 != 0) {
    tls1_get_supported_groups(param_1,&local_18,&iStack_14);
    if (iStack_14 == 0) {
      return 0;
    }
    if (*local_18 != param_2) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (iStack_14 == iVar2) {
          return 0;
        }
        local_18 = local_18 + 1;
      } while (*local_18 != param_2);
    }
  }
  iVar2 = tls_curve_allowed(param_1,param_2,0x20006);
  if (iVar2 == 0) {
    return 0;
  }
  if (((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x578) != 0)) &&
     (puVar1 = *(ushort **)(param_1 + 0x57c), *puVar1 != param_2)) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(param_1 + 0x578) == iVar2) {
        return 0;
      }
      puVar1 = puVar1 + 1;
    } while (*puVar1 != param_2);
  }
  return 1;
}

