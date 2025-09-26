
/* WARNING: Unknown calling convention */

int32_t set_register_to_get_domain_voltage
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t which_domain
                  )

{
  uint reg_data;
  uint uVar1;
  uint unaff_r9;
  uint32_t reg_data_00;
  
  uVar1 = (uint)which_domain;
  if (uVar1 < 4) {
    reg_data = *(uint *)(CSWTCH_48 + uVar1 * 4);
  }
  else {
    unaff_r9 = 0xc305;
    reg_data = 0x200cc305;
  }
  if (uVar1 < 4) {
    reg_data_00 = reg_data | 0x200000;
  }
  else {
    reg_data_00 = unaff_r9 & 0xffff | 0x202c0000;
  }
  send_set_config_command(which_chain,mode,which_asic_address,0xb8,reg_data);
  usleep(10000);
  send_set_config_command(which_chain,mode,which_asic_address,0xb9,0x12480);
  usleep(10000);
  send_set_config_command(which_chain,mode,which_asic_address,0xba,0x110);
  usleep(10000);
  send_set_config_command(which_chain,mode,which_asic_address,0x54,uVar1 + 4 & 0xf);
  usleep(20000);
  send_set_config_command(which_chain,mode,which_asic_address,0xb8,reg_data_00);
  usleep(10000);
  return 0;
}

