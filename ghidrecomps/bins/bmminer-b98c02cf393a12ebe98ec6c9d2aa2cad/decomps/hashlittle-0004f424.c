
uint hashlittle(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar5 = param_3 + -0x21524111 + param_2;
  uVar4 = uVar5;
  uVar6 = uVar5;
  if (((uint)param_1 & 3) == 0) {
    uVar7 = uVar5;
    if (0xc < param_2) {
      piVar1 = param_1 + 3;
      do {
        param_1 = piVar1;
        param_2 = param_2 - 0xc;
        uVar5 = uVar5 + param_1[-1];
        uVar4 = (param_1[-3] - uVar5) + uVar7 ^ (uVar5 >> 0x1c | uVar5 * 0x10);
        iVar2 = uVar5 + param_1[-2] + uVar6;
        iVar8 = uVar4 + iVar2;
        uVar4 = (param_1[-2] + uVar6) - uVar4 ^ (uVar4 >> 0x1a | uVar4 << 6);
        iVar3 = uVar4 + iVar8;
        uVar4 = iVar2 - uVar4 ^ (uVar4 >> 0x18 | uVar4 << 8);
        iVar2 = uVar4 + iVar3;
        uVar4 = iVar8 - uVar4 ^ (uVar4 >> 0x10 | uVar4 << 0x10);
        uVar7 = uVar4 + iVar2;
        uVar4 = iVar3 - uVar4 ^ (uVar4 >> 0xd | uVar4 << 0x13);
        uVar6 = uVar4 + uVar7;
        uVar5 = iVar2 - uVar4 ^ (uVar4 >> 0x1c | uVar4 << 4);
        uVar4 = uVar5;
        piVar1 = param_1 + 3;
      } while (0xc < param_2);
    }
    switch(param_2) {
    case 3:
      uVar7 = uVar7 + (uint)*(byte *)((int)param_1 + 2) * 0x10000;
    case 2:
      uVar7 = uVar7 + (uint)*(byte *)((int)param_1 + 1) * 0x100;
    case 1:
      uVar7 = *(byte *)param_1 + uVar7;
      break;
    case 7:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 6) * 0x10000;
    case 6:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 5) * 0x100;
    case 5:
      uVar6 = uVar6 + *(byte *)(param_1 + 1);
    case 4:
      uVar7 = *param_1 + uVar7;
      break;
    case 0xb:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 10) * 0x10000;
    case 10:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 9) * 0x100;
    case 9:
      uVar4 = uVar4 + *(byte *)(param_1 + 2);
    case 8:
      uVar6 = uVar6 + param_1[1];
      uVar7 = *param_1 + uVar7;
      break;
    case 0xc:
      uVar4 = uVar4 + param_1[2];
      uVar6 = uVar6 + param_1[1];
      uVar7 = *param_1 + uVar7;
      break;
    default:
      goto switchD_0004f4b4_caseD_c;
    }
  }
  else if ((int)param_1 << 0x1f < 0) {
    uVar7 = uVar5;
    if (0xc < param_2) {
      piVar1 = param_1 + 3;
      do {
        param_1 = piVar1;
        param_2 = param_2 - 0xc;
        uVar5 = uVar5 + (uint)*(byte *)(param_1 + -1) +
                        (uint)*(byte *)((int)param_1 + -2) * 0x10000 +
                        (uint)*(byte *)((int)param_1 + -3) * 0x100 +
                        (uint)*(byte *)((int)param_1 + -1) * 0x1000000;
        uVar7 = (((uint)*(byte *)(param_1 + -3) +
                  (uint)*(byte *)((int)param_1 + -10) * 0x10000 +
                  (uint)*(byte *)((int)param_1 + -0xb) * 0x100 +
                 (uint)*(byte *)((int)param_1 + -9) * 0x1000000) - uVar5) + uVar7 ^
                (uVar5 >> 0x1c | uVar5 * 0x10);
        iVar3 = uVar6 + (uint)*(byte *)(param_1 + -2) +
                        (uint)*(byte *)((int)param_1 + -6) * 0x10000 +
                        (uint)*(byte *)((int)param_1 + -7) * 0x100 +
                        (uint)*(byte *)((int)param_1 + -5) * 0x1000000;
        iVar2 = uVar5 + iVar3;
        uVar4 = iVar3 - uVar7 ^ (uVar7 >> 0x1a | uVar7 << 6);
        iVar3 = uVar7 + iVar2;
        iVar8 = uVar4 + iVar3;
        uVar4 = iVar2 - uVar4 ^ (uVar4 >> 0x18 | uVar4 << 8);
        iVar2 = uVar4 + iVar8;
        uVar4 = iVar3 - uVar4 ^ (uVar4 >> 0x10 | uVar4 << 0x10);
        uVar7 = uVar4 + iVar2;
        uVar4 = iVar8 - uVar4 ^ (uVar4 >> 0xd | uVar4 << 0x13);
        uVar6 = uVar4 + uVar7;
        uVar5 = iVar2 - uVar4 ^ (uVar4 >> 0x1c | uVar4 << 4);
        uVar4 = uVar5;
        piVar1 = param_1 + 3;
      } while (0xc < param_2);
    }
    switch(param_2) {
    case 0xc:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 0xb) * 0x1000000;
    case 0xb:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 10) * 0x10000;
    case 10:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 9) * 0x100;
    case 9:
      uVar4 = uVar4 + *(byte *)(param_1 + 2);
    case 8:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 7) * 0x1000000;
    case 7:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 6) * 0x10000;
    case 6:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 5) * 0x100;
    case 5:
      uVar6 = uVar6 + *(byte *)(param_1 + 1);
    case 4:
      uVar7 = uVar7 + (uint)*(byte *)((int)param_1 + 3) * 0x1000000;
    case 3:
      uVar7 = uVar7 + (uint)*(byte *)((int)param_1 + 2) * 0x10000;
    case 2:
      uVar7 = uVar7 + (uint)*(byte *)((int)param_1 + 1) * 0x100;
    case 1:
      uVar7 = *(byte *)param_1 + uVar7;
      break;
    default:
      goto switchD_0004f4b4_caseD_c;
    }
  }
  else {
    if (0xc < param_2) {
      piVar1 = param_1 + 3;
      do {
        param_1 = piVar1;
        param_2 = param_2 - 0xc;
        uVar4 = uVar4 + (uint)*(ushort *)(param_1 + -1) +
                        (uint)*(ushort *)((int)param_1 + -2) * 0x10000;
        uVar5 = uVar5 + (((uint)*(ushort *)(param_1 + -3) +
                         (uint)*(ushort *)((int)param_1 + -10) * 0x10000) - uVar4) ^
                (uVar4 >> 0x1c | uVar4 * 0x10);
        iVar2 = (uint)*(ushort *)(param_1 + -2) + (uint)*(ushort *)((int)param_1 + -6) * 0x10000 +
                uVar6;
        iVar3 = uVar4 + iVar2;
        iVar8 = uVar5 + iVar3;
        uVar4 = iVar2 - uVar5 ^ (uVar5 >> 0x1a | uVar5 << 6);
        iVar2 = uVar4 + iVar8;
        uVar4 = iVar3 - uVar4 ^ (uVar4 >> 0x18 | uVar4 << 8);
        iVar3 = uVar4 + iVar2;
        uVar4 = iVar8 - uVar4 ^ (uVar4 >> 0x10 | uVar4 << 0x10);
        uVar5 = uVar4 + iVar3;
        uVar4 = iVar2 - uVar4 ^ (uVar4 >> 0xd | uVar4 << 0x13);
        uVar6 = uVar4 + uVar5;
        uVar4 = iVar3 - uVar4 ^ (uVar4 >> 0x1c | uVar4 << 4);
        piVar1 = param_1 + 3;
      } while (0xc < param_2);
    }
    switch(param_2) {
    case 1:
      uVar7 = *(byte *)param_1 + uVar5;
      break;
    case 3:
      uVar5 = uVar5 + (uint)*(byte *)((int)param_1 + 2) * 0x10000;
    case 2:
      uVar7 = *(ushort *)param_1 + uVar5;
      break;
    case 5:
      uVar6 = uVar6 + *(byte *)(param_1 + 1);
    case 4:
      uVar7 = *(ushort *)param_1 + uVar5 + (uint)*(ushort *)((int)param_1 + 2) * 0x10000;
      break;
    case 7:
      uVar6 = uVar6 + (uint)*(byte *)((int)param_1 + 6) * 0x10000;
    case 6:
      uVar7 = *(ushort *)param_1 + uVar5 + (uint)*(ushort *)((int)param_1 + 2) * 0x10000;
      uVar6 = uVar6 + *(ushort *)(param_1 + 1);
      break;
    case 9:
      uVar4 = uVar4 + *(byte *)(param_1 + 2);
    case 8:
      uVar6 = *(ushort *)(param_1 + 1) + uVar6 + (uint)*(ushort *)((int)param_1 + 6) * 0x10000;
      uVar7 = *(ushort *)param_1 + uVar5 + (uint)*(ushort *)((int)param_1 + 2) * 0x10000;
      break;
    case 0xb:
      uVar4 = uVar4 + (uint)*(byte *)((int)param_1 + 10) * 0x10000;
    case 10:
      uVar6 = *(ushort *)(param_1 + 1) + uVar6 + (uint)*(ushort *)((int)param_1 + 6) * 0x10000;
      uVar7 = *(ushort *)param_1 + uVar5 + (uint)*(ushort *)((int)param_1 + 2) * 0x10000;
      uVar4 = uVar4 + *(ushort *)(param_1 + 2);
      break;
    case 0xc:
      uVar4 = uVar4 + *(ushort *)(param_1 + 2) + (uint)*(ushort *)((int)param_1 + 10) * 0x10000;
      uVar6 = *(ushort *)(param_1 + 1) + uVar6 + (uint)*(ushort *)((int)param_1 + 6) * 0x10000;
      uVar7 = *(ushort *)param_1 + uVar5 + (uint)*(ushort *)((int)param_1 + 2) * 0x10000;
      break;
    default:
switchD_0004f4b4_caseD_c:
      return uVar4;
    }
  }
  uVar5 = (uVar4 ^ uVar6) - (uVar6 >> 0x12 | uVar6 << 0xe);
  uVar4 = (uVar7 ^ uVar5) - (uVar5 >> 0x15 | uVar5 * 0x800);
  uVar7 = (uVar6 ^ uVar4) - (uVar4 >> 7 | uVar4 * 0x2000000);
  uVar6 = (uVar5 ^ uVar7) - (uVar7 >> 0x10 | uVar7 * 0x10000);
  uVar4 = (uVar4 ^ uVar6) - (uVar6 >> 0x1c | uVar6 * 0x10);
  uVar4 = (uVar7 ^ uVar4) - (uVar4 >> 0x12 | uVar4 * 0x4000);
  return (uVar6 ^ uVar4) - (uVar4 >> 8 | uVar4 * 0x1000000);
}

