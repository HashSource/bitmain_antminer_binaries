
void BM1385_set_gateblk(undefined param_1,undefined4 param_2,char param_3)

{
  byte local_10;
  undefined local_f;
  byte local_e;
  byte local_d;
  byte local_9;
  
  local_10 = 0;
  local_9 = 0;
  if (param_3 != '\0') {
    local_10 = 0x80;
  }
  local_10 = local_10 | 6;
  local_f = 0;
  local_e = (byte)Conf._268_4_ | 0x80;
  local_d = 0;
  local_9 = CRC5(&local_10,0x1b);
  local_9 = local_9 & 0x1f;
  local_d = local_9 | local_d;
  uart_send(param_1,&local_10,4);
  usleep(10000);
  return;
}

