
undefined4 ipv6_cb(undefined1 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_3 + 0x10);
  if (iVar3 != 0x10) {
    if (param_2 == 0) {
      if (*(int *)(param_3 + 0x14) == -1) {
        *(int *)(param_3 + 0x14) = iVar3;
      }
      else if (iVar3 != *(int *)(param_3 + 0x14)) {
        return 0;
      }
      *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
      return 1;
    }
    if (param_2 < 5) {
      uVar1 = 0;
      while( true ) {
        uVar2 = uVar1 << 4;
        uVar1 = OPENSSL_hexchar2int(*param_1);
        if ((int)uVar1 < 0) break;
        param_2 = param_2 + -1;
        uVar1 = uVar1 & 0xff | uVar2;
        param_1 = param_1 + 1;
        if (param_2 == 0) {
          *(char *)(param_3 + iVar3) = (char)(uVar2 >> 8);
          *(char *)(param_3 + iVar3 + 1) = (char)uVar1;
          *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 2;
          return 1;
        }
      }
    }
    else if (((iVar3 < 0xd) && (param_1[param_2] == '\0')) &&
            (iVar3 = ipv4_from_asc(param_3 + iVar3,param_1), iVar3 != 0)) {
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 4;
      return 1;
    }
  }
  return 0;
}

