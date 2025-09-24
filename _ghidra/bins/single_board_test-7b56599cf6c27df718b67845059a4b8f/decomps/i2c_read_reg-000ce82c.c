
/* WARNING: Unknown calling convention */

int32_t i2c_read_reg(int32_t ctx,uint8_t *reg,uint32_t bytes,void *data,uint32_t size,
                    _Bool reg_addr_valid)

{
  void *pvVar1;
  undefined4 uVar2;
  uchar uVar3;
  clib_bool cVar4;
  uint8_t *data_00;
  uint uVar5;
  int32_t iVar6;
  uint uVar7;
  uint32_t val;
  uint uVar8;
  int32_t local_834 [2];
  void *temp;
  char tmp42 [2048];
  
  local_834[0] = ctx;
  if (1 < bytes - 1) {
    builtin_strncpy(tmp42,"more than two byte reg data len is not supported",0x30);
    tmp42[0x30] = '\n';
    tmp42[0x31] = '\0';
    _applog(0,tmp42,false);
    return -3;
  }
  temp = (void *)pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (temp == (void *)0x0) {
    cVar4 = find_c_map(i2c_ctx_map,local_834,&temp);
    pvVar1 = temp;
    if (cVar4 == 1) {
      if (size != 0) {
        uVar8 = 0;
        do {
                    /* WARNING: Load size is inaccurate */
          uVar5 = *(uint *)((int)pvVar1 + 4);
          uVar7 = *pvVar1 << 0x1a;
          if (bytes == 2) {
            uVar7 = uVar7 | 0x2000000;
          }
          else {
            uVar7 = uVar7 | 0x2080000;
          }
          val = uVar7 | (uVar5 >> 4) << 0x14 | ((uVar5 << 0x1c) >> 0x1d) << 0x10;
          if (reg_addr_valid) {
            val = val | (*reg + uVar8) * 0x100 | 0x1000000;
          }
          uVar3 = wait4i2c_ready();
          uVar2 = tmp42._20_4_;
          if (uVar3 == '\0') {
            builtin_strncpy(tmp42,"iic not ready 4 read1\n",0x17);
            tmp42[0x17] = SUB41(uVar2,3);
            _applog(0,tmp42,false);
            free(temp);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -2;
          }
          fpga_write(0xc,val);
          usleep(10000);
          data_00 = (uint8_t *)((int)data + uVar8);
          uVar8 = uVar8 + bytes + 1;
          uVar3 = wait4i2c_data(data_00);
          if (uVar3 == '\0') {
            free(temp);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -3;
          }
        } while (uVar8 < size);
      }
      free(temp);
      usleep(10000);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return size;
    }
    snprintf(tmp42,0x800,"ctx %d not inited\n",local_834[0]);
    _applog(0,tmp42,false);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    iVar6 = -2;
  }
  else {
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
    iVar6 = -1;
  }
  return iVar6;
}

