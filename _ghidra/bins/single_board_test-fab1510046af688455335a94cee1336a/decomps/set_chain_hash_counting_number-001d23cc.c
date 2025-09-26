
/* WARNING: Unknown calling convention */

int32_t set_chain_hash_counting_number(uint8_t which_chain,uint32_t hash_counting_num)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x10,hash_counting_num);
  return iVar1;
}

