
/* WARNING: Unknown calling convention */

int check_hashboard_plug_in(void)

{
  uint32_t uVar1;
  char time_stamp [48];
  char tmp1 [256];
  bitmain_sys_capability_t info;
  int i;
  
  get_system_capability(&info);
  gHashBoard_plug_in = false;
  do {
    uVar1 = info.board_num;
    i = uVar1 - 1;
    if (i < 0) {
      return -1;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : boardID %d\n","check_hashboard_plug_in",info.board[uVar1 - 1].board_id);
    snprintf(tmp1,0x100,"boardID %d",info.board[uVar1 - 1].board_id);
    log_to_file(tmp1,time_stamp);
    info.board_num = i;
  } while (info.board[uVar1 - 1].board_id == 3);
  gHashBoard_plug_in = true;
  gChain = info.board[uVar1 - 1].board_id;
  return 0;
}

