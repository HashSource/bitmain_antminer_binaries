
_Bool access_temp_synopsys_reg(uint32_t chain)

{
  uint8_t which_chain;
  uint32_t chain_local;
  
  which_chain = (uint8_t)chain;
  set_chain_asic_synopsys_temp(which_chain,0,true,false,false,false);
  usleep(10000);
  set_chain_asic_synopsys_temp(which_chain,0,true,true,false,false);
  usleep(10000);
  set_chain_asic_synopsys_temp(which_chain,0,true,false,true,false);
  usleep(10000);
  get_register_value(0,0xb4,true,(Local_Config_Information->Hash_Board).Asic_Type);
  return true;
}

