
undefined4 ossl_statem_client_process_message(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  void *local_24;
  undefined1 *local_20;
  uint local_1c;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 2:
    uVar2 = dtls_process_hello_verify();
    break;
  case 3:
    uVar2 = tls_process_server_hello();
    break;
  case 4:
    uVar2 = tls_process_server_certificate();
    break;
  case 5:
    uVar2 = tls_process_cert_status();
    break;
  case 6:
    uVar2 = tls_process_key_exchange();
    break;
  case 7:
    uVar2 = tls_process_certificate_request();
    break;
  case 8:
    uVar2 = tls_process_server_done();
    break;
  case 9:
    uVar2 = tls_process_new_session_ticket();
    break;
  case 10:
    uVar2 = tls_process_change_cipher_spec();
    break;
  case 0xb:
    uVar2 = tls_process_finished();
    break;
  default:
    ossl_statem_fatal(param_1,0x50,0x252,0x44,"ssl/statem/statem_clnt.c",0x406);
    uVar2 = 0;
    break;
  case 0x26:
    local_24 = (void *)0x0;
    if ((uint)param_2[1] < 2) {
LAB_000f1c66:
      ossl_statem_fatal(param_1,0x32,0x1bc,0x9f,"ssl/statem/statem_clnt.c",0xe72);
    }
    else {
      puVar3 = (undefined1 *)*param_2;
      uVar4 = param_2[1] - 2;
      uVar5 = (uint)CONCAT11(*puVar3,puVar3[1]);
      if (uVar4 < uVar5) goto LAB_000f1c66;
      if (uVar5 != uVar4) goto LAB_000f1c66;
      *param_2 = puVar3 + 2 + uVar5;
      param_2[1] = 0;
      local_20 = puVar3 + 2;
      local_1c = uVar5;
      iVar1 = tls_collect_extensions(param_1,&local_20,0x400,&local_24,0,1);
      if ((iVar1 != 0) &&
         (iVar1 = tls_parse_all_extensions(param_1,0x400,local_24,0,0,1), iVar1 != 0)) {
        CRYPTO_free(local_24);
        return 3;
      }
    }
    CRYPTO_free(local_24);
    uVar2 = 0;
    break;
  case 0x27:
    uVar2 = tls_process_cert_verify();
    break;
  case 0x29:
    uVar2 = tls_process_hello_req();
    break;
  case 0x2d:
    uVar2 = tls_process_key_update();
  }
  return uVar2;
}

