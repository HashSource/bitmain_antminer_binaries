
/* WARNING: Unknown calling convention */

int32_t set_register_cache_value
                  (cache_level_e level,uint8_t which_chain,uint32_t which_asic_address,
                  uint32_t register_address,uint32_t cache_value)

{
  uint uVar1;
  uint uVar2;
  asic_register_value_t *paVar3;
  int32_t iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (uint)which_chain;
  uVar5 = register_address & 3;
  uVar1 = register_address >> 2;
  uVar6 = uVar5 + uVar1;
  if (uVar2 < 4) {
    if (which_asic_address < 0x100) {
      if (uVar6 < 0x81) {
        pthread_mutex_lock((pthread_mutex_t *)&hashboard_register_value_mutex);
        if (level == hashboard_cache_level) {
          if (register_address == hashboard_register_value[uVar2][uVar6].register_addr) {
            hashboard_register_value[uVar2][uVar6].register_value = cache_value;
            paVar3 = hashboard_asic_register_value[uVar2][0] + uVar6;
            do {
              paVar3->register_value = cache_value;
              paVar3 = paVar3 + 0x80;
            } while (paVar3 != hashboard_asic_register_value[uVar2 + 1][0] + uVar6);
LAB_000d084c:
            pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
            return 0;
          }
          iVar4 = -4;
        }
        else if (level == asic_cache_level) {
          if (register_address ==
              hashboard_asic_register_value[uVar2][which_asic_address][uVar1 + uVar5].register_addr)
          {
            hashboard_asic_register_value[uVar2][which_asic_address][uVar1 + uVar5].register_value =
                 cache_value;
            goto LAB_000d084c;
          }
          iVar4 = -5;
        }
        else {
          iVar4 = -6;
        }
        pthread_mutex_unlock((pthread_mutex_t *)&hashboard_register_value_mutex);
        printf("[%s] level::%d, which_chain::%u, which_asic::%u,register_index::%u, hash_register_value::%08x, register_address::%02x failed ,ret:%d.\r\n"
               ,"set_register_cache_value",level,uVar2,which_asic_address,uVar6,
               hashboard_register_value[uVar2][uVar6].register_addr,register_address,iVar4);
      }
      else {
        iVar4 = -3;
      }
    }
    else {
      iVar4 = -2;
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}

