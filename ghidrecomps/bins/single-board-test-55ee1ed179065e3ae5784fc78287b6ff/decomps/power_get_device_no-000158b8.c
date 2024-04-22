
void power_get_device_no(void)

{
  int iVar1;
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
  
  local_10 = DAT_0002b18c;
  local_c = DAT_0002b190;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = power_send_cmd(&local_10,6,&local_30,8);
  if (iVar1 != 0) {
    printf("power device no is %02x %02x\n",local_2c >> 8 & 0xff,local_2c & 0xff);
  }
  return;
}

