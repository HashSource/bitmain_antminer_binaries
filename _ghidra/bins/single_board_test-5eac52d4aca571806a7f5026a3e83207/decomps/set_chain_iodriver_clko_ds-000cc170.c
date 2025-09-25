
/* WARNING: Unknown calling convention */

int32_t set_chain_iodriver_clko_ds(uint8_t which_chain,uint8_t clko_ds)

{
  int32_t iVar1;
  io_driver_strength_cfg_t io_dvr;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0x58,&io_dvr.v);
  io_dvr.v._1_1_ = io_dvr.v._1_1_ & 0xf | clko_ds << 4;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x58,io_dvr.v);
  return iVar1;
}

