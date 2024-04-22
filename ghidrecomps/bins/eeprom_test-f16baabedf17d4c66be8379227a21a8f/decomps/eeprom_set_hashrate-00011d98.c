
/* WARNING: Variable defined which should be unmapped: hash-local */

_Bool eeprom_set_hashrate(uint8_t chain,uint32_t hash)

{
  _Bool _Var1;
  uint32_t hash_local;
  uint8_t chain_local;
  uint8_t hash_rate [4];
  int i;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain,(uint)chain,(uint)chain,hash);
    _Var1 = false;
  }
  else {
    hash_rate[0] = (uint8_t)hash;
    hash_rate[1] = (uint8_t)(hash >> 8);
    hash_rate[2] = (uint8_t)(hash >> 0x10);
    hash_rate[3] = (uint8_t)(hash >> 0x18);
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    for (i = 0; (uint)i < 4; i = i + 1) {
      eeprom_write_one_byte((char)i + 'n',hash_rate[i],chain);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  return _Var1;
}

