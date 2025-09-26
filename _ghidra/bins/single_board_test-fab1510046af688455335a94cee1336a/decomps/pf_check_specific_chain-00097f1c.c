
_Bool pf_check_specific_chain(int chain)

{
  int iVar1;
  int chain_local;
  char tmp42 [256];
  bitmain_sys_capability_t info;
  int i;
  
  get_system_capability(&info);
  do {
    i = info.board_num - 1;
    if (i < 0) {
      snprintf(tmp42,0x100,"user input chain ID %d not connected",chain);
      puts(tmp42);
      return false;
    }
    iVar1 = info.board_num - 1;
    info.board_num = i;
  } while (info.board[iVar1].board_id != chain);
  return true;
}

