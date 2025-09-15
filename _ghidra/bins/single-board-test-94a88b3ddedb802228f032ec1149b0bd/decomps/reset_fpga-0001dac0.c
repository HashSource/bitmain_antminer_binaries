
void reset_fpga(void)

{
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_PWM(100);
  return;
}

