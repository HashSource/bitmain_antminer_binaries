
/* WARNING: Unknown calling convention */

int32_t i2c_write_reg(int32_t ctx,uint8_t *reg,uint32_t bytes,void *data,uint32_t size,
                     _Bool reg_addr_valid)

{
  void *pvVar1;
  undefined4 uVar2;
  uchar uVar3;
  clib_bool cVar4;
  uint uVar5;
  int32_t iVar6;
  uint32_t val;
  byte *pbVar7;
  byte *pbVar8;
  int32_t local_834;
  uint8_t no_use;
  void *temp;
  char tmp42 [2048];
  
  local_834 = ctx;
  if (bytes == 1) {
    temp = (void *)pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    if (temp == (void *)0x0) {
      cVar4 = find_c_map(i2c_ctx_map,&local_834,&temp);
      pvVar1 = temp;
      if (cVar4 == 1) {
        if (size != 0) {
          pbVar7 = (byte *)data;
          do {
            uVar5 = *(uint *)((int)pvVar1 + 4);
                    /* WARNING: Load size is inaccurate */
            pbVar8 = pbVar7 + 1;
            val = (uVar5 >> 4) << 0x14 | *pvVar1 << 0x1a | ((uVar5 << 0x1c) >> 0x1d) << 0x10 |
                  (uint)*pbVar7;
            if (reg_addr_valid) {
              val = val | (int)(pbVar7 + ((uint)*reg - (int)data)) * 0x100 | 0x1000000;
            }
            uVar3 = wait4i2c_ready();
            uVar2 = tmp42._20_4_;
            if (uVar3 == '\0') {
              builtin_strncpy(tmp42,"iic not ready 4 write\n",0x17);
              tmp42[0x17] = SUB41(uVar2,3);
              _applog(0,tmp42,false);
              free(temp);
              pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
              return -2;
            }
            fpga_write(0xc,val);
            usleep(10000);
            uVar3 = wait4i2c_data(&no_use);
            uVar2 = tmp42._20_4_;
            if (uVar3 == '\0') {
              builtin_strncpy(tmp42,"iic write reg failed\n",0x16);
              tmp42._22_2_ = SUB42(uVar2,2);
              _applog(0,tmp42,false);
              free(temp);
              pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
              return -3;
            }
            pbVar7 = pbVar8;
          } while ((byte *)((int)data + size) != pbVar8);
        }
        free(temp);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        return size;
      }
      snprintf(tmp42,0x800,"ctx %d not inited\n",local_834);
      _applog(0,tmp42,false);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      iVar6 = -2;
    }
    else {
      builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
      _applog(0,tmp42,false);
      iVar6 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"more than one byte reg address is not supported\n",0x30);
    tmp42[0x30] = '\0';
    _applog(0,tmp42,false);
    iVar6 = -3;
  }
  return iVar6;
}

