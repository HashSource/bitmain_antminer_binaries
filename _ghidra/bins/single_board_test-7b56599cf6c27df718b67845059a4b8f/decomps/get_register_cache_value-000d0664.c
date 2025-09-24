
/* WARNING: Unknown calling convention */

int32_t get_register_cache_value
                  (cache_level_e level,uint8_t which_chain,uint32_t which_asic_address,
                  uint32_t register_address,uint32_t *cache_value)

{
  uint uVar1;
  uint uVar2;
  int32_t iVar3;
  
  uVar1 = (uint)which_chain;
  if (3 < uVar1) {
    return -1;
  }
  if (0xff < which_asic_address) {
    return -2;
  }
  uVar2 = register_address >> 2;
  if (uVar2 < 0x80) {
    pthread_mutex_lock((pthread_mutex_t *)&hashboard_register_value_mutex);
    if (level == hashboard_cache_level) {
      if (register_address == hashboard_register_value[uVar1][uVar2].register_addr) {
        *cache_value = hashboard_register_value[uVar1][uVar2].register_value;
LAB_000d0730:
        pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
        return 0;
      }
      iVar3 = -4;
    }
    else if (level == asic_cache_level) {
      if (register_address ==
          hashboard_asic_register_value[uVar1][which_asic_address][uVar2].register_addr) {
        *cache_value = hashboard_asic_register_value[uVar1][which_asic_address][uVar2].
                       register_value;
        goto LAB_000d0730;
      }
      iVar3 = -5;
    }
    else {
      iVar3 = -6;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
    printf("[%s] level::%d, which_chain::%u, which_asic::%u,register_index::%u, hash_reg_val::%08x, register_address::%02x failed.\r\n"
           ,0x1ffff8,level,uVar1,which_asic_address,uVar2,
           hashboard_register_value[uVar1][uVar2].register_addr,register_address);
  }
  else {
    iVar3 = -3;
  }
  return iVar3;
}

