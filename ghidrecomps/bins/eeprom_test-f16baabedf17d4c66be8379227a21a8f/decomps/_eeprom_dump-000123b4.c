
void _eeprom_dump(uint8_t chain)

{
  uint8_t uVar1;
  void *__ptr;
  uint8_t chain_local;
  uint8_t *temp;
  int i_1;
  int i;
  
  __ptr = malloc(0x100);
  if (__ptr == (void *)0x0) {
    perror("allocat memory failed");
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    for (i = 0; i < 0x100; i = i + 1) {
      uVar1 = eeprom_read_one_byte((uint8_t)i,chain);
      *(uint8_t *)((int)__ptr + i) = uVar1;
    }
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    printf("eeprom data in chain[%d]:\n",(uint)chain);
    puts("offset: 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0d");
    for (i_1 = 0; i_1 < 0x100; i_1 = i_1 + 1) {
      if ((i_1 & 0xfU) == 0) {
        printf("%06x: ",i_1);
      }
      printf("%02x ",(uint)*(byte *)(i_1 + (int)__ptr));
      if ((i_1 + 1U & 0xf) == 0) {
        putchar(10);
      }
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    putchar(10);
  }
  return;
}

