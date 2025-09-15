
undefined4 get_next_test_voltage_and_freq(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_24;
  undefined4 local_20;
  FILE *local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_24 = 0;
  if (param_2 != '\0') {
    test_level_7573 = 0;
  }
  iVar2 = test_level_7573;
  if (*(char *)((int)&DAT_000585d8 + param_1) == '\0') {
    test_level_7573 = test_level_7573 + 1;
    local_14 = getBoardTestVoltageAndFreq(iVar2,&local_20,&local_24);
  }
  else {
    test_level_7573 = test_level_7573 + 1;
    local_14 = getBoardTestVoltageAndFreqForS11LowPowerMode(iVar2,&local_20,&local_24);
  }
  push_info_when_new_voltage(param_1,g_freq_info_all_vol_level,local_20,param_2);
  if (local_14 == -1) {
    uVar3 = 0;
  }
  else {
    if (3 < log_level) {
      local_1c = fopen(log_file,"a+");
      uVar3 = local_20;
      if (local_1c != (FILE *)0x0) {
        iVar2 = atoi(*(char **)(freq_pll_1385 + local_24 * 0x10));
        fprintf(local_1c,"%s:%d: next test vol level %d freq level %d\n","board_frq_tuning.c",0x459,
                uVar3,iVar2);
      }
      fclose(local_1c);
    }
    for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
      iVar2 = is_S9_Hydro();
      if (iVar2 == 0) {
        if (*(int *)(cgpu + (local_18 + 0x9c638) * 4) != 0) {
          cVar1 = *(char *)(local_18 + param_1 + 0x58588);
          goto joined_r0x000156d6;
        }
      }
      else if (*(int *)(cgpu + (local_18 + 0x9c638) * 4) != 0) {
        iVar2 = get_board_index_S9_Hydro(local_18,0);
        cVar1 = *(char *)(param_1 + iVar2 + 0x58588);
joined_r0x000156d6:
        if (cVar1 == '\0') {
          *(undefined4 *)(param_1 + (local_18 + 0x15002) * 4) = local_20;
          *(int *)(param_1 + (local_18 + 0x15012) * 4) = local_24;
        }
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

