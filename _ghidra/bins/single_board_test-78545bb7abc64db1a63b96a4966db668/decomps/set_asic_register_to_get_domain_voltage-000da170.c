
/* WARNING: Unknown calling convention */

int32_t set_asic_register_to_get_domain_voltage
                  (uint8_t which_chain,uint32_t which_asic_address,uint8_t which_domain)

{
  int32_t iVar1;
  uint8_t in_r3;
  
  iVar1 = set_register_to_get_domain_voltage(which_chain,'\0',which_asic_address,in_r3);
  return iVar1;
}

