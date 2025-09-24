
_Bool pf_check_specific_chain(int chain)

{
  int iVar1;
  int chain_local;
  char time_stamp [48];
  char tmp1 [256];
  bitmain_sys_capability_t info;
  int i;
  
  get_system_capability(&info);
  do {
    i = info.board_num - 1;
    if (i < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : user input chain ID %d not connected\n","pf_check_specific_chain",chain);
      snprintf(tmp1,0x100,"user input chain ID %d not connected",chain);
      log_to_file(tmp1,time_stamp);
      return false;
    }
    iVar1 = info.board_num - 1;
    info.board_num = i;
  } while (info.board[iVar1].board_id != chain);
  return true;
}

