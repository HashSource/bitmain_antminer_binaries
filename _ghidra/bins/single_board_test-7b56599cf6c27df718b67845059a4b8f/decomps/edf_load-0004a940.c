
eeprom_data_format_t * edf_load(uint8_t *src,size_t len)

{
  eeprom_data_format_t *peVar1;
  uint uVar2;
  size_t len_local;
  uint8_t *src_local;
  char time_stamp [48];
  char tmp1 [256];
  int ret;
  eeprom_data_format_t *ctx;
  int i;
  
  i = 0;
  while( true ) {
    if (1 < i) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : got nothing\n\n","edf_load");
      builtin_strncpy(tmp1,"got nothing\n",0xc);
      tmp1[0xc] = '\0';
      log_to_file(tmp1,time_stamp);
      return (eeprom_data_format_t *)0x0;
    }
    peVar1 = (*submodule_init[i])();
    if (peVar1 == (eeprom_data_format_t *)0x0) break;
    uVar2 = (*peVar1->load)(peVar1,src,len,0xe);
    if ((-1 < (int)uVar2) && ((uVar2 & 2) != 0)) {
      return peVar1;
    }
    (*peVar1->destroy)(peVar1);
    i = i + 1;
  }
  puts("edf_load failed no memory");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

