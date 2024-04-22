
void bm174x_reg_handle(uint8_t *str,int len,uint8_t chainid)

{
  reg_list_item_t item;
  byte bVar1;
  undefined4 in_stack_fffffbc8;
  undefined8 in_stack_fffffbcc;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  reg_list_item_t new_item;
  uint8_t crc5;
  reg_respond *reg;
  
  bVar1 = CRC5_v1(str + 2,((char)len + -3) * '\b' + '\x03');
  if (bVar1 == (str[8] & 0x1f)) {
    item.reg_data = (int)in_stack_fffffbcc;
    item.age = (int)((ulonglong)in_stack_fffffbcc >> 0x20);
    item.chainid = (char)in_stack_fffffbc8;
    item.chip_addr = (char)((uint)in_stack_fffffbc8 >> 8);
    item.reg_addr = (char)((uint)in_stack_fffffbc8 >> 0x10);
    item._3_1_ = (char)((uint)in_stack_fffffbc8 >> 0x18);
    add_reg_item(item);
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s CRC error crc = %02x\n","bm174x_reg_handle",(uint)bVar1);
    _applog(0,tmp42,false);
  }
  return;
}

