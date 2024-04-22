
int read_reg_item(reg_list_item_t *item,int ms)

{
  bool bVar1;
  int iVar2;
  int extraout_r1;
  int ms_local;
  reg_list_item_t *item_local;
  int check_interval_ms;
  int i;
  int check_times;
  
  iVar2 = __aeabi_idiv(ms,0x32);
  __aeabi_idivmod(ms,0x32);
  check_times = extraout_r1 + iVar2;
  do {
    usleep(50000);
    pthread_mutex_lock(DAT_00032864);
    for (i = 0; i < 100; i = i + 1) {
      if ((((rs.reg_list_items[i].chainid == item->chainid) &&
           (rs.reg_list_items[i].chip_addr == item->chip_addr)) &&
          (rs.reg_list_items[i].reg_addr == item->reg_addr)) && (-1 < rs.reg_list_items[i].age)) {
        item->reg_data = rs.reg_list_items[i].reg_data;
        rs.reg_list_items[i].age = -1;
        pthread_mutex_unlock(DAT_00032864);
        return 1;
      }
    }
    pthread_mutex_unlock(DAT_00032864);
    bVar1 = check_times < 1;
    check_times = check_times + -1;
    if (bVar1) {
      return -1;
    }
  } while( true );
}

