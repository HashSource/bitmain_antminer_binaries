
void adjust_freq_table_with_flag_table(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  void *__s;
  FILE *__stream;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = __aeabi_idiv(param_3,param_4);
  __s = malloc(iVar1 << 2);
  if (__s != (void *)0x0) {
    memset(__s,0,iVar1 << 2);
    local_18 = 0;
    for (local_c = 0; local_c < iVar1; local_c = local_c + 1) {
      local_14 = 9999;
      for (local_10 = 0; local_10 < param_4; local_10 = local_10 + 1) {
        iVar3 = local_10 + param_4 * local_c;
        if ((*(char *)(iVar3 + param_2) == '\0') && (*(int *)(iVar3 * 4 + param_1) < local_14)) {
          local_14 = *(int *)(iVar3 * 4 + param_1);
          local_18 = iVar3;
        }
      }
      *(undefined *)(local_18 + param_2) = 2;
      *(int *)(local_c * 4 + (int)__s) = local_14;
    }
    uVar2 = get_min(__s,iVar1);
    for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
      if (*(char *)(local_c + param_2) == '\x02') {
        *(undefined4 *)(local_c * 4 + param_1) = uVar2;
        *(undefined *)(local_c + param_2) = 1;
      }
    }
    free(__s);
    return;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"Assert fail!! %s:%d: malloc fail!\n","board_frq_tuning.c",0x31a);
  }
  fclose(__stream);
                    /* WARNING: Subroutine does not return */
  __assert_fail("min_freq_of_chain != ((void *)0)","board_frq_tuning.c",0x31a,
                "adjust_freq_table_with_flag_table");
}

