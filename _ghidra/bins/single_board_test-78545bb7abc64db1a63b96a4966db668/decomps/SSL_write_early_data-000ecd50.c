
int SSL_write_early_data(SSL *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  void *extraout_r3;
  void *extraout_r3_00;
  uint uVar3;
  void *pvVar4;
  undefined1 auStack_24 [8];
  
  pvVar4 = param_1->msg_callback_arg;
  switch(pvVar4) {
  case (void *)0x0:
    if (((param_1->in_handshake != 0) || (iVar2 = SSL_in_before(), iVar2 == 0)) ||
       (((param_1[2].tlsext_ticket_expected == 0 ||
         (*(int *)(param_1[2].tlsext_ticket_expected + 0x1e0) == 0)) && (param_1[3].type == 0)))) {
      iVar2 = 0x7e8;
      goto LAB_000ece2a;
    }
  case (void *)0x1:
    param_1->msg_callback_arg = (void *)0x2;
    iVar1 = SSL_connect(param_1);
    iVar2 = iVar1;
    pvVar4 = extraout_r3;
    if (iVar1 < 1) {
      pvVar4 = (void *)0x1;
      iVar2 = 0;
    }
    if (0 < iVar1) {
switchD_000ecd64_caseD_3:
      uVar3 = param_1[3].new_session;
      param_1->msg_callback_arg = &DAT_00000004;
      param_1[3].new_session = uVar3 & 0xfffffffe;
      iVar2 = SSL_write_ex(param_1,param_2,param_3,auStack_24);
      param_1[3].new_session = uVar3 & 1 | param_1[3].new_session;
      if (iVar2 == 0) {
        param_1->msg_callback_arg = (void *)0x3;
        return 0;
      }
      param_1->msg_callback_arg = &DAT_00000005;
      goto switchD_000ecd64_caseD_5;
    }
    param_1->msg_callback_arg = pvVar4;
    break;
  default:
    iVar2 = 0x81e;
LAB_000ece2a:
    ERR_put_error(0x14,0x20e,0x42,"ssl/ssl_lib.c",iVar2);
    return 0;
  case (void *)0x3:
    goto switchD_000ecd64_caseD_3;
  case (void *)0x5:
switchD_000ecd64_caseD_5:
    iVar2 = statem_flush(param_1);
    pvVar4 = extraout_r3_00;
    if (iVar2 == 1) {
      pvVar4 = (void *)0x3;
      *param_4 = param_3;
    }
    if (iVar2 == 1) {
      param_1->msg_callback_arg = pvVar4;
      iVar2 = 1;
    }
    else {
      iVar2 = 0;
    }
    break;
  case (void *)0xa:
  case (void *)0xc:
    param_1->msg_callback_arg = &DAT_00000006;
    iVar2 = SSL_write_ex(param_1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      BIO_ctrl(param_1->rbio,0xb,0,(void *)0x0);
    }
    param_1->msg_callback_arg = pvVar4;
    return iVar2;
  }
  return iVar2;
}

