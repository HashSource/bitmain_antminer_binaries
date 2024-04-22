
/* WARNING: Unknown calling convention */

uint32_t hashlittle(void *key,size_t length,uint32_t initval)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t a;
  uint uVar3;
  uint32_t *k;
  uint8_t *k8;
  uint16_t *k_2;
  uint8_t *k8_1;
  uint8_t *k_1;
  uint32_t uVar4;
  uint uVar5;
  int iVar6;
  uint32_t uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar2 = initval + length + 0xdeadbeef;
  uVar4 = uVar2;
  if (((uint)key & 3) == 0) {
    k8 = (uint8_t *)key;
    uVar7 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
        k8 = (uint8_t *)((int)key + 0xc);
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar2 + *(int *)((int)key + 8);
        iVar1 = uVar3 + uVar4 + *(int *)((int)key + 4);
        uVar3 = uVar7 + (*key - uVar3) ^ (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar10 = uVar3 + iVar1;
        uVar3 = (uVar4 + *(int *)((int)key + 4)) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
        iVar6 = uVar3 + iVar10;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar6;
        uVar3 = iVar10 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar7 = uVar3 + iVar1;
        uVar3 = iVar6 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar4 = uVar3 + uVar7;
        uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
        key = k8;
      } while (0xc < length);
    }
    switch(length) {
    case 3:
      uVar7 = uVar7 + (uint)k8[2] * 0x10000;
    case 2:
      uVar7 = uVar7 + (uint)k8[1] * 0x100;
    case 1:
      uVar3 = uVar7 + *k8;
      break;
    case 7:
      uVar4 = uVar4 + (uint)k8[6] * 0x10000;
    case 6:
      uVar4 = uVar4 + (uint)k8[5] * 0x100;
    case 5:
      uVar4 = uVar4 + k8[4];
    case 4:
      uVar3 = uVar7 + *(int *)k8;
      break;
    case 0xb:
      uVar2 = uVar2 + (uint)k8[10] * 0x10000;
    case 10:
      uVar2 = uVar2 + (uint)k8[9] * 0x100;
    case 9:
      uVar2 = uVar2 + k8[8];
    case 8:
      uVar4 = uVar4 + *(int *)(k8 + 4);
      uVar3 = uVar7 + *(int *)k8;
      break;
    case 0xc:
      uVar2 = uVar2 + *(int *)(k8 + 8);
      uVar4 = uVar4 + *(int *)(k8 + 4);
      uVar3 = uVar7 + *(int *)k8;
      break;
    default:
      return uVar2;
    }
  }
  else if ((int)key << 0x1f < 0) {
    uVar7 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000 +
                        (uint)*(byte *)((int)key + 9) * 0x100 + (uint)*(byte *)((int)key + 8) +
                        (uint)*(byte *)((int)key + 0xb) * 0x1000000;
        uVar9 = (((uint)*(byte *)((int)key + 2) * 0x10000 + (uint)*(byte *)((int)key + 1) * 0x100 +
                  (uint)*key + (uint)*(byte *)((int)key + 3) * 0x1000000) - uVar3) + uVar7 ^
                (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar6 = uVar4 + (uint)*(byte *)((int)key + 6) * 0x10000 +
                        (uint)*(byte *)((int)key + 5) * 0x100 + (uint)*(byte *)((int)key + 4) +
                        (uint)*(byte *)((int)key + 7) * 0x1000000;
        key = (void *)((int)key + 0xc);
        iVar1 = uVar3 + iVar6;
        uVar3 = iVar6 - uVar9 ^ (uVar9 >> 0x1a | uVar9 << 6);
        iVar6 = uVar9 + iVar1;
        iVar10 = uVar3 + iVar6;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar10;
        uVar3 = iVar6 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar7 = uVar3 + iVar1;
        uVar3 = iVar10 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar4 = uVar3 + uVar7;
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
      uVar4 = uVar4 + (uint)*(byte *)((int)key + 7) * 0x1000000;
    case 7:
      uVar4 = uVar4 + (uint)*(byte *)((int)key + 6) * 0x10000;
    case 6:
      uVar4 = uVar4 + (uint)*(byte *)((int)key + 5) * 0x100;
    case 5:
      uVar4 = uVar4 + *(byte *)((int)key + 4);
    case 4:
      uVar7 = uVar7 + (uint)*(byte *)((int)key + 3) * 0x1000000;
    case 3:
      uVar7 = uVar7 + (uint)*(byte *)((int)key + 2) * 0x10000;
    case 2:
      uVar7 = uVar7 + (uint)*(byte *)((int)key + 1) * 0x100;
    case 1:
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar7 + *key;
      break;
    default:
      return uVar2;
    }
  }
  else {
    k8_1 = (uint8_t *)key;
    uVar7 = uVar2;
    if (0xc < length) {
      do {
        length = length - 0xc;
        k8_1 = (uint8_t *)((int)key + 0xc);
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar2 + (uint)*(ushort *)((int)key + 8) + (uint)*(ushort *)((int)key + 10) * 0x10000
        ;
        iVar6 = uVar4 + (uint)*(ushort *)((int)key + 4) + (uint)*(ushort *)((int)key + 6) * 0x10000;
        iVar1 = uVar3 + iVar6;
        uVar3 = uVar7 + (((uint)*key + (uint)*(ushort *)((int)key + 2) * 0x10000) - uVar3) ^
                (uVar3 >> 0x1c | uVar3 * 0x10);
        iVar10 = uVar3 + iVar1;
        uVar3 = iVar6 - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
        iVar6 = uVar3 + iVar10;
        uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
        iVar1 = uVar3 + iVar6;
        uVar3 = iVar10 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
        uVar7 = uVar3 + iVar1;
        uVar3 = iVar6 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
        uVar4 = uVar3 + uVar7;
        uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
        key = k8_1;
      } while (0xc < length);
    }
    switch(length) {
    case 1:
      uVar3 = *k8_1 + uVar7;
      break;
    case 3:
      uVar7 = uVar7 + (uint)k8_1[2] * 0x10000;
    case 2:
      uVar3 = uVar7 + *(ushort *)k8_1;
      break;
    case 5:
      uVar4 = uVar4 + k8_1[4];
    case 4:
      uVar3 = *(ushort *)k8_1 + uVar7 + (uint)*(ushort *)(k8_1 + 2) * 0x10000;
      break;
    case 7:
      uVar4 = uVar4 + (uint)k8_1[6] * 0x10000;
    case 6:
      uVar3 = *(ushort *)k8_1 + uVar7 + (uint)*(ushort *)(k8_1 + 2) * 0x10000;
      uVar4 = uVar4 + *(ushort *)(k8_1 + 4);
      break;
    case 9:
      uVar2 = uVar2 + k8_1[8];
    case 8:
      uVar4 = *(ushort *)(k8_1 + 4) + uVar4 + (uint)*(ushort *)(k8_1 + 6) * 0x10000;
      uVar3 = *(ushort *)k8_1 + uVar7 + (uint)*(ushort *)(k8_1 + 2) * 0x10000;
      break;
    case 0xb:
      uVar2 = uVar2 + (uint)k8_1[10] * 0x10000;
    case 10:
      uVar4 = *(ushort *)(k8_1 + 4) + uVar4 + (uint)*(ushort *)(k8_1 + 6) * 0x10000;
      uVar3 = *(ushort *)k8_1 + uVar7 + (uint)*(ushort *)(k8_1 + 2) * 0x10000;
      uVar2 = uVar2 + *(ushort *)(k8_1 + 8);
      break;
    case 0xc:
      uVar2 = *(ushort *)(k8_1 + 8) + uVar2 + (uint)*(ushort *)(k8_1 + 10) * 0x10000;
      uVar4 = *(ushort *)(k8_1 + 4) + uVar4 + (uint)*(ushort *)(k8_1 + 6) * 0x10000;
      uVar3 = *(ushort *)k8_1 + uVar7 + (uint)*(ushort *)(k8_1 + 2) * 0x10000;
      break;
    default:
      return uVar2;
    }
  }
  uVar9 = (uVar2 ^ uVar4) - (uVar4 >> 0x12 | uVar4 << 0xe);
  uVar8 = (uVar3 ^ uVar9) - (uVar9 >> 0x15 | uVar9 * 0x800);
  uVar5 = (uVar4 ^ uVar8) - (uVar8 >> 7 | uVar8 * 0x2000000);
  uVar3 = (uVar9 ^ uVar5) - (uVar5 >> 0x10 | uVar5 * 0x10000);
  uVar9 = (uVar8 ^ uVar3) - (uVar3 >> 0x1c | uVar3 * 0x10);
  uVar9 = (uVar5 ^ uVar9) - (uVar9 >> 0x12 | uVar9 * 0x4000);
  return (uVar9 ^ uVar3) - (uVar9 >> 8 | uVar9 * 0x1000000);
}

