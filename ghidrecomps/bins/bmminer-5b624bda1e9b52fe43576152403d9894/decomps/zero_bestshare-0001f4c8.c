
/* WARNING: Unknown calling convention */

void zero_bestshare(void)

{
  undefined4 *puVar1;
  int iVar2;
  pool *pool;
  int *piVar3;
  int *piVar4;
  int iVar6;
  uint in_stack_ffffffe4;
  int *piVar5;
  
  puVar1 = DAT_0001f52c;
  iVar2 = DAT_0001f528;
  iVar6 = DAT_0001f528 + 0x7f0;
  *(undefined4 *)(DAT_0001f528 + 0x7f0) = 0;
  *(undefined4 *)(iVar2 + 0x7f4) = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  suffix_string((ulonglong)in_stack_ffffffe4 << 0x20,(char *)0x0,0,iVar6);
  iVar2 = *DAT_0001f520;
  if (0 < iVar2) {
    piVar3 = *DAT_0001f524;
    piVar4 = piVar3;
    do {
      piVar5 = piVar4 + 1;
      iVar6 = *piVar4;
      *(undefined4 *)(iVar6 + 0x170) = 0;
      *(undefined4 *)(iVar6 + 0x174) = 0;
      piVar4 = piVar5;
    } while (piVar5 != piVar3 + iVar2);
  }
  return;
}

