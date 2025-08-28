
void BM1722_set_address(undefined1 param_1,undefined1 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  
  local_c = 0;
  local_10 = 0x40;
  local_f = 5;
  local_d = 0;
  local_e = param_2;
  local_c = CRC5(&local_10,0x20);
  dcr_uart_send(param_1,&local_10,5);
  return;
}

