
void BM1385_chain_inactive(undefined param_1)

{
  undefined local_c;
  undefined local_b;
  undefined local_a;
  undefined local_9;
  
  local_9 = 0;
  local_c = 0x85;
  local_b = 0;
  local_a = 0;
  local_9 = CRC5(&local_c,0x1b);
  uart_send(param_1,&local_c,4);
  usleep(5000);
  return;
}

