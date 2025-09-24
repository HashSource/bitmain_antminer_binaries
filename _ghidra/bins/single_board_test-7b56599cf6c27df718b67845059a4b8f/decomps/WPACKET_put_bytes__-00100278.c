
bool WPACKET_put_bytes__(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,
                        uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_14;
  
  if ((param_5 < 9) && (iVar1 = WPACKET_allocate_bytes(param_1,param_5,&local_14), iVar1 != 0)) {
    iVar1 = param_5 - 1;
    iVar2 = local_14 + iVar1;
    uVar3 = param_3;
    uVar6 = param_4;
    if (param_5 != 0) {
      *(char *)(local_14 + iVar1) = (char)param_3;
      uVar3 = param_3 >> 8 | param_4 << 0x18;
      uVar6 = param_4 >> 8;
      if (iVar1 != 0) {
        *(char *)(iVar2 + -1) = (char)(param_3 >> 8);
        uVar3 = uVar3 >> 8 | (param_4 >> 8) << 0x18;
        uVar6 = param_4 >> 0x10;
        if (param_5 != 2) {
          *(char *)(iVar2 + -2) = (char)(param_3 >> 0x10);
          uVar3 = uVar3 >> 8 | (param_4 >> 0x10) << 0x18;
          uVar5 = param_4 >> 0x18;
          uVar6 = uVar5;
          if (param_5 != 3) {
            *(char *)(iVar2 + -3) = (char)(param_3 >> 0x18);
            uVar4 = uVar3 >> 8 | uVar5 << 0x18;
            uVar6 = 0;
            uVar3 = uVar4;
            if (param_5 != 4) {
              *(char *)(iVar2 + -4) = (char)param_4;
              uVar3 = uVar4 >> 8;
              if (param_5 != 5) {
                *(char *)(iVar2 + -5) = (char)(param_4 >> 8);
                uVar3 = uVar4 >> 0x10;
                if ((param_5 != 6) &&
                   (*(char *)(iVar2 + -6) = (char)(param_4 >> 0x10), uVar3 = uVar5, param_5 != 7)) {
                  uVar3 = 0;
                  *(char *)(iVar2 + -7) = (char)(param_4 >> 0x18);
                }
              }
            }
          }
        }
      }
    }
    return uVar3 == 0 && uVar6 == 0;
  }
  return false;
}

