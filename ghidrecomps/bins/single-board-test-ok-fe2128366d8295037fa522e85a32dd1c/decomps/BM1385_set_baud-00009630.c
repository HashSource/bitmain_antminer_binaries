
void BM1385_set_baud(undefined param_1,undefined param_2,byte param_3,char param_4)

{
  byte local_c;
  undefined local_b;
  byte local_a;
  undefined local_9;
  
  local_c = 0;
  local_9 = 0;
  if (param_4 != '\0') {
    local_c = 0x80;
  }
  local_c = local_c | 6;
  local_a = param_3 & 0x1f;
  local_b = param_2;
  local_9 = CRC5(&local_c,0x1b);
  uart_send(param_1,&local_c,4);
  return;
}

