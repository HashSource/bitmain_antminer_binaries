
void set_BM1385_freq(undefined param_1,undefined param_2,undefined4 param_3,char param_4)

{
  byte bVar1;
  undefined2 local_32;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  byte local_1c;
  undefined local_1b;
  undefined local_1a;
  byte local_19;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = 0;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_2c = 0;
  local_30 = 0;
  local_14 = 0;
  local_18 = 0;
  local_32 = 0;
  printf("\n--- %s\n","set_BM1385_freq");
  get_BM1385_plldata(param_3,&local_2c,&local_32,&local_30);
  local_1c = 7;
  local_1b = (undefined)((uint)local_2c >> 0x10);
  local_1a = (undefined)((uint)local_2c >> 8);
  bVar1 = (byte)local_2c;
  local_19 = bVar1;
  local_19 = CRC5(&local_1c,0x1b);
  local_19 = local_19 | bVar1;
  uart_send(param_1,&local_1c,4);
  usleep(3000);
  memset(&local_1c,0,4);
  memset(&local_28,0,0xc);
  if (param_4 != '\0') {
    local_1c = local_1c | 0x80;
  }
  local_1c = local_1c | 2;
  local_1a = (undefined)((ushort)local_32 >> 8);
  bVar1 = (byte)local_32;
  local_1b = param_2;
  local_19 = bVar1;
  local_19 = CRC5(&local_1c,0x1b);
  local_19 = local_19 | bVar1;
  uart_send(param_1,&local_1c,4);
  usleep(5000);
  return;
}

