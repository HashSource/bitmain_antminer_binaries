
void set_special_nonce_rate(eeprom_v1 *ctx,config_ctx *conf)

{
  byte bVar1;
  size_t __n;
  char *pcVar2;
  config_ctx *conf_local;
  eeprom_v1 *ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  int ftlen;
  uint bin;
  
  __n = strlen((char *)((ctx->data).field_2.raw + 0x3b));
  bVar1 = (ctx->data).field_2.raw[0x48];
  memcpy(ft,(void *)((int)&(ctx->data).field_2 + 0x3b),__n);
  sprintf(ft + __n,"-%d",(uint)bVar1);
  pcVar2 = strstr(ft,"F1V01B2C1-4");
  if ((((((pcVar2 != (char *)0x0) || (pcVar2 = strstr(ft,"F1V01B3C2-2"), pcVar2 != (char *)0x0)) ||
        (pcVar2 = strstr(ft,"F1V01B4C2-1"), pcVar2 != (char *)0x0)) ||
       ((pcVar2 = strstr(ft,"F1V01B4C2-2"), pcVar2 != (char *)0x0 ||
        (pcVar2 = strstr(ft,"F1V01B5C1-1"), pcVar2 != (char *)0x0)))) ||
      ((pcVar2 = strstr(ft,"F1V01B1C2-1"), pcVar2 != (char *)0x0 ||
       ((pcVar2 = strstr(ft,"F1V01B1C2-2"), pcVar2 != (char *)0x0 ||
        (pcVar2 = strstr(ft,"F1V01B1C2-3"), pcVar2 != (char *)0x0)))))) ||
     (pcVar2 = strstr(ft,"F1V01B2C2-1"), pcVar2 != (char *)0x0)) {
    (conf->standard).nonce_rate = 0x26ca;
    (conf->standard).asic_nonce_rate = 0x25b2;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : specail set ft:%s, set nonce_rate[%d], asic_nonce_rate[%d]\n",
           "set_special_nonce_rate",ft,(conf->standard).nonce_rate,(conf->standard).asic_nonce_rate)
    ;
    snprintf(tmp1,0x100,"specail set ft:%s, set nonce_rate[%d], asic_nonce_rate[%d]",ft,
             (conf->standard).nonce_rate,(conf->standard).asic_nonce_rate);
    log_to_file(tmp1,time_stamp);
  }
  pcVar2 = strstr(ft,"F1V01B5C1-4");
  if (pcVar2 != (char *)0x0) {
    (conf->standard).nonce_rate = 0x2616;
    (conf->standard).asic_nonce_rate = 0x25b2;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : specail set ft:%s, set nonce_rate[%d], asic_nonce_rate[%d]\n",
           "set_special_nonce_rate",ft,(conf->standard).nonce_rate,(conf->standard).asic_nonce_rate)
    ;
    snprintf(tmp1,0x100,"specail set ft:%s, set nonce_rate[%d], asic_nonce_rate[%d]",ft,
             (conf->standard).nonce_rate,(conf->standard).asic_nonce_rate);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

