
void edf_v5_destroy(eeprom_data_format_t *ctx)

{
  eeprom_data_format_t *ctx_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  if ((ctx == (eeprom_data_format_t *)0x0) || (ctx->priv == (void *)0x0)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: edf_v5_destroy: input arg wrong\n","edf_v5_destroy");
    builtin_strncpy(tmp1,"edf_v5_destroy: input arg wrong",0x20);
    log_to_file(tmp1,time_stamp);
  }
  else {
    free(ctx->priv);
    free(ctx);
  }
  return;
}

