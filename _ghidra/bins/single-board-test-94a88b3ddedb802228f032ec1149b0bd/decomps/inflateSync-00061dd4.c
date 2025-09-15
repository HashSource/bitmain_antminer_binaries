
undefined4 inflateSync(int *param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  uint uVar8;
  char *pcVar9;
  int *piVar10;
  char cVar11;
  uint uVar12;
  int iVar13;
  char cStack_25;
  char local_24 [8];
  
  if ((param_1 == (int *)0x0) || (piVar10 = (int *)param_1[7], piVar10 == (int *)0x0)) {
    uVar4 = 0xfffffffe;
  }
  else {
    uVar3 = param_1[1];
    if ((uVar3 == 0) && ((uint)piVar10[0xf] < 8)) {
      uVar4 = 0xfffffffb;
    }
    else {
      if (*piVar10 == 0x1f) {
        uVar8 = piVar10[0x1a];
        bVar7 = uVar8 < 4;
      }
      else {
        uVar3 = piVar10[0xf];
        *piVar10 = 0x1f;
        uVar8 = uVar3 & 0xfffffff8;
        piVar10[0xf] = uVar8;
        uVar3 = piVar10[0xe] << (uVar3 & 7);
        piVar10[0xe] = uVar3;
        if (uVar8 < 8) {
          bVar7 = true;
          uVar8 = 0;
          piVar10[0x1a] = 0;
        }
        else {
          uVar12 = uVar8 - 8 >> 3;
          pcVar9 = &cStack_25;
          do {
            pcVar9 = pcVar9 + 1;
            *pcVar9 = (char)uVar3;
            uVar3 = uVar3 >> 8;
          } while (pcVar9 != local_24 + uVar12);
          uVar8 = 0;
          piVar10[0xe] = uVar3;
          uVar3 = 0;
          piVar10[0xf] = 0;
          piVar10[0x1a] = 0;
          do {
            if (uVar8 < 2) {
              cVar2 = '\0';
            }
            else {
              cVar2 = -1;
            }
            if (local_24[uVar3] == cVar2) {
              uVar8 = uVar8 + 1;
              bVar7 = uVar8 < 4;
            }
            else {
              uVar8 = 4 - uVar8;
              if (local_24[uVar3] == '\0') {
                if (uVar8 < 4) {
                  bVar7 = true;
                }
                else {
                  bVar7 = false;
                }
              }
              else {
                bVar7 = true;
                uVar8 = 0;
              }
            }
            uVar3 = uVar3 + 1;
            bVar1 = bVar7;
            if (uVar12 + 1 <= uVar3) {
              bVar1 = false;
            }
          } while (bVar1);
        }
        piVar10[0x1a] = uVar8;
        uVar3 = param_1[1];
      }
      if (uVar3 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = (uint)bVar7;
      }
      iVar13 = *param_1;
      if (uVar12 != 0) {
        uVar12 = 0;
        do {
          cVar2 = *(char *)(iVar13 + uVar12);
          if (uVar8 < 2) {
            cVar11 = '\0';
          }
          else {
            cVar11 = -1;
          }
          if (cVar2 == cVar11) {
            uVar8 = uVar8 + 1;
            bVar7 = uVar8 < 4;
          }
          else {
            uVar8 = 4 - uVar8;
            if (cVar2 == '\0') {
              if (uVar8 < 4) {
                bVar7 = true;
              }
              else {
                bVar7 = false;
              }
            }
            else {
              bVar7 = true;
              uVar8 = 0;
            }
          }
          uVar12 = uVar12 + 1;
          if (uVar3 <= uVar12) {
            bVar7 = false;
          }
        } while (bVar7);
      }
      piVar10[0x1a] = uVar8;
      iVar5 = param_1[2];
      *param_1 = iVar13 + uVar12;
      param_1[1] = param_1[1] - uVar12;
      param_1[2] = uVar12 + iVar5;
      if (uVar8 == 4) {
        uVar3 = piVar10[2];
        iVar13 = param_1[5];
        piVar10[10] = 0;
        piVar10[0xb] = 0;
        piVar10[0xc] = 0;
        piVar10[7] = 0;
        param_1[5] = 0;
        param_1[2] = 0;
        param_1[6] = 0;
        if (uVar3 != 0) {
          param_1[0xc] = uVar3 & 1;
        }
        piVar6 = piVar10 + 0x14c;
        uVar4 = 0;
        piVar10[1] = 0;
        piVar10[3] = 0;
        piVar10[8] = 0;
        piVar10[0xe] = 0;
        piVar10[0xf] = 0;
        piVar10[5] = 0x8000;
        piVar10[0x1b] = (int)piVar6;
        piVar10[0x14] = (int)piVar6;
        piVar10[0x13] = (int)piVar6;
        piVar10[0x6f0] = 1;
        piVar10[0x6f1] = -1;
        param_1[2] = uVar12 + iVar5;
        param_1[5] = iVar13;
        *piVar10 = 0xb;
      }
      else {
        uVar4 = 0xfffffffd;
      }
    }
  }
  return uVar4;
}

