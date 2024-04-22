
undefined4 get_runtime_hash_rate(void)

{
  uint *puVar1;
  FILE *__stream;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  UDItype UVar8;
  undefined4 in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  
  uVar5 = 0;
  iVar6 = 0;
  piVar2 = (int *)(dev + 4);
  puVar3 = DAT_00035168;
  do {
    while (piVar2 = piVar2 + 1, *piVar2 == 1) {
      uVar4 = *puVar3;
      puVar1 = puVar3 + 1;
      puVar3 = puVar3 + 2;
      bVar7 = CARRY4(uVar5,uVar4);
      uVar5 = uVar5 + uVar4;
      iVar6 = iVar6 + *puVar1 + (uint)bVar7;
      if (puVar3 == DAT_00035168 + 0x20) goto LAB_000350d4;
    }
    puVar3 = puVar3 + 2;
  } while (puVar3 != DAT_00035168 + 0x20);
LAB_000350d4:
  __aeabi_uldivmod(uVar5,iVar6,&DAT_000f4240,0);
  __floatundidf();
  UVar8 = __fixunsdfdi((DFtype)CONCAT44(in_stack_ffffffdc,in_stack_ffffffd8));
  if (log_level < 5) {
    return (int)UVar8;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: RT hash = %llu\n","driver-btm-c5.c",0x26d0,DAT_0003516c);
  }
  fclose(__stream);
  return (int)UVar8;
}

