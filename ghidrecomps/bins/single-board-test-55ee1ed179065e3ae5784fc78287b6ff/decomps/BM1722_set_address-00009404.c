
void BM1722_set_address(undefined param_1,undefined param_2)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  
  local_c = 0;
  local_10 = 0x40;
  local_f = 5;
  local_d = 0;
  local_e = param_2;
  local_c = CRC5(&local_10,0x20);
  dcr_uart_send(param_1,&local_10,5);
  return;
}

