
int32_t recv_scan_data(char *recv_buffer,int32_t length)

{
  uint32_t size;
  int32_t iVar1;
  int32_t length_local;
  char *recv_buffer_local;
  int32_t read_len;
  int32_t readable_data_len;
  
  size = uart_get_readable_byte_num(3);
  if ((int)size < 1) {
    iVar1 = -1;
  }
  else {
    if (length <= (int)size) {
      size = length;
    }
    iVar1 = uart_receive(3,recv_buffer,size,0);
  }
  return iVar1;
}

