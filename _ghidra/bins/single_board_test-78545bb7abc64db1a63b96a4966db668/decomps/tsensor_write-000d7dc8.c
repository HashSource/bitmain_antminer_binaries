
/* WARNING: Unknown calling convention */

int32_t tsensor_write(uint32_t which_chain,uint8_t slave_addr,uint8_t reg_addr,uint8_t *buf,
                     uint32_t len)

{
  int iVar1;
  int32_t iVar2;
  uint8_t *data;
  uint8_t *puVar3;
  byte local_829 [8];
  uint8_t tmp_addr;
  char tmp42 [2048];
  
  local_829[0] = slave_addr;
  if (which_chain < 0x10) {
    iVar1 = find_index(which_chain,slave_addr);
    if ((iVar1 != -0x7ffffa00) ||
       ((iVar2 = tsensor_open(which_chain,local_829,'\x01'), -1 < iVar2 &&
        (iVar1 = find_index(which_chain,local_829[0]), iVar1 != -0x7ffffa00)))) {
      if (len != 0) {
        data = buf;
        do {
          puVar3 = data + 1;
          tmp_addr = reg_addr;
          iVar2 = iic_write_reg(_g_tsensor_state[which_chain].bitmain_tsensor[iVar1].tsensor_fd,
                                &tmp_addr,1,data,1,true);
          reg_addr = reg_addr + '\x01';
          if (iVar2 != 1) {
            snprintf(tmp42,0x800,"fail to write tsensor by iic, chain:%d, slave: %d, addr: %d",
                     which_chain,(uint)local_829[0],(uint)tmp_addr);
            _applog(0,tmp42,false);
            return -0x7ffffa00;
          }
          data = puVar3;
        } while (puVar3 != buf + len);
      }
      return len;
    }
    snprintf(tmp42,0x800," auto exec tsensor_open, but chain %d,slave_addr %d open failed\n",
             which_chain,(uint)local_829[0]);
    _applog(0,tmp42,false);
  }
  else {
    snprintf(tmp42,0x800," Bad T-sensor param, input chain is %d\n",which_chain);
    _applog(0,tmp42,false);
    iVar2 = -0x7ffff9ff;
  }
  return iVar2;
}

