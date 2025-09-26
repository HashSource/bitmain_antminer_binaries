
/* WARNING: Unknown calling convention */

int32_t set_asic_iodriver_clko_ds(uint8_t which_chain,uint32_t which_asic_address,uint8_t clko_ds)

{
  int32_t iVar1;
  io_driver_strength_cfg_t io_dvr;
  
  get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0x58,&io_dvr.v);
  io_dvr.v._1_1_ = io_dvr.v._1_1_ & 0xf | clko_ds << 4;
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x58,io_dvr.v);
  return iVar1;
}

