
/* WARNING: Unknown calling convention */

int32_t tsensor_open(uint32_t which_chain,uint8_t *slave_addr,uint8_t slave_num)

{
  byte bVar1;
  int32_t iVar2;
  uint32_t uVar3;
  uint uVar4;
  char *__format;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  iic_init_param_t param;
  char tmp42 [2048];
  
  if (which_chain < 0x10) {
    if (slave_num < 8) {
      if (slave_num != '\0') {
        pbVar5 = slave_addr;
        do {
          while( true ) {
            iVar2 = find_index(which_chain,*pbVar5);
            pbVar6 = pbVar5 + 1;
            if (iVar2 != -0x7ffffa00) break;
            param.i2c_path = (char *)0x0;
            uVar7 = (*pbVar5 + which_chain) * 0x2000000;
            uVar4 = *pbVar5 + which_chain & 7;
            param._4_4_ = (uint)CONCAT11((char)uVar4,(byte)(uVar7 >> 0x1c)) << 0x10;
            param.chain_id = which_chain;
            printf("high:%d,low:%d\n",uVar7 >> 0x1c,uVar4);
            uVar3 = iic_init(&param);
            if ((int)uVar3 < 0) {
              snprintf(tmp42,0x800," open T-sensor error, chain is %d,slave addr is %d\n",
                       which_chain,(uint)*pbVar5);
              _applog(0,tmp42,false);
              return uVar3;
            }
            bVar1 = _g_tsensor_state[which_chain].num;
            _g_tsensor_state[which_chain].num = bVar1 + 1;
            _g_tsensor_state[which_chain].bitmain_tsensor[bVar1].slave_addr = *pbVar5;
            _g_tsensor_state[which_chain].bitmain_tsensor[bVar1].tsensor_fd = uVar3;
            pbVar5 = pbVar6;
            if (pbVar6 == slave_addr + (byte)(slave_num - 1) + 1) {
              return 0;
            }
          }
          pbVar5 = pbVar6;
        } while (pbVar6 != slave_addr + (byte)(slave_num - 1) + 1);
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

