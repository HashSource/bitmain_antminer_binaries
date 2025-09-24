
int X509v3_asid_validate_resource_set(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (param_2 == (int *)0x0) {
    return 1;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = OPENSSL_sk_num();
  if (iVar3 == 0) {
    return 0;
  }
  if ((param_3 == 0) && (iVar3 = X509v3_asid_inherits(param_2), iVar3 != 0)) {
    return 0;
  }
  iVar3 = OPENSSL_sk_num(param_1);
  if (iVar3 < 1) {
    return 0;
  }
  iVar3 = X509v3_asid_is_canonical(param_2);
  if (iVar3 == 0) {
    return 0;
  }
  piVar6 = (int *)*param_2;
  if (piVar6 == (int *)0x0) {
LAB_0017316c:
    bVar1 = false;
    iVar3 = 0;
  }
  else if (*piVar6 == 0) {
    bVar1 = true;
    iVar3 = 0;
  }
  else {
    if (*piVar6 != 1) goto LAB_0017316c;
    iVar3 = piVar6[1];
    bVar1 = false;
  }
  piVar6 = (int *)param_2[1];
  if (piVar6 != (int *)0x0) {
    iVar9 = *piVar6;
    bVar2 = true;
    if (iVar9 == 0) goto LAB_001730ce;
    if (iVar9 == 1) {
      iVar9 = piVar6[1];
      bVar2 = false;
      goto LAB_001730ce;
    }
  }
  bVar2 = false;
  iVar9 = 0;
LAB_001730ce:
  iVar7 = 0;
  for (iVar8 = 0; iVar4 = OPENSSL_sk_num(param_1), iVar8 < iVar4; iVar8 = iVar8 + 1) {
    iVar7 = OPENSSL_sk_value(param_1,iVar8);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(int *)(iVar7 + 0xac) == 0) {
      if (iVar9 != 0 || iVar3 != 0) {
        return 0;
      }
      iVar9 = 0;
      iVar3 = iVar9;
    }
    else {
      iVar4 = X509v3_asid_is_canonical();
      if (iVar4 == 0) {
        return 0;
      }
      puVar5 = *(undefined4 **)(iVar7 + 0xac);
      piVar6 = (int *)*puVar5;
      if (piVar6 == (int *)0x0) {
        if (iVar3 != 0) {
          return 0;
        }
      }
      else if (*piVar6 == 1) {
        if (!bVar1) {
          iVar3 = asid_contains(piVar6[1],iVar3);
          if (iVar3 == 0) {
            return 0;
          }
          puVar5 = *(undefined4 **)(iVar7 + 0xac);
          piVar6 = (int *)*puVar5;
        }
        iVar3 = piVar6[1];
        bVar1 = false;
      }
      piVar6 = (int *)puVar5[1];
      if (piVar6 == (int *)0x0) {
        if (iVar9 != 0) {
          return 0;
        }
      }
      else if (*piVar6 == 1) {
        if (!bVar2) {
          iVar9 = asid_contains(piVar6[1],iVar9);
          if (iVar9 == 0) {
            return 0;
          }
          piVar6 = *(int **)(*(int *)(iVar7 + 0xac) + 4);
        }
        iVar9 = piVar6[1];
        bVar2 = false;
      }
    }
  }
  if (iVar7 != 0) {
    piVar6 = *(int **)(iVar7 + 0xac);
    if (piVar6 != (int *)0x0) {
      if (((int *)*piVar6 != (int *)0x0) && (*(int *)*piVar6 == 0)) {
        return 0;
      }
      if ((int *)piVar6[1] != (int *)0x0) {
        iVar3 = *(int *)piVar6[1];
        if (iVar3 != 0) {
          iVar3 = 1;
        }
        return iVar3;
      }
    }
    return 1;
  }
  return 0;
}

