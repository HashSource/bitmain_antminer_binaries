
_Bool eeprom_get_hashrate(uint8_t chain,uint32_t *hash)

{
  uint8_t uVar1;
  _Bool _Var2;
  uint32_t *hash_local;
  uint8_t chain_local;
  uint8_t hash_rate [4];
  int i;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var2 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    for (i = 0; (uint)i < 4; i = i + 1) {
      uVar1 = eeprom_read_one_byte((char)i + 'n',chain);
      hash_rate[i] = uVar1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    *hash = (uint)hash_rate[0] + (uint)hash_rate[1] * 0x100 + (uint)hash_rate[2] * 0x10000 +
            (uint)hash_rate[3] * 0x1000000;
    _Var2 = eeprom_check_crc(chain);
  }
  return _Var2;
}

