
bool ipv6_from_asc(undefined4 *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  bool bVar4;
  undefined4 local_34 [4];
  size_t local_24;
  size_t local_20;
  int local_1c;
  
  local_24 = 0;
  local_1c = 0;
  local_20 = 0xffffffff;
  iVar3 = CONF_parse_list(param_2,0x3a,0,DAT_000c6f24,local_34);
  sVar2 = local_20;
  sVar1 = local_24;
  if (iVar3 == 0) {
    return false;
  }
  if (local_20 == 0xffffffff) {
    if (local_24 != 0x10) {
      return false;
    }
LAB_000c6efe:
    bVar4 = true;
    *param_1 = local_34[0];
    param_1[1] = local_34[1];
    param_1[2] = local_34[2];
    param_1[3] = local_34[3];
  }
  else {
    if (local_24 == 0x10) {
      return false;
    }
    if (3 < local_1c) {
      return false;
    }
    if (local_1c == 3) {
      if (0 < (int)local_24) {
        return false;
      }
LAB_000c6eb4:
      if ((int)local_20 < 0) goto LAB_000c6efe;
    }
    else {
      if (local_1c != 2) {
        if (local_20 == 0) {
          return false;
        }
        if (local_20 == local_24) {
          return false;
        }
        goto LAB_000c6eb4;
      }
      if (local_20 != 0) {
        if (local_20 != local_24) {
          return false;
        }
        goto LAB_000c6eb4;
      }
    }
    memcpy(param_1,local_34,local_20);
    memset((void *)((int)param_1 + sVar2),0,0x10 - sVar1);
    bVar4 = sVar2 == sVar1;
    if (!bVar4) {
      bVar4 = true;
      memcpy((void *)((int)param_1 + ((sVar2 + 0x10) - sVar1)),(void *)((int)local_34 + sVar2),
             sVar1 - sVar2);
    }
  }
  return bVar4;
}

