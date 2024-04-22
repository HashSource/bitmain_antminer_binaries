
void read_sensor_test(void)

{
  byte local_11;
  int local_10;
  uint local_c;
  
  set_i2c_enable();
  usleep(500000);
  local_11 = 0;
  for (local_c = 0; (int)local_c < 1; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      i2c_recv(local_c & 0xff,*(uint *)((int)&sensor_chip_addr + local_10 * 4) & 0xff,0x4c,1,
               &local_11);
      if (local_11 != 0) {
        sensor_ok = sensor_ok + 1;
        printf("i2c i2c_reg_addr=%02x\n",(uint)local_11);
      }
    }
  }
  return;
}

