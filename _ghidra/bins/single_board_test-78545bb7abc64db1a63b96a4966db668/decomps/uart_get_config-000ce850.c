
/* WARNING: Unknown calling convention */

int32_t uart_get_config(uint32_t chain_id,bitmain_uart_conf_type_t type,void *val,int32_t *size)

{
  int32_t iVar1;
  uint32_t baudd;
  char tmp42 [2048];
  
  if (size == (int32_t *)0x0 || val == (void *)0x0) {
    iVar1 = -3;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + chain_id));
    if (type == BAUD) {
      baudd = type;
      iVar1 = fpga_read(0xf,&baudd);
      *(uint32_t *)val = baudd;
      *size = 4;
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"uart_get_config return %d\n",*val);
      _applog(3,tmp42,false);
    }
    else {
      iVar1 = -5;
      snprintf(tmp42,0x800,"unknown set config type = %d\n",type);
      _applog(1,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + chain_id));
  }
  return iVar1;
}

