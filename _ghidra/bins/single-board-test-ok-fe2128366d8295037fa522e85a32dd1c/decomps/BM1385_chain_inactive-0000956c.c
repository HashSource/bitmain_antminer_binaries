
void BM1385_chain_inactive(undefined1 param_1)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = 0;
  local_c = 0x85;
  local_b = 0;
  local_a = 0;
  local_9 = CRC5(&local_c,0x1b);
  uart_send(param_1,&local_c,4);
  usleep(5000);
  return;
}

