
/* WARNING: Variable defined which should be unmapped: magic_num-local */

_Bool eeprom_get_magic(uint8_t chain,uint8_t *magic_num)

{
  _Bool _Var1;
  uint8_t *magic_num_local;
  uint8_t chain_local;
  uint8_t ret;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain,(uint)chain,(uint)chain,magic_num);
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    eeprom_read_one_byte('\0',chain);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_check_crc(chain);
  }
  return _Var1;
}

