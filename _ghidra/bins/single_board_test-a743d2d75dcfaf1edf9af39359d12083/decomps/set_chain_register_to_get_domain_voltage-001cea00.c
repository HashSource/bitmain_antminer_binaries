
/* WARNING: Unknown calling convention */

int32_t set_chain_register_to_get_domain_voltage(uint8_t which_chain,uint8_t which_domain)

{
  int32_t iVar1;
  
  iVar1 = set_register_to_get_domain_voltage(which_chain,'\x01',0,which_domain);
  return iVar1;
}

