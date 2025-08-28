
undefined4 get_runtime_hash_rate(void)

{
  uint *puVar1;
  FILE *__stream;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  undefined4 extraout_s1;
  UDItype UVar9;
  
  puVar3 = rate;
  uVar5 = 0;
  iVar6 = 0;
  piVar2 = (int *)(dev + 4);
  do {
    while (piVar2 = piVar2 + 1, *piVar2 == 1) {
      uVar4 = *(uint *)puVar3;
      puVar1 = (uint *)((int)puVar3 + 4);
      puVar3 = (undefined1 *)((int)puVar3 + 8);
      bVar7 = CARRY4(uVar5,uVar4);
      uVar5 = uVar5 + uVar4;
      iVar6 = iVar6 + *puVar1 + (uint)bVar7;
      if (puVar3 == rate_error) goto LAB_000350d4;
    }
    puVar3 = (undefined1 *)((int)puVar3 + 8);
  } while (puVar3 != rate_error);
LAB_000350d4:
  __aeabi_uldivmod(uVar5,iVar6,&DAT_000f4240,0);
  uVar8 = __floatundidf();
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar8));
  if (log_level < 5) {
    return (int)UVar9;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: RT hash = %llu\n","driver-btm-c5.c",0x26d0,"get_runtime_hash_rate");
  }
  fclose(__stream);
  return (int)UVar9;
}

