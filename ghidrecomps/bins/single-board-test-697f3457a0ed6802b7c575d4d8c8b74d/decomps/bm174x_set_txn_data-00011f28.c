
void bm174x_set_txn_data(int fd,uint32_t txn_data)

{
  uint32_t txn_data_local;
  int fd_local;
  base_type_t item;
  
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = 'X';
  reg_value.txn_data = txn_data;
  item.data = txn_data;
  bm174x_ioctl(fd,1,&item);
  return;
}

