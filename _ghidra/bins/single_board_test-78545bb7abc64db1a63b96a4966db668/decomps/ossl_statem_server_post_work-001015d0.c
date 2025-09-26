
/* WARNING: Type propagation algorithm not settling */

undefined4 ossl_statem_server_post_work(SSL *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 auStack_14 [4];
  
  param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
  switch(param_1->init_msg) {
  case (void *)0x13:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 3;
    }
    iVar1 = ssl3_init_finished_mac(param_1);
    break;
  default:
    goto LAB_00101608;
  case (void *)0x15:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 3;
    }
    if ((param_1->version != 0x100) && (iVar1 = ssl3_init_finished_mac(param_1), iVar1 == 0)) {
      return 0;
    }
    param_1[3].rstate = 1;
    return 2;
  case (void *)0x16:
    piVar2 = (int *)param_1->type;
    iVar1 = piVar2[0x19];
    if (*(int *)(iVar1 + 0x30) << 0x1c < 0) {
      return 2;
    }
    iVar3 = *piVar2;
    iVar5 = iVar3 + -0x10000;
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    if (iVar3 < 0x304) {
      iVar5 = 0;
    }
    if ((iVar5 != 0) && (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1)) {
      if (param_1[3].server << 0xb < 0) {
        return 2;
      }
      goto switchD_001015e2_caseD_1a;
    }
    if (iVar3 == 0x10000 || iVar3 < 0x304) {
      return 2;
    }
    if (param_1[3].server << 0xb < 0) {
      if (param_1[2].tlsext_debug_cb != (_func_3297 *)0x2) {
        return 2;
      }
      iVar1 = piVar2[0x19];
    }
    else if (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1) goto LAB_001017ee;
    goto LAB_00101690;
  case (void *)0x19:
    if (param_1[3].tlsext_status_type != 3) {
      return 2;
    }
  case (void *)0x1a:
switchD_001015e2_caseD_1a:
    iVar1 = statem_flush(param_1);
    if (iVar1 == 1) {
      return 2;
    }
    return 3;
  case (void *)0x21:
    piVar2 = __errno_location();
    piVar4 = (int *)param_1->type;
    *piVar2 = 0;
    if ((*(uint *)(piVar4[0x19] + 0x30) & 8) != 0) {
      return 2;
    }
    iVar1 = *piVar4;
    if (iVar1 == 0x10000 || iVar1 < 0x304) {
      return 2;
    }
    iVar1 = statem_flush(param_1);
    if (iVar1 == 1) {
      return 2;
    }
    iVar1 = SSL_get_error(param_1,0);
    if (iVar1 == 5) {
      if ((*piVar2 != 0x20) && (*piVar2 != 0x68)) {
        return 3;
      }
      param_1->bbio = (BIO *)0x1;
      return 2;
    }
    return 3;
  case (void *)0x23:
    if (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1) {
LAB_001017ee:
      iVar1 = statem_flush(param_1);
      if (iVar1 != 0) {
        return 2;
      }
      return 3;
    }
    piVar2 = (int *)param_1->type;
    iVar1 = piVar2[0x19];
    if (*(int *)(iVar1 + 0x30) << 0x1c < 0) goto LAB_001017be;
LAB_00101690:
    if (*piVar2 != 0x10000 && 0x303 < *piVar2) {
      iVar1 = (**(code **)(iVar1 + 8))(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(param_1->type + 100) + 0x10))(param_1,0xa2);
      if (iVar1 == 0) {
        return 0;
      }
      if ((param_1[3].psk_server_callback != (_func_3296 *)0x2) &&
         (iVar1 = (**(code **)(*(int *)(param_1->type + 100) + 0x10))(param_1,0xa1), iVar1 == 0)) {
        return 0;
      }
      param_1->msg_callback = (_func_3292 *)0x1;
      return 2;
    }
LAB_001017be:
    iVar1 = (**(code **)(iVar1 + 0x10))(param_1,0x22);
    if (iVar1 == 0) {
      return 0;
    }
    if (-1 < *(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c) {
      return 2;
    }
    dtls1_reset_seq_numbers(param_1,2);
    return 2;
  case (void *)0x24:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 3;
    }
    iVar1 = ((int *)param_1->type)[0x19];
    if ((*(uint *)(iVar1 + 0x30) & 8) != 0) {
      return 2;
    }
    iVar3 = *(int *)param_1->type;
    if (iVar3 == 0x10000 || iVar3 < 0x304) {
      return 2;
    }
    iVar1 = (**(code **)(iVar1 + 0xc))
                      (param_1,&param_1->tlsext_ecpointformatlist,&param_1->max_cert_list,0,
                       auStack_14);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)(param_1->type + 100) + 0x10))(param_1,0x122);
    break;
  case (void *)0x2a:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 3;
    }
    iVar1 = tls13_update_key(param_1,1);
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_00101608:
  return 2;
}

