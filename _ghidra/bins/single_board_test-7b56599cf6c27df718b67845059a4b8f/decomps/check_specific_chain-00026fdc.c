
_Bool check_specific_chain(int chain)

{
  int iVar1;
  int chain_local;
  bitmain_sys_capability_t info;
  int i;
  
  get_system_capability(&info);
  do {
    i = info.board_num - 1;
    if (i < 0) {
      return false;
    }
    iVar1 = info.board_num - 1;
    info.board_num = i;
  } while (info.board[iVar1].board_id != chain);
  gHashBoard_plug_in = true;
  gChain = chain;
  return true;
}

