
undefined4 ossl_statem_client_post_process_message(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x40) != 7) && (*(int *)(param_1 + 0x40) != 0x27)) {
    ossl_statem_fatal(param_1,0x50,0x251,0x44,"ssl/statem/statem_clnt.c",0x442);
    return 0;
  }
  uVar1 = tls_prepare_client_certificate(param_1);
  return uVar1;
}

