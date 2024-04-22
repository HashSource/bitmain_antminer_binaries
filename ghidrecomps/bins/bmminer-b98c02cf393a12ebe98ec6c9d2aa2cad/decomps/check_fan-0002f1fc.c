
void check_fan(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte local_25;
  int local_24;
  
  iVar5 = dev;
  iVar6 = 2;
  local_25 = 0;
  *(undefined4 *)(dev + 0x5400) = 0;
  *(undefined4 *)(iVar5 + 0x5404) = 0;
  do {
    iVar5 = 8;
    do {
      while (iVar2 = get_fan_speed(&local_25,&local_24), iVar1 = dev, iVar2 == -1) {
LAB_0002f254:
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) goto LAB_0002f2b4;
      }
      uVar7 = (uint)local_25;
      uVar4 = local_24 * 0x78;
      *(uint *)(dev + (uVar7 + 0x14e2) * 4 + 4) = uVar4;
      if (local_24 == 0) {
        if (*(char *)(iVar1 + uVar7 + 0x5384) == '\x01') {
          *(undefined *)(iVar1 + uVar7 + 0x5384) = 0;
          uVar3 = *(uint *)(iVar1 + 0x4c) & 1;
          if (1 << uVar7 != 0) {
            uVar3 = 0;
          }
          *(char *)(iVar1 + 0x53fe) = *(char *)(iVar1 + 0x53fe) + -1;
          *(uint *)(iVar1 + 0x4c) = uVar3;
        }
      }
      else if (*(char *)(iVar1 + uVar7 + 0x5384) == '\0') {
        *(undefined *)(iVar1 + uVar7 + 0x5384) = 1;
        *(uint *)(iVar1 + 0x4c) = 1 << uVar7 | *(uint *)(iVar1 + 0x4c);
        *(char *)(iVar1 + 0x53fe) = *(char *)(iVar1 + 0x53fe) + '\x01';
      }
      if (*(uint *)(iVar1 + 0x5400) < uVar4) {
        *(uint *)(iVar1 + 0x5400) = uVar4;
      }
      if ((uVar4 != 0 && uVar4 < *(uint *)(iVar1 + 0x5404)) || (*(uint *)(iVar1 + 0x5404) == 0)) {
        *(uint *)(iVar1 + 0x5404) = uVar4;
        goto LAB_0002f254;
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
LAB_0002f2b4:
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

