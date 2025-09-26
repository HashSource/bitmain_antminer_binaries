
int edf_v4_load(edf_ctx_p ctx,uint8_t *src,size_t len,int flag)

{
  _Bool _Var1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint32_t uVar5;
  void *pvVar6;
  uint32_t *puVar7;
  int flag_local;
  size_t len_local;
  uint8_t *src_local;
  edf_ctx_p ctx_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t buf [256];
  uint8_t sweep_info_crc;
  uint8_t param_info_crc;
  uint8_t board_info_crc;
  uint8_t *src_p;
  uint8_t *dst_p;
  edf_v4_priv *priv_ctx;
  char *errmsg;
  int ret;
  
  ret = 0;
  pvVar6 = ctx->priv;
  bVar2 = *src;
  uVar3 = edf_v4_version_get(ctx);
  if (bVar2 != uVar3) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    bVar2 = *src;
    iVar4 = edf_v4_version_get(ctx);
    printf("%s: version invalid %d!=%d\n","edf_v4_load",(uint)bVar2,iVar4);
    bVar2 = *src;
    iVar4 = edf_v4_version_get(ctx);
    snprintf(tmp1,0x800,"version invalid %d!=%d",(uint)bVar2,iVar4);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  uVar5 = edf_v4_capability(ctx);
  if ((flag & uVar5) == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: flag invalid\n","edf_v4_load");
    builtin_strncpy(tmp1,"flag invalid",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 2U) != 0) && (len < 0x62)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: region1 len invalid\n","edf_v4_load");
    builtin_strncpy(tmp1,"region1 len invalid",0x14);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 4U) != 0) && (len < 0x72)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: region2 len invalid\n","edf_v4_load");
    builtin_strncpy(tmp1,"region2 len invalid",0x14);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 8U) != 0) && (len < 0xfa)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: region3 len invalid\n","edf_v4_load");
    builtin_strncpy(tmp1,"region3 len invalid",0x14);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (0x100 < len) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: len too large, should less than 256\n","edf_v4_load");
    builtin_strncpy(tmp1,"len too large, should less than 256",0x24);
    log_to_file(tmp1,time_stamp);
  }
  *(uint8_t *)((int)pvVar6 + 1) = src[1];
  memcpy(buf,src,len);
  if ((flag & 2U) != 0) {
    puVar7 = (uint32_t *)(buf + 2);
    memcpy(puVar7,src + 2,0x60);
    _Var1 = data_dec(puVar7,0x60,*(byte *)((int)pvVar6 + 1) >> 4,*(byte *)((int)pvVar6 + 1) & 0xf);
    if (!_Var1) {
      errmsg = "DEC 1ST REGION";
      ret = -1;
      goto LAB_000870de;
    }
    bVar2 = CRC5_long(buf,0x308);
    if (bVar2 != buf[0x61]) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: region2 = %x,buf[BOARD_INFO_CRC_OFFSET] = %x\n\n","edf_v4_load",(uint)bVar2,
             (uint)buf[0x61]);
      snprintf(tmp1,0x800,"region2 = %x,buf[BOARD_INFO_CRC_OFFSET] = %x\n",(uint)bVar2,
               (uint)buf[0x61]);
      log_to_file(tmp1,time_stamp);
      errmsg = "CRC 1ST REGION";
      ret = -1;
      goto LAB_000870de;
    }
    memcpy((void *)((int)pvVar6 + 2),puVar7,0x60);
    if (*(char *)((int)pvVar6 + 0x5f) != '\x01') {
      errmsg = "PT1 test NOT pass, redo it";
      ret = -1;
      goto LAB_000870de;
    }
    ret = 2;
  }
  if ((flag & 4U) != 0) {
    puVar7 = (uint32_t *)(buf + 0x62);
    memcpy(puVar7,src + 0x62,0x10);
    _Var1 = data_dec(puVar7,0x10,*(byte *)((int)pvVar6 + 1) >> 4,*(byte *)((int)pvVar6 + 1) & 0xf);
    if (!_Var1) {
      errmsg = "DEC 2ND REGION";
      goto LAB_000870de;
    }
    bVar2 = CRC5_long(buf + 0x62,0x78);
    if (bVar2 != buf[0x71]) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: region2 = %x,buf[PARAM_INFO_CRC_OFFSET] = %x\n\n","edf_v4_load",(uint)bVar2,
             (uint)buf[0x71]);
      snprintf(tmp1,0x800,"region2 = %x,buf[PARAM_INFO_CRC_OFFSET] = %x\n",(uint)bVar2,
               (uint)buf[0x71]);
      log_to_file(tmp1,time_stamp);
      errmsg = "CRC 2ND REGION";
      goto LAB_000870de;
    }
    memcpy((void *)((int)pvVar6 + 0x62),puVar7,0x10);
    if (*(char *)((int)pvVar6 + 0x6c) != '\x01') {
      errmsg = "PT2 test NOT pass, redo it";
      goto LAB_000870de;
    }
    ret = ret | 4;
  }
  if ((flag & 8U) == 0) {
    return ret;
  }
  puVar7 = (uint32_t *)(buf + 0x72);
  memcpy(puVar7,src + 0x72,0x88);
  _Var1 = data_dec(puVar7,0x88,*(byte *)((int)pvVar6 + 1) >> 4,*(byte *)((int)pvVar6 + 1) & 0xf);
  if (_Var1) {
    bVar2 = CRC5_long(buf + 0x72,0x438);
    if (bVar2 == buf[0xf9]) {
      memcpy((void *)((int)pvVar6 + 0x72),puVar7,0x88);
      return ret | 8;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: region3 = %x,buf[BAD_ASIC_CRC_OFFSET] = %x\n\n","edf_v4_load",(uint)bVar2,
           (uint)buf[0xf9]);
    snprintf(tmp1,0x800,"region3 = %x,buf[BAD_ASIC_CRC_OFFSET] = %x\n",(uint)bVar2,(uint)buf[0xf9]);
    log_to_file(tmp1,time_stamp);
    errmsg = "CRC 3ND REGION";
  }
  else {
    errmsg = "DEC 3ND REGION";
  }
LAB_000870de:
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: EEPROM error: %s\n","edf_v4_load",errmsg);
  snprintf(tmp1,0x800,"EEPROM error: %s",errmsg);
  log_to_file(tmp1,time_stamp);
  return ret;
}

