
undefined4 ssl_get_min_max_version(int *param_1,int *param_2,int *param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (*(int *)param_1[1] == 0x10000) {
    puVar6 = (undefined1 *)&tls_version_table;
  }
  else {
    if (*(int *)param_1[1] != 0x1ffff) {
      iVar9 = *param_1;
      *param_3 = iVar9;
      *param_2 = iVar9;
      if (param_4 == (int *)0x0) {
        return 0;
      }
      return 0x44;
    }
    puVar6 = dtls_version_table;
  }
  *param_2 = 0;
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (*(int *)puVar6 == 0) {
    *param_3 = 0;
  }
  else {
    iVar9 = 0;
    iVar10 = 0;
    bVar2 = true;
    piVar7 = (int *)((int)puVar6 + 0x24);
    do {
      while ((code *)piVar7[-8] == (code *)0x0) {
        HintPreloadData(piVar7);
        bVar2 = true;
        piVar3 = piVar7 + -6;
        iVar9 = 0;
        piVar7 = piVar7 + 3;
        if (*piVar3 == 0) goto LAB_000f0c58;
      }
      piVar3 = (int *)(*(code *)piVar7[-8])();
      bVar1 = bVar2;
      if (iVar9 != 0) {
        bVar1 = false;
      }
      if (bVar1) {
        iVar9 = piVar7[-9];
      }
      iVar5 = param_1[0x13d];
      iVar8 = *piVar3;
      if ((iVar5 == 0) || (iVar8 == iVar5)) {
LAB_000f0c1e:
        iVar5 = ssl_security(param_1,9,0,iVar8,0);
        if (iVar5 == 0) goto LAB_000f0c30;
        iVar5 = param_1[0x13e];
        if ((iVar5 != 0) && (iVar8 != iVar5)) {
          if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
            if (iVar8 < iVar5) goto LAB_000f0cac;
          }
          else {
            if (iVar8 == 0x100) {
              if (iVar5 == 0x100) goto LAB_000f0c30;
              iVar8 = 0xff00;
            }
            else if (iVar5 == 0x100) {
              iVar5 = 0xff00;
            }
            if (iVar5 < iVar8) goto LAB_000f0cac;
          }
          goto LAB_000f0c30;
        }
LAB_000f0cac:
        if (((param_1[0x13b] & piVar3[2]) != 0) ||
           ((piVar3[1] << 0x1e < 0 && ((*(uint *)(param_1[0x101] + 0x10) & 0x30000) != 0))))
        goto LAB_000f0c30;
        if (bVar2) {
          bVar2 = false;
          if (param_4 != (int *)0x0 && iVar9 != 0) {
            *param_4 = iVar9;
          }
          iVar10 = *piVar3;
          *param_2 = iVar10;
        }
        else {
          *param_2 = *piVar3;
        }
      }
      else {
        if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
          if (iVar5 <= iVar8) goto LAB_000f0c1e;
        }
        else {
          if (iVar8 == 0x100) {
            if (iVar5 == 0x100) goto LAB_000f0c1e;
            iVar4 = 0xff00;
          }
          else {
            iVar4 = iVar8;
            if (iVar5 == 0x100) {
              iVar5 = 0xff00;
            }
          }
          if (iVar4 <= iVar5) goto LAB_000f0c1e;
        }
LAB_000f0c30:
        bVar2 = true;
      }
      HintPreloadData(piVar7);
      piVar3 = piVar7 + -6;
      piVar7 = piVar7 + 3;
    } while (*piVar3 != 0);
LAB_000f0c58:
    *param_3 = iVar10;
    if (iVar10 != 0) {
      return 0;
    }
  }
  return 0xbf;
}

