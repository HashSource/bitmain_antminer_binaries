
undefined4 tls_parse_ctos_post_handshake_auth(int param_1,int param_2)

{
  if (*(int *)(param_2 + 4) == 0) {
    *(undefined4 *)(param_1 + 0x5f4) = 2;
    return 1;
  }
  ossl_statem_fatal(param_1,0x32,0x26c,0x116,"ssl/statem/extensions_srvr.c",0x510);
  return 0;
}

