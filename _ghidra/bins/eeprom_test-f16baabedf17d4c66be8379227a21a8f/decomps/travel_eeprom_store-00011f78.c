
void travel_eeprom_store(uint8_t chain)

{
  eeprom_store_t *peVar1;
  uint8_t chain_local;
  uint32_t hast_rate;
  eeprom_store_t *eeprom;
  int k;
  int l;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
  }
  else {
    peVar1 = (eeprom_store_t *)malloc(0x72);
    if (peVar1 == (eeprom_store_t *)0x0) {
      puts("fetal error: failed to allocate memory for eeprom!");
    }
    else {
      memset(peVar1,0,0x72);
      peVar1 = read_eeprom_store_from_at24c02(peVar1,chain);
      printf("chain[%d] data in eeprom is:\n",(uint)chain);
      printf("magic number: 0x%02x\n",(uint)peVar1->magic_num);
      puts("freq data per ASIC:");
      for (l = 0; l < 0xc; l = l + 1) {
        for (k = 0; k < 9; k = k + 1) {
          printf("IC[%03d]:%d ",(l * 0x6c) / 0xc + k,
                 peVar1->chain_freq_data[k + (l * 0x6c) / 0xc] + 200);
        }
        putchar(10);
      }
      printf("voltage: %.02f V\n");
      printf("hash rate: %05d GH/s\n",
             (uint)peVar1->hash_rate[3] * 0x1000000 +
             (uint)peVar1->hash_rate[0] + (uint)peVar1->hash_rate[1] * 0x100 +
             (uint)peVar1->hash_rate[2] * 0x10000);
      if (peVar1 != (eeprom_store_t *)0x0) {
        free(peVar1);
      }
    }
  }
  return;
}

