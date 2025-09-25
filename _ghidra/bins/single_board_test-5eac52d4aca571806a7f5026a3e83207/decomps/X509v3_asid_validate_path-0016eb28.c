
int X509v3_asid_validate_path(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (((((*(int *)(param_1 + 0x50) == 0) || (iVar3 = OPENSSL_sk_num(), iVar3 == 0)) ||
       (*(int *)(param_1 + 0x1c) == 0)) ||
      ((iVar3 = *(int *)(param_1 + 0x50), iVar3 == 0 || (iVar4 = OPENSSL_sk_num(iVar3), iVar4 < 1)))
      ) || (*(int *)(param_1 + 0x1c) == 0)) {
LAB_0016ec58:
    *(undefined4 *)(param_1 + 0x60) = 1;
    return 0;
  }
  iVar4 = OPENSSL_sk_value(iVar3,0);
  puVar9 = *(undefined4 **)(iVar4 + 0xac);
  if (puVar9 == (undefined4 *)0x0) {
    return 1;
  }
  iVar5 = X509v3_asid_is_canonical(puVar9);
  if (iVar5 == 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0x29;
    *(int *)(param_1 + 100) = iVar4;
    iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
    if (iVar5 != 0) goto LAB_0016eb88;
LAB_0016ec54:
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
LAB_0016eb88:
    piVar7 = (int *)*puVar9;
    if (piVar7 == (int *)0x0) {
LAB_0016ed10:
      bVar1 = false;
      iVar12 = 0;
    }
    else if (*piVar7 == 0) {
      bVar1 = true;
      iVar12 = 0;
    }
    else {
      if (*piVar7 != 1) goto LAB_0016ed10;
      iVar12 = piVar7[1];
      bVar1 = false;
    }
    piVar7 = (int *)puVar9[1];
    if (piVar7 == (int *)0x0) {
      iVar11 = 0;
      bVar2 = false;
    }
    else if (*piVar7 == 0) {
      bVar2 = true;
      iVar11 = 0;
    }
    else if (*piVar7 == 1) {
      iVar11 = piVar7[1];
      bVar2 = false;
    }
    else {
      iVar11 = 0;
      bVar2 = false;
    }
    for (iVar10 = 1; iVar6 = OPENSSL_sk_num(iVar3), iVar10 < iVar6; iVar10 = iVar10 + 1) {
      iVar4 = OPENSSL_sk_value(iVar3,iVar10);
      if (iVar4 == 0) goto LAB_0016ec58;
      if (*(int *)(iVar4 + 0xac) == 0) {
        if (iVar11 == 0 && iVar12 == 0) {
          iVar11 = 0;
          iVar12 = iVar11;
        }
        else {
          *(undefined4 *)(param_1 + 0x60) = 0x2e;
          *(int *)(param_1 + 0x5c) = iVar10;
LAB_0016ec44:
          *(int *)(param_1 + 100) = iVar4;
          iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
          if (iVar5 == 0) goto LAB_0016ec54;
        }
      }
      else {
        iVar6 = X509v3_asid_is_canonical();
        if (iVar6 == 0) {
          *(int *)(param_1 + 0x5c) = iVar10;
          *(undefined4 *)(param_1 + 0x60) = 0x29;
          *(int *)(param_1 + 100) = iVar4;
          iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
          if (iVar5 == 0) goto LAB_0016ec54;
        }
        piVar8 = *(int **)(iVar4 + 0xac);
        piVar7 = (int *)*piVar8;
        if (piVar7 == (int *)0x0) {
          if (iVar12 != 0) {
            *(int *)(param_1 + 0x5c) = iVar10;
            *(undefined4 *)(param_1 + 0x60) = 0x2e;
            *(int *)(param_1 + 100) = iVar4;
            iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar5 == 0) goto LAB_0016ec54;
            piVar8 = *(int **)(iVar4 + 0xac);
            piVar7 = (int *)*piVar8;
            if (piVar7 == (int *)0x0) {
              iVar12 = 0;
              bVar1 = false;
            }
            else {
              if (*piVar7 == 1) {
                iVar12 = 0;
                goto LAB_0016ed1c;
              }
              bVar1 = false;
              iVar12 = 0;
            }
          }
        }
        else if (*piVar7 == 1) {
          if (!bVar1) {
LAB_0016ed1c:
            iVar6 = asid_contains(piVar7[1],iVar12);
            if (iVar6 == 0) {
              *(undefined4 *)(param_1 + 0x60) = 0x2e;
              *(int *)(param_1 + 0x5c) = iVar10;
              *(int *)(param_1 + 100) = iVar4;
              iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
              if (iVar5 != 0) {
                piVar8 = *(int **)(iVar4 + 0xac);
                bVar1 = false;
                goto LAB_0016ebf8;
              }
              goto LAB_0016ec54;
            }
            piVar8 = *(int **)(iVar4 + 0xac);
            piVar7 = (int *)*piVar8;
          }
          iVar12 = piVar7[1];
          bVar1 = false;
        }
LAB_0016ebf8:
        piVar7 = (int *)piVar8[1];
        if (piVar7 == (int *)0x0) {
          if (iVar11 != 0) {
            *(int *)(param_1 + 0x5c) = iVar10;
            *(undefined4 *)(param_1 + 0x60) = 0x2e;
            *(int *)(param_1 + 100) = iVar4;
            iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar5 == 0) goto LAB_0016ec54;
            piVar7 = *(int **)(*(int *)(iVar4 + 0xac) + 4);
            if (piVar7 == (int *)0x0) {
              iVar11 = 0;
              bVar2 = false;
            }
            else {
              if (*piVar7 == 1) {
                iVar11 = 0;
                goto LAB_0016ed34;
              }
              bVar2 = false;
              iVar11 = 0;
            }
          }
        }
        else if (*piVar7 == 1) {
          if (!bVar2) {
LAB_0016ed34:
            iVar6 = asid_contains(piVar7[1],iVar11);
            if (iVar6 == 0) {
              *(undefined4 *)(param_1 + 0x60) = 0x2e;
              *(int *)(param_1 + 0x5c) = iVar10;
              bVar2 = false;
              goto LAB_0016ec44;
            }
            piVar7 = *(int **)(*(int *)(iVar4 + 0xac) + 4);
          }
          iVar11 = piVar7[1];
          bVar2 = false;
        }
      }
    }
    puVar9 = *(undefined4 **)(iVar4 + 0xac);
    if (puVar9 == (undefined4 *)0x0) {
      return iVar5;
    }
    if (((int *)*puVar9 != (int *)0x0) && (*(int *)*puVar9 == 0)) {
      *(int *)(param_1 + 0x5c) = iVar10;
      *(undefined4 *)(param_1 + 0x60) = 0x2e;
      *(int *)(param_1 + 100) = iVar4;
      iVar5 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar5 == 0) goto LAB_0016ec54;
      puVar9 = *(undefined4 **)(iVar4 + 0xac);
    }
    if (((int *)puVar9[1] != (int *)0x0) && (*(int *)puVar9[1] == 0)) {
      *(int *)(param_1 + 0x5c) = iVar10;
      *(int *)(param_1 + 100) = iVar4;
      *(undefined4 *)(param_1 + 0x60) = 0x2e;
                    /* WARNING: Could not recover jumptable at 0x0016edea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
      return iVar3;
    }
  }
  return iVar5;
}

