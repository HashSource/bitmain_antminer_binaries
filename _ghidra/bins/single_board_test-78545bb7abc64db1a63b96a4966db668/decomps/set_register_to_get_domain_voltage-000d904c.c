
int32_t set_register_to_get_domain_voltage
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t which_domain
                  )

{
  send_set_config_command(which_chain,mode,which_asic_address,0xb8,0x20002209);
  usleep(20000);
  send_set_config_command(which_chain,mode,which_asic_address,0xb8,0x20202209);
  usleep(10000);
  return 0;
}

