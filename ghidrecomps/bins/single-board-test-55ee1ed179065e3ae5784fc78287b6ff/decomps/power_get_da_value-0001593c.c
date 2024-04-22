
uint power_get_da_value(void)

{
  uint uVar1;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  
  local_10 = DAT_0002b1b0;
  local_c = DAT_0002b1b4;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  uVar1 = power_send_cmd(&local_10,6,&local_30,8);
  if (uVar1 != 0) {
    printf("power get da value is %02x\n",local_2c & 0xff);
    uVar1 = local_2c & 0xff;
  }
  return uVar1;
}

