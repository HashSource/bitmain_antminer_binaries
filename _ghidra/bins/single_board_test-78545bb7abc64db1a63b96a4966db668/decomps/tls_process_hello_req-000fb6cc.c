
undefined4 tls_process_hello_req(SSL *param_1,int param_2)

{
  if (*(int *)(param_2 + 4) != 0) {
    ossl_statem_fatal(param_1,0x32,0x1fb,0x9f,"ssl/statem/statem_clnt.c",0xe52);
    return 0;
  }
  if (-1 < param_1[3].server << 1) {
    if (-1 < *(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c) {
      SSL_renegotiate_abbreviated(param_1);
      return 1;
    }
    SSL_renegotiate(param_1);
    return 1;
  }
  ssl3_send_alert(param_1,1,100);
  return 1;
}

