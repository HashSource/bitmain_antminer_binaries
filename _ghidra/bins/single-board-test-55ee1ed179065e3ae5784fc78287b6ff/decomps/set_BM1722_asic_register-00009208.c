
void set_BM1722_asic_register
               (undefined1 param_1,undefined1 param_2,undefined1 param_3,char param_4,
               undefined4 param_5)

{
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  
  local_c = 0;
  local_14 = 0x41;
  local_13 = 9;
  if (param_4 != '\0') {
    local_14 = 0x51;
  }
  local_10 = (undefined1)((uint)param_5 >> 0x18);
  local_f = (undefined1)((uint)param_5 >> 0x10);
  local_e = (undefined1)((uint)param_5 >> 8);
  local_d = (undefined1)param_5;
  local_12 = param_2;
  local_11 = param_3;
  local_c = CRC5(&local_14,0x40);
  dcr_uart_send(param_1,&local_14,9);
  return;
}

