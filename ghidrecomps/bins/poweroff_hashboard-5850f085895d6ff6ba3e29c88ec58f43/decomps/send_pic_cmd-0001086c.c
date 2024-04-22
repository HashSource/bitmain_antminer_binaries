
void send_pic_cmd(undefined param_1,int param_2,byte param_3,int param_4,byte param_5)

{
  undefined uVar1;
  short local_16;
  int local_14;
  
  local_16 = param_3 + 3;
  for (local_14 = 0; local_14 < (int)(uint)param_3; local_14 = local_14 + 1) {
    local_16 = local_16 + (ushort)*(byte *)(local_14 + param_2);
  }
  write_pic_iic(param_1,0x55);
  write_pic_iic(param_1,0xaa);
  write_pic_iic(param_1,param_3 + 3);
  for (local_14 = 0; local_14 < (int)(uint)param_3; local_14 = local_14 + 1) {
    write_pic_iic(param_1,*(undefined *)(local_14 + param_2));
  }
  write_pic_iic(param_1,(char)((ushort)local_16 >> 8));
  write_pic_iic(param_1,(char)local_16);
  usleep(550000);
  for (local_14 = 0; local_14 < (int)(uint)param_5; local_14 = local_14 + 1) {
    uVar1 = read_pic_iic(param_1);
    *(undefined *)(param_4 + local_14) = uVar1;
  }
  return;
}

