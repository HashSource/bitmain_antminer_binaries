
uint added_obj_hash(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)param_1[1];
  switch(*param_1) {
  case 0:
    break;
  case 1:
    uVar1 = OPENSSL_LH_strhash(*puVar2);
    return uVar1 & 0x3fffffff | *param_1 << 0x1e;
  case 2:
    uVar1 = OPENSSL_LH_strhash(puVar2[1]);
    return uVar1 & 0x3fffffff | *param_1 << 0x1e;
  case 3:
    return puVar2[2] & 0x3fffffff | 0xc0000000;
  default:
    return 0;
  }
  iVar7 = puVar2[3];
  uVar1 = iVar7 << 0x14;
  if (0 < iVar7) {
    iVar3 = 0;
    pbVar5 = (byte *)puVar2[4];
    do {
      pbVar6 = pbVar5 + 1;
      uVar4 = iVar3 % 0x18;
      iVar3 = iVar3 + 3;
      uVar1 = uVar1 ^ (uint)*pbVar5 << (uVar4 & 0xff);
      pbVar5 = pbVar6;
    } while ((byte *)puVar2[4] + iVar7 != pbVar6);
  }
  return uVar1 & 0x3fffffff;
}

