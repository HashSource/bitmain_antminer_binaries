
/* WARNING: Unknown calling convention */

int32_t find_index(uint32_t which_chain,uint8_t slave_addr)

{
  bitmain_tsensor_t *pbVar1;
  uint uVar2;
  uint uVar3;
  int32_t iVar4;
  bitmain_chain_tsensor *pbVar5;
  
  if (0xf < which_chain) {
    iVar4 = find_index(which_chain,slave_addr);
    return iVar4;
  }
  pbVar5 = _g_tsensor_state + which_chain;
  if (_g_tsensor_state[which_chain].num == 0) {
LAB_000d7bfc:
    uVar3 = 0x80000600;
  }
  else if (_g_tsensor_state[which_chain].bitmain_tsensor[0].slave_addr == slave_addr) {
    uVar3 = 0;
  }
  else {
    uVar2 = 1;
    do {
      uVar3 = uVar2;
      if ((uint)_g_tsensor_state[which_chain].num <= (uVar3 & 0xff)) goto LAB_000d7bfc;
      pbVar1 = pbVar5->bitmain_tsensor;
      pbVar5 = (bitmain_chain_tsensor *)&pbVar5->bitmain_tsensor[0].tsensor_fd;
      uVar2 = uVar3 + 1;
    } while (pbVar1[1].slave_addr != slave_addr);
  }
  return uVar3;
}

