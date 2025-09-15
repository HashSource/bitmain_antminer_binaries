
void BM1385_set_address(undefined1 param_1,undefined1 param_2)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = 0;
  local_c = 1;
  local_a = 0;
  local_b = param_2;
  local_9 = CRC5(&local_c,0x1b);
  uart_send(param_1,&local_c,4);
  return;
}

