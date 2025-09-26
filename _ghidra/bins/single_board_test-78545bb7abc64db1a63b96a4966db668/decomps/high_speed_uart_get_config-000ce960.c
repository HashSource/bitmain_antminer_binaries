
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int high_speed_uart_get_config
              (uint32_t chain_id,bitmain_uart_conf_type_t type,void *val,int32_t *size)

{
  code *pcVar1;
  int iVar2;
  char tmp42 [2048];
  
  if (size != (int32_t *)0x0) {
    size = (int32_t *)0x1;
  }
  if (val == (void *)0x0) {
    size = (int32_t *)((uint)size | 1);
  }
  if (size == (int32_t *)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + chain_id));
    if (type == BAUD) {
      tmp42._0_4_ = type;
      fpga_read(0xf,(uint32_t *)tmp42);
      *(uint *)val = (uint)(tmp42._0_4_ << 10) >> 0x1a;
      _shift = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xce9dc);
      (*pcVar1)();
    }
    snprintf(tmp42,0x800,"unknown set config type = %d\n",type);
    _applog(1,tmp42,false);
    pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + chain_id));
    iVar2 = -5;
  }
  else {
    iVar2 = -3;
  }
  return iVar2;
}

