
void saving_voltage(int *param_1)

{
  int iVar1;
  undefined auStack_20 [4];
  int local_1c;
  FILE *local_18;
  int local_14;
  
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) &&
       ((iVar1 = is_S9_Hydro(), iVar1 == 0 ||
        (iVar1 = get_board_index_S9_Hydro(local_14,0), iVar1 == local_14)))) {
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        iVar1 = is_S9i();
        if (iVar1 == 0) {
          if (*(char *)(param_1 + 0x16176) == '\0') {
            chain_pic_buf[local_14 * 0x80 + 1] = (char)(param_1[local_14 + 0x15002] / 5);
          }
          else {
            *(char *)(local_14 * 0x80 + *param_1 + 0x1a3fbc2) =
                 (char)(param_1[local_14 + 0x15002] / 5);
          }
        }
        else {
          *(int *)(chain_vol_value + local_14 * 4) = param_1[local_14 + 0x15002];
        }
      }
      else {
        getPICChainIndexOffset(local_14,&local_1c,auStack_20);
        chain_pic_buf[local_1c * 0x80 + 1] = (char)(param_1[local_14 + 0x15002] / 5);
        if (3 < log_level) {
          local_18 = fopen(log_file,"a+");
          if (local_18 != (FILE *)0x0) {
            fprintf(local_18,"%s:%d: chain index: %d, chain_pic_buf[board_index][1]: %x\n",
                    "board_frq_tuning.c",0x60a,local_1c,
                    (uint)(byte)chain_pic_buf[local_1c * 0x80 + 1]);
          }
          fclose(local_18);
        }
      }
    }
  }
  return;
}

