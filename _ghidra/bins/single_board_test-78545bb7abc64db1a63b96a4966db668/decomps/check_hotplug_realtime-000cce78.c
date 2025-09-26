
void check_hotplug_realtime(bitmain_sys_capability_t *capa)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t local_82c;
  char tmp42 [2048];
  
  local_82c = 0;
  memset(&capability,0,0x124);
  fpga_read(2,&local_82c);
  if (local_82c != 0) {
    if ((int)local_82c < 0) {
      local_82c = local_82c >> 0x18;
      platform_is_t9 = 1;
      snprintf(tmp42,0x800,"HASH_ON_PLUG T9 = 0x%x\n",local_82c);
      _applog(2,tmp42,false);
      if (local_82c != 0) {
        uVar2 = 0;
        do {
          if ((local_82c & 1) != 0) {
            capability.board[capability.board_num].board_id = uVar2;
            if (uVar2 == 1) {
              capability.board[capability.board_num].chain[0].chain_id = 2;
              capability.board[capability.board_num].chain[1].chain_id = 10;
              capability.board[capability.board_num].chain[2].chain_id = 0xb;
              capability.board[capability.board_num].chain_num = 3;
            }
            else if (uVar2 == 0) {
              capability.board[capability.board_num].chain[0].chain_id = 1;
              capability.board[capability.board_num].chain[1].chain_id = 8;
              capability.board[capability.board_num].chain[2].chain_id = 9;
              capability.board[capability.board_num].chain_num = 3;
            }
            else if (uVar2 == 2) {
              capability.board[capability.board_num].chain[0].chain_id = 3;
              capability.board[capability.board_num].chain[1].chain_id = 0xc;
              capability.board[capability.board_num].chain[2].chain_id = 0xd;
              capability.board[capability.board_num].chain_num = 3;
            }
            capability.board_num = capability.board_num + 1;
          }
          local_82c = local_82c >> 1;
          uVar2 = uVar2 + 1;
        } while (local_82c != 0);
      }
    }
    else {
      local_82c = local_82c & 0xffff;
      platform_is_t9 = 0;
      if (local_82c != 0) {
        uVar1 = 0;
        uVar2 = capability.board_num;
        do {
          capability.board_num = uVar2;
          if ((int)(local_82c << 0x1f) < 0) {
            uVar3 = capability.board[uVar2].chain_num;
            capability.board_num = uVar2 + 1;
            capability.board[uVar2].board_id = uVar1;
            capability.board[uVar2].chain_num = uVar3 + 1;
            capability.board[uVar2].chain[uVar3].chain_id = uVar1;
          }
          local_82c = local_82c >> 1;
          uVar1 = uVar1 + 1;
          uVar2 = capability.board_num;
        } while (local_82c != 0);
      }
    }
    return;
  }
  builtin_strncpy(tmp42,"Cannot Find Any Plug In!",0x18);
  tmp42[0x18] = '\r';
  tmp42[0x19] = '\n';
  tmp42[0x1a] = '\0';
  _applog(0,tmp42,false);
  return;
}

