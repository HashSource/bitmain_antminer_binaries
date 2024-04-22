
void set_config_BM1391_t(uchar which_chain,uchar chip_addr,uchar mode,uchar reg,uint reg_data)

{
  uchar reg_local;
  uchar mode_local;
  uchar chip_addr_local;
  uchar which_chain_local;
  
  send_set_config_command((uint)which_chain,mode,chip_addr,reg,reg_data);
  return;
}

