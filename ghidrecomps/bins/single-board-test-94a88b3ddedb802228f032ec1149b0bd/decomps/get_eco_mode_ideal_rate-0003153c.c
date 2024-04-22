
int get_eco_mode_ideal_rate(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_1c;
  uint local_18;
  int local_14;
  
  local_1c = 0;
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) == 1) {
      for (local_18 = 0; (int)local_18 < 0x54; local_18 = local_18 + 1) {
        if (*(int *)(chain_badcore_num + (local_18 + local_14 * 0x100) * 4) < 0xf) {
          uVar2 = local_18 + 3;
          if (-1 < (int)local_18) {
            uVar2 = local_18;
          }
          uVar3 = local_18 & 3;
          if ((int)local_18 < 1) {
            uVar3 = -(-local_18 & 3);
          }
          iVar1 = get_pll_index_for_lowpower_mode
                            ((int)(uint)*(byte *)(local_14 * 0x80 + ((int)uVar2 >> 2) + 0x1a3fc17)
                             >> ((uVar3 & 0x7f) << 1) & 3);
          iVar1 = atoi(*(char **)(freq_pll_1385 + iVar1 * 0x10));
          local_1c = (0x72 - *(int *)(chain_badcore_num + (local_18 + local_14 * 0x100) * 4)) *
                     iVar1 + local_1c;
        }
      }
    }
  }
  return local_1c / 1000;
}

