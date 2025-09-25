
bool ssl_security_default_callback
               (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  int local_14;
  
  iVar1 = ssl_get_security_level_bits(param_1,param_2,&local_14);
  if (local_14 == 0) {
    bVar2 = param_4 == 0x4f;
    if (param_4 < 0x50) {
      bVar2 = param_3 == 0x40007;
    }
    return (bool)(bVar2 ^ 1);
  }
  if (param_3 == 0xf) {
LAB_000d9006:
    return local_14 < 2;
  }
  if (param_3 < 0x10) {
    if (param_3 != 9) {
      if (param_3 == 10) {
LAB_000d8fe8:
        return local_14 < 3;
      }
      goto LAB_000d906e;
    }
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      return local_14 < 4 || param_5 != 0x100 && param_5 < 0xfefe;
    }
    if (param_5 < 0x301) goto LAB_000d9006;
    if (param_5 == 0x301) goto LAB_000d8fe8;
    if (param_5 == 0x302) {
      return local_14 < 4;
    }
    goto LAB_000d90b4;
  }
  if (2 < param_3 - 0x10001U) {
LAB_000d906e:
    return iVar1 <= param_4;
  }
  if ((param_4 < iVar1) || ((*(uint *)(param_6 + 0x14) & 4) != 0)) {
LAB_000d906a:
    bVar2 = false;
  }
  else {
    if ((*(uint *)(param_6 + 0x1c) & 1) != 0) {
      return false;
    }
    if ((0xa0 < iVar1) && ((int)(*(uint *)(param_6 + 0x1c) << 0x1e) < 0)) {
      return false;
    }
    if (1 < local_14) {
      if (*(int *)(param_6 + 0x18) == 4) goto LAB_000d906a;
      if ((local_14 != 2) && (*(int *)(param_6 + 0x20) != 0x304)) {
        return (*(uint *)(param_6 + 0x10) & 0x186) != 0;
      }
    }
LAB_000d90b4:
    bVar2 = true;
  }
  return bVar2;
}

