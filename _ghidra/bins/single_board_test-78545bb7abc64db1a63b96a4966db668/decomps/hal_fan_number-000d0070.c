
/* WARNING: Unknown calling convention */

int32_t hal_fan_number(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    piVar1 = (int *)((int)&fans[0].fan_id + iVar3);
    iVar3 = iVar3 + 0xc;
    if (*piVar1 != -1) {
      iVar2 = iVar2 + 1;
    }
  } while (iVar3 != 0x48);
  return iVar2;
}

