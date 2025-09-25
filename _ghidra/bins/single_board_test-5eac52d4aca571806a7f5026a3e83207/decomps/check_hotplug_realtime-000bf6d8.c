
void check_hotplug_realtime(bitmain_sys_capability_t *capa)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t local_82c;
  char tmp42 [2048];
  
  uVar5 = 0;
  local_82c = 0;
  memset(&capability,0,0x124);
  fpga_read(2,&local_82c);
  if (local_82c == 0) {
    builtin_strncpy(tmp42,"Cannot Find Any Plug In!",0x18);
    tmp42[0x18] = '\r';
    tmp42[0x19] = '\n';
    tmp42[0x1a] = '\0';
    _applog(0,tmp42,false);
    return;
  }
  if ((int)local_82c < 0) {
    local_82c = local_82c >> 0x18;
    platform_is_t9 = 1;
    snprintf(tmp42,0x800,"HASH_ON_PLUG T9 = 0x%x\n",local_82c);
    _applog(2,tmp42,false);
    if (local_82c == 0) {
      return;
    }
    bVar1 = false;
    uVar5 = 0;
    uVar4 = capability.board_num;
    do {
      if ((local_82c & 1) != 0) {
        capability.board[uVar4].board_id = uVar5;
        if (uVar5 == 1) {
          capability.board[uVar4].chain[0].chain_id = 2;
          capability.board[uVar4].chain[1].chain_id = 10;
          capability.board[uVar4].chain[2].chain_id = 0xb;
          capability.board[uVar4].chain_num = 3;
        }
        else if (uVar5 == 0) {
          capability.board[uVar4].chain[0].chain_id = 1;
          capability.board[uVar4].chain[1].chain_id = 8;
          capability.board[uVar4].chain[2].chain_id = 9;
          capability.board[uVar4].chain_num = 3;
        }
        else if (uVar5 == 2) {
          capability.board[uVar4].chain[0].chain_id = 3;
          capability.board[uVar4].chain[1].chain_id = 0xc;
          capability.board[uVar4].chain[2].chain_id = 0xd;
          capability.board[uVar4].chain_num = 3;
        }
        uVar4 = uVar4 + 1;
        bVar1 = true;
      }
      local_82c = local_82c >> 1;
      uVar5 = uVar5 + 1;
    } while (local_82c != 0);
  }
  else {
    local_82c = local_82c & 0xffff;
    platform_is_t9 = 0;
    if (local_82c == 0) {
      platform_is_t9 = 0;
      return;
    }
    bVar1 = false;
    uVar3 = capability.board_num;
    do {
      uVar4 = uVar3;
      if ((local_82c & 1) != 0) {
        uVar2 = capability.board[uVar3].chain_num;
        bVar1 = true;
        uVar4 = uVar3 + 1;
        capability.board[uVar3].board_id = uVar5;
        capability.board[uVar3].chain_num = uVar2 + 1;
        capability.board[uVar3].chain[uVar2].chain_id = uVar5;
      }
      local_82c = local_82c >> 1;
      uVar5 = uVar5 + 1;
      uVar3 = uVar4;
    } while (local_82c != 0);
  }
  if (bVar1) {
    capability.board_num = uVar4;
  }
  return;
}

