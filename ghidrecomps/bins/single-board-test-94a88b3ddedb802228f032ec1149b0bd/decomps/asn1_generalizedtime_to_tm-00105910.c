
bool asn1_generalizedtime_to_tm(int *param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  
  iVar10 = DAT_00105b84;
  if (param_2[1] != 0x18) {
    return false;
  }
  iVar8 = *param_2;
  pbVar11 = (byte *)param_2[2];
  if (iVar8 < 0xd) {
    return false;
  }
  iVar4 = 0;
  iVar2 = 1;
  iVar9 = DAT_00105b84 + 0x24;
  iVar3 = 0;
  pbVar1 = pbVar11;
  while( true ) {
    if (9 < (*pbVar1 - 0x30 & 0xff)) {
      return false;
    }
    if (iVar8 < iVar3 + 1) {
      return false;
    }
    if (9 < pbVar1[1] - 0x30) {
      return false;
    }
    iVar5 = iVar3 + 2;
    iVar12 = (uint)pbVar1[1] + (*pbVar1 - 0x30) * 10;
    iVar6 = iVar12 + -0x30;
    if (iVar8 < iVar5) {
      return false;
    }
    if (iVar6 < *(int *)(iVar10 + iVar4)) {
      return false;
    }
    if (*(int *)(iVar9 + iVar4) < iVar6) {
      return false;
    }
    if (param_1 == (int *)0x0) break;
    switch(iVar2) {
    case 2:
      param_1[5] = param_1[5] + iVar6;
      break;
    case 3:
      param_1[4] = iVar12 + -0x31;
      break;
    case 4:
      param_1[3] = iVar6;
      break;
    case 5:
      param_1[2] = iVar6;
      break;
    case 6:
      param_1[1] = iVar6;
      break;
    case 7:
      *param_1 = iVar6;
      uVar7 = (uint)pbVar11[iVar5];
      goto LAB_001059f6;
    default:
      param_1[5] = iVar6 * 100 + -0x76c;
      goto LAB_001059a8;
    }
LAB_001059ae:
    if ((iVar2 == 6) &&
       ((uVar7 = (uint)pbVar11[iVar5], uVar7 == 0x5a || uVar7 == 0x2b || (uVar7 == 0x2d)))) {
      if (param_1 != (int *)0x0) {
        *param_1 = 0;
        uVar7 = (uint)pbVar1[2];
      }
      goto LAB_001059f6;
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
    iVar3 = iVar5;
    pbVar1 = pbVar1 + 2;
  }
LAB_001059a8:
  if (iVar2 != 7) goto LAB_001059ae;
  uVar7 = (uint)pbVar11[iVar5];
LAB_001059f6:
  if (uVar7 == 0x2e) {
    iVar3 = iVar3 + 3;
    if (iVar8 < iVar3) {
      return false;
    }
    iVar5 = iVar3;
    if (9 < pbVar11[iVar3] - 0x30) {
      return false;
    }
    do {
      iVar5 = iVar5 + 1;
      uVar7 = (uint)pbVar11[iVar5];
      if (9 < uVar7 - 0x30) break;
    } while (iVar5 <= iVar8);
    if (iVar3 == iVar5) {
      return false;
    }
  }
  if (uVar7 == 0x5a) {
    iVar5 = iVar5 + 1;
  }
  else if (uVar7 == 0x2b || uVar7 == 0x2d) {
    if (uVar7 == 0x2d) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
    }
    if (iVar8 <= iVar5 + 4) {
      return false;
    }
    if (param_1 != (int *)0x0) {
      iVar2 = iVar5 + 3;
      pbVar11 = pbVar11 + iVar5;
      iVar4 = 7;
      iVar9 = 8;
      iVar3 = 0;
      do {
        if (9 < (pbVar11[1] - 0x30 & 0xff)) {
          return false;
        }
        iVar5 = (uint)pbVar11[2] + (pbVar11[1] - 0x30) * 10 + -0x30;
        if (9 < pbVar11[2] - 0x30) {
          return false;
        }
        iVar3 = iVar3 + iVar5 * 0x3c;
        if (iVar5 < (int)(&min_9286)[iVar4]) {
          return false;
        }
        if (*(int *)(DAT_00105b80 + iVar4 * 4) < iVar5) {
          return false;
        }
        if (iVar4 == 7) {
          iVar3 = iVar5 * 0xe10;
        }
        else if (iVar9 == 9) {
          iVar5 = iVar2;
          if ((iVar3 != 0) && (iVar10 = OPENSSL_gmtime_adj(param_1,0,iVar10 * iVar3), iVar10 == 0))
          {
            return false;
          }
          goto LAB_00105ac2;
        }
        pbVar11 = pbVar11 + 2;
        iVar9 = iVar9 + 1;
        iVar2 = iVar2 + 2;
        iVar4 = iVar4 + 1;
      } while( true );
    }
    if (9 < (pbVar11[iVar5 + 1] - 0x30 & 0xff)) {
      return false;
    }
    if (9 < pbVar11[iVar5 + 2] - 0x30) {
      return false;
    }
    iVar10 = (uint)pbVar11[iVar5 + 2] + (pbVar11[iVar5 + 1] - 0x30) * 10 + -0x30;
    if (iVar10 < 0) {
      return false;
    }
    if (0xc < iVar10) {
      return false;
    }
    if (9 < (pbVar11[iVar5 + 3] - 0x30 & 0xff)) {
      return false;
    }
    if (9 < pbVar11[iVar5 + 4] - 0x30) {
      return false;
    }
    iVar10 = (uint)pbVar11[iVar5 + 4] + (pbVar11[iVar5 + 3] - 0x30) * 10 + -0x30;
    if (iVar10 < 0) {
      return false;
    }
    if (0x3b < iVar10) {
      return false;
    }
    iVar5 = iVar5 + 5;
  }
  else if (uVar7 != 0) {
    return false;
  }
LAB_00105ac2:
  return iVar5 == iVar8;
}

