
/* WARNING: Unknown calling convention */

int32_t tsensor_read(uint32_t which_chain,uint8_t slave_addr,uint8_t reg_addr,uint8_t *buf,
                    uint32_t len)

{
  int iVar1;
  uint32_t uVar2;
  byte local_81a;
  byte local_819;
  char tmp42 [2048];
  
  local_81a = reg_addr;
  local_819 = slave_addr;
  if (which_chain < 0x10) {
    iVar1 = find_index(which_chain,slave_addr);
    if ((iVar1 == -0x7ffffa00) &&
       ((uVar2 = tsensor_open(which_chain,&local_819,'\x01'), (int)uVar2 < 0 ||
        (iVar1 = find_index(which_chain,local_819), iVar1 == -0x7ffffa00)))) {
      snprintf(tmp42,0x800," auto exec tsensor_open, but chain %d,slave_addr %d open failed\n",
               which_chain,(uint)local_819);
      _applog(0,tmp42,false);
      len = uVar2;
    }
    else {
      uVar2 = iic_read_reg(_g_tsensor_state[which_chain].bitmain_tsensor[iVar1].tsensor_fd,
                           &local_81a,2,buf,len,true);
      if (len != uVar2) {
        snprintf(tmp42,0x800,"fail to read tsensor by iic, chain: %d, slave: %d, addr: %d\n",
                 which_chain,(uint)local_819,(uint)local_81a);
        _applog(0,tmp42,false);
        len = 0x80000600;
      }
    }
  }
  else {
    snprintf(tmp42,0x800," Bad T-sensor param, input chain is %d\n",which_chain);
    _applog(0,tmp42,false);
    len = 0x80000601;
  }
  return len;
}

