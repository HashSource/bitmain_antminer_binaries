
int * ossl_statem_client_read_transition(SSL *param_1,int param_2)

{
  int *piVar1;
  BIO *b;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  EVP_CIPHER_CTX *pEVar6;
  void *pvVar7;
  
  piVar1 = (int *)param_1->type;
  puVar4 = (undefined1 *)(*(uint *)(piVar1[0x19] + 0x30) & 8);
  if (puVar4 == (undefined1 *)0x0) {
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)0x10000 || (int)piVar1 < 0x304) {
      pvVar7 = (void *)((int)param_1->init_msg + -1);
      switch(param_1->init_msg) {
      case (void *)0x1:
        goto switchD_000ef020_caseD_1;
      case (void *)0x3:
        goto switchD_000ef020_caseD_3;
      case (void *)0x4:
        goto switchD_000ef020_caseD_4;
      case (void *)0x5:
        goto switchD_000ef020_caseD_5;
      case (void *)0x6:
        goto switchD_000ef020_caseD_6;
      case (void *)0x7:
        goto switchD_000ef020_caseD_7;
      case (void *)0x9:
        goto switchD_000ef020_caseD_9;
      case (void *)0xa:
        goto switchD_000ef020_caseD_a;
      case (void *)0xc:
        goto switchD_000ef020_caseD_c;
      case (void *)0x12:
        goto switchD_000ef020_caseD_12;
      case (void *)0x2e:
        goto switchD_000ef020_caseD_2e;
      }
      goto switchD_000ef020_caseD_2;
    }
    pEVar6 = (EVP_CIPHER_CTX *)((int)param_1->init_msg + -1);
    switch(pEVar6) {
    case (EVP_CIPHER_CTX *)0x0:
      if (param_2 == 4) {
        pEVar6 = (EVP_CIPHER_CTX *)&DAT_00000009;
      }
      if (param_2 == 4) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      if (param_2 == 0x18) {
        pEVar6 = (EVP_CIPHER_CTX *)0x2d;
      }
      if (param_2 == 0x18) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      if ((param_2 == 0xd) && (param_1[3].tlsext_status_type == 1)) {
        param_1[3].tlsext_status_type = 4;
        iVar2 = tls13_restore_handshake_digest_for_pha(param_1);
        if (iVar2 != 0) {
LAB_000ef224:
          param_1->init_msg = &DAT_00000007;
          return (int *)0x1;
        }
        puVar4 = (undefined1 *)(*(uint *)(*(int *)(param_1->type + 100) + 0x30) & 8);
      }
      break;
    case (EVP_CIPHER_CTX *)0x2:
      if (param_2 == 8) {
        pEVar6 = (EVP_CIPHER_CTX *)0x26;
      }
      if (param_2 == 8) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      break;
    case (EVP_CIPHER_CTX *)0x3:
      if (param_2 == 0xf) {
        pEVar6 = (EVP_CIPHER_CTX *)0x27;
      }
      if (param_2 == 0xf) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      break;
    case (EVP_CIPHER_CTX *)0xb:
      if (param_2 == 2) {
        pEVar6 = (EVP_CIPHER_CTX *)0x3;
      }
      if (param_2 == 2) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      break;
    case (EVP_CIPHER_CTX *)0x25:
      pEVar6 = param_1->enc_write_ctx;
      if (pEVar6 != (EVP_CIPHER_CTX *)0x0) goto switchD_000eef5c_caseD_26;
      pEVar6 = (EVP_CIPHER_CTX *)0x0;
      if (param_2 == 0xd) goto LAB_000ef224;
    case (EVP_CIPHER_CTX *)0x6:
      if (param_2 == 0xb) {
        pEVar6 = (EVP_CIPHER_CTX *)&DAT_00000004;
      }
      if (param_2 == 0xb) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
      break;
    case (EVP_CIPHER_CTX *)0x26:
switchD_000eef5c_caseD_26:
      if (param_2 == 0x14) {
        pEVar6 = (EVP_CIPHER_CTX *)0xb;
      }
      if (param_2 == 0x14) {
        param_1->init_msg = pEVar6;
        return (int *)0x1;
      }
    }
    goto switchD_000eef5c_caseD_1;
  }
  pvVar7 = (void *)((int)param_1->init_msg + -1);
  switch(pvVar7) {
  case (void *)0x0:
switchD_000ef020_caseD_1:
    if (param_2 == 0) {
      param_1->init_msg = (void *)0x29;
      return (int *)0x1;
    }
    break;
  default:
    puVar4 = (undefined1 *)0x1;
    goto LAB_000ef0ac;
  case (void *)0x2:
switchD_000ef020_caseD_3:
    if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) goto switchD_000ef020_caseD_12;
    if (puVar4 != (undefined1 *)0x0) {
      puVar4 = (undefined1 *)0x1;
    }
    if (param_2 == 3) {
      uVar3 = (uint)puVar4 & 1;
    }
    else {
      uVar3 = 0;
    }
    if (uVar3 != 0) {
LAB_000ef152:
      param_1->init_msg = (void *)0x2;
      return (int *)0x1;
    }
    piVar1 = (int *)param_1->version;
    if ((0x300 < (int)piVar1) && (param_1[3].generate_session_id != (GEN_SESSION_CB)0x0)) {
      iVar2 = *(int *)(param_1[2].tlsext_ticket_expected + 0x1d0);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      if (param_2 != 0x101) {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        param_1->enc_write_ctx = (EVP_CIPHER_CTX *)0x1;
        param_1->init_msg = (void *)0xa;
        return (int *)0x1;
      }
    }
    iVar2 = *(int *)(param_1->mac_flags + 0x210);
    uVar3 = *(uint *)(iVar2 + 0x14);
    if ((uVar3 & 0x54) == 0) {
      if (param_2 == 0xb) {
        puVar4 = &DAT_00000004;
        piVar1 = (int *)0x1;
      }
      if (param_2 == 0xb) {
        param_1->init_msg = puVar4;
        return piVar1;
      }
      goto LAB_000ef0ac;
    }
    uVar5 = *(uint *)(iVar2 + 0x10);
    if ((uVar5 & 0x1a6) != 0) {
      if (param_2 == 0xc) goto LAB_000ef108;
      goto LAB_000ef0ac;
    }
    if ((uVar5 & 0x1c8) != 0 && param_2 == 0xc) goto LAB_000ef108;
    if (param_2 != 0xd) {
      if (param_2 == 0xe) goto LAB_000ef2c6;
      goto LAB_000ef0ac;
    }
    if ((0x300 < (int)piVar1) && ((int)(uVar3 << 0x1d) < 0)) goto switchD_000ef020_caseD_2;
    goto joined_r0x000ef18c;
  case (void *)0x3:
