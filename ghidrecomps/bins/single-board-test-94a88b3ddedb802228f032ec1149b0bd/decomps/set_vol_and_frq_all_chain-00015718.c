
void set_vol_and_frq_all_chain(int *param_1)

{
  char cVar1;
  FILE *__stream;
  int iVar2;
  undefined4 uVar3;
  uint local_18;
  uint local_14;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set_vol_and_frq_all_chain enter\n","board_frq_tuning.c",0x471);
    }
    fclose(__stream);
  }
  local_14 = 0;
  do {
    if (0xf < (int)local_14) {
      return;
    }
    iVar2 = is_S9_Hydro();
    if (iVar2 == 0) {
      if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)((int)param_1 + local_14 + 0x58588);
        goto joined_r0x000157e2;
      }
    }
    else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      iVar2 = get_board_index_S9_Hydro(local_14,0);
      cVar1 = *(char *)((int)param_1 + iVar2 + 0x58588);
joined_r0x000157e2:
      if (cVar1 == '\0') {
        iVar2 = is_S9_Hydro();
        if (iVar2 == 0) {
          uVar3 = getPICvoltageFromValue(param_1[local_14 + 0x15002]);
          set_pic_voltage(local_14 & 0xff,uVar3);
          for (local_18 = 0; (int)local_18 < *param_1; local_18 = local_18 + 1) {
            set_frequency_with_addr_plldatai
                      (param_1[local_14 + 0x15012],0,(local_18 & 0x7f) << 1,local_14 & 0xff);
          }
        }
        else {
          for (local_18 = 0; (int)local_18 < 0x54; local_18 = local_18 + 1) {
            set_frequency_with_addr_plldatai
                      (param_1[local_14 + 0x15012],0,(local_18 & 0x7f) << 1,local_14 & 0xff);
          }
        }
      }
    }
    local_14 = local_14 + 1;
  } while( true );
}

