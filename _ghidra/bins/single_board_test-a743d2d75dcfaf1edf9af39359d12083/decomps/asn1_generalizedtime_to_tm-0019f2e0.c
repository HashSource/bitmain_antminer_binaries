
bool asn1_generalizedtime_to_tm(int *param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  
  if (param_2[1] != 0x18) {
    return false;
  }
  iVar7 = *param_2;
  pbVar9 = (byte *)param_2[2];
  if (iVar7 < 0xd) {
    return false;
  }
  iVar3 = 0;
  iVar2 = 1;
  iVar8 = 0;
  pbVar1 = pbVar9;
  while( true ) {
    if (9 < (*pbVar1 - 0x30 & 0xff)) {
      return false;
    }
    if (iVar7 < iVar8 + 1) {
      return false;
    }
    if (9 < pbVar1[1] - 0x30) {
      return false;
    }
    iVar4 = iVar8 + 2;
    iVar10 = (uint)pbVar1[1] + (*pbVar1 - 0x30) * 10;
    iVar5 = iVar10 + -0x30;
    if (iVar7 < iVar4) {
      return false;
    }
    if (iVar5 < *(int *)((int)&min_9286 + iVar3)) {
      return false;
    }
    if (*(int *)(max_9287 + iVar3) < iVar5) {
      return false;
    }
    if (param_1 == (int *)0x0) break;
    switch(iVar2) {
    case 2:
      param_1[5] = param_1[5] + iVar5;
      break;
    case 3:
      param_1[4] = iVar10 + -0x31;
      break;
    case 4:
      param_1[3] = iVar5;
      break;
    case 5:
      param_1[2] = iVar5;
      break;
    case 6:
      param_1[1] = iVar5;
      break;
    case 7:
      *param_1 = iVar5;
      uVar6 = (uint)pbVar9[iVar4];
      goto LAB_0019f3c6;
    default:
      param_1[5] = iVar5 * 100 + -0x76c;
      goto LAB_0019f378;
    }
LAB_0019f37e:
    if ((iVar2 == 6) &&
       ((uVar6 = (uint)pbVar9[iVar4], uVar6 == 0x5a || uVar6 == 0x2b || (uVar6 == 0x2d)))) {
      if (param_1 != (int *)0x0) {
        *param_1 = 0;
        uVar6 = (uint)pbVar1[2];
      }
      goto LAB_0019f3c6;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
    iVar8 = iVar4;
    pbVar1 = pbVar1 + 2;
  }
LAB_0019f378:
  if (iVar2 != 7) goto LAB_0019f37e;
  uVar6 = (uint)pbVar9[iVar4];
LAB_0019f3c6:
  if (uVar6 == 0x2e) {
    iVar8 = iVar8 + 3;
    if (iVar7 < iVar8) {
      return false;
    }
    iVar4 = iVar8;
    if (9 < pbVar9[iVar8] - 0x30) {
      return false;
    }
    do {
      iVar4 = iVar4 + 1;
      uVar6 = (uint)pbVar9[iVar4];
      if (9 < uVar6 - 0x30) break;
    } while (iVar4 <= iVar7);
    if (iVar8 == iVar4) {
      return false;
    }
  }
  if (uVar6 == 0x5a) {
    iVar4 = iVar4 + 1;
  }
  else if (uVar6 == 0x2b || uVar6 == 0x2d) {
    if (uVar6 == 0x2d) {
      iVar8 = -1;
    }
    else {
      iVar8 = 1;
    }
    if (iVar7 <= iVar4 + 4) {
      return false;
    }
    if (param_1 != (int *)0x0) {
      iVar3 = iVar4 + 3;
      pbVar9 = pbVar9 + iVar4;
      iVar4 = 7;
      iVar5 = 8;
      iVar2 = 0;
      do {
        if (9 < (pbVar9[1] - 0x30 & 0xff)) {
          return false;
        }
        iVar10 = (uint)pbVar9[2] + (pbVar9[1] - 0x30) * 10 + -0x30;
        if (9 < pbVar9[2] - 0x30) {
          return false;
        }
        iVar2 = iVar2 + iVar10 * 0x3c;
        if (iVar10 < (int)(&min_9286)[iVar4]) {
          return false;
        }
        if (*(int *)(max_9287 + iVar4 * 4) < iVar10) {
          return false;
        }
        if (iVar4 == 7) {
          iVar2 = iVar10 * 0xe10;
        }
        else if (iVar5 == 9) {
          iVar4 = iVar3;
          if ((iVar2 != 0) && (iVar8 = OPENSSL_gmtime_adj(param_1,0,iVar8 * iVar2), iVar8 == 0)) {
            return false;
          }
          goto LAB_0019f492;
        }
        pbVar9 = pbVar9 + 2;
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 2;
        iVar4 = iVar4 + 1;
      } while( true );
    }
    if (9 < (pbVar9[iVar4 + 1] - 0x30 & 0xff)) {
      return false;
    }
    if (9 < pbVar9[iVar4 + 2] - 0x30) {
      return false;
    }
    iVar8 = (uint)pbVar9[iVar4 + 2] + (pbVar9[iVar4 + 1] - 0x30) * 10 + -0x30;
    if (iVar8 < 0) {
      return false;
    }
    if (0xc < iVar8) {
      return false;
    }
    if (9 < (pbVar9[iVar4 + 3] - 0x30 & 0xff)) {
      return false;
    }
    if (9 < pbVar9[iVar4 + 4] - 0x30) {
      return false;
    }
    iVar8 = (uint)pbVar9[iVar4 + 4] + (pbVar9[iVar4 + 3] - 0x30) * 10 + -0x30;
    if (iVar8 < 0) {
      return false;
    }
    if (0x3b < iVar8) {
      return false;
    }
    iVar4 = iVar4 + 5;
  }
  else if (uVar6 != 0) {
    return false;
  }
LAB_0019f492:
  return iVar4 == iVar7;
}

