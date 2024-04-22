
/* WARNING: Unknown calling convention */

void reg_list_init(void)

{
  int id;
  
  rs.alive = 1;
  pthread_mutex_init(DAT_0003296c,(pthread_mutexattr_t *)0x0);
  rs.reg_list_items = (reg_list_item_t *)calloc(0xc,100);
  for (id = 0; id < 100; id = id + 1) {
    rs.reg_list_items[id].age = -1;
  }
  pthread_create(DAT_00032970,(pthread_attr_t *)0x0,reg_list_aging + 1,(void *)0x0);
  return;
}

