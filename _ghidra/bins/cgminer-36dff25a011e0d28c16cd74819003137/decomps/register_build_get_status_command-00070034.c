
void register_build_get_status_command(get_status_t *get_st,uint8_t asic,uint8_t reg)

{
  byte bVar1;
  FILE *__stream;
  uint8_t reg_local;
  uint8_t asic_local;
  get_status_t *get_st_local;
  FILE *pFile;
  
  if (get_st == (get_status_t *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Invalid parameter.\n","register.c",0x33a,
                "register_build_get_status_command");
      }
      fclose(__stream);
    }
  }
  else {
    memset(get_st,0,5);
    get_st->v[0] = get_st->v[0] & 0xf0 | 2;
    get_st->v[0] = get_st->v[0] & 0xef;
    get_st->v[0] = get_st->v[0] & 0x1f | 0x40;
    (get_st->u)._Length = '\x05';
    (get_st->u)._ADDR = asic * dev->addrInterval;
    (get_st->u)._REGADDR = reg;
    bVar1 = CRC5(get_st->v,' ');
    get_st->v[4] = get_st->v[4] & 0xe0 | bVar1 & 0x1f;
  }
  return;
}

