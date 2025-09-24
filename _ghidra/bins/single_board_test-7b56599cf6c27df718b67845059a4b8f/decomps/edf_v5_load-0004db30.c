
int edf_v5_load(edf_ctx_p ctx,uint8_t *src,size_t len,int flag)

{
  byte bVar1;
  _Bool _Var2;
  uint8_t uVar3;
  uint uVar4;
  int iVar5;
  uint32_t uVar6;
  void *pvVar7;
  uint32_t *puVar8;
  int flag_local;
  size_t len_local;
  uint8_t *src_local;
  edf_ctx_p ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t buf [256];
  uint8_t sweep_info_crc;
  uint8_t param_info_crc;
  uint8_t board_info_crc;
  uint8_t *src_p;
  uint8_t *dst_p;
  edf_v5_priv *priv_ctx;
  char *errmsg;
  int ret;
  
  ret = 0;
  pvVar7 = ctx->priv;
  bVar1 = *src;
  uVar4 = edf_v5_version_get(ctx);
  if (bVar1 != uVar4) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    bVar1 = *src;
    iVar5 = edf_v5_version_get(ctx);
    printf("%s : version invalid %d!=%d\n","edf_v5_load",(uint)bVar1,iVar5);
    bVar1 = *src;
    iVar5 = edf_v5_version_get(ctx);
    snprintf(tmp1,0x100,"version invalid %d!=%d",(uint)bVar1,iVar5);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  uVar6 = edf_v5_capability(ctx);
  if ((flag & uVar6) == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : flag invalid\n","edf_v5_load");
    builtin_strncpy(tmp1,"flag invalid",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 2U) != 0) && (len < 0x62)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : len invalid\n","edf_v5_load");
    builtin_strncpy(tmp1,"len invalid",0xc);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 4U) != 0) && (len < 0x72)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : len invalid\n","edf_v5_load");
    builtin_strncpy(tmp1,"len invalid",0xc);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (((flag & 8U) != 0) && (len < 0xfa)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : len invalid\n","edf_v5_load");
    builtin_strncpy(tmp1,"len invalid",0xc);
    log_to_file(tmp1,time_stamp);
    return -1;
  }
  if (0x100 < len) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : len too large, should less than 256\n","edf_v5_load");
    builtin_strncpy(tmp1,"len too large, should less than 256",0x24);
    log_to_file(tmp1,time_stamp);
  }
  *(uint8_t *)((int)pvVar7 + 1) = src[1];
  memcpy(buf,src,len);
  if ((flag & 2U) != 0) {
    puVar8 = (uint32_t *)(buf + 2);
    memcpy(puVar8,src + 2,0x60);
    _Var2 = data_dec(puVar8,0x60,*(byte *)((int)pvVar7 + 1) >> 4,*(byte *)((int)pvVar7 + 1) & 0xf);
    if (!_Var2) {
      errmsg = "DEC 1ST REGION";
      ret = -1;
      goto LAB_0004e0e8;
    }
    uVar3 = CRC5_long(buf,0x308);
    if (uVar3 != buf[0x61]) {
      errmsg = "CRC 1ST REGION";
      ret = -1;
      goto LAB_0004e0e8;
    }
    memcpy((void *)((int)pvVar7 + 2),puVar8,0x60);
    if (*(char *)((int)pvVar7 + 0x5f) != '\x01') {
      errmsg = "PT1 test NOT pass, redo it";
      ret = -1;
      goto LAB_0004e0e8;
    }
    ret = 2;
  }
  if ((flag & 4U) != 0) {
    puVar8 = (uint32_t *)(buf + 0x62);
    memcpy(puVar8,src + 0x62,0x10);
    _Var2 = data_dec(puVar8,0x10,*(byte *)((int)pvVar7 + 1) >> 4,*(byte *)((int)pvVar7 + 1) & 0xf);
    if (!_Var2) {
      errmsg = "DEC 2ND REGION";
      goto LAB_0004e0e8;
    }
    uVar3 = CRC5_long(buf + 0x62,0x78);
    if (uVar3 != buf[0x71]) {
      errmsg = "CRC 2ND REGION";
      goto LAB_0004e0e8;
    }
    memcpy((void *)((int)pvVar7 + 0x62),puVar8,0x10);
    if (*(char *)((int)pvVar7 + 0x6c) != '\x01') {
      errmsg = "PT2 test NOT pass, redo it";
      goto LAB_0004e0e8;
    }
    ret = ret | 4;
  }
  if ((flag & 8U) == 0) {
    return ret;
  }
  puVar8 = (uint32_t *)(buf + 0x72);
  memcpy(puVar8,src + 0x72,0x88);
  _Var2 = data_dec(puVar8,0x88,*(byte *)((int)pvVar7 + 1) >> 4,*(byte *)((int)pvVar7 + 1) & 0xf);
  if (_Var2) {
    uVar3 = CRC5_long(buf + 0x72,0x438);
    if (uVar3 == buf[0xf9]) {
      memcpy((void *)((int)pvVar7 + 0x72),puVar8,0x88);
      if (*(char *)((int)pvVar7 + 0xf7) == '\x01') {
        return ret | 8;
      }
      errmsg = "sweep NOT pass, redo it";
    }
    else {
      errmsg = "CRC 3RD REGION";
    }
  }
  else {
    errmsg = "DEC 3ND REGION";
  }
LAB_0004e0e8:
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : EEPROM error: %s\n","edf_v5_load",errmsg);
  snprintf(tmp1,0x100,"EEPROM error: %s",errmsg);
  log_to_file(tmp1,time_stamp);
  return ret;
}

