
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reg_list_exit(void)

{
  rs.alive = 0;
  usleep(1500000);
  pthread_cancel(rs.p_reg_list);
  pthread_join(rs.p_reg_list,(void **)0x0);
  free(rs.reg_list_items);
  pthread_mutex_destroy((pthread_mutex_t *)&rs.reg_list_mutex);
  return;
}

