
void check_hotplug_realtime(bitmain_sys_capability_t *capa)

{
  bitmain_board_t *pbVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t val;
  char tmp42 [2048];
  
  uVar4 = 0;
  val = 0;
  memset(&capability,0,0x124);
  fpga_read(2,&val);
  if (val == 0) {
    builtin_strncpy(tmp42,"Cannot Find Any Plug In!",0x18);
    tmp42[0x18] = '\r';
    tmp42[0x19] = '\n';
    tmp42[0x1a] = '\0';
    _applog(0,tmp42,false);
  }
  else if ((int)val < 0) {
    val = val >> 0x18;
    platform_is_t9 = 1;
    snprintf(tmp42,0x800,"HASH_ON_PLUG T9 = 0x%x\n",val);
    _applog(0,tmp42,false);
    for (; val != 0; val = val >> 1) {
      if ((int)(val << 0x1f) < 0) {
        snprintf(tmp42,0x800,"slot %d pluged\n",uVar4);
        _applog(0,tmp42,false);
        uVar2 = capability.board_num;
        capability.board[capability.board_num].board_id = uVar4;
        if (uVar4 == 1) {
          capability.board[uVar2].chain[0].chain_id = 2;
          capability.board[uVar2].chain[1].chain_id = 10;
          capability.board[uVar2].chain[2].chain_id = 0xb;
          capability.board[uVar2].chain_num = 3;
        }
        else if (uVar4 == 0) {
          capability.board[uVar2].chain[0].chain_id = 1;
          capability.board[uVar2].chain[1].chain_id = 8;
          capability.board[uVar2].chain[2].chain_id = 9;
          capability.board[uVar2].chain_num = 3;
        }
        else if (uVar4 == 2) {
          capability.board[uVar2].chain[0].chain_id = 3;
          capability.board[uVar2].chain_num = 3;
          capability.board[uVar2].chain[1].chain_id = 0xc;
          capability.board[uVar2].chain[2].chain_id = 0xd;
        }
        else {
          snprintf(tmp42,0x800,"slot %d pluged but not added\n",uVar4);
          _applog(0,tmp42,false);
          uVar2 = capability.board_num;
        }
        capability.board_num = uVar2 + 1;
      }
      uVar4 = uVar4 + 1;
    }
  }
  else {
    val = val & 0xffff;
    platform_is_t9 = 0;
    snprintf(tmp42,0x800,"HASH_ON_PLUG V9 = 0x%x\n",val);
    _applog(0,tmp42,false);
    for (; val != 0; val = val >> 1) {
      if ((int)(val << 0x1f) < 0) {
        snprintf(tmp42,0x800,"slot %d pluged\n",uVar4);
        _applog(0,tmp42,false);
        uVar2 = capability.board_num;
        uVar3 = capability.board[capability.board_num].chain_num;
        pbVar1 = capability.board + capability.board_num;
        capability.board_num = capability.board_num + 1;
        pbVar1->board_id = uVar4;
        capability.board[uVar2].chain_num = uVar3 + 1;
        capability.board[uVar2].chain[uVar3].chain_id = uVar4;
      }
      uVar4 = uVar4 + 1;
    }
  }
  return;
}

