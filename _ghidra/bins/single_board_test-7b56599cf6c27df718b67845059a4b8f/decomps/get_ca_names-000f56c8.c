
stack_st_X509_NAME *
get_ca_names(SSL *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  stack_st_X509_NAME *psVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined8 uVar2;
  
  if (((param_1->in_handshake != 0) &&
      (psVar1 = SSL_get_client_CA_list(param_1), param_2 = extraout_r1, param_3 = extraout_r2,
      psVar1 != (stack_st_X509_NAME *)0x0)) &&
     (uVar2 = OPENSSL_sk_num(), param_2 = (undefined4)((ulonglong)uVar2 >> 0x20),
     param_3 = extraout_r2_00, (int)uVar2 != 0)) {
    return psVar1;
  }
  psVar1 = (stack_st_X509_NAME *)SSL_get0_CA_list(param_1,param_2,param_3,param_4);
  return psVar1;
}

