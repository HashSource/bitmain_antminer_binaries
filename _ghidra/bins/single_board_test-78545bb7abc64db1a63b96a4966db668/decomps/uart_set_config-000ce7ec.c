
/* WARNING: Unknown calling convention */

int32_t uart_set_config(uint32_t chain_id,bitmain_uart_conf_type_t type,void *val,int32_t size)

{
  char tmp42 [2048];
  
  if (val != (void *)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + chain_id));
    if (type == BAUD) {
                    /* WARNING: Load size is inaccurate */
      fpga_write(0xf,*val);
    }
    else {
      snprintf(tmp42,0x800,"unknown set config type = %d\n",type);
      _applog(1,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + chain_id));
    return -5;
  }
  return -3;
}

