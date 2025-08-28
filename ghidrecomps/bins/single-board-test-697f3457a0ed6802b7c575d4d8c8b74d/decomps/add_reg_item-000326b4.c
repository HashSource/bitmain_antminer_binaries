
int add_reg_item(reg_list_item_t item)

{
  undefined4 uVar1;
  reg_list_item_t *prVar2;
  reg_list_item_t item_local;
  int i;
  
  uVar1 = item._0_4_;
  pthread_mutex_lock((pthread_mutex_t *)&rs.reg_list_mutex);
  i = 0;
  while( true ) {
    if (99 < i) {
      pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
      return -1;
    }
    if (rs.reg_list_items[i].age < 0) break;
    i = i + 1;
  }
  prVar2 = rs.reg_list_items + i;
  prVar2->chainid = (char)uVar1;
  prVar2->chip_addr = (char)((uint)uVar1 >> 8);
  prVar2->reg_addr = (char)((uint)uVar1 >> 0x10);
  prVar2->field_0x3 = (char)((uint)uVar1 >> 0x18);
  prVar2->reg_data = item.reg_data;
  prVar2->age = item.age;
  pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
  return 1;
}

