
int edf_v5_region_2_encode(edf_ctx_p ctx,char *dst,size_t *len,size_t *offset)

{
  uint8_t uVar1;
  _Bool _Var2;
  void *pvVar3;
  int iVar4;
  size_t *offset_local;
  size_t *len_local;
  char *dst_local;
  edf_ctx_p ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  edf_v5_priv *priv_ctx;
  
  pvVar3 = ctx->priv;
  if (*len < 0x10) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : INPUT too short %u<%u\n","edf_v5_region_2_encode",*len,0x10);
    snprintf(tmp1,0x100,"INPUT too short %u<%u",*len,0x10);
    log_to_file(tmp1,time_stamp);
    iVar4 = -1;
  }
  else {
    uVar1 = CRC5_long((uint8_t *)((int)pvVar3 + 0x62),0x78);
    *(uint8_t *)((int)pvVar3 + 0x71) = uVar1;
    memcpy(dst,(void *)((int)pvVar3 + 0x62),0x10);
    _Var2 = data_enc((uint32_t *)dst,0x10,*(byte *)((int)pvVar3 + 1) >> 4,
                     *(byte *)((int)pvVar3 + 1) & 0xf);
    if (_Var2) {
      *len = 0x10;
      *offset = 0x62;
      iVar4 = 0;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s: data_enc error\n","edf_v5_region_2_encode","edf_v5_region_2_encode");
      snprintf(tmp1,0x100,"%s: data_enc error","edf_v5_region_2_encode");
      log_to_file(tmp1,time_stamp);
      iVar4 = -1;
    }
  }
  return iVar4;
}

