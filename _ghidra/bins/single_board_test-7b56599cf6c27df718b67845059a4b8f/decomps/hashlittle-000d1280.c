
/* WARNING: Unknown calling convention */

uint32_t hashlittle(void *key,size_t length,uint32_t initval)

{
  int iVar1;
  uint32_t uVar2;
  uint uVar3;
  uint *puVar4;
  uint32_t uVar5;
  uint uVar6;
  int iVar7;
  uint32_t uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar2 = initval + length + 0xdeadbeef;
  uVar5 = uVar2;
  uVar8 = uVar2;
  if (((uint)key & 3) != 0) {
    if ((int)key << 0x1f < 0) {
      if (0xc < length) {
        do {
          length = length - 0xc;
                    /* WARNING: Load size is inaccurate */
          uVar3 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000 +
                          (uint)*(byte *)((int)key + 9) * 0x100 + (uint)*(byte *)((int)key + 8) +
                          (uint)*(byte *)((int)key + 0xb) * 0x1000000;
          uVar10 = (((uint)*(byte *)((int)key + 2) * 0x10000 + (uint)*(byte *)((int)key + 1) * 0x100
                     + (uint)*key + (uint)*(byte *)((int)key + 3) * 0x1000000) - uVar3) + uVar8 ^
                   (uVar3 >> 0x1c | uVar3 * 0x10);
          iVar7 = uVar5 + (uint)*(byte *)((int)key + 6) * 0x10000 +
                          (uint)*(byte *)((int)key + 5) * 0x100 + (uint)*(byte *)((int)key + 4) +
                          (uint)*(byte *)((int)key + 7) * 0x1000000;
          key = (void *)((int)key + 0xc);
          iVar1 = uVar3 + iVar7;
          uVar3 = iVar7 - uVar10 ^ (uVar10 >> 0x1a | uVar10 << 6);
          iVar7 = uVar10 + iVar1;
          iVar11 = uVar3 + iVar7;
          uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
          iVar1 = uVar3 + iVar11;
          uVar3 = iVar7 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
          uVar8 = uVar3 + iVar1;
          uVar3 = iVar11 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
          uVar5 = uVar3 + uVar8;
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
        uVar5 = uVar5 + (uint)*(byte *)((int)key + 7) * 0x1000000;
      case 7:
        uVar5 = uVar5 + (uint)*(byte *)((int)key + 6) * 0x10000;
      case 6:
        uVar5 = uVar5 + (uint)*(byte *)((int)key + 5) * 0x100;
      case 5:
        uVar5 = uVar5 + *(byte *)((int)key + 4);
      case 4:
        uVar8 = uVar8 + (uint)*(byte *)((int)key + 3) * 0x1000000;
      case 3:
        uVar8 = uVar8 + (uint)*(byte *)((int)key + 2) * 0x10000;
      case 2:
        uVar8 = uVar8 + (uint)*(byte *)((int)key + 1) * 0x100;
      case 1:
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar8 + *key;
        break;
      default:
        goto switchD_000d1302_default;
      }
    }
    else {
      puVar4 = (uint *)key;
      if (0xc < length) {
        do {
          length = length - 0xc;
          key = puVar4 + 3;
          uVar3 = uVar2 + (uint)(ushort)puVar4[2] + (uint)*(ushort *)((int)puVar4 + 10) * 0x10000;
          iVar7 = uVar5 + (uint)(ushort)puVar4[1] + (uint)*(ushort *)((int)puVar4 + 6) * 0x10000;
          iVar1 = uVar3 + iVar7;
          uVar3 = uVar8 + (((uint)(ushort)*puVar4 + (uint)*(ushort *)((int)puVar4 + 2) * 0x10000) -
                          uVar3) ^ (uVar3 >> 0x1c | uVar3 * 0x10);
          iVar11 = uVar3 + iVar1;
          uVar3 = iVar7 - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
          iVar7 = uVar3 + iVar11;
          uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
          iVar1 = uVar3 + iVar7;
          uVar3 = iVar11 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
          uVar8 = uVar3 + iVar1;
          uVar3 = iVar7 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
          uVar5 = uVar3 + uVar8;
          uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
          puVar4 = (uint *)key;
        } while (0xc < length);
      }
      switch(length) {
      case 1:
        goto switchD_000d1302_caseD_1;
      case 3:
        uVar8 = uVar8 + (uint)*(byte *)((int)key + 2) * 0x10000;
      case 2:
switchD_000d1302_caseD_2:
                    /* WARNING: Load size is inaccurate */
        uVar3 = uVar8 + (ushort)*key;
        break;
      case 5:
        uVar5 = uVar5 + (byte)*(uint *)((int)key + 4);
      case 4:
                    /* WARNING: Load size is inaccurate */
        uVar3 = (ushort)*key + uVar8 + (uint)*(ushort *)((int)key + 2) * 0x10000;
        break;
      case 7:
        uVar5 = uVar5 + (uint)*(byte *)((int)key + 6) * 0x10000;
      case 6:
                    /* WARNING: Load size is inaccurate */
        uVar3 = (ushort)*key + uVar8 + (uint)*(ushort *)((int)key + 2) * 0x10000;
        uVar5 = uVar5 + (ushort)*(uint *)((int)key + 4);
        break;
      case 9:
        uVar2 = uVar2 + (byte)*(uint *)((int)key + 8);
      case 8:
                    /* WARNING: Load size is inaccurate */
        uVar5 = (ushort)*(uint *)((int)key + 4) + uVar5 + (uint)*(ushort *)((int)key + 6) * 0x10000;
        uVar3 = (ushort)*key + uVar8 + (uint)*(ushort *)((int)key + 2) * 0x10000;
        break;
      case 0xb:
        uVar2 = uVar2 + (uint)*(byte *)((int)key + 10) * 0x10000;
      case 10:
                    /* WARNING: Load size is inaccurate */
        uVar5 = (ushort)*(uint *)((int)key + 4) + uVar5 + (uint)*(ushort *)((int)key + 6) * 0x10000;
        uVar3 = (ushort)*key + uVar8 + (uint)*(ushort *)((int)key + 2) * 0x10000;
        uVar2 = uVar2 + (ushort)*(uint *)((int)key + 8);
        break;
      case 0xc:
                    /* WARNING: Load size is inaccurate */
        uVar2 = (ushort)*(uint *)((int)key + 8) + uVar2 + (uint)*(ushort *)((int)key + 10) * 0x10000
        ;
        uVar5 = (ushort)*(uint *)((int)key + 4) + uVar5 + (uint)*(ushort *)((int)key + 6) * 0x10000;
        uVar3 = (ushort)*key + uVar8 + (uint)*(ushort *)((int)key + 2) * 0x10000;
        break;
      default:
        goto switchD_000d1302_default;
      }
    }
    goto LAB_000d1360;
  }
  puVar4 = (uint *)key;
  if (0xc < length) {
    do {
      length = length - 0xc;
      key = puVar4 + 3;
      uVar3 = uVar2 + puVar4[2];
      iVar1 = uVar3 + uVar5 + puVar4[1];
      uVar3 = uVar8 + (*puVar4 - uVar3) ^ (uVar3 >> 0x1c | uVar3 * 0x10);
      iVar11 = uVar3 + iVar1;
      uVar3 = (uVar5 + puVar4[1]) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
      iVar7 = uVar3 + iVar11;
      uVar3 = iVar1 - uVar3 ^ (uVar3 >> 0x18 | uVar3 << 8);
      iVar1 = uVar3 + iVar7;
      uVar3 = iVar11 - uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10);
      uVar8 = uVar3 + iVar1;
      uVar3 = iVar7 - uVar3 ^ (uVar3 >> 0xd | uVar3 << 0x13);
      uVar5 = uVar3 + uVar8;
      uVar2 = iVar1 - uVar3 ^ (uVar3 >> 0x1c | uVar3 << 4);
      puVar4 = (uint *)key;
    } while (0xc < length);
  }
  switch(length) {
  case 1:
switchD_000d1302_caseD_1:
                    /* WARNING: Load size is inaccurate */
    uVar3 = (byte)*key + uVar8;
    break;
  case 2:
    goto switchD_000d1302_caseD_2;
  case 3:
                    /* WARNING: Load size is inaccurate */
    uVar3 = (*key & 0xffffff) + uVar8;
    break;
  case 4:
                    /* WARNING: Load size is inaccurate */
    uVar3 = uVar8 + *key;
    break;
  case 5:
                    /* WARNING: Load size is inaccurate */
    uVar5 = uVar5 + (byte)*(uint *)((int)key + 4);
    uVar3 = uVar8 + *key;
    break;
  case 6:
                    /* WARNING: Load size is inaccurate */
    uVar5 = uVar5 + (ushort)*(uint *)((int)key + 4);
    uVar3 = uVar8 + *key;
    break;
  case 7:
                    /* WARNING: Load size is inaccurate */
    uVar5 = uVar5 + (*(uint *)((int)key + 4) & 0xffffff);
    uVar3 = uVar8 + *key;
    break;
  case 8:
                    /* WARNING: Load size is inaccurate */
    uVar5 = uVar5 + *(uint *)((int)key + 4);
    uVar3 = uVar8 + *key;
    break;
  case 9:
    uVar3 = (uint)(byte)*(uint *)((int)key + 8);
    goto LAB_000d1534;
  case 10:
    uVar3 = (uint)(ushort)*(uint *)((int)key + 8);
    goto LAB_000d1534;
  case 0xb:
                    /* WARNING: Load size is inaccurate */
    uVar2 = uVar2 + (*(uint *)((int)key + 8) & 0xffffff);
    uVar5 = uVar5 + *(uint *)((int)key + 4);
    uVar3 = uVar8 + *key;
    break;
  case 0xc:
    uVar3 = *(uint *)((int)key + 8);
LAB_000d1534:
    uVar2 = uVar2 + uVar3;
                    /* WARNING: Load size is inaccurate */
    uVar5 = uVar5 + *(uint *)((int)key + 4);
    uVar3 = uVar8 + *key;
    break;
  default:
    goto switchD_000d1302_default;
  }
LAB_000d1360:
  uVar10 = (uVar2 ^ uVar5) - (uVar5 >> 0x12 | uVar5 << 0xe);
  uVar9 = (uVar3 ^ uVar10) - (uVar10 >> 0x15 | uVar10 * 0x800);
  uVar6 = (uVar5 ^ uVar9) - (uVar9 >> 7 | uVar9 * 0x2000000);
  uVar3 = (uVar10 ^ uVar6) - (uVar6 >> 0x10 | uVar6 * 0x10000);
  uVar10 = (uVar9 ^ uVar3) - (uVar3 >> 0x1c | uVar3 * 0x10);
  uVar10 = (uVar6 ^ uVar10) - (uVar10 >> 0x12 | uVar10 * 0x4000);
  uVar2 = (uVar10 ^ uVar3) - (uVar10 >> 8 | uVar10 * 0x1000000);
switchD_000d1302_default:
  return uVar2;
}

