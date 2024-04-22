
void set_temperature_offset_value(undefined4 param_1,undefined param_2,undefined4 param_3)

{
  printf("\n--- %s\n","set_temperature_offset_value");
  write_temperature_offset_PIC16F1704(param_1,param_2,param_3);
  usleep(100000);
  return;
}

