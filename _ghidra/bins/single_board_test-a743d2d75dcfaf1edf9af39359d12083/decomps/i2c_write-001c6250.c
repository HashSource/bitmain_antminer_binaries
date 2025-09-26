
/* WARNING: Unknown calling convention */

int32_t i2c_write(int32_t ctx,void *data,uint32_t size)

{
  byte bVar1;
  void *pvVar2;
  uchar uVar3;
  clib_bool cVar4;
  int32_t iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  int32_t local_82c;
  uint8_t no_use;
  void *temp;
  char tmp42 [2048];
  
  local_82c = ctx;
  temp = (void *)pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (temp == (void *)0x0) {
    cVar4 = find_c_map(i2c_ctx_map,&local_82c,&temp);
    pvVar2 = temp;
    if (cVar4 == 1) {
      if (size != 0) {
        pbVar8 = (byte *)data;
        do {
                    /* WARNING: Load size is inaccurate */
          iVar6 = *pvVar2;
          uVar7 = *(uint *)((int)pvVar2 + 4);
          pbVar9 = pbVar8 + 1;
          bVar1 = *pbVar8;
          uVar3 = wait4i2c_ready();
          if (uVar3 == '\0') {
            free(temp);
            builtin_strncpy(tmp42,"iic not ready 4 writ",0x14);
            tmp42[0x14] = 'e';
            tmp42[0x15] = '\n';
            tmp42[0x16] = '\0';
            _applog(0,tmp42,false);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -2;
          }
          fpga_write(0xc,(uVar7 >> 4) << 0x14 | iVar6 << 0x1a | ((uVar7 << 0x1c) >> 0x1d) << 0x10 |
                         (uint)bVar1);
          uVar3 = wait4i2c_data(&no_use);
          if (uVar3 == '\0') {
            builtin_strncpy(tmp42,"iic write failed",0x10);
            tmp42[0x10] = '\n';
            tmp42[0x11] = '\0';
            _applog(0,tmp42,false);
            free(temp);
            pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
            return -3;
          }
          pbVar8 = pbVar9;
        } while ((byte *)((int)data + size) != pbVar9);
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
  return iVar5;
}

