
void set_voltage_setting_time(undefined param_1,int param_2)

{
  int local_c;
  
  printf("\n--- %s\n","set_voltage_setting_time");
  send_pic_command(param_1);
  send_data_to_pic_iic(param_1,0x11,param_2,6);
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    printf("%s: time[%d] = 0x%02x\n","set_voltage_setting_time",local_c,
           (uint)*(byte *)(local_c + param_2));
  }
  usleep(100000);
  return;
}

