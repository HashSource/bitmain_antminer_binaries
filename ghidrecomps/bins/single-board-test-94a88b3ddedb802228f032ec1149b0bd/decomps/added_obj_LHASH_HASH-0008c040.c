
uint added_obj_LHASH_HASH(int *param_1)

{
  int iVar1;
  uint uVar2;
  char **ppcVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  
  ppcVar3 = (char **)param_1[1];
  switch(*param_1) {
  case 0:
    pcVar7 = ppcVar3[3];
    pcVar6 = (char *)((int)pcVar7 << 0x14);
    if (0 < (int)pcVar7) {
      iVar1 = 0;
      pbVar4 = (byte *)ppcVar3[4];
      do {
        pbVar5 = pbVar4 + 1;
        uVar2 = iVar1 % 0x18;
        iVar1 = iVar1 + 3;
        pcVar6 = (char *)((uint)pcVar6 ^ (uint)*pbVar4 << (uVar2 & 0xff));
        pbVar4 = pbVar5;
      } while (pbVar5 != (byte *)(ppcVar3[4] + (int)pcVar7));
    }
    iVar1 = 0;
    break;
  case 1:
    pcVar6 = (char *)lh_strhash(*ppcVar3);
    iVar1 = *param_1;
    break;
  case 2:
    pcVar6 = (char *)lh_strhash(ppcVar3[1]);
    iVar1 = *param_1;
    break;
  case 3:
    pcVar6 = ppcVar3[2];
    iVar1 = 3;
    break;
  default:
    return 0;
  }
  return (uint)pcVar6 & 0x3fffffff | iVar1 << 0x1e;
}

