
void asn1_item_clear(undefined4 *param_1,undefined1 *param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
LAB_001133fa:
  switch(*param_2) {
  case 0:
    puVar1 = *(uint **)(param_2 + 8);
    if (puVar1 == (uint *)0x0) {
      iVar2 = *(int *)(param_2 + 0x10);
      if (iVar2 != 0) goto LAB_00113430;
      if (*(int *)(param_2 + 4) == 1) {
        *param_1 = *(undefined4 *)(param_2 + 0x14);
        return;
      }
    }
    else if ((*puVar1 & 0x306) == 0) goto code_r0x00113426;
  case 1:
  case 2:
  case 6:
switchD_00113400_caseD_1:
    *param_1 = 0;
switchD_00113400_caseD_3:
    return;
  default:
    goto switchD_00113400_caseD_3;
  case 4:
    if (*(int *)(param_2 + 0x10) == 0) goto switchD_00113400_caseD_1;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc);
    break;
  case 5:
    iVar2 = *(int *)(param_2 + 0x10);
    if (iVar2 == 0) goto switchD_00113400_caseD_1;
LAB_00113430:
    UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x10);
  }
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011343a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  goto switchD_00113400_caseD_1;
code_r0x00113426:
  param_2 = (undefined1 *)puVar1[4];
  goto LAB_001133fa;
}

