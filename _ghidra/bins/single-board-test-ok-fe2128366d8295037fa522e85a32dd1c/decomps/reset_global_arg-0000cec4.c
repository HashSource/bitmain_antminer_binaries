
void reset_global_arg(void)

{
  uint local_c;
  
  printf("\n--- %s\n","reset_global_arg");
  time_counter = 0;
  gHighest_Temp = 0;
  gChain = 0xff;
  gWork_Num_For_Hw_Check = 0;
  gIsOpenCoreEnd = 0;
  gStartTest = 0;
  gBegin_Get_Nonce = 0;
  memset(gValid_Nonce_Num,0,0x40);
  memset(gHw_Nonce_Num,0,0x40);
  memset(reg_value_buf,0,0x1008);
  memset(gWorks_For_Hw_Check,0,0x910);
  memset(lcd_buffer + 0x20,0x20,0x40);
  write(lcd_fd,lcd_buffer + 0x20,0x40);
  pthread_mutex_init((pthread_mutex_t *)reg_mutex,(pthread_mutexattr_t *)0x0);
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    pthread_mutex_init((pthread_mutex_t *)(&uart_send_mutex + local_c * 0x18),
                       (pthread_mutexattr_t *)0x0);
    pthread_mutex_init((pthread_mutex_t *)(uart_receive_mutex + local_c * 0x18),
                       (pthread_mutexattr_t *)0x0);
  }
  clear_register_value_buf();
  return;
}

