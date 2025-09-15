
uint16_t ISL_set_voltage(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t voltage
                        )

{
  uint16_t voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint16_t r_voltage;
  uint8_t retry_limits;
  uint8_t retry;
  
  puts("begin to read voltage");
  ISL_page_enable(which_chain,which_i2c,i2c_dev_addr,'\0');
  usleep(100000);
  usleep(100000);
  ISL_set_vout_command(which_chain,which_i2c,i2c_dev_addr,voltage);
  usleep(100000);
  usleep(100000);
  puts("end to read voltage");
  retry = '\0';
  retry_limits = '\x05';
  r_voltage = 0;
  do {
    usleep(100000);
    ISL_get_voltage(which_chain,which_i2c,i2c_dev_addr,&r_voltage);
    retry = retry + 1;
    if (retry_limits < retry) break;
  } while (r_voltage == 0);
  printf("--- ISL_get_voltage, Voltage: 0.%03d V\n\n",(uint)r_voltage);
  return r_voltage;
}

