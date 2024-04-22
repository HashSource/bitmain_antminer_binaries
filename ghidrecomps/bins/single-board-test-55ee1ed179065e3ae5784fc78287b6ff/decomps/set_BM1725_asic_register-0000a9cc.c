
void set_BM1725_asic_register
               (undefined param_1,undefined param_2,undefined param_3,char param_4,
               undefined4 param_5)

{
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  
  local_c = 0;
  local_14 = 0x41;
  local_13 = 9;
  if (param_4 != '\0') {
    local_14 = 0x51;
  }
  local_10 = (undefined)((uint)param_5 >> 0x18);
  local_f = (undefined)((uint)param_5 >> 0x10);
  local_e = (undefined)((uint)param_5 >> 8);
  local_d = (undefined)param_5;
  local_12 = param_2;
  local_11 = param_3;
  local_c = CRC5(&local_14,0x40);
  dcr_uart_send(param_1,&local_14,9);
  return;
}

