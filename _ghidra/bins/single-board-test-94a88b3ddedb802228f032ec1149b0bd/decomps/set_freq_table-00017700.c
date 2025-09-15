
void set_freq_table(int *param_1,int param_2)

{
  int iVar1;
  int aiStack_78 [20];
  int local_28;
  FILE *local_24;
  void *local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  memset(aiStack_78,0,0x50);
  local_20 = malloc(param_1[1] << 2);
  if (local_20 == (void *)0x0) {
    local_24 = fopen(log_file,"a+");
    if (local_24 != (FILE *)0x0) {
      fprintf(local_24,"Assert fail!! %s:%d: malloc fail.","board_frq_tuning.c",0x6b8);
    }
    fclose(local_24);
    if (local_20 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("best_freq_of_asic_quality != ((void *)0)","board_frq_tuning.c",0x6b8,
                    "set_freq_table");
    }
  }
  local_28 = 0;
  for (local_14 = 0; local_14 < param_1[1]; local_14 = local_14 + 1) {
    memset(aiStack_78,0,0x50);
    for (local_18 = 0; local_18 < 0x14; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
        if (param_1[local_1c + param_2 * 0x100 + 0x15162] == local_14 + 1) {
          aiStack_78[local_18] =
               aiStack_78[local_18] +
               param_1[local_1c + (param_2 * 0x14 + local_18) * 0x100 + 0x1002];
        }
      }
    }
    local_28 = get_max_index(aiStack_78,0x14);
    *(int *)((int)local_20 + local_14 * 4) = param_1[param_2 * 0x14 + local_28 + 0x15022];
  }
  local_14 = 0;
  while( true ) {
    if (*param_1 <= local_14) break;
    iVar1 = is_S9_Hydro();
    if (iVar1 == 0) {
      local_18 = local_14;
    }
    else if (local_14 % 3 == 0) {
      local_18 = local_14 / 3;
    }
    else if (local_14 % 3 == 1) {
      local_18 = (local_14 + -1) / 3 + 0x54;
    }
    else if (local_14 % 3 == 2) {
      local_18 = (local_14 + -2) / 3 + 0xa8;
    }
    param_1[local_18 + param_2 * 0x100 + 2] =
         *(int *)((param_1[local_14 + param_2 * 0x100 + 0x15162] + 0x3fffffff) * 4 + (int)local_20);
    local_14 = local_14 + 1;
  }
  free(local_20);
  return;
}

