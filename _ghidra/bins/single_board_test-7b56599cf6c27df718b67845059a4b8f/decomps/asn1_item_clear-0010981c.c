
void asn1_item_clear(undefined4 *param_1,undefined1 *param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
LAB_00109822:
  switch(*param_2) {
  case 0:
    puVar1 = *(uint **)(param_2 + 8);
    if (puVar1 == (uint *)0x0) {
      iVar2 = *(int *)(param_2 + 0x10);
      if (iVar2 != 0) goto LAB_00109858;
      if (*(int *)(param_2 + 4) == 1) {
        *param_1 = *(undefined4 *)(param_2 + 0x14);
        return;
      }
    }
    else if ((*puVar1 & 0x306) == 0) goto code_r0x0010984e;
  case 1:
  case 2:
  case 6:
switchD_00109828_caseD_1:
    *param_1 = 0;
switchD_00109828_caseD_3:
    return;
  default:
    goto switchD_00109828_caseD_3;
  case 4:
    if (*(int *)(param_2 + 0x10) == 0) goto switchD_00109828_caseD_1;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc);
    break;
  case 5:
    iVar2 = *(int *)(param_2 + 0x10);
    if (iVar2 == 0) goto switchD_00109828_caseD_1;
LAB_00109858:
    UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x10);
  }
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00109862. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  goto switchD_00109828_caseD_1;
code_r0x0010984e:
  param_2 = (undefined1 *)puVar1[4];
  goto LAB_00109822;
}

