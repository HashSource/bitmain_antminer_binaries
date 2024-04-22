
void change_time_format(uint *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (param_1[5] & 0xff) - 100;
  *param_2 = (char)uVar1 + (char)((uVar1 & 0xff) / 10) * -10 +
             (char)(((param_1[5] & 0xff) - 100 & 0xff) / 10) * '\x10';
  uVar1 = (param_1[4] & 0xff) + 1;
  param_2[1] = (char)uVar1 + (char)((uVar1 & 0xff) / 10) * -10 +
               (char)(((param_1[4] & 0xff) + 1 & 0xff) / 10) * '\x10';
  param_2[2] = (char)param_1[3] + (char)((param_1[3] & 0xff) / 10) * -10 +
               (char)((param_1[3] & 0xff) / 10) * '\x10';
  param_2[3] = (char)param_1[2] + (char)((param_1[2] & 0xff) / 10) * -10 +
               (char)((param_1[2] & 0xff) / 10) * '\x10';
  param_2[4] = (char)param_1[1] + (char)((param_1[1] & 0xff) / 10) * -10 +
               (char)((param_1[1] & 0xff) / 10) * '\x10';
  param_2[5] = (char)*param_1 + (char)((*param_1 & 0xff) / 10) * -10 +
               (char)((*param_1 & 0xff) / 10) * '\x10';
  printf("%s: year = 0x%02x\n","change_time_format",(uint)*param_2);
  printf("%s: month = 0x%02x\n","change_time_format",(uint)param_2[1]);
  printf("%s: day = 0x%02x\n","change_time_format",(uint)param_2[2]);
  printf("%s: hour = 0x%02x\n","change_time_format",(uint)param_2[3]);
  printf("%s: minute = 0x%02x\n","change_time_format",(uint)param_2[4]);
  printf("%s: second = 0x%02x\n","change_time_format",(uint)param_2[5]);
  return;
}

