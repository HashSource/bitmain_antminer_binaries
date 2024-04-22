
void get_BM1722_asic_register(undefined param_1,undefined param_2,undefined param_3,char param_4)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  
  local_c = 0;
  local_10 = 0x42;
  local_f = 5;
  if (param_4 != '\0') {
    local_10 = 0x52;
  }
  local_e = param_2;
  local_d = param_3;
  local_c = CRC5(&local_10,0x20);
  dcr_uart_send(param_1,&local_10,5);
  return;
}

