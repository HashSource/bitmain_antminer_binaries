
undefined4 ossl_statem_server_process_message(int param_1)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0x14:
    uVar1 = tls_process_client_hello();
    return uVar1;
  default:
    ossl_statem_fatal(param_1,0x50,0x25b,0x44,"ssl/statem/statem_srvr.c",0x4a7);
    return 0;
  case 0x1b:
    uVar1 = tls_process_client_certificate();
    return uVar1;
  case 0x1c:
    uVar1 = tls_process_client_key_exchange();
    return uVar1;
  case 0x1d:
    uVar1 = tls_process_cert_verify();
    return uVar1;
  case 0x1e:
    uVar1 = tls_process_next_proto();
    return uVar1;
  case 0x1f:
    uVar1 = tls_process_change_cipher_spec();
    return uVar1;
  case 0x20:
    uVar1 = tls_process_finished();
    return uVar1;
  case 0x2c:
    uVar1 = tls_process_key_update();
    return uVar1;
  case 0x31:
    uVar1 = tls_process_end_of_early_data();
    return uVar1;
  }
}