switchD_000ef020_caseD_4:
    pEVar6 = param_1[3].enc_read_ctx;
    if (pEVar6 != (EVP_CIPHER_CTX *)0x0) {
      pEVar6 = (EVP_CIPHER_CTX *)0x1;
    }
    if (param_2 != 0x16) {
      pEVar6 = (EVP_CIPHER_CTX *)0x0;
    }
    if (pEVar6 != (EVP_CIPHER_CTX *)0x0) {
      param_1->init_msg = &DAT_00000005;
      return (int *)0x1;
    }
  case (void *)0x4:
switchD_000ef020_caseD_5:
    uVar3 = *(uint *)(*(int *)(param_1->mac_flags + 0x210) + 0x10);
    if ((uVar3 & 0x1a6) != 0) {
      if (param_2 == 0xc) goto LAB_000ef108;
      break;
    }
    if ((uVar3 & 0x1c8) != 0 && param_2 == 0xc) {
LAB_000ef108:
      param_1->init_msg = &DAT_00000006;
      return (int *)0x1;
    }
switchD_000ef020_caseD_6:
    if (param_2 != 0xd) {
switchD_000ef020_caseD_7:
      if (param_2 == 0xe) {
LAB_000ef2c6:
        param_1->init_msg = (void *)0x8;
        return (int *)0x1;
      }
      break;
    }
    uVar3 = *(uint *)(*(int *)(param_1->mac_flags + 0x210) + 0x14);
    if ((param_1->version < 0x301) || (-1 < (int)(uVar3 << 0x1d))) {
joined_r0x000ef18c:
      if ((uVar3 & 0x50) == 0) {
        param_1->init_msg = &DAT_00000007;
        return (int *)0x1;
      }
    }
    goto switchD_000ef020_caseD_2;
  case (void *)0x5:
    goto switchD_000ef020_caseD_6;
  case (void *)0x6:
    goto switchD_000ef020_caseD_7;
  case (void *)0x8:
switchD_000ef020_caseD_9:
    pvVar7 = (void *)0x101;
    if (param_2 == 0x101) {
      pvVar7 = (void *)0xa;
      piVar1 = (int *)0x1;
    }
    if (param_2 == 0x101) {
      param_1->init_msg = pvVar7;
      return piVar1;
    }
    goto switchD_000ef020_caseD_2;
  case (void *)0x9:
switchD_000ef020_caseD_a:
    if (param_2 == 0x14) {
      pvVar7 = (void *)0xb;
      piVar1 = (int *)0x1;
    }
    if (param_2 == 0x14) {
      param_1->init_msg = pvVar7;
      return piVar1;
    }
    break;
  case (void *)0xb:
switchD_000ef020_caseD_c:
    if (param_2 == 2) {
LAB_000ef16a:
      param_1->init_msg = (void *)0x3;
      return (int *)0x1;
    }
    if (puVar4 != (undefined1 *)0x0) {
      puVar4 = (undefined1 *)0x1;
    }
    if (param_2 == 3) {
      uVar3 = (uint)puVar4 & 1;
    }
    else {
      uVar3 = 0;
    }
    if (uVar3 != 0) goto LAB_000ef152;
    goto LAB_000ef0ac;
  case (void *)0x11:
switchD_000ef020_caseD_12:
    if (param_1[3].compress == (COMP_CTX *)0x0) goto switchD_000ef020_caseD_9;
    if (param_2 == 4) {
      param_1->init_msg = &DAT_00000009;
      return (int *)0x1;
    }
    break;
  case (void *)0x2d:
switchD_000ef020_caseD_2e:
    if (param_2 == 2) goto LAB_000ef16a;
  }
switchD_000eef5c_caseD_1:
  if (puVar4 != (undefined1 *)0x0) {
    puVar4 = (undefined1 *)0x1;
  }
LAB_000ef0ac:
  if (param_2 == 0x101) {
    uVar3 = (uint)puVar4 & 1;
  }
  else {
    uVar3 = 0;
  }
  if (uVar3 == 0) {
switchD_000ef020_caseD_2:
    ossl_statem_fatal(param_1,10,0x1a1,0xf4,"ssl/statem/statem_clnt.c",0x18b);
  }
  else {
    param_1->bbio = (BIO *)0x3;
    param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
    b = SSL_get_rbio(param_1);
    BIO_clear_flags(b,0xf);
    BIO_set_flags(b,9);
  }
  return (int *)0x0;
}

