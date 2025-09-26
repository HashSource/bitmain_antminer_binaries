
_Bool check_specific_chain(int chain)

{
  uint32_t uVar1;
  int chain_local;
  bitmain_sys_capability_t info;
  int i;
  
  get_system_capability(&info);
  do {
    uVar1 = info.board_num;
    i = uVar1 - 1;
    if (i < 0) {
      return false;
    }
    info.board_num = i;
  } while ((info.board[uVar1 - 1].board_id == 3) ||
          (info.board_num = i, info.board[uVar1 - 1].board_id != chain));
  gHashBoard_plug_in = true;
  gChain = chain;
  return true;
}

