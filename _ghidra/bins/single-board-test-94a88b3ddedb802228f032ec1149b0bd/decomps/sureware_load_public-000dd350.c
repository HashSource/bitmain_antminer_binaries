
EVP_PKEY *
sureware_load_public(ENGINE *param_1,undefined4 param_2,void *param_3,uint param_4,char param_5)

{
  DSA *d;
  BIGNUM *pBVar1;
  RSA *r;
  int iVar2;
  EVP_PKEY *pEVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  uint uVar6;
  uint uVar7;
  char local_68 [21];
  undefined1 auStack_53 [47];
  
  builtin_strncpy(local_68,"sureware_load_public",0x14);
  local_68[0x14] = 0;
  memset(auStack_53,0,0x2b);
  if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) || (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)
     ) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
  }
  else {
    if (param_5 == '\x01') {
      r = RSA_new_method(param_1);
      RSA_set_ex_data(r,rsaHndidx,param_3);
      r->flags = r->flags | 0x20;
      pBVar1 = BN_new();
      r->e = pBVar1;
      pBVar1 = BN_new();
      r->n = pBVar1;
      if ((r->e != (BIGNUM *)0x0) && (pBVar1 != (BIGNUM *)0x0)) {
        uVar7 = param_4 >> 2;
        bn_expand2(r->e,uVar7);
        bn_expand2(r->n,uVar7);
        if ((uVar7 == r->e->dmax) && (uVar7 == r->n->dmax)) {
          iVar2 = (*p_surewarehk_Load_Rsa_Pubkey)(local_68,param_2,param_4,r->n->d,r->e->d);
          surewarehk_error_handling(local_68,0x6a,iVar2);
          if (iVar2 == 1) {
            pBVar1 = r->e;
            pBVar1->top = uVar7;
            if (uVar7 == 0) {
              r->n->top = 0;
            }
            else {
              uVar6 = uVar7;
              puVar5 = pBVar1->d + (uVar7 - 1);
              do {
                if (*puVar5 != 0) break;
                uVar6 = uVar6 - 1;
                puVar5 = puVar5 + -1;
              } while (uVar6 != 0);
              pBVar4 = r->n;
              pBVar1->top = uVar6;
              pBVar4->top = uVar7;
              puVar5 = pBVar4->d + (uVar7 - 1);
              do {
                if (*puVar5 != 0) break;
                uVar7 = uVar7 - 1;
                puVar5 = puVar5 + -1;
              } while (uVar7 != 0);
              pBVar4->top = uVar7;
            }
            pEVar3 = EVP_PKEY_new();
            EVP_PKEY_assign(pEVar3,6,r);
            return pEVar3;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
        }
      }
      RSA_free(r);
      return (EVP_PKEY *)0x0;
    }
    if (param_5 == '\x02') {
      d = DSA_new_method(param_1);
      DSA_set_ex_data(d,dsaHndidx,param_3);
      pBVar1 = BN_new();
      d->pub_key = pBVar1;
      pBVar1 = BN_new();
      d->p = pBVar1;
      pBVar1 = BN_new();
      d->q = pBVar1;
      pBVar1 = BN_new();
      d->g = pBVar1;
      if ((((d->pub_key != (BIGNUM *)0x0) && (d->p != (BIGNUM *)0x0)) && (d->q != (BIGNUM *)0x0)) &&
         (pBVar1 != (BIGNUM *)0x0)) {
        uVar7 = param_4 >> 2;
        bn_expand2(d->pub_key,uVar7);
        bn_expand2(d->p,uVar7);
        bn_expand2(d->q,5);
        bn_expand2(d->g,uVar7);
        if (((uVar7 == d->pub_key->dmax) && (uVar7 == d->p->dmax)) &&
           ((d->q->dmax == 5 && (uVar7 == d->g->dmax)))) {
          iVar2 = (*p_surewarehk_Load_Dsa_Pubkey)
                            (local_68,param_2,param_4,d->pub_key->d,d->p->d,d->q->d,d->g->d);
          surewarehk_error_handling(local_68,0x6a,iVar2);
          if (iVar2 == 1) {
            pBVar1 = d->pub_key;
            pBVar1->top = uVar7;
            if (uVar7 == 0) {
              d->p->top = 0;
            }
            else {
              uVar6 = uVar7;
              puVar5 = pBVar1->d + (uVar7 - 1);
              do {
                if (*puVar5 != 0) break;
                uVar6 = uVar6 - 1;
                puVar5 = puVar5 + -1;
              } while (uVar6 != 0);
              pBVar4 = d->p;
              pBVar1->top = uVar6;
              pBVar4->top = uVar7;
              puVar5 = pBVar4->d + (uVar7 - 1);
              uVar6 = uVar7;
              do {
                if (*puVar5 != 0) break;
                uVar6 = uVar6 - 1;
                puVar5 = puVar5 + -1;
              } while (uVar6 != 0);
              pBVar4->top = uVar6;
            }
            pBVar1 = d->q;
            iVar2 = 5;
            pBVar1->top = 5;
            do {
              if (pBVar1->d[iVar2 + -1] != 0) break;
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
            pBVar4 = d->g;
            pBVar1->top = iVar2;
            pBVar4->top = uVar7;
            if (uVar7 != 0) {
              puVar5 = pBVar4->d + (uVar7 - 1);
              do {
                if (*puVar5 != 0) break;
                uVar7 = uVar7 - 1;
                puVar5 = puVar5 + -1;
              } while (uVar7 != 0);
              pBVar4->top = uVar7;
            }
            pEVar3 = EVP_PKEY_new();
            EVP_PKEY_assign(pEVar3,0x74,d);
            return pEVar3;
          }
          ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
        }
      }
      DSA_free(d);
      return (EVP_PKEY *)0x0;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
  }
  return (EVP_PKEY *)0x0;
}

