
/* WARNING: Unknown calling convention */

int32_t detect_scan_code_gun(void)

{
  bitmain_sys_capability_t sysinfo;
  uint32_t chain_index;
  uint32_t board_index;
  
  memset(&sysinfo,0,0x124);
  get_system_capability(&sysinfo);
  board_index = 0;
  do {
    if (sysinfo.board_num <= board_index) {
      return -1;
    }
    for (chain_index = 0; chain_index < sysinfo.board[board_index].chain_num;
        chain_index = chain_index + 1) {
      if (sysinfo.board[board_index].chain[chain_index].chain_id == 3) {
        return 0;
      }
    }
    board_index = board_index + 1;
  } while( true );
}

