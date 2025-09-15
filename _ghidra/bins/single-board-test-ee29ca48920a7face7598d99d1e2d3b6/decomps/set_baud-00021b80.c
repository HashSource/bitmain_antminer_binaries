
void set_baud(uint param_1)

{
  set_baud_chain(param_1);
  sleep(1);
  set_fpga_baud(param_1 & 0xff);
  usleep(10000);
  return;
}

