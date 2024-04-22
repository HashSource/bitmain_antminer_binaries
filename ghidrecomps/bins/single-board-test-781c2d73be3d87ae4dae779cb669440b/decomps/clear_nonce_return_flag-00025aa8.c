
/* WARNING: Unknown calling convention */

void clear_nonce_return_flag(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  work *pwVar6;
  work *pwVar7;
  work *pwVar8;
  int iVar9;
  uint OpenCoreNum1;
  int iVar10;
  int *piVar11;
  uint OpenCoreNum2;
  uint OpenCoreNum3;
  uint OpenCoreNum4;
  uint uVar12;
  int *piVar13;
  
  uVar12 = Conf.OpenCoreNum4;
  OpenCoreNum3 = Conf.OpenCoreNum3;
  OpenCoreNum2 = Conf.OpenCoreNum2;
  OpenCoreNum1 = Conf.OpenCoreNum1;
  puts(DAT_00025bbc);
  if (Conf.AsicNum == 1) {
    iVar9 = 0x20;
    iVar10 = 0;
    do {
      uVar1 = OpenCoreNum1 & 1;
      OpenCoreNum1 = OpenCoreNum1 >> 1;
      if (uVar1 != 0) {
        iVar10 = iVar10 + 1;
      }
      uVar1 = OpenCoreNum2 & 1;
      OpenCoreNum2 = OpenCoreNum2 >> 1;
      if (uVar1 != 0) {
        iVar10 = iVar10 + 1;
      }
      uVar1 = OpenCoreNum3 & 1;
      OpenCoreNum3 = OpenCoreNum3 >> 1;
      if (uVar1 != 0) {
        iVar10 = iVar10 + 1;
      }
      uVar1 = uVar12 & 1;
      uVar12 = uVar12 >> 1;
      if (uVar1 != 0) {
        iVar10 = iVar10 + 1;
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    printf("%s: single ASIC get_pattern_loop = %d\n",DAT_00025bbc,iVar10);
  }
  else {
    iVar10 = 0;
  }
  uVar12 = Conf.pattern_number;
  if (Conf.AsicType == 0x569) {
    iVar9 = 0x32;
  }
  else {
    iVar9 = 0;
  }
  if (gHashBoard_V9 == false) {
    if (Conf.AsicNum != 1) {
      return;
    }
  }
  else if (Conf.AsicNum != 1) {
    piVar13 = DAT_00025bc0 + 0x2d;
    iVar10 = Conf.pattern_number * 0x44;
    piVar11 = DAT_00025bc0;
    do {
      piVar11 = piVar11 + 1;
      if (iVar9 != 0) {
        iVar2 = 0;
        iVar4 = *piVar11;
        do {
          iVar3 = iVar4 + iVar10;
          if (uVar12 != 0) {
            do {
              *(undefined4 *)(iVar4 + 0x34) = 0;
              iVar5 = iVar4 + 0x44;
              *(undefined4 *)(iVar4 + 0x38) = 0;
              *(undefined4 *)(iVar4 + 0x3c) = 0;
              *(undefined4 *)(iVar4 + 0x40) = 0;
              iVar4 = iVar5;
            } while (iVar3 != iVar5);
          }
          iVar2 = iVar2 + 1;
          iVar4 = iVar3;
        } while (iVar9 != iVar2);
      }
    } while (piVar13 != piVar11);
    return;
  }
  if (iVar10 != 0) {
    iVar9 = 0;
    do {
      if (uVar12 != 0) {
        pwVar6 = cgpu.works[iVar9];
        pwVar7 = pwVar6;
        do {
          pwVar7->is_nonce_return_back[0][0] = 0;
          pwVar8 = pwVar7 + 1;
          pwVar7->is_nonce_return_back[1][0] = 0;
          pwVar7->is_nonce_return_back[2][0] = 0;
          pwVar7->is_nonce_return_back[3][0] = 0;
          pwVar7 = pwVar8;
        } while (pwVar6 + uVar12 != pwVar8);
      }
      iVar9 = iVar9 + 1;
    } while (iVar10 != iVar9);
  }
  return;
}

