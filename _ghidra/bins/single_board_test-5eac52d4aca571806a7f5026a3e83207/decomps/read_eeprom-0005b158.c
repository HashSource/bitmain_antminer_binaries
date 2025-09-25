
int read_eeprom(int chain,eeprom_v1 **ctx)

{
  _Bool _Var1;
  int iVar2;
  eeprom_v1 **ctx_local;
  int chain_local;
  char time_stamp [48];
  char tmp1 [256];
  
  eeprom_v1_init(&read_eeprom::eeprom_ctx,(uint8_t)chain,read_eeprom::eeprom_nonce);
  iVar2 = (*read_eeprom::eeprom_ctx.version_retrieve)(&read_eeprom::eeprom_ctx);
  if ((((iVar2 == 0) &&
       (iVar2 = (*read_eeprom::eeprom_ctx.board_name_retrieve)(&read_eeprom::eeprom_ctx), iVar2 == 0
       )) && (iVar2 = (*read_eeprom::eeprom_ctx.pt1_retrieve)(&read_eeprom::eeprom_ctx), iVar2 == 0)
      ) && (((_Var1 = (*read_eeprom::eeprom_ctx.is_version_available)(&read_eeprom::eeprom_ctx),
             _Var1 && (_Var1 = (*read_eeprom::eeprom_ctx.is_board_name_available)
                                         (&read_eeprom::eeprom_ctx), _Var1)) &&
            (_Var1 = (*read_eeprom::eeprom_ctx.is_pt1_available)(&read_eeprom::eeprom_ctx), _Var1)))
     ) {
    iVar2 = (*read_eeprom::eeprom_ctx.pt2_retrieve)(&read_eeprom::eeprom_ctx);
    if (iVar2 != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 retrieve failed\n","read_eeprom");
      builtin_strncpy(tmp1,"pt2 retrieve failed",0x14);
      log_to_file(tmp1,time_stamp);
    }
    iVar2 = (*read_eeprom::eeprom_ctx.sweep_retrieve)(&read_eeprom::eeprom_ctx);
    if (iVar2 != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 retrieve failed\n","read_eeprom");
      builtin_strncpy(tmp1,"pt2 retrieve failed",0x14);
      log_to_file(tmp1,time_stamp);
    }
    *ctx = &read_eeprom::eeprom_ctx;
    iVar2 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : load eeprom failed\n","read_eeprom");
    builtin_strncpy(tmp1,"load eeprom fail",0x10);
    tmp1[0x10] = 'e';
    tmp1[0x11] = 'd';
    tmp1[0x12] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  return iVar2;
}

