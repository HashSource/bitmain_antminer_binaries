
/* WARNING: Unknown calling convention */

int32_t set_asic_hash_counting_number
                  (uint8_t which_chain,uint32_t which_asic_address,uint32_t hash_counting_num)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x10,hash_counting_num);
  return iVar1;
}

