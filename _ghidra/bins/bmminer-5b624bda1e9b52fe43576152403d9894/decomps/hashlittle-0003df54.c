
/* WARNING: Unknown calling convention */

uint32_t hashlittle(void *key,size_t length,uint32_t initval)

{
  int iVar1;
  uint32_t uVar2;
  uint uVar3;
  byte *pbVar4;
  ushort *puVar5;
  uint32_t uVar6;
  uint uVar7;
  int iVar8;
  uint32_t uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  uVar2 = initval + length + 0xdeadbeef;
  uVar6 = uVar2;
  if (((uint)key & 3) == 0) {
    pbVar4 = (byte *)key;
    uVar9 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
        key = pbVar4 + 0xc;
        uVar3 = uVar2 + *(int *)(pbVar4 + 8);
        iVar1 = uVar3 + uVar6 + *(int *)(pbVar4 + 4);
        uVar3 = uVar9 + (*(int *)pbVar4 - uVar3) ^ (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar12 = uVar3 + iVar1;
        uVar3 = (uVar6 + *(int *)(pbVar4 + 4)) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
        iVar8 = uVar3 + iVar12;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar8;
        uVar3 = iVar12 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar9 = uVar3 + iVar1;
        uVar3 = iVar8 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar6 = uVar3 + uVar9;
        uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
        pbVar4 = (byte *)key;
      } while (0xc < length);
    }
    switch(length) {
    case 3:
      uVar9 = uVar9 + (uint)*(byte *)((int)key + 2) * 0x10000;
    case 2:
      uVar9 = uVar9 + (uint)*(byte *)((int)key + 1) * 0x100;
    case 1:
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar9 + *key;
      break;
    case 7:
      uVar6 = uVar6 + (uint)*(byte *)((int)key + 6) * 0x10000;
    case 6:
      uVar6 = uVar6 + (uint)*(byte *)((int)key + 5) * 0x100;
    case 5:
      uVar6 = uVar6 + *(byte *)((int)key + 4);
    case 4:
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar9 + *key;
      break;
    case 0xb:
      uVar2 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000;
    case 10:
      uVar2 = uVar2 + (uint)*(byte *)((int)key + 9) * 0x100;
    case 9:
      uVar2 = uVar2 + *(byte *)((int)key + 8);
    case 8:
                    /* WARNING: Load size is inaccurate */
      uVar6 = uVar6 + *(int *)((int)key + 4);
      uVar3 = uVar9 + *key;
      break;
    case 0xc:
                    /* WARNING: Load size is inaccurate */
      uVar2 = uVar2 + *(int *)((int)key + 8);
      uVar6 = uVar6 + *(int *)((int)key + 4);
      uVar3 = uVar9 + *key;
      break;
    default:
      goto switchD_0003dfd6_default;
    }
  }
  else if ((int)key << 0x1f < 0) {
    uVar9 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000 +
                        (uint)*(byte *)((int)key + 9) * 0x100 + (uint)*(byte *)((int)key + 8) +
                        (uint)*(byte *)((int)key + 0xb) * 0x1000000;
        uVar11 = (((uint)*(byte *)((int)key + 2) * 0x10000 + (uint)*(byte *)((int)key + 1) * 0x100 +
                   (uint)*key + (uint)*(byte *)((int)key + 3) * 0x1000000) - uVar3) + uVar9 ^
                 (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar8 = uVar6 + (uint)*(byte *)((int)key + 6) * 0x10000 +
                        (uint)*(byte *)((int)key + 5) * 0x100 + (uint)*(byte *)((int)key + 4) +
                        (uint)*(byte *)((int)key + 7) * 0x1000000;
        key = (void *)((int)key + 0xc);
        iVar1 = uVar3 + iVar8;
        uVar3 = iVar8 - uVar11 ^ (uVar11 >> 0x1a | uVar11 << 6);
        iVar8 = uVar11 + iVar1;
        iVar12 = uVar3 + iVar8;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar12;
        uVar3 = iVar8 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar9 = uVar3 + iVar1;
        uVar3 = iVar12 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar6 = uVar3 + uVar9;
        uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
      } while (0xc < length);
    }
    switch(length) {
    case 0xc:
      uVar2 = uVar2 + (uint)*(byte *)((int)key + 0xb) * 0x1000000;
    case 0xb:
      uVar2 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000;
    case 10:
      uVar2 = uVar2 + (uint)*(byte *)((int)key + 9) * 0x100;
    case 9:
      uVar2 = uVar2 + *(byte *)((int)key + 8);
    case 8:
      uVar6 = uVar6 + (uint)*(byte *)((int)key + 7) * 0x1000000;
    case 7:
      uVar6 = uVar6 + (uint)*(byte *)((int)key + 6) * 0x10000;
    case 6:
      uVar6 = uVar6 + (uint)*(byte *)((int)key + 5) * 0x100;
    case 5:
      uVar6 = uVar6 + *(byte *)((int)key + 4);
    case 4:
      uVar9 = uVar9 + (uint)*(byte *)((int)key + 3) * 0x1000000;
    case 3:
      uVar9 = uVar9 + (uint)*(byte *)((int)key + 2) * 0x10000;
    case 2:
      uVar9 = uVar9 + (uint)*(byte *)((int)key + 1) * 0x100;
    case 1:
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar9 + *key;
      break;
    default:
      goto switchD_0003dfd6_default;
    }
  }
  else {
    puVar5 = (ushort *)key;
    uVar9 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
        key = puVar5 + 6;
        uVar3 = uVar2 + (uint)puVar5[4] + (uint)puVar5[5] * 0x10000;
        iVar8 = uVar6 + (uint)puVar5[2] + (uint)puVar5[3] * 0x10000;
        iVar1 = uVar3 + iVar8;
        uVar3 = uVar9 + (((uint)*puVar5 + (uint)puVar5[1] * 0x10000) - uVar3) ^
                (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar12 = uVar3 + iVar1;
        uVar3 = iVar8 - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
        iVar8 = uVar3 + iVar12;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar8;
        uVar3 = iVar12 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar9 = uVar3 + iVar1;
        uVar3 = iVar8 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar6 = uVar3 + uVar9;
        uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
        puVar5 = (ushort *)key;
      } while (0xc < length);
    }
    switch(length) {
    case 1:
                    /* WARNING: Load size is inaccurate */
      uVar3 = (byte)*key + uVar9;
      break;
    case 3:
      uVar9 = uVar9 + (uint)(byte)*(ushort *)((int)key + 2) * 0x10000;
    case 2:
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar9 + *key;
      break;
    case 5:
      uVar6 = uVar6 + (byte)*(ushort *)((int)key + 4);
    case 4:
                    /* WARNING: Load size is inaccurate */
      uVar3 = *key + uVar9 + (uint)*(ushort *)((int)key + 2) * 0x10000;
      break;
    case 7:
      uVar6 = uVar6 + (uint)(byte)*(ushort *)((int)key + 6) * 0x10000;
    case 6:
                    /* WARNING: Load size is inaccurate */
      uVar3 = *key + uVar9 + (uint)*(ushort *)((int)key + 2) * 0x10000;
      uVar6 = uVar6 + *(ushort *)((int)key + 4);
      break;
    case 9:
      uVar2 = uVar2 + (byte)*(ushort *)((int)key + 8);
    case 8:
                    /* WARNING: Load size is inaccurate */
      uVar6 = *(ushort *)((int)key + 4) + uVar6 + (uint)*(ushort *)((int)key + 6) * 0x10000;
      uVar3 = *key + uVar9 + (uint)*(ushort *)((int)key + 2) * 0x10000;
      break;
    case 0xb:
      uVar2 = uVar2 + (uint)(byte)*(ushort *)((int)key + 10) * 0x10000;
    case 10:
                    /* WARNING: Load size is inaccurate */
      uVar6 = *(ushort *)((int)key + 4) + uVar6 + (uint)*(ushort *)((int)key + 6) * 0x10000;
      uVar3 = *key + uVar9 + (uint)*(ushort *)((int)key + 2) * 0x10000;
      uVar2 = uVar2 + *(ushort *)((int)key + 8);
      break;
    case 0xc:
                    /* WARNING: Load size is inaccurate */
      uVar2 = *(ushort *)((int)key + 8) + uVar2 + (uint)*(ushort *)((int)key + 10) * 0x10000;
      uVar6 = *(ushort *)((int)key + 4) + uVar6 + (uint)*(ushort *)((int)key + 6) * 0x10000;
      uVar3 = *key + uVar9 + (uint)*(ushort *)((int)key + 2) * 0x10000;
      break;
    default:
      goto switchD_0003dfd6_default;
    }
  }
  uVar11 = (uVar2 ^ uVar6) - (uVar6 >> 0x12 | uVar6 << 0xe);
  uVar10 = (uVar3 ^ uVar11) - (uVar11 >> 0x15 | uVar11 * 0x800);
  uVar7 = (uVar6 ^ uVar10) - (uVar10 >> 7 | uVar10 * 0x2000000);
  uVar3 = (uVar11 ^ uVar7) - (uVar7 >> 0x10 | uVar7 * 0x10000);
  uVar11 = (uVar10 ^ uVar3) - (uVar3 >> 0x1c | uVar3 * 0x10);
  uVar11 = (uVar7 ^ uVar11) - (uVar11 >> 0x12 | uVar11 * 0x4000);
  uVar2 = (uVar11 ^ uVar3) - (uVar11 >> 8 | uVar11 * 0x1000000);
switchD_0003dfd6_default:
  return uVar2;
}

