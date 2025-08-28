
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reg_list_init(void)

{
  int id;
  
  rs.alive = 1;
  pthread_mutex_init((pthread_mutex_t *)&rs.reg_list_mutex,(pthread_mutexattr_t *)0x0);
  rs.reg_list_items = (reg_list_item_t *)calloc(0xc,100);
  for (id = 0; id < 100; id = id + 1) {
    rs.reg_list_items[id].age = -1;
  }
  pthread_create(&rs.p_reg_list,(pthread_attr_t *)0x0,(__start_routine *)0x32869,(void *)0x0);
  return;
}

