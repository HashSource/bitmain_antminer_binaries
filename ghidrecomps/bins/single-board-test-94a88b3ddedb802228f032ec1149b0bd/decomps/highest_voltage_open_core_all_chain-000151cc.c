
void highest_voltage_open_core_all_chain(int param_1)

{
  char cVar1;
  int iVar2;
  int local_c;
  
  local_c = 0;
  do {
    if (0xf < local_c) {
      return;
    }
    iVar2 = is_S9_Hydro();
    if (iVar2 == 0) {
      if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)(local_c + param_1 + 0x58588);
        goto joined_r0x00015248;
      }
    }
    else if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      iVar2 = get_board_index_S9_Hydro(local_c,0);
      cVar1 = *(char *)(param_1 + iVar2 + 0x58588);
joined_r0x00015248:
      if (cVar1 == '\0') {
        highest_voltage_open_core_on_chain
                  (local_c,*(undefined4 *)(param_1 + (local_c + 0x15002) * 4));
      }
    }
    local_c = local_c + 1;
  } while( true );
}

