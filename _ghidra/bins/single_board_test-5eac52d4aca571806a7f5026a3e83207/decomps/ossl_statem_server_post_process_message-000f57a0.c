
undefined4 ossl_statem_server_post_process_message(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x40) == 0x14) {
    uVar1 = tls_post_process_client_hello();
    return uVar1;
  }
  if (*(int *)(param_1 + 0x40) == 0x1c) {
    uVar1 = tls_post_process_client_key_exchange();
    return uVar1;
  }
  ossl_statem_fatal(param_1,0x50,0x259,0x44,"ssl/statem/statem_srvr.c",0x4d7);
  return 0;
}

