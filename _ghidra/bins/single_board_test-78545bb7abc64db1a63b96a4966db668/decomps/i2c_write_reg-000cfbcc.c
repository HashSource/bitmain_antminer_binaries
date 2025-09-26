
/* WARNING: Unknown calling convention */

int32_t i2c_write_reg(int32_t ctx,uint8_t *reg,uint32_t bytes,void *data,uint32_t size,
                     _Bool reg_addr_valid)

{
  void *pvVar1;
  undefined4 uVar2;
  uchar uVar3;
  clib_bool cVar4;
  int32_t iVar5;
  uint uVar6;
  uint32_t val;
  uint32_t uVar7;
  byte *pbVar8;
  int32_t local_82c;
  uint8_t no_use;
  void *temp;
  char tmp42 [2048];
  
  local_82c = ctx;
  if (bytes == 1) {
    temp = (void *)pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    if (temp == (void *)0x0) {
      cVar4 = find_c_map(i2c_ctx_map,&local_82c,&temp);
      pvVar1 = temp;
      if (cVar4 == 1) {
        if (size != 0) {
          pbVar8 = (byte *)((int)data + -1);
          uVar7 = 0;
          do {
                    /* WARNING: Load size is inaccurate */
            uVar6 = *(uint *)((int)pvVar1 + 4);
            pbVar8 = pbVar8 + 1;
            val = *pvVar1 << 0x1a | (uVar6 >> 4) << 0x14 | ((uVar6 << 0x1c) >> 0x1d) << 0x10 |
                  (uint)*pbVar8;
            if (reg_addr_valid) {
              val = val | 0x1000000 | (uVar7 + *reg) * 0x100;
            }
            uVar7 = uVar7 + 1;
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
          } while (uVar7 != size);
        }
        free(temp);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        return size;
      }
      snprintf(tmp42,0x800,"ctx %d not inited\n",local_82c);
      _applog(0,tmp42,false);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      iVar5 = -2;
    }
    else {
      builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
      _applog(0,tmp42,false);
      iVar5 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"more than one byte reg address is not supported\n",0x30);
    tmp42[0x30] = '\0';
    _applog(0,tmp42,false);
    iVar5 = -3;
  }
  return iVar5;
}

