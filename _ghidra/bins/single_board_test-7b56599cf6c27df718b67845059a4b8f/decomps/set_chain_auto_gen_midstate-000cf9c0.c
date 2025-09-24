
/* WARNING: Unknown calling convention */

int32_t set_chain_auto_gen_midstate
                  (uint8_t which_chain,_Bool is_auto_gen,uint8_t midsx_gen,uint16_t version_mask)

{
  undefined1 uVar1;
  int32_t iVar2;
  midstate_cal_register_t midstate_cal_register;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xa4,&midstate_cal_register.v);
  if (is_auto_gen) {
    midstate_cal_register.v._2_2_ = midstate_cal_register.v._2_2_ | 0x8000;
  }
  else {
    midstate_cal_register.v._2_2_ = midstate_cal_register.v._2_2_ & 0x7fff;
  }
  uVar1 = midstate_cal_register.v._3_1_;
  midstate_cal_register.v._0_2_ = version_mask;
  midstate_cal_register.v = CONCAT13(uVar1,midstate_cal_register.v._0_3_) & 0x8fffffff | 0x10000000;
  iVar2 = send_set_config_command(which_chain,'\x01',0,0xa4,midstate_cal_register.v);
  return iVar2;
}

