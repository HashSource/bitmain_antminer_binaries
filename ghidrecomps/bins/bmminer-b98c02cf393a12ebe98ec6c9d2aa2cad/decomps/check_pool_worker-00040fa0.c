
undefined4 check_pool_worker(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < total_pools) {
    iVar4 = 0;
    iVar3 = 0;
    do {
      while (iVar2 = *(int *)(pools + iVar3 * 4), **(char **)(iVar2 + 0xa4) == '\0') {
LAB_00040fdc:
        iVar3 = iVar3 + 1;
        if (total_pools <= iVar3) goto LAB_00041042;
      }
      if (**(char **)(iVar2 + 0xac) != '\0') {
        iVar4 = iVar4 + 1;
        goto LAB_00040fdc;
      }
      if (log_level < 4) goto LAB_00040fdc;
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Blank worker exists.\n","mp_test_fw.c",0x39,"check_pool_worker");
      }
      iVar3 = iVar3 + 1;
      fclose(pFVar1);
    } while (iVar3 < total_pools);
LAB_00041042:
    if (iVar4 != 0) {
      return 0;
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: No valid pools, please configure them first!\n","mp_test_fw.c",0x40,
              "check_pool_worker");
    }
    fclose(pFVar1);
  }
  return 0xff;
}

