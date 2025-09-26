
ssl3_state_st * ossl_statem_server_read_transition(SSL *param_1,int param_2)

{
  int iVar1;
  ssl3_state_st *psVar2;
  BIO *b;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  bool bVar6;
  
  pvVar3 = (void *)(*(uint *)(((int *)param_1->type)[0x19] + 0x30) & 8);
  if (pvVar3 != (void *)0x0) {
    psVar2 = (ssl3_state_st *)param_1->init_msg;
    switch(psVar2) {
    case (ssl3_state_st *)0x0:
    case (ssl3_state_st *)0x1:
    case (ssl3_state_st *)0x15:
      goto switchD_00100ee4_caseD_0;
    case (ssl3_state_st *)0x1a:
switchD_00100ee4_caseD_1a:
      if (param_2 == 0x10) {
        if (*(int *)(param_1->mac_flags + 0x244) == 0) {
LAB_00100fce:
          param_1->init_msg = (void *)0x1c;
          return (ssl3_state_st *)0x1;
        }
        if (param_1->version == 0x300) {
          if ((*(uint *)&param_1[2].next_proto_negotiated_len & 3) == 3) {
            ossl_statem_fatal(param_1,0x28,0x1a2,199,"ssl/statem/statem_srvr.c",200);
            return (ssl3_state_st *)0x0;
          }
          goto LAB_00100fce;
        }
        goto switchD_00100ee4_caseD_2;
      }
      iVar1 = *(int *)(param_1->mac_flags + 0x244);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      if (param_2 != 0xb) {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        param_1->init_msg = (void *)0x1b;
        return (ssl3_state_st *)0x1;
      }
      break;
    case (ssl3_state_st *)0x1b:
switchD_00100ee4_caseD_1b:
      if (param_2 == 0x10) goto LAB_00100fce;
      break;
    case (ssl3_state_st *)0x1c:
switchD_00100ee4_caseD_1c:
      psVar2 = *(ssl3_state_st **)(param_1[2].tlsext_ticket_expected + 0x19c);
      if ((psVar2 == (ssl3_state_st *)0x0) || (psVar2 = param_1->s3, psVar2 != (ssl3_state_st *)0x0)
         ) goto switchD_00100ee4_caseD_1d;
      bVar6 = param_2 == 0xf;
      if (bVar6) {
        pvVar3 = (void *)0x1d;
      }
      if (bVar6) {
        param_1->init_msg = pvVar3;
        return (ssl3_state_st *)(uint)bVar6;
      }
      break;
    case (ssl3_state_st *)0x1d:
    case (ssl3_state_st *)0x24:
switchD_00100ee4_caseD_1d:
      pvVar3 = (void *)0x101;
      if (param_2 == 0x101) {
        pvVar3 = (void *)0x1f;
        psVar2 = (ssl3_state_st *)0x1;
      }
      if (param_2 == 0x101) {
        param_1->init_msg = pvVar3;
        return psVar2;
      }
      goto switchD_00100ee4_caseD_2;
    case (ssl3_state_st *)0x1e:
switchD_00100ee4_caseD_1e:
      if (param_2 == 0x14) {
        pvVar3 = (void *)0x20;
        psVar2 = (ssl3_state_st *)0x1;
      }
      if (param_2 == 0x14) {
        param_1->init_msg = pvVar3;
        return psVar2;
      }
      break;
    case (ssl3_state_st *)0x1f:
switchD_00100ee4_caseD_1f:
      psVar2 = *(ssl3_state_st **)(param_1->mac_flags + 0x33c);
      if (psVar2 == (ssl3_state_st *)0x0) goto switchD_00100ee4_caseD_1e;
      if (param_2 == 0x43) {
        pvVar3 = (void *)0x1e;
        psVar2 = (ssl3_state_st *)0x1;
      }
      if (param_2 == 0x43) {
        param_1->init_msg = pvVar3;
        return psVar2;
      }
    }
switchD_00100e4a_caseD_2:
    if (pvVar3 != (void *)0x0 && param_2 == 0x101) {
      param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
      param_1->bbio = (BIO *)0x3;
      b = SSL_get_rbio(param_1);
      BIO_clear_flags(b,0xf);
      BIO_set_flags(b,9);
      return (ssl3_state_st *)0x0;
    }
    goto switchD_00100ee4_caseD_2;
  }
  iVar1 = *(int *)param_1->type;
  iVar5 = iVar1 + -0x10000;
  if (iVar5 != 0) {
    iVar5 = 1;
  }
  if (iVar1 < 0x304) {
    iVar5 = 0;
  }
  psVar2 = (ssl3_state_st *)param_1->init_msg;
  if (iVar5 == 0) {
    switch(psVar2) {
    case (ssl3_state_st *)0x0:
    case (ssl3_state_st *)0x1:
    case (ssl3_state_st *)0x15:
      goto switchD_00100ee4_caseD_0;
    default:
      goto switchD_00100ee4_caseD_2;
    case (ssl3_state_st *)0x1a:
      goto switchD_00100ee4_caseD_1a;
    case (ssl3_state_st *)0x1b:
      goto switchD_00100ee4_caseD_1b;
    case (ssl3_state_st *)0x1c:
      goto switchD_00100ee4_caseD_1c;
    case (ssl3_state_st *)0x1d:
    case (ssl3_state_st *)0x24:
      goto switchD_00100ee4_caseD_1d;
    case (ssl3_state_st *)0x1e:
      goto switchD_00100ee4_caseD_1e;
    case (ssl3_state_st *)0x1f:
      goto switchD_00100ee4_caseD_1f;
    }
  }
  pvVar4 = (void *)0x0;
  switch(psVar2) {
  case (ssl3_state_st *)0x1:
    pvVar3 = param_1->msg_callback_arg;
    if (pvVar3 == (void *)0xb) goto switchD_00100ee4_caseD_2;
    if (param_2 != 0xb) {
      if (param_2 == 0x18) {
        pvVar3 = (void *)0x2c;
      }
      if (param_2 == 0x18) {
        param_1->init_msg = pvVar3;
        return (ssl3_state_st *)0x1;
      }
      goto switchD_00100ee4_caseD_2;
    }
    if (param_1[3].tlsext_status_type != 4) goto switchD_00100ee4_caseD_2;
    goto LAB_0010100e;
  default:
    goto switchD_00100e4a_caseD_2;
  case (ssl3_state_st *)0x1b:
    pvVar4 = *(void **)(param_1[2].tlsext_ticket_expected + 0x19c);
    if (pvVar4 != (void *)0x0) {
      if (param_2 == 0xf) {
        pvVar4 = (void *)0x1d;
      }
      if (param_2 == 0xf) {
        param_1->init_msg = pvVar4;
        return (ssl3_state_st *)0x1;
      }
      goto switchD_00100ee4_caseD_2;
    }
    break;
  case (ssl3_state_st *)0x1d:
    break;
  case (ssl3_state_st *)0x24:
  case (ssl3_state_st *)0x31:
    goto switchD_00100e4a_caseD_24;
  case (ssl3_state_st *)0x2e:
    if (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1) {
      pvVar3 = (void *)0x1;
      if (param_2 == 1) {
        pvVar3 = (void *)0x14;
      }
      if (param_2 == 1) {
        param_1->init_msg = pvVar3;
        return (ssl3_state_st *)0x1;
      }
      goto switchD_00100ee4_caseD_2;
    }
    if (param_1[3].psk_server_callback == (_func_3296 *)0x2) {
      pvVar3 = (void *)0x2;
      if (param_2 == 5) {
        pvVar3 = (void *)0x31;
      }
      if (param_2 == 5) {
        param_1->init_msg = pvVar3;
        return (ssl3_state_st *)0x1;
      }
      goto switchD_00100ee4_caseD_2;
    }
switchD_00100e4a_caseD_24:
    pvVar4 = *(void **)(param_1->mac_flags + 0x244);
    if (pvVar4 != (void *)0x0) {
      if (param_2 == 0xb) {
LAB_0010100e:
        param_1->init_msg = (void *)0x1b;
        return (ssl3_state_st *)0x1;
      }
      goto switchD_00100ee4_caseD_2;
    }
  }
  if (param_2 == 0x14) {
    pvVar4 = (void *)0x20;
  }
  if (param_2 == 0x14) {
    param_1->init_msg = pvVar4;
    return (ssl3_state_st *)0x1;
  }
switchD_00100ee4_caseD_2:
  ossl_statem_fatal(param_1,10,0x1a2,0xf4,"ssl/statem/statem_srvr.c",0x139);
  return (ssl3_state_st *)0x0;
switchD_00100ee4_caseD_0:
  if (param_2 == 1) {
    pvVar3 = (void *)0x14;
    psVar2 = (ssl3_state_st *)0x1;
  }
  if (param_2 == 1) {
    param_1->init_msg = pvVar3;
    return psVar2;
  }
  goto switchD_00100e4a_caseD_2;
}

