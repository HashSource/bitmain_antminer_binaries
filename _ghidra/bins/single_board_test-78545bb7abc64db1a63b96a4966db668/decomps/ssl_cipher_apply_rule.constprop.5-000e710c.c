
void ssl_cipher_apply_rule_constprop_5
               (uint param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6,
               int param_7,int *param_8,int *param_9)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  
  if (param_6 == 6 || param_6 == 3) {
    piVar7 = (int *)*param_8;
    piVar5 = (int *)*param_9;
    piVar9 = piVar7;
    piVar10 = piVar5;
  }
  else {
    piVar5 = (int *)*param_8;
    piVar7 = (int *)*param_9;
    piVar9 = piVar5;
    piVar10 = piVar7;
  }
  piVar3 = (int *)0x0;
LAB_000e7150:
  do {
    piVar6 = piVar5;
    if (piVar6 == (int *)0x0 || piVar3 == piVar7) {
      *param_8 = (int)piVar9;
      *param_9 = (int)piVar10;
      return;
    }
    piVar2 = (int *)piVar6[3];
    piVar4 = (int *)piVar6[4];
    iVar8 = *piVar6;
    piVar5 = piVar2;
    if (param_6 == 6 || param_6 == 3) {
      piVar5 = piVar4;
    }
    piVar3 = piVar6;
    if (-1 < param_7) goto LAB_000e7146;
  } while ((((((param_1 != 0) && ((param_1 & *(uint *)(iVar8 + 0x10)) == 0)) ||
             ((param_2 != 0 && ((param_2 & *(uint *)(iVar8 + 0x14)) == 0)))) ||
            ((param_3 != 0 && ((param_3 & *(uint *)(iVar8 + 0x18)) == 0)))) ||
           ((param_4 != 0 && ((param_4 & *(uint *)(iVar8 + 0x1c)) == 0)))) ||
          ((param_5 != 0 && (param_5 != *(int *)(iVar8 + 0x20)))));
  goto LAB_000e71aa;
LAB_000e7146:
  if (param_7 == *(int *)(iVar8 + 0x38)) {
LAB_000e71aa:
    if (param_6 == 1) {
      if (piVar6[1] == 0) {
        if (piVar6 != piVar10) {
          if (piVar6 == piVar9) {
            piVar9 = piVar2;
          }
          if (piVar4 != (int *)0x0) {
            piVar4[3] = (int)piVar2;
            piVar2 = (int *)piVar6[3];
          }
          if (piVar2 != (int *)0x0) {
            piVar2[4] = (int)piVar4;
          }
          piVar10[3] = (int)piVar6;
          piVar6[4] = (int)piVar10;
          piVar6[3] = 0;
          piVar10 = piVar6;
        }
        piVar6[1] = 1;
      }
    }
    else if (param_6 == 4) {
      if (piVar6 != piVar10 && piVar6[1] != 0) {
        if (piVar6 == piVar9) {
          piVar9 = piVar2;
        }
        if (piVar4 != (int *)0x0) {
          piVar4[3] = (int)piVar2;
          piVar2 = (int *)piVar6[3];
        }
        if (piVar2 != (int *)0x0) {
          piVar2[4] = (int)piVar4;
        }
        piVar10[3] = (int)piVar6;
        piVar6[4] = (int)piVar10;
        piVar6[3] = 0;
        piVar10 = piVar6;
      }
    }
    else if (param_6 == 3) {
      if (piVar6[1] != 0) {
        if (piVar6 != piVar9) {
          if (piVar6 == piVar10) {
            piVar10 = piVar4;
          }
          if (piVar2 != (int *)0x0) {
            piVar2[4] = (int)piVar4;
            piVar4 = (int *)piVar6[4];
          }
          if (piVar4 != (int *)0x0) {
            piVar4[3] = (int)piVar2;
          }
          piVar9[4] = (int)piVar6;
          piVar6[3] = (int)piVar9;
          piVar6[4] = 0;
          piVar9 = piVar6;
        }
        piVar6[1] = 0;
      }
    }
    else if (param_6 == 6) {
      if (piVar6 != piVar9 && piVar6[1] != 0) {
        if (piVar6 == piVar10) {
          piVar10 = piVar4;
        }
        if (piVar2 != (int *)0x0) {
          piVar2[4] = (int)piVar4;
          piVar4 = (int *)piVar6[4];
        }
        if (piVar4 != (int *)0x0) {
          piVar4[3] = (int)piVar2;
        }
        piVar9[4] = (int)piVar6;
        piVar6[3] = (int)piVar9;
        piVar6[4] = 0;
        piVar9 = piVar6;
      }
    }
    else if (param_6 == 2) {
      piVar1 = piVar2;
      if (piVar6 != piVar9) {
        piVar4[3] = (int)piVar2;
        piVar2 = (int *)piVar6[3];
        piVar1 = piVar9;
      }
      piVar6[1] = 0;
      if (piVar6 == piVar10) {
        piVar10 = piVar4;
      }
      if (piVar2 != (int *)0x0) {
        piVar2[4] = (int)piVar4;
        piVar4 = (int *)piVar6[4];
      }
      if (piVar4 != (int *)0x0) {
        piVar4[3] = (int)piVar2;
      }
      piVar6[3] = 0;
      piVar6[4] = 0;
      piVar9 = piVar1;
    }
  }
  goto LAB_000e7150;
}

