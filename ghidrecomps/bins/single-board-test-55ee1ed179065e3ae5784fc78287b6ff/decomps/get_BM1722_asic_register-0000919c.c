
void get_BM1722_asic_register(undefined1 param_1,undefined1 param_2,undefined1 param_3,char param_4)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  
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

