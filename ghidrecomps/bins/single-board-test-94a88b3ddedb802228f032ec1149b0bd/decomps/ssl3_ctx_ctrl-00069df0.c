
void ssl3_ctx_ctrl(int param_1,int param_2,uint param_3,RSA *param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  _STACK *st;
  DH *dh;
  RSA *pRVar3;
  EC_KEY *key;
  void *__dest;
  char *pcVar4;
  ENGINE *pEVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  int *piVar8;
  RSA_METHOD *pRVar9;
  int iVar10;
  BIGNUM *pBVar11;
  
  uVar1 = DAT_0006a144;
  piVar8 = *(int **)(param_1 + 0xb0);
  switch(param_2) {
  case 1:
    if ((piVar8[7] == 0) && ((EVP_PKEY *)piVar8[0x10] != (EVP_PKEY *)0x0)) {
      EVP_PKEY_size((EVP_PKEY *)piVar8[0x10]);
    }
    break;
  case 2:
    if ((param_4 == (RSA *)0x0) || (pRVar3 = RSAPrivateKey_dup(param_4), pRVar3 == (RSA *)0x0)) {
      ERR_put_error(0x14,0x85,4,DAT_0006a13c,0xe66);
    }
    else {
      if ((RSA *)piVar8[7] != (RSA *)0x0) {
        RSA_free((RSA *)piVar8[7]);
      }
      piVar8[7] = (int)pRVar3;
    }
    break;
  case 3:
    dh = DHparams_dup((DH *)param_4);
    if (dh == (DH *)0x0) {
      ERR_put_error(0x14,0x85,5,DAT_0006a384,0xe7e);
    }
    else if ((*(int *)(param_1 + 0xa4) << 0xb < 0) || (iVar10 = DH_generate_key(dh), iVar10 != 0)) {
      if ((DH *)piVar8[9] != (DH *)0x0) {
        DH_free((DH *)piVar8[9]);
      }
      piVar8[9] = (int)dh;
    }
    else {
      ERR_put_error(0x14,0x85,5,DAT_0006a384,0xe83);
      DH_free(dh);
    }
    break;
  case 4:
    if (param_4 == (RSA *)0x0) {
      ERR_put_error(0x14,0x85,0x2b,DAT_0006a384,0xe9d);
    }
    else {
      key = EC_KEY_dup((EC_KEY *)param_4);
      if (key == (EC_KEY *)0x0) {
        ERR_put_error(0x14,0x85,0x10,DAT_0006a384,0xea2);
      }
      else if ((*(int *)(param_1 + 0xa4) << 0xc < 0) ||
              (iVar10 = EC_KEY_generate_key(key), iVar10 != 0)) {
        if ((EC_KEY *)piVar8[0xb] != (EC_KEY *)0x0) {
          EC_KEY_free((EC_KEY *)piVar8[0xb]);
        }
        piVar8[0xb] = (int)key;
      }
      else {
        EC_KEY_free(key);
        ERR_put_error(0x14,0x85,0x2b,DAT_0006a384,0xea8);
      }
    }
    break;
  case 5:
    iVar10 = 0xe72;
    goto LAB_0006a048;
  case 6:
    iVar10 = 0xe92;
    goto LAB_0006a048;
  case 7:
    iVar10 = 0xeb6;
LAB_0006a048:
    ERR_put_error(0x14,0x85,0x42,DAT_0006a13c,iVar10);
    break;
  case 0xe:
    st = *(_STACK **)(param_1 + 0x94);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(param_1 + 0x94) = st;
      if (st == (_STACK *)0x0) {
        return;
      }
    }
    sk_push(st,param_4);
    break;
  case 0x36:
    *(RSA **)(param_1 + 0x104) = param_4;
    break;
  case 0x3a:
  case 0x3b:
    if (param_4 != (RSA *)0x0) {
      if (param_3 == 0x30) {
        if (param_2 == 0x3b) {
          pRVar9 = param_4->meth;
          iVar10 = param_4->pad;
          pEVar5 = param_4->engine;
          *(long *)(param_1 + 0x10c) = param_4->version;
          *(int *)(param_1 + 0x108) = iVar10;
          *(RSA_METHOD **)(param_1 + 0x110) = pRVar9;
          *(ENGINE **)(param_1 + 0x114) = pEVar5;
          pBVar7 = param_4->d;
          pBVar11 = param_4->e;
          pBVar6 = param_4->p;
          *(BIGNUM **)(param_1 + 0x118) = param_4->n;
          *(BIGNUM **)(param_1 + 0x11c) = pBVar11;
          *(BIGNUM **)(param_1 + 0x120) = pBVar7;
          *(BIGNUM **)(param_1 + 0x124) = pBVar6;
          pBVar11 = param_4->dmp1;
          pBVar6 = param_4->dmq1;
          pBVar7 = param_4->iqmp;
          *(BIGNUM **)(param_1 + 0x128) = param_4->q;
          *(BIGNUM **)(param_1 + 300) = pBVar11;
          *(BIGNUM **)(param_1 + 0x130) = pBVar6;
          *(BIGNUM **)(param_1 + 0x134) = pBVar7;
        }
        else {
          pRVar9 = *(RSA_METHOD **)(param_1 + 0x110);
          pEVar5 = *(ENGINE **)(param_1 + 0x114);
          iVar10 = *(int *)(param_1 + 0x108);
          param_4->version = *(long *)(param_1 + 0x10c);
          param_4->meth = pRVar9;
          param_4->pad = iVar10;
          param_4->engine = pEVar5;
          pBVar6 = *(BIGNUM **)(param_1 + 0x120);
          pBVar7 = *(BIGNUM **)(param_1 + 0x124);
          pBVar11 = *(BIGNUM **)(param_1 + 0x118);
          param_4->e = *(BIGNUM **)(param_1 + 0x11c);
          param_4->d = pBVar6;
          param_4->n = pBVar11;
          param_4->p = pBVar7;
          pBVar11 = *(BIGNUM **)(param_1 + 300);
          pBVar6 = *(BIGNUM **)(param_1 + 0x130);
          pBVar7 = *(BIGNUM **)(param_1 + 0x134);
          param_4->q = *(BIGNUM **)(param_1 + 0x128);
          param_4->dmp1 = pBVar11;
          param_4->dmq1 = pBVar6;
          param_4->iqmp = pBVar7;
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x145,DAT_0006a384,0xec6);
      }
    }
    break;
  case 0x40:
    *(RSA **)(param_1 + 0x140) = param_4;
    break;
  case 0x4e:
    *(RSA **)(param_1 + 0x164) = param_4;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    break;
  case 0x4f:
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    if (*(void **)(param_1 + 0x174) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x174));
    }
    *(undefined4 *)(param_1 + 0x174) = 0;
    if (param_4 != (RSA *)0x0) {
      sVar2 = strlen((char *)param_4);
      if ((sVar2 < 0x100) && (*(char *)&param_4->pad != '\0')) {
        pcVar4 = BUF_strdup((char *)param_4);
        *(char **)(param_1 + 0x174) = pcVar4;
        if (pcVar4 == (char *)0x0) {
          ERR_put_error(0x14,0x85,0x44,DAT_0006a384,0xeee);
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x165,DAT_0006a13c,0xeea);
      }
    }
    break;
  case 0x50:
    *(uint *)(param_1 + 0x19c) = param_3;
    break;
  case 0x51:
    *(RSA **)(param_1 + 0x198) = param_4;
    *(undefined4 *)(param_1 + 0x170) = uVar1;
    break;
  case 0x52:
    if ((*(int *)(param_1 + 0x94) != 0) || (param_3 != 0)) {
      param_4->pad = *(int *)(param_1 + 0x94);
      return;
    }
  case 0x73:
    param_4->pad = *(int *)(*piVar8 + 0xc);
    break;
  case 0x53:
    if (*(_STACK **)(param_1 + 0x94) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x94),DAT_0006a140);
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    break;
  case 0x58:
    if (param_3 != 0) {
      ssl_cert_set1_chain();
      return;
    }
    ssl_cert_set0_chain(piVar8,param_4);
    return;
  case 0x59:
    if (param_3 != 0) {
      ssl_cert_add1_chain_cert();
      return;
    }
    ssl_cert_add0_chain_cert(piVar8,param_4);
    return;
  case 0x5b:
    tls1_set_curves(param_1 + 0x1d4,param_1 + 0x1d0,param_4,param_3);
    return;
  case 0x5c:
    tls1_set_curves_list(param_1 + 0x1d4,param_1 + 0x1d0,param_4);
    return;
  case 0x5e:
    piVar8[0xd] = param_3;
    break;
  case 0x61:
    tls1_set_sigalgs(piVar8,param_4,param_3,0);
    return;
  case 0x62:
    tls1_set_sigalgs_list(piVar8,param_4,0);
    return;
  case 0x65:
    tls1_set_sigalgs(piVar8,param_4,param_3,1);
    return;
  case 0x66:
    tls1_set_sigalgs_list(piVar8,param_4,1);
    return;
  case 0x68:
    if ((void *)piVar8[0x47] != (void *)0x0) {
      CRYPTO_free((void *)piVar8[0x47]);
      piVar8[0x47] = 0;
    }
    if ((param_4 != (RSA *)0x0 && param_3 != 0) && (param_3 < 0x100)) {
      __dest = CRYPTO_malloc(param_3,DAT_0006a384,0x10c6);
      piVar8[0x47] = (int)__dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_4,param_3);
        piVar8[0x48] = param_3;
      }
    }
    break;
  case 0x69:
    ssl_build_cert_chain(piVar8,*(undefined4 *)(param_1 + 0xc));
    return;
  case 0x6a:
    ssl_cert_set_cert_store(piVar8,param_4,0,param_3);
    return;
  case 0x6b:
    ssl_cert_set_cert_store(piVar8,param_4,1,param_3);
    return;
  case 0x74:
    ssl_cert_select_current(piVar8,param_4);
    return;
  case 0x75:
    ssl_cert_set_current(piVar8,param_3);
    return;
  }
  return;
}

