
void init_chip_rate_table(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_44;
  FILE *local_40;
  FILE *local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  int local_2c;
  FILE *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_24 = 0;
  local_24 = atoi(*(char **)(freq_pll_1385 + param_1[param_3 + 0x15012] * 0x10));
  local_20 = get_scan_level_index_from_freq(param_1,param_1[param_3 + 0x15012],param_3);
  if (5 < log_level) {
    local_28 = fopen(log_file,"a+");
    if (local_28 != (FILE *)0x0) {
      uVar1 = get_board_index_S9_Hydro(param_3,0);
      fprintf(local_28,"%s:%d: chip rate table of chain[%d], scan_freq[%dMhz]:\n",
              "board_frq_tuning.c",0x503,uVar1,local_24);
    }
    fclose(local_28);
  }
  iVar2 = is_S9_Hydro();
  if (iVar2 == 0) {
    for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
      param_1[local_1c + (param_3 * 0x14 + local_20) * 0x100 + 0x1002] =
           local_24 * *(int *)(local_1c * 4 + param_2);
      if (5 < log_level) {
        local_38 = fopen(log_file,"a+");
        if (local_38 != (FILE *)0x0) {
          fprintf(local_38,"%7d ",param_1[local_1c + (param_3 * 0x14 + local_20) * 0x100 + 0x1002]);
        }
        fclose(local_38);
      }
      if (((local_1c + 1) % 0xc == 0) && (5 < log_level)) {
        local_3c = fopen(log_file,"a+");
        if (local_3c != (FILE *)0x0) {
          fputc(10,local_3c);
        }
        fclose(local_3c);
      }
    }
    if (5 < log_level) {
      local_40 = fopen(log_file,"a+");
      if (local_40 != (FILE *)0x0) {
        fputc(10,local_40);
      }
      fclose(local_40);
    }
  }
  else {
    local_14 = 0;
    local_18 = 0;
    local_2c = get_board_index_S9_Hydro(param_3,&local_44);
    for (local_14 = local_44 * 0x54; iVar2 = (local_44 + 1) * 0x54,
        iVar2 - local_14 != 0 && local_14 <= iVar2; local_14 = local_14 + 1) {
      if ((local_14 < 0) || (0x53 < local_14)) {
        if ((local_14 < 0x54) || (0xa7 < local_14)) {
          if ((0xa7 < local_14) && (local_14 < 0xfc)) {
            local_18 = (local_14 + -0xa8) * 3 + 2;
          }
        }
        else {
          local_18 = (local_14 + -0x54) * 3 + 1;
        }
      }
      else {
        local_18 = local_14 * 3;
      }
      param_1[local_18 + (local_2c * 0x14 + local_20) * 0x100 + 0x1002] =
           local_24 * *(int *)((local_14 + local_44 * -0x54) * 4 + param_2);
      if (5 < log_level) {
        local_30 = fopen(log_file,"a+");
        if (local_30 != (FILE *)0x0) {
          fprintf(local_30,"%7d ",param_1[local_18 + (param_3 * 0x14 + local_20) * 0x100 + 0x1002]);
        }
        fclose(local_30);
      }
    }
    if (5 < log_level) {
      local_34 = fopen(log_file,"a+");
      if (local_34 != (FILE *)0x0) {
        fputc(10,local_34);
      }
      fclose(local_34);
    }
  }
  return;
}

