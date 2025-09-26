
uint tls1_shared_group(int param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_30;
  ushort *local_2c;
  uint local_28;
  int local_24 [2];
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  if (param_2 == 0xfffffffe) {
    if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) != 0) {
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0xc);
      if (iVar2 == 0x300c02b) {
        return 0x17;
      }
      if (iVar2 != 0x300c02c) {
        return 0;
      }
      return 0x18;
    }
    param_2 = 0;
  }
  if (*(int *)(param_1 + 0x4ec) << 9 < 0) {
    tls1_get_supported_groups(param_1,&local_30,&local_28);
    local_24[0] = *(int *)(param_1 + 0x578);
    local_2c = *(ushort **)(param_1 + 0x57c);
  }
  else {
    local_28 = *(uint *)(param_1 + 0x578);
    local_30 = *(int *)(param_1 + 0x57c);
    tls1_get_supported_groups(param_1,&local_2c,local_24);
  }
  uVar4 = local_28;
  if (local_28 != 0) {
    uVar4 = 0;
    uVar5 = 0;
    uVar6 = local_28;
    do {
      while (uVar3 = (uint)*(ushort *)(local_30 + uVar5 * 2), local_24[0] == 0) {
LAB_001042a8:
        uVar5 = uVar5 + 1;
        if (uVar6 <= uVar5) goto LAB_001042b0;
      }
      if (*local_2c != uVar3) {
        iVar2 = 0;
        puVar1 = local_2c;
        do {
          iVar2 = iVar2 + 1;
          if (local_24[0] == iVar2) goto LAB_001042a8;
          puVar1 = puVar1 + 1;
        } while (*puVar1 != uVar3);
      }
      iVar2 = tls_curve_allowed(param_1,uVar3,0x20005);
      if (iVar2 != 0) {
        if (param_2 == uVar4) {
          return uVar3;
        }
        uVar4 = uVar4 + 1;
      }
      uVar5 = uVar5 + 1;
      uVar6 = local_28;
    } while (uVar5 < local_28);
  }
LAB_001042b0:
  if (param_2 != 0xffffffff) {
    return 0;
  }
  return uVar4 & 0xffff;
}

