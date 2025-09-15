
void set_vol_and_frq(uint param_1,undefined4 param_2,int param_3)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_14;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set_vol_and_frq enter\n","board_frq_tuning.c",0xb6);
    }
    fclose(pFVar1);
  }
  *(int *)(Fmax + param_1 * 4) = param_3;
  *(undefined4 *)(chain_vol_value + param_1 * 4) = param_2;
  *(undefined4 *)(chain_vol_added + param_1 * 4) = 0;
  iVar2 = is_S9_plus();
  if (iVar2 == 0) {
    uVar3 = getPICvoltageFromValue(param_2);
    set_pic_voltage(param_1 & 0xff,uVar3);
  }
  else {
    quickly_set_to_working_voltage();
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set freq=%s voltage=%d on chain[%d]\n","board_frq_tuning.c",0xc5,
              *(undefined4 *)(freq_pll_1385 + param_3 * 0x10),param_2,param_1);
    }
    fclose(pFVar1);
  }
  for (local_14 = 0; (int)local_14 < 0x54; local_14 = local_14 + 1) {
    *(int *)(last_freq + (local_14 + param_1 * 0x100) * 4) = param_3;
    set_frequency_with_addr_plldatai(param_3,0,(local_14 & 0x7f) << 1,param_1 & 0xff);
  }
  return;
}

