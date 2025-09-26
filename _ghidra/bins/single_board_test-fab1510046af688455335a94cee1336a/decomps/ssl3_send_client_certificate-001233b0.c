
int ssl3_send_client_certificate(SSL *param_1)

{
  stack_st_X509_NAME *ca_dn;
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int extraout_r3;
  int iVar4;
  ssl3_state_st *psVar5;
  _func_3296 *p_Var6;
  ENGINE *e;
  X509 *local_18;
  EVP_PKEY *local_14 [2];
  
  iVar2 = param_1->state;
  local_18 = (X509 *)0x0;
  local_14[0] = (EVP_PKEY *)0x0;
  if (iVar2 == 0x1170) {
    pcVar3 = *(code **)(param_1->cert + 0x144);
    if (pcVar3 == (code *)0x0) {
LAB_00123402:
      iVar2 = ssl3_check_client_certificate(param_1);
      if (iVar2 != 0) goto LAB_0012340a;
      param_1->state = 0x1171;
      goto LAB_00123458;
    }
    iVar2 = (*pcVar3)(param_1,*(undefined4 *)(param_1->cert + 0x148));
    if (iVar2 < 0) goto LAB_00123530;
    iVar4 = extraout_r3;
    if (iVar2 != 0) {
      iVar4 = 1;
    }
    if (iVar2 != 0) {
      param_1->rwstate = iVar4;
      goto LAB_00123402;
    }
LAB_00123440:
    ssl3_send_alert(param_1,2,0x50);
    param_1->state = 5;
  }
  else {
    if (iVar2 == 0x1171) {
LAB_00123458:
      p_Var6 = param_1->psk_server_callback;
      e = *(ENGINE **)(p_Var6 + 0xfc);
      if (e == (ENGINE *)0x0) {
LAB_00123488:
        if (*(code **)(p_Var6 + 0x74) != (code *)0x0) {
          iVar2 = (**(code **)(p_Var6 + 0x74))(param_1,&local_18,local_14);
          goto LAB_00123498;
        }
        param_1->rwstate = 1;
        iVar2 = 0;
      }
      else {
        ca_dn = SSL_get_client_CA_list(param_1);
        iVar2 = ENGINE_load_ssl_client_cert
                          (e,param_1,ca_dn,&local_18,local_14,(stack_st_X509 **)0x0,(UI_METHOD *)0x0
                           ,(void *)0x0);
        if (iVar2 == 0) {
          p_Var6 = param_1->psk_server_callback;
          goto LAB_00123488;
        }
LAB_00123498:
        if (iVar2 < 0) {
LAB_00123530:
          param_1->rwstate = 4;
          return -1;
        }
        param_1->rwstate = 1;
        if (iVar2 == 1) {
          if ((local_14[0] == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
            ERR_put_error(0x14,0x97,0x6a,"s3_clnt.c",0xd41);
            iVar2 = 0;
          }
          else {
            param_1->state = 0x1171;
            iVar2 = SSL_use_certificate(param_1,local_18);
            if ((iVar2 != 0) && (iVar2 = SSL_use_PrivateKey(param_1,local_14[0]), iVar2 != 0)) {
              iVar2 = 1;
            }
          }
        }
      }
      if (local_18 != (X509 *)0x0) {
        X509_free(local_18);
      }
      if (local_14[0] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(local_14[0]);
      }
      if ((iVar2 != 0) && (iVar2 = ssl3_check_client_certificate(param_1), iVar2 != 0))
      goto LAB_0012340a;
      if (param_1->version == 0x300) {
        (param_1->s3->tmp).cert_req = 0;
        ssl3_send_alert(param_1,1,0x29);
        return 1;
      }
      psVar5 = param_1->s3;
      (psVar5->tmp).cert_req = 2;
LAB_0012340c:
      iVar2 = (psVar5->tmp).cert_req;
      param_1->state = 0x1173;
      if (iVar2 == 2) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined4 *)param_1->cert;
      }
      iVar2 = ssl3_output_cert_chain(param_1,uVar1);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0x97,0x44,"s3_clnt.c",0xd5d);
        iVar2 = 0;
        goto LAB_00123440;
      }
    }
    else if (iVar2 == 0x1172) {
LAB_0012340a:
      psVar5 = param_1->s3;
      goto LAB_0012340c;
    }
    iVar2 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
  }
  return iVar2;
}

