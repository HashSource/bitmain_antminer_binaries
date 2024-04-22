
int add_reg_item(reg_list_item_t item)

{
  undefined4 in_r0;
  uint32_t in_r1;
  int in_r2;
  reg_list_item_t *prVar1;
  reg_list_item_t item_local;
  int i;
  
  pthread_mutex_lock(DAT_00032734);
  i = 0;
  while( true ) {
    if (99 < i) {
      pthread_mutex_unlock(DAT_00032734);
      return -1;
    }
    if (rs.reg_list_items[i].age < 0) break;
    i = i + 1;
  }
  prVar1 = rs.reg_list_items + i;
  prVar1->chainid = (char)in_r0;
  prVar1->chip_addr = (char)((uint)in_r0 >> 8);
  prVar1->reg_addr = (char)((uint)in_r0 >> 0x10);
  prVar1->field_0x3 = (char)((uint)in_r0 >> 0x18);
  prVar1->reg_data = in_r1;
  prVar1->age = in_r2;
  pthread_mutex_unlock(DAT_00032734);
  return 1;
}

