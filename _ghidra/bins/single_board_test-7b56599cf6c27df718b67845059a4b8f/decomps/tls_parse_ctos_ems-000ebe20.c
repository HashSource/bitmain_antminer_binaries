
undefined4 tls_parse_ctos_ems(int param_1,int param_2)

{
  if (*(int *)(param_2 + 4) == 0) {
    **(uint **)(param_1 + 0x7c) = **(uint **)(param_1 + 0x7c) | 0x200;
    return 1;
  }
  ossl_statem_fatal(param_1,0x32,0x23a,0x6e,"ssl/statem/extensions_srvr.c",0x3e1);
  return 0;
}

