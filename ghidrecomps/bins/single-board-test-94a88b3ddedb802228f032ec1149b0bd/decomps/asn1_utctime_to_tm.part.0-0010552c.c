
/* WARNING: Type propagation algorithm not settling */

bool asn1_utctime_to_tm_part_0(int *param_1,int *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  int local_2c;
  
  iVar10 = DAT_0010574c;
  iVar9 = *param_2;
  pbVar11 = (byte *)param_2[2];
  if (iVar9 < 0xb) {
    return false;
  }
  iVar6 = 0;
  iVar4 = 1;
  iVar12 = DAT_0010574c + 0x20;
  iVar5 = 0;
  pbVar1 = pbVar11;
  while( true ) {
    if (9 < (*pbVar1 - 0x30 & 0xff)) {
      return false;
    }
    if (iVar9 < iVar5 + 1) {
      return false;
    }
    if (9 < pbVar1[1] - 0x30) {
      return false;
    }
    iVar7 = iVar5 + 2;
    iVar3 = (uint)pbVar1[1] + (*pbVar1 - 0x30) * 10;
    iVar8 = iVar3 + -0x30;
    if (iVar9 < iVar7) {
      return false;
    }
    if (iVar8 < *(int *)(iVar10 + iVar6)) {
      return false;
    }
    if (*(int *)(iVar12 + iVar6) < iVar8) {
      return false;
    }
    if (param_1 == (int *)0x0) break;
    switch(iVar4) {
    case 2:
      param_1[4] = iVar3 + -0x31;
      break;
    case 3:
      param_1[3] = iVar8;
      break;
    case 4:
      param_1[2] = iVar8;
      break;
    case 5:
      param_1[1] = iVar8;
      break;
    case 6:
      *param_1 = iVar8;
      bVar2 = pbVar11[iVar7];
      goto LAB_00105612;
    default:
      if (iVar8 < 0x32) {
        iVar8 = iVar3 + 0x34;
      }
      param_1[5] = iVar8;
      goto LAB_001055b6;
    }
LAB_001055bc:
    if ((iVar4 == 5) &&
       ((bVar2 = pbVar11[iVar7], bVar2 == 0x5a || bVar2 == 0x2b || (bVar2 == 0x2d)))) {
      if (param_1 != (int *)0x0) {
        *param_1 = 0;
        bVar2 = pbVar1[2];
      }
      goto LAB_00105612;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar5 = iVar7;
    pbVar1 = pbVar1 + 2;
  }
LAB_001055b6:
  if (iVar4 != 6) goto LAB_001055bc;
  bVar2 = pbVar11[iVar7];
LAB_00105612:
  if (bVar2 == 0x5a) {
    iVar7 = iVar5 + 3;
  }
  else if (bVar2 == 0x2d || bVar2 == 0x2b) {
    if (bVar2 == 0x2d) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
    }
    if (iVar5 + 6 < iVar9) {
      if (param_1 != (int *)0x0) {
        pbVar11 = pbVar11 + iVar7;
        iVar7 = iVar5 + 5;
        iVar4 = 6;
        iVar5 = 0;
        local_2c = 7;
        do {
          if (9 < (pbVar11[1] - 0x30 & 0xff)) {
            return false;
          }
          iVar6 = (uint)pbVar11[2] + (pbVar11[1] - 0x30) * 10 + -0x30;
          if (9 < pbVar11[2] - 0x30) {
            return false;
          }
          iVar5 = iVar5 + iVar6 * 0x3c;
          if (iVar6 < (int)(&min_9286)[iVar4]) {
            return false;
          }
          if (*(int *)(DAT_00105748 + iVar4 * 4) < iVar6) {
            return false;
          }
          if (iVar4 == 6) {
            iVar5 = iVar6 * 0xe10;
          }
          else if (local_2c == 8) {
            if ((iVar5 != 0) && (iVar10 = OPENSSL_gmtime_adj(param_1,0,iVar5 * iVar10), iVar10 == 0)
               ) {
              return false;
            }
            goto LAB_001056b8;
          }
          pbVar11 = pbVar11 + 2;
          iVar7 = iVar7 + 2;
          iVar4 = iVar4 + 1;
          local_2c = local_2c + 1;
        } while( true );
      }
      if ((((9 < (pbVar11[iVar5 + 3] - 0x30 & 0xff)) || (9 < pbVar11[iVar5 + 4] - 0x30)) ||
          (iVar10 = (uint)pbVar11[iVar5 + 4] + (pbVar11[iVar5 + 3] - 0x30) * 10 + -0x30, iVar10 < 0)
          ) || ((0xc < iVar10 || (9 < (pbVar11[iVar5 + 5] - 0x30 & 0xff))))) {
        return false;
      }
      if (((pbVar11[iVar5 + 6] - 0x30 < 10) &&
          (iVar10 = (uint)pbVar11[iVar5 + 6] + (pbVar11[iVar5 + 5] - 0x30) * 10 + -0x30, -1 < iVar10
          )) && (iVar10 < 0x3c)) {
        iVar7 = iVar5 + 7;
        goto LAB_001056b8;
      }
    }
    return false;
  }
LAB_001056b8:
  return iVar9 == iVar7;
}

