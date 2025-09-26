
/* WARNING: Unknown calling convention */

int32_t tsensor_open(uint32_t which_chain,uint8_t *slave_addr,uint8_t slave_num)

{
  byte bVar1;
  byte bVar2;
  int32_t iVar3;
  uint32_t uVar4;
  uint uVar5;
  char *__format;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  iic_init_param_t param;
  char tmp42 [2048];
  
  if (which_chain < 0x10) {
    if (slave_num < 8) {
      if (slave_num != '\0') {
        pbVar6 = slave_addr;
        do {
          while (iVar3 = find_index(which_chain,*pbVar6), iVar3 != -0x7ffffa00) {
            pbVar6 = pbVar6 + 1;
            if (pbVar6 == slave_addr + (byte)(slave_num - 1) + 1) {
              return 0;
            }
          }
          param.i2c_path = (char *)0x0;
          uVar8 = (*pbVar6 + which_chain) * 0x2000000;
          uVar5 = *pbVar6 + which_chain & 7;
          param._4_4_ = (uint)CONCAT11((char)uVar5,(byte)(uVar8 >> 0x1c)) << 0x10;
          param.chain_id = which_chain;
          printf("high:%d,low:%d\n",uVar8 >> 0x1c,uVar5);
          uVar4 = iic_init(&param);
          if ((int)uVar4 < 0) {
            snprintf(tmp42,0x800," open T-sensor error, chain is %d,slave addr is %d\n",which_chain,
                     (uint)*pbVar6);
            _applog(0,tmp42,false);
            return uVar4;
          }
          bVar1 = _g_tsensor_state[which_chain].num;
          pbVar7 = pbVar6 + 1;
          _g_tsensor_state[which_chain].num = bVar1 + 1;
          bVar2 = *pbVar6;
          _g_tsensor_state[which_chain].bitmain_tsensor[bVar1].tsensor_fd = uVar4;
          _g_tsensor_state[which_chain].bitmain_tsensor[bVar1].slave_addr = bVar2;
          pbVar6 = pbVar7;
        } while (pbVar7 != slave_addr + (byte)(slave_num - 1) + 1);
      }
      return 0;
    }
    __format = " Bad T-sensor param, input num is %d\n";
  }
  else {
    __format = " Bad T-sensor param, input chain is %d\n";
  }
  snprintf(tmp42,0x800,__format);
  _applog(0,tmp42,false);
  return -0x7ffff9ff;
}

