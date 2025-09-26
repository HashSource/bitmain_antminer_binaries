
int edf_v6_region_1_encode(edf_ctx_p ctx,char *dst,size_t *len,size_t *offset)

{
  uint8_t uVar1;
  _Bool _Var2;
  uint8_t *pdata;
  int iVar3;
  size_t *offset_local;
  size_t *len_local;
  char *dst_local;
  edf_ctx_p ctx_local;
  char time_stamp [48];
  char tmp1 [2048];
  char src [256];
  edf_v6_priv *priv_ctx;
  
  pdata = (uint8_t *)ctx->priv;
  if (*len < 0x62) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: INPUT too short %u<%u\n","edf_v6_region_1_encode",*len,0x62);
    snprintf(tmp1,0x800,"INPUT too short %u<%u",*len,0x62);
    log_to_file(tmp1,time_stamp);
    iVar3 = -1;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: BOARD_CRC_DATA_LEN=%d\n","edf_v6_region_1_encode",0x61);
    snprintf(tmp1,0x800,"BOARD_CRC_DATA_LEN=%d",0x61);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: BOARD_ENC_DATA_START=%d\n","edf_v6_region_1_encode",2);
    snprintf(tmp1,0x800,"BOARD_ENC_DATA_START=%d",2);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: BOARD_ENC_DATA_LEN=%d\n","edf_v6_region_1_encode",0x60);
    snprintf(tmp1,0x800,"BOARD_ENC_DATA_LEN=%d",0x60);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PARAM_CRC_DATA_START=%d\n","edf_v6_region_1_encode",0x62);
    snprintf(tmp1,0x800,"PARAM_CRC_DATA_START=%d",0x62);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PARAM_CRC_DATA_LEN=%d\n","edf_v6_region_1_encode",0xf);
    snprintf(tmp1,0x800,"PARAM_CRC_DATA_LEN=%d",0xf);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PARAM_ENC_DATA_START=%d\n","edf_v6_region_1_encode",0x62);
    snprintf(tmp1,0x800,"PARAM_ENC_DATA_START=%d",0x62);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PARAM_ENC_DATA_LEN=%d\n","edf_v6_region_1_encode",0x10);
    snprintf(tmp1,0x800,"PARAM_ENC_DATA_LEN=%d",0x10);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: SWEEP_CRC_DATA_START=%d\n","edf_v6_region_1_encode",0x72);
    snprintf(tmp1,0x800,"SWEEP_CRC_DATA_START=%d",0x72);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: SWEEP_CRC_DATA_LEN=%d\n","edf_v6_region_1_encode",0x87);
    snprintf(tmp1,0x800,"SWEEP_CRC_DATA_LEN=%d",0x87);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: SWEEP_ENC_DATA_START=%d\n","edf_v6_region_1_encode",0x72);
    snprintf(tmp1,0x800,"SWEEP_ENC_DATA_START=%d",0x72);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: SWEEP_ENC_DATA_LEN=%d\n","edf_v6_region_1_encode",0x88);
    snprintf(tmp1,0x800,"SWEEP_ENC_DATA_LEN=%d",0x88);
    log_to_file(tmp1,time_stamp);
    uVar1 = CRC5_long(pdata,0x308);
    pdata[0x61] = uVar1;
    memcpy(src,pdata + 2,0x60);
    _Var2 = data_enc((uint32_t *)src,0x60,pdata[1] >> 4,pdata[1] & 0xf);
    if (_Var2) {
      memcpy(dst,pdata,2);
      memcpy(dst + 2,src,0x60);
      *len = 0x62;
      *offset = 0;
      iVar3 = 0;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: %s: data_enc error\n","edf_v6_region_1_encode","edf_v6_region_1_encode");
      snprintf(tmp1,0x800,"%s: data_enc error","edf_v6_region_1_encode");
      log_to_file(tmp1,time_stamp);
      iVar3 = -1;
    }
  }
  return iVar3;
}

