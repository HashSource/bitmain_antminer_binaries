
RSA * ssl3_ctrl(int *param_1,int param_2,uint param_3,RSA *param_4)

{
  undefined uVar1;
  undefined uVar2;
  int iVar3;
  EVP_PKEY *pkey;
  EVP_MD *md;
  void *__dest;
  DH *dh;
  SSL_METHOD *pSVar4;
  size_t sVar5;
  char *pcVar6;
  RSA *pRVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  
  if (((param_2 == 2 || param_2 == 5) || (param_2 == 3 || param_2 == 6)) &&
     (iVar3 = ssl_cert_inst(param_1 + 0x26), iVar3 == 0)) {
    ERR_put_error(0x14,0xd5,0x41,DAT_000698f4,0xc44);
    return (RSA *)0x0;
  }
  switch(param_2) {
  case 1:
    iVar3 = param_1[0x26];
    if ((iVar3 == 0) || (*(int *)(iVar3 + 0x1c) != 0)) goto switchD_000695f8_caseD_9;
    if (*(EVP_PKEY **)(iVar3 + 0x40) != (EVP_PKEY *)0x0) {
      iVar3 = EVP_PKEY_size(*(EVP_PKEY **)(iVar3 + 0x40));
      return (RSA *)(uint)(0x40 < iVar3);
    }
    goto LAB_00069bc2;
  case 2:
    iVar3 = 0xc69;
    if (param_4 != (RSA *)0x0) {
      pRVar7 = RSAPrivateKey_dup(param_4);
      if (pRVar7 != (RSA *)0x0) {
        iVar3 = param_1[0x26];
        if (*(RSA **)(iVar3 + 0x1c) != (RSA *)0x0) {
          RSA_free(*(RSA **)(iVar3 + 0x1c));
          iVar3 = param_1[0x26];
        }
        *(RSA **)(iVar3 + 0x1c) = pRVar7;
        return (RSA *)0x1;
      }
      ERR_put_error(0x14,0xd5,4,DAT_00069d80,0xc6d);
      return (RSA *)0x0;
    }
    goto LAB_00069c26;
  case 3:
    if (param_4 != (RSA *)0x0) {
      dh = DHparams_dup((DH *)param_4);
      if (dh == (DH *)0x0) {
        ERR_put_error(0x14,0xd5,5,DAT_00069d80,0xc86);
        return (RSA *)0x0;
      }
      if ((-1 < param_1[0x40] << 0xb) && (iVar3 = DH_generate_key(dh), iVar3 == 0)) {
        DH_free(dh);
        ERR_put_error(0x14,0xd5,5,DAT_00069d80,0xc8c);
        return (RSA *)0x0;
      }
      iVar3 = param_1[0x26];
      if (*(DH **)(iVar3 + 0x24) != (DH *)0x0) {
        DH_free(*(DH **)(iVar3 + 0x24));
        iVar3 = param_1[0x26];
      }
      *(DH **)(iVar3 + 0x24) = dh;
      return (RSA *)0x1;
    }
    iVar3 = 0xc82;
    goto LAB_00069c26;
  case 4:
    iVar3 = 0xca3;
    if (param_4 != (RSA *)0x0) {
      pRVar7 = (RSA *)EC_KEY_up_ref((EC_KEY *)param_4);
      iVar3 = 0xca7;
      if (pRVar7 != (RSA *)0x0) {
        if ((param_1[0x40] << 0xc < 0) ||
           (iVar3 = EC_KEY_generate_key((EC_KEY *)param_4), iVar3 != 0)) {
          iVar3 = param_1[0x26];
          if (*(EC_KEY **)(iVar3 + 0x2c) != (EC_KEY *)0x0) {
            EC_KEY_free(*(EC_KEY **)(iVar3 + 0x2c));
            iVar3 = param_1[0x26];
          }
          *(RSA **)(iVar3 + 0x2c) = param_4;
          return (RSA *)0x1;
        }
        EC_KEY_free((EC_KEY *)param_4);
        iVar3 = 0xcae;
        pRVar7 = (RSA *)0x0;
      }
      ERR_put_error(0x14,0xd5,0x2b,DAT_00069d80,iVar3);
      return pRVar7;
    }
LAB_00069c26:
    ERR_put_error(0x14,0xd5,0x43,DAT_00069d80,iVar3);
    break;
  case 5:
    iVar3 = 0xc78;
    goto LAB_0006970a;
  case 6:
    iVar3 = 0xc98;
    goto LAB_0006970a;
  case 7:
    iVar3 = 0xcba;
LAB_0006970a:
    ERR_put_error(0x14,0xd5,0x42,DAT_000698f4,iVar3);
    goto switchD_000695f8_caseD_9;
  case 8:
    param_4 = (RSA *)param_1[0x1b];
    break;
  default:
    goto switchD_000695f8_caseD_9;
  case 10:
    param_4 = *(RSA **)(param_1[0x16] + 0x19c);
    break;
  case 0xb:
    param_4 = *(RSA **)(param_1[0x16] + 0x19c);
    *(undefined4 *)(param_1[0x16] + 0x19c) = 0;
    break;
  case 0xc:
    param_4 = *(RSA **)(param_1[0x16] + 0x198);
    break;
  case 0xd:
    param_4 = *(RSA **)param_1[0x16];
    break;
  case 0x37:
    if (param_3 != 0) {
      ERR_put_error(0x14,0xd5,0x140,DAT_00069d80,0xcd2);
      return (RSA *)0x0;
    }
    if ((void *)param_1[0x48] != (void *)0x0) {
      CRYPTO_free((void *)param_1[0x48]);
    }
    param_1[0x48] = 0;
    if (param_4 != (RSA *)0x0) {
      sVar5 = strlen((char *)param_4);
      if (0xff < sVar5) {
        ERR_put_error(0x14,0xd5,0x13f,DAT_00069d80,0xcca);
        return (RSA *)0x0;
      }
      pcVar6 = BUF_strdup((char *)param_4);
      param_1[0x48] = (int)pcVar6;
      if (pcVar6 == (char *)0x0) {
        ERR_put_error(0x14,0xd5,0x44,DAT_00069d80,0xcce);
        return (RSA *)0x0;
      }
    }
    goto LAB_00069bc2;
  case 0x39:
    param_1[0x47] = (int)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x41:
    param_1[0x4a] = param_3;
    param_4 = (RSA *)0x1;
    break;
  case 0x42:
    *(int *)param_4 = param_1[0x4d];
    param_4 = (RSA *)0x1;
    break;
  case 0x43:
    param_1[0x4d] = (int)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x44:
    *(int *)param_4 = param_1[0x4c];
    param_4 = (RSA *)0x1;
    break;
  case 0x45:
    param_1[0x4c] = (int)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x46:
    pRVar7 = (RSA *)param_1[0x4f];
    *(int *)param_4 = param_1[0x4e];
    param_4 = pRVar7;
    break;
  case 0x47:
    if ((void *)param_1[0x4e] != (void *)0x0) {
      CRYPTO_free((void *)param_1[0x4e]);
    }
    param_1[0x4e] = (int)param_4;
    param_1[0x4f] = param_3;
    param_4 = (RSA *)0x1;
    break;
  case 0x55:
    if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c < 0) {
      pRVar7 = (RSA *)dtls1_heartbeat();
      return pRVar7;
    }
    pRVar7 = (RSA *)tls1_heartbeat(param_1);
    return pRVar7;
  case 0x56:
    param_4 = (RSA *)param_1[0x62];
    break;
  case 0x57:
    param_4 = (RSA *)0x1;
    if (param_3 == 0) {
      param_1[0x61] = param_1[0x61] & 0xfffffffb;
    }
    else {
      param_1[0x61] = param_1[0x61] | 4;
    }
    break;
  case 0x58:
    if (param_3 != 0) {
      pRVar7 = (RSA *)ssl_cert_set1_chain();
      return pRVar7;
    }
    pRVar7 = (RSA *)ssl_cert_set0_chain(param_1[0x26],param_4);
    return pRVar7;
  case 0x59:
    if (param_3 != 0) {
      pRVar7 = (RSA *)ssl_cert_add1_chain_cert();
      return pRVar7;
    }
    pRVar7 = (RSA *)ssl_cert_add0_chain_cert(param_1[0x26],param_4);
    return pRVar7;
  case 0x5a:
    iVar3 = param_1[0x30];
    if (iVar3 != 0) {
      pRVar7 = (RSA *)(*(uint *)(iVar3 + 0xdc) >> 1);
      if (param_4 == (RSA *)0x0) {
        return pRVar7;
      }
      if (pRVar7 == (RSA *)0x0) {
        return (RSA *)0x0;
      }
      iVar8 = 0;
      iVar10 = 0;
      puVar9 = *(undefined **)(iVar3 + 0xe0);
      do {
        uVar1 = *puVar9;
        uVar2 = puVar9[1];
        iVar3 = tls1_ec_curve_id2nid((uint)CONCAT11(uVar1,uVar2));
        if (iVar3 == 0) {
          *(uint *)(&param_4->field_0x0 + iVar8) = CONCAT11(uVar1,uVar2) | 0x1000000;
        }
        else {
          *(int *)(&param_4->field_0x0 + iVar8) = iVar3;
        }
        iVar10 = iVar10 + 1;
        iVar8 = iVar8 + 4;
        puVar9 = puVar9 + 2;
      } while ((RSA *)iVar10 != pRVar7);
      return pRVar7;
    }
    goto switchD_000695f8_caseD_9;
  case 0x5b:
    pRVar7 = (RSA *)tls1_set_curves(param_1 + 0x54,param_1 + 0x53,param_4,param_3);
    return pRVar7;
  case 0x5c:
    pRVar7 = (RSA *)tls1_set_curves_list(param_1 + 0x54,param_1 + 0x53,param_4);
    return pRVar7;
  case 0x5d:
    pRVar7 = (RSA *)tls1_shared_curve(param_1,param_3);
    return pRVar7;
  case 0x5e:
    *(uint *)(param_1[0x26] + 0x34) = param_3;
    param_4 = (RSA *)0x1;
    break;
  case 0x61:
    pRVar7 = (RSA *)tls1_set_sigalgs(param_1[0x26],param_4,param_3,0);
    return pRVar7;
  case 0x62:
    pRVar7 = (RSA *)tls1_set_sigalgs_list(param_1[0x26],param_4,0);
    return pRVar7;
  case 0x65:
    pRVar7 = (RSA *)tls1_set_sigalgs(param_1[0x26],param_4,param_3,1);
    return pRVar7;
  case 0x66:
    pRVar7 = (RSA *)tls1_set_sigalgs_list(param_1[0x26],param_4,1);
    return pRVar7;
  case 0x67:
    if ((param_1[9] == 0) && (iVar3 = param_1[0x16], *(int *)(iVar3 + 0x358) != 0)) {
      iVar8 = param_1[0x26];
      if (*(int *)(iVar8 + 0x11c) != 0) {
        if (param_4 != (RSA *)0x0) {
          *(int *)param_4 = *(int *)(iVar8 + 0x11c);
          iVar8 = param_1[0x26];
        }
        return *(RSA **)(iVar8 + 0x120);
      }
      if (param_4 != (RSA *)0x0) {
        *(int *)param_4 = iVar3 + 0x360;
        iVar3 = param_1[0x16];
      }
      return *(RSA **)(iVar3 + 0x35c);
    }
    goto switchD_000695f8_caseD_9;
  case 0x68:
    if (param_1[9] == 0) goto switchD_000695f8_caseD_9;
    iVar3 = param_1[0x26];
    if (*(void **)(iVar3 + 0x11c) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar3 + 0x11c));
      *(undefined4 *)(iVar3 + 0x11c) = 0;
    }
    if (param_4 != (RSA *)0x0 && param_3 != 0) {
      if (0xff < param_3) {
        return (RSA *)0x0;
      }
      __dest = CRYPTO_malloc(param_3,DAT_000698f4,0x10c6);
      *(void **)(iVar3 + 0x11c) = __dest;
      if (__dest == (void *)0x0) {
        return (RSA *)0x0;
      }
      memcpy(__dest,param_4,param_3);
      *(uint *)(iVar3 + 0x120) = param_3;
      return (RSA *)0x1;
    }
    goto LAB_00069bc2;
  case 0x69:
    pRVar7 = (RSA *)ssl_build_cert_chain(param_1[0x26],*(undefined4 *)(param_1[0x39] + 0xc),param_3)
    ;
    return pRVar7;
  case 0x6a:
    pRVar7 = (RSA *)ssl_cert_set_cert_store(param_1[0x26],param_4,0,param_3);
    return pRVar7;
  case 0x6b:
    pRVar7 = (RSA *)ssl_cert_set_cert_store(param_1[0x26],param_4,1,param_3);
    return pRVar7;
  case 0x6c:
    if (((*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1e < 0) && (param_1[0x30] != 0)) &&
       ((iVar3 = *(int *)(param_1[0x30] + 0x98), iVar3 != 0 &&
        (md = *(EVP_MD **)(*(int *)(iVar3 + 8) + 8), md != (EVP_MD *)0x0)))) {
      iVar3 = EVP_MD_type(md);
      *(int *)param_4 = iVar3;
      return (RSA *)0x1;
    }
    goto switchD_000695f8_caseD_9;
  case 0x6d:
    if (((((param_1[9] == 0) && (param_1[0x30] != 0)) &&
         (iVar3 = *(int *)(param_1[0x30] + 0x98), iVar3 != 0)) &&
        (((*(int *)(iVar3 + 0xec) != 0 || (*(int *)(iVar3 + 0xf0) != 0)) ||
         (*(int *)(iVar3 + 0xf4) != 0)))) && (pkey = EVP_PKEY_new(), pkey != (EVP_PKEY *)0x0)) {
      if (*(rsa_st **)(iVar3 + 0xec) == (rsa_st *)0x0) {
        if (*(dh_st **)(iVar3 + 0xf0) == (dh_st *)0x0) {
          if (*(ec_key_st **)(iVar3 + 0xf4) == (ec_key_st *)0x0) goto LAB_00069cda;
          iVar3 = EVP_PKEY_set1_EC_KEY(pkey,*(ec_key_st **)(iVar3 + 0xf4));
        }
        else {
          iVar3 = EVP_PKEY_set1_DH(pkey,*(dh_st **)(iVar3 + 0xf0));
        }
      }
      else {
        iVar3 = EVP_PKEY_set1_RSA(pkey,*(rsa_st **)(iVar3 + 0xec));
      }
      if (iVar3 != 0) {
        *(EVP_PKEY **)param_4 = pkey;
        return (RSA *)0x1;
      }
LAB_00069cda:
      EVP_PKEY_free(pkey);
      return (RSA *)0x0;
    }
    goto switchD_000695f8_caseD_9;
  case 0x6f:
    iVar3 = param_1[0x30];
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0xd8) != 0)) {
      *(int *)param_4 = *(int *)(iVar3 + 0xd8);
      return *(RSA **)(iVar3 + 0xd4);
    }
    goto switchD_000695f8_caseD_9;
  case 0x73:
    *(undefined4 *)param_4 = *(undefined4 *)(*(int *)param_1[0x26] + 0xc);
    param_4 = (RSA *)0x0;
    break;
  case 0x74:
    pRVar7 = (RSA *)ssl_cert_select_current(param_1[0x26],param_4);
    return pRVar7;
  case 0x75:
    if (param_3 != 3) {
      pRVar7 = (RSA *)ssl_cert_set_current(param_1[0x26],param_3);
      return pRVar7;
    }
    if ((param_1[9] != 0) && (*(int *)(param_1[0x16] + 0x344) != 0)) {
      if ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10) & 0x404) != 0) {
        return (RSA *)0x2;
      }
      iVar3 = ssl_get_server_send_pkey(param_1);
      if (iVar3 != 0) {
        *(int *)param_1[0x26] = iVar3;
        return (RSA *)0x1;
      }
    }
switchD_000695f8_caseD_9:
    param_4 = (RSA *)0x0;
    break;
  case 0x77:
    iVar3 = **(int **)param_1[0x39];
    if (*param_1 != iVar3) {
      pSVar4 = SSLv23_method();
      if (iVar3 == pSVar4->version) {
        iVar3 = param_1[0x40];
        if (-1 < iVar3 << 4) {
          return (RSA *)(uint)(*param_1 == 0x303);
        }
        if (-1 < iVar3 << 3) {
          return (RSA *)(uint)(*param_1 == 0x302);
        }
        if (-1 < iVar3 << 5) {
          return (RSA *)(uint)(*param_1 == 0x301);
        }
        if (-1 < iVar3 << 6) {
          return (RSA *)(uint)(*param_1 == 0x300);
        }
        if (-1 < iVar3 << 7) {
          return (RSA *)(uint)(*param_1 == 2);
        }
      }
      goto switchD_000695f8_caseD_9;
    }
LAB_00069bc2:
    param_4 = (RSA *)0x1;
  }
  return param_4;
}

