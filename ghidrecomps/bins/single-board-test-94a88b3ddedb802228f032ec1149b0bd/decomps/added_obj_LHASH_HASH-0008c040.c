
uint added_obj_LHASH_HASH(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  ulong uVar7;
  
  puVar3 = (undefined4 *)param_1[1];
  switch(*param_1) {
  case 0:
    iVar1 = puVar3[3];
    uVar7 = iVar1 << 0x14;
    if (0 < iVar1) {
      iVar6 = 0;
      pbVar4 = (byte *)puVar3[4];
      do {
        pbVar5 = pbVar4 + 1;
        uVar2 = iVar6 % 0x18;
        iVar6 = iVar6 + 3;
        uVar7 = uVar7 ^ (uint)*pbVar4 << (uVar2 & 0xff);
        pbVar4 = pbVar5;
      } while (pbVar5 != (byte *)puVar3[4] + iVar1);
    }
    iVar1 = 0;
    break;
  case 1:
    uVar7 = lh_strhash((char *)*puVar3);
    iVar1 = *param_1;
    break;
  case 2:
    uVar7 = lh_strhash((char *)puVar3[1]);
    iVar1 = *param_1;
    break;
  case 3:
    uVar7 = puVar3[2];
    iVar1 = 3;
    break;
  default:
    return 0;
  }
  return uVar7 & 0x3fffffff | iVar1 << 0x1e;
}

