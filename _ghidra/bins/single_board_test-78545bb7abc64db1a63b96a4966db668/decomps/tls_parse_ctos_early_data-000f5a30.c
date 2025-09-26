
undefined4 tls_parse_ctos_early_data(int param_1,int param_2)

{
  if (*(int *)(param_2 + 4) != 0) {
    ossl_statem_fatal(param_1,0x32,0x238,0x6e,"ssl/statem/extensions_srvr.c",0x3f0);
    return 0;
  }
  if (*(int *)(param_1 + 0x44c) == 0) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x2f,0x238,0x6e,"ssl/statem/extensions_srvr.c",0x3f6);
  return 0;
}

