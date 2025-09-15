
undefined4 power_check_reply(char *param_1,char *param_2,byte param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort local_c;
  ushort local_a;
  
  local_a = 0;
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[3] == param_2[3])) &&
     ((byte)param_2[2] + 2 == (uint)param_3)) {
    for (local_c = 2; (int)(uint)local_c < (int)(param_3 - 2); local_c = local_c + 1) {
      local_a = (byte)param_2[local_c] + local_a;
    }
    uVar1 = (ushort)(byte)param_2[param_3 - 1] * 0x100 + (ushort)(byte)param_2[param_3 - 2];
    if (local_a == uVar1) {
      uVar2 = 1;
    }
    else {
      printf("power reply crc error, crc %04x != crc_reply %04x:\n",(uint)local_a,(uint)uVar1);
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        printf("%02x ",(uint)(byte)param_2[local_c]);
      }
      putchar(10);
      uVar2 = 0;
    }
  }
  else {
    puts("power reply data error:");
    for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
      printf("%02x ",(uint)(byte)param_2[local_c]);
    }
    putchar(10);
    uVar2 = 0;
  }
  return uVar2;
}

