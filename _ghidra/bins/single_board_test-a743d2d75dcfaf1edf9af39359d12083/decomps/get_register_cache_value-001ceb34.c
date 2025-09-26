
/* WARNING: Unknown calling convention */

int32_t get_register_cache_value
                  (cache_level_e level,uint8_t which_chain,uint32_t which_asic_address,
                  uint32_t register_address,uint32_t *cache_value)

{
  uint uVar1;
  int iVar2;
  int32_t iVar3;
  
  uVar1 = (uint)which_chain;
  if (3 < uVar1) {
    return -1;
  }
  if (0xff < which_asic_address) {
    return -2;
  }
  pthread_mutex_lock((pthread_mutex_t *)&hashboard_register_value_mutex);
  if (level == hashboard_cache_level) {
    iVar2 = 0;
    do {
      if (hashboard_register_value[uVar1][iVar2].register_addr == register_address) {
        *cache_value = hashboard_register_value[uVar1][iVar2].register_value;
        if (iVar2 == 0x7f) {
          iVar3 = -4;
          goto LAB_001ceb9a;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x80);
  }
  else {
    if (level != asic_cache_level) {
      iVar3 = -6;
LAB_001ceb9a:
      pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
      printf("get_register_cache_value failed, ret = %d",iVar3);
      return iVar3;
    }
    iVar2 = 0;
    do {
      if (register_address ==
          hashboard_asic_register_value[uVar1][which_asic_address][iVar2].register_addr) {
        *cache_value = hashboard_asic_register_value[uVar1][which_asic_address][iVar2].
                       register_value;
        if (iVar2 == 0x7f) {
          iVar3 = -5;
          goto LAB_001ceb9a;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x80);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
  return 0;
}

