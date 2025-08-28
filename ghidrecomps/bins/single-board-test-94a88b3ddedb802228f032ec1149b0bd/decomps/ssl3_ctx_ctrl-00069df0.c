
void ssl3_ctx_ctrl(int param_1,int param_2,uint param_3,RSA *param_4)

{
  size_t sVar1;
  _STACK *st;
  DH *dh;
  RSA *pRVar2;
  EC_KEY *key;
  void *__dest;
  char *pcVar3;
  ENGINE *pEVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int *piVar7;
  RSA_METHOD *pRVar8;
  int iVar9;
  BIGNUM *pBVar10;
  
  piVar7 = *(int **)(param_1 + 0xb0);
  switch(param_2) {
  case 1:
    if (piVar7[7] == 0) {
      if ((EVP_PKEY *)piVar7[0x10] == (EVP_PKEY *)0x0) {
        return;
      }
      EVP_PKEY_size((EVP_PKEY *)piVar7[0x10]);
      return;
    }
  default:
switchD_00069e06_caseD_8:
    break;
  case 2:
    if ((param_4 != (RSA *)0x0) && (pRVar2 = RSAPrivateKey_dup(param_4), pRVar2 != (RSA *)0x0)) {
      if ((RSA *)piVar7[7] != (RSA *)0x0) {
        RSA_free((RSA *)piVar7[7]);
      }
      piVar7[7] = (int)pRVar2;
      return;
    }
    ERR_put_error(0x14,0x85,4,"s3_lib.c",0xe66);
    goto switchD_00069e06_caseD_8;
  case 3:
    dh = DHparams_dup((DH *)param_4);
    if (dh == (DH *)0x0) {
      ERR_put_error(0x14,0x85,5,"s3_lib.c",0xe7e);
    }
    else if ((*(int *)(param_1 + 0xa4) << 0xb < 0) || (iVar9 = DH_generate_key(dh), iVar9 != 0)) {
      if ((DH *)piVar7[9] != (DH *)0x0) {
        DH_free((DH *)piVar7[9]);
      }
      piVar7[9] = (int)dh;
    }
    else {
      ERR_put_error(0x14,0x85,5,"s3_lib.c",0xe83);
      DH_free(dh);
    }
    break;
  case 4:
    if (param_4 == (RSA *)0x0) {
      ERR_put_error(0x14,0x85,0x2b,"s3_lib.c",0xe9d);
    }
    else {
      key = EC_KEY_dup((EC_KEY *)param_4);
      if (key == (EC_KEY *)0x0) {
        ERR_put_error(0x14,0x85,0x10,"s3_lib.c",0xea2);
      }
      else if ((*(int *)(param_1 + 0xa4) << 0xc < 0) ||
              (iVar9 = EC_KEY_generate_key(key), iVar9 != 0)) {
        if ((EC_KEY *)piVar7[0xb] != (EC_KEY *)0x0) {
          EC_KEY_free((EC_KEY *)piVar7[0xb]);
        }
        piVar7[0xb] = (int)key;
      }
      else {
        EC_KEY_free(key);
        ERR_put_error(0x14,0x85,0x2b,"s3_lib.c",0xea8);
      }
    }
    break;
  case 5:
    iVar9 = 0xe72;
    goto LAB_0006a048;
  case 6:
    iVar9 = 0xe92;
    goto LAB_0006a048;
  case 7:
    iVar9 = 0xeb6;
LAB_0006a048:
    ERR_put_error(0x14,0x85,0x42,"s3_lib.c",iVar9);
    break;
  case 0xe:
    st = *(_STACK **)(param_1 + 0x94);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(param_1 + 0x94) = st;
      if (st == (_STACK *)0x0) goto switchD_00069e06_caseD_8;
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
          pRVar8 = param_4->meth;
          iVar9 = param_4->pad;
          pEVar4 = param_4->engine;
          *(long *)(param_1 + 0x10c) = param_4->version;
          *(int *)(param_1 + 0x108) = iVar9;
          *(RSA_METHOD **)(param_1 + 0x110) = pRVar8;
          *(ENGINE **)(param_1 + 0x114) = pEVar4;
          pBVar6 = param_4->d;
          pBVar10 = param_4->e;
          pBVar5 = param_4->p;
          *(BIGNUM **)(param_1 + 0x118) = param_4->n;
          *(BIGNUM **)(param_1 + 0x11c) = pBVar10;
          *(BIGNUM **)(param_1 + 0x120) = pBVar6;
          *(BIGNUM **)(param_1 + 0x124) = pBVar5;
          pBVar10 = param_4->dmp1;
          pBVar5 = param_4->dmq1;
          pBVar6 = param_4->iqmp;
          *(BIGNUM **)(param_1 + 0x128) = param_4->q;
          *(BIGNUM **)(param_1 + 300) = pBVar10;
          *(BIGNUM **)(param_1 + 0x130) = pBVar5;
          *(BIGNUM **)(param_1 + 0x134) = pBVar6;
        }
        else {
          pRVar8 = *(RSA_METHOD **)(param_1 + 0x110);
          pEVar4 = *(ENGINE **)(param_1 + 0x114);
          iVar9 = *(int *)(param_1 + 0x108);
          param_4->version = *(long *)(param_1 + 0x10c);
          param_4->meth = pRVar8;
          param_4->pad = iVar9;
          param_4->engine = pEVar4;
          pBVar5 = *(BIGNUM **)(param_1 + 0x120);
          pBVar6 = *(BIGNUM **)(param_1 + 0x124);
          pBVar10 = *(BIGNUM **)(param_1 + 0x118);
          param_4->e = *(BIGNUM **)(param_1 + 0x11c);
          param_4->d = pBVar5;
          param_4->n = pBVar10;
          param_4->p = pBVar6;
          pBVar10 = *(BIGNUM **)(param_1 + 300);
          pBVar5 = *(BIGNUM **)(param_1 + 0x130);
          pBVar6 = *(BIGNUM **)(param_1 + 0x134);
          param_4->q = *(BIGNUM **)(param_1 + 0x128);
          param_4->dmp1 = pBVar10;
          param_4->dmq1 = pBVar5;
          param_4->iqmp = pBVar6;
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x145,"s3_lib.c",0xec6);
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
      sVar1 = strlen((char *)param_4);
      if ((sVar1 < 0x100) && ((char)param_4->pad != '\0')) {
        pcVar3 = BUF_strdup((char *)param_4);
        *(char **)(param_1 + 0x174) = pcVar3;
        if (pcVar3 == (char *)0x0) {
          ERR_put_error(0x14,0x85,0x44,"s3_lib.c",0xeee);
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x165,"s3_lib.c",0xeea);
      }
    }
    break;
  case 0x50:
    *(uint *)(param_1 + 0x19c) = param_3;
    break;
  case 0x51:
    *(RSA **)(param_1 + 0x198) = param_4;
    *(undefined4 *)(param_1 + 0x170) = 0x69351;
    break;
  case 0x52:
    if ((*(int *)(param_1 + 0x94) != 0) || (param_3 != 0)) {
      param_4->pad = *(int *)(param_1 + 0x94);
      return;
    }
  case 0x73:
    param_4->pad = *(int *)(*piVar7 + 0xc);
    break;
  case 0x53:
    if (*(_STACK **)(param_1 + 0x94) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x94),(func *)0xb7c0d);
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    break;
  case 0x58:
    if (param_3 != 0) {
      ssl_cert_set1_chain();
      return;
    }
    ssl_cert_set0_chain(piVar7,param_4);
    return;
  case 0x59:
    if (param_3 != 0) {
      ssl_cert_add1_chain_cert();
      return;
    }
    ssl_cert_add0_chain_cert(piVar7,param_4);
    return;
  case 0x5b:
    tls1_set_curves(param_1 + 0x1d4,param_1 + 0x1d0,param_4,param_3);
    return;
  case 0x5c:
    tls1_set_curves_list(param_1 + 0x1d4,param_1 + 0x1d0,param_4);
    return;
  case 0x5e:
    piVar7[0xd] = param_3;
    break;
  case 0x61:
    tls1_set_sigalgs(piVar7,param_4,param_3,0);
    return;
  case 0x62:
    tls1_set_sigalgs_list(piVar7,param_4,0);
    return;
  case 0x65:
    tls1_set_sigalgs(piVar7,param_4,param_3,1);
    return;
  case 0x66:
    tls1_set_sigalgs_list(piVar7,param_4,1);
    return;
  case 0x68:
    if ((void *)piVar7[0x47] != (void *)0x0) {
      CRYPTO_free((void *)piVar7[0x47]);
      piVar7[0x47] = 0;
    }
    if ((param_4 != (RSA *)0x0 && param_3 != 0) && (param_3 < 0x100)) {
      __dest = CRYPTO_malloc(param_3,"s3_lib.c",0x10c6);
      piVar7[0x47] = (int)__dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_4,param_3);
        piVar7[0x48] = param_3;
      }
    }
    break;
  case 0x69:
    ssl_build_cert_chain(piVar7,*(undefined4 *)(param_1 + 0xc));
    return;
  case 0x6a:
    ssl_cert_set_cert_store(piVar7,param_4,0,param_3);
    return;
  case 0x6b:
    ssl_cert_set_cert_store(piVar7,param_4,1,param_3);
    return;
  case 0x74:
    ssl_cert_select_current(piVar7,param_4);
    return;
  case 0x75:
    ssl_cert_set_current(piVar7,param_3);
    return;
  }
  return;
}

