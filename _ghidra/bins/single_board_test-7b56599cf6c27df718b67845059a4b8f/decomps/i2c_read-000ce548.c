
/* WARNING: Unknown calling convention */

int32_t i2c_read(int32_t ctx,void *data,uint32_t size)

{
  uchar uVar1;
  clib_bool cVar2;
  int32_t iVar3;
  uint uVar4;
  int iVar5;
  uint8_t *puVar6;
  uint8_t *data_00;
  int32_t local_824 [2];
  void *temp;
  char tmp42 [2048];
  
  local_824[0] = ctx;
  temp = (void *)pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (temp == (void *)0x0) {
    cVar2 = find_c_map(i2c_ctx_map,local_824,&temp);
    if (cVar2 == 1) {
                    /* WARNING: Load size is inaccurate */
      iVar5 = *temp;
      uVar4 = *(uint *)((int)temp + 4);
      if (size != 0) {
        data_00 = (uint8_t *)data;
        do {
          uVar1 = wait4i2c_ready();
          if (uVar1 == '\0') {
            free(temp);
            builtin_strncpy(tmp42,"iic not ready 4 read",0x14);
            tmp42[0x14] = '1';
            tmp42[0x15] = '\n';
            tmp42[0x16] = '\0';
            _applog(0,tmp42,false);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -2;
          }
          fpga_write(0xc,iVar5 << 0x1a | 0x2080000U | (uVar4 >> 4) << 0x14 |
                         ((uVar4 << 0x1c) >> 0x1d) << 0x10);
          usleep(50000);
          puVar6 = data_00 + 1;
          uVar1 = wait4i2c_data(data_00);
          if (uVar1 == '\0') {
            free(temp);
            builtin_strncpy(tmp42,"iic not ready 4 read",0x14);
            tmp42[0x14] = '2';
            tmp42[0x15] = '\n';
            tmp42[0x16] = '\0';
            _applog(0,tmp42,false);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -3;
          }
          data_00 = puVar6;
        } while (puVar6 != (uint8_t *)((int)data + size));
      }
      free(temp);
      usleep(10000);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return size;
    }
    snprintf(tmp42,0x800,"ctx %d not inited\n",local_824[0]);
    _applog(0,tmp42,false);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    iVar3 = -2;
  }
  else {
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
    iVar3 = -1;
  }
  return iVar3;
}

