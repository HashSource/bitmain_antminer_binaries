
int check_crl(X509_STORE_CTX *param_1,X509_CRL *param_2)

{
  stack_st_X509 *psVar1;
  int iVar2;
  ASN1_TIME *s;
  EVP_PKEY *r;
  X509 *a;
  X509 *b;
  uint uVar3;
  X509 *x;
  int iVar4;
  time_t *t;
  X509_VERIFY_PARAM *pXVar5;
  _STACK *p_Var6;
  X509_STORE_CTX XStack_a0;
  
  iVar4 = param_1->error_depth;
  iVar2 = sk_num(&param_1->chain->stack);
  x = param_1->current_issuer;
  if (x == (X509 *)0x0) {
    if (iVar2 + -1 <= iVar4) {
      x = (X509 *)sk_value(&param_1->chain->stack,iVar2 + -1);
      iVar2 = (*param_1->check_issued)(param_1,x,x);
      if (iVar2 != 0) goto LAB_00161062;
      param_1->error = 0x21;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 != 0) goto LAB_00161062;
      goto LAB_0016104c;
    }
    x = (X509 *)sk_value(&param_1->chain->stack,iVar4 + 1);
LAB_00161062:
    if (x != (X509 *)0x0) goto LAB_00160f98;
LAB_00161066:
    iVar2 = 1;
    r = (EVP_PKEY *)0x0;
  }
  else {
LAB_00160f98:
    if (param_2->base_crl_number == (ASN1_INTEGER *)0x0) {
      if (((int)(x->ex_flags << 0x1e) < 0) && ((x->ex_kusage & 2) == 0)) {
        param_1->error = 0x23;
        iVar2 = (*param_1->verify_cb)(0,param_1);
        if (iVar2 == 0) goto LAB_0016104c;
      }
      uVar3 = param_1->current_crl_score;
      if ((uVar3 & 0x80) == 0) {
        param_1->error = 0x2c;
        iVar2 = (*param_1->verify_cb)(0,param_1);
        if (iVar2 == 0) goto LAB_0016104c;
        uVar3 = param_1->current_crl_score;
      }
      if (-1 < (int)(uVar3 << 0x1c)) {
        if ((param_1->parent == (X509_STORE_CTX *)0x0) &&
           (iVar2 = X509_STORE_CTX_init(&XStack_a0,param_1->ctx,param_1->current_issuer,
                                        param_1->untrusted), iVar2 != 0)) {
          XStack_a0.crls = param_1->crls;
          pXVar5 = param_1->param;
          if (XStack_a0.param != (X509_VERIFY_PARAM *)0x0) {
            X509_VERIFY_PARAM_free(XStack_a0.param);
          }
          XStack_a0.verify_cb = param_1->verify_cb;
          XStack_a0.param = pXVar5;
          XStack_a0.parent = param_1;
          iVar2 = X509_verify_cert(&XStack_a0);
          psVar1 = XStack_a0.chain;
          if (0 < iVar2) {
            p_Var6 = &param_1->chain->stack;
            iVar2 = sk_num(p_Var6);
            a = (X509 *)sk_value(p_Var6,iVar2 + -1);
            iVar2 = sk_num(&psVar1->stack);
            b = (X509 *)sk_value(&psVar1->stack,iVar2 + -1);
            uVar3 = X509_cmp(a,b);
            iVar2 = 1 - uVar3;
            if (1 < uVar3) {
              iVar2 = 0;
            }
          }
          if (XStack_a0.cleanup != (_func_2008 *)0x0) {
            (*XStack_a0.cleanup)(&XStack_a0);
          }
          if (XStack_a0.param != (X509_VERIFY_PARAM *)0x0) {
            if (XStack_a0.parent == (X509_STORE_CTX *)0x0) {
              X509_VERIFY_PARAM_free(XStack_a0.param);
            }
            XStack_a0.param = (X509_VERIFY_PARAM *)0x0;
          }
          if (XStack_a0.tree != (X509_POLICY_TREE *)0x0) {
            X509_policy_tree_free(XStack_a0.tree);
            XStack_a0.tree = (X509_POLICY_TREE *)0x0;
          }
          if (&(XStack_a0.chain)->stack != (_STACK *)0x0) {
            sk_pop_free(&(XStack_a0.chain)->stack,(func *)0x1579c9);
            XStack_a0.chain = (stack_st_X509 *)0x0;
          }
          CRYPTO_free_ex_data(5,&XStack_a0,&XStack_a0.ex_data);
          XStack_a0.ex_data.dummy = 0;
          XStack_a0.ex_data.sk = (stack_st_void *)0x0;
          if (iVar2 == 1) goto LAB_00161086;
        }
        param_1->error = 0x36;
        iVar2 = (*param_1->verify_cb)(0,param_1);
        if (iVar2 == 0) goto LAB_0016104c;
      }
LAB_00161086:
      if (param_2->idp_flags << 0x1e < 0) {
        param_1->error = 0x29;
        iVar2 = (*param_1->verify_cb)(0,param_1);
        if (iVar2 == 0) goto LAB_0016104c;
      }
    }
    if (param_1->current_crl_score << 0x19 < 0) {
LAB_00160ff0:
      r = X509_get_pubkey(x);
      if (r != (EVP_PKEY *)0x0) {
        iVar2 = X509_CRL_check_suiteb(param_2,r,param_1->param->flags);
        if (iVar2 != 0) {
          param_1->error = iVar2;
          iVar2 = (*param_1->verify_cb)(0,param_1);
          if (iVar2 == 0) {
            iVar2 = 0;
            goto LAB_0016101a;
          }
        }
        iVar2 = X509_CRL_verify(param_2,r);
        if (iVar2 < 1) {
          param_1->error = 8;
          iVar2 = (*param_1->verify_cb)(0,param_1);
          if (iVar2 != 0) {
            iVar2 = 1;
          }
        }
        else {
          iVar2 = 1;
        }
        goto LAB_0016101a;
      }
      param_1->error = 6;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 != 0) goto LAB_00161066;
    }
    else {
      param_1->current_crl = param_2;
      t = (time_t *)(param_1->param->flags & 2);
      if (t != (time_t *)0x0) {
        t = &param_1->param->check_time;
      }
      iVar2 = X509_cmp_time(param_2->crl->lastUpdate,t);
      if (iVar2 != 0) {
        if (0 < iVar2) {
          param_1->error = 0xb;
          iVar2 = (*param_1->verify_cb)(0,param_1);
          if (iVar2 == 0) goto LAB_0016104c;
        }
LAB_00160fce:
        s = param_2->crl->nextUpdate;
        if (s != (ASN1_TIME *)0x0) {
          iVar2 = X509_cmp_time(s,t);
          if (iVar2 == 0) {
            param_1->error = 0x10;
            iVar2 = (*param_1->verify_cb)(0,param_1);
          }
          else {
            if ((-1 < iVar2) || ((param_1->current_crl_score & 2U) != 0)) goto LAB_00160fec;
            param_1->error = 0xc;
            iVar2 = (*param_1->verify_cb)(0,param_1);
          }
          if (iVar2 == 0) goto LAB_0016104c;
        }
LAB_00160fec:
        param_1->current_crl = (X509_CRL *)0x0;
        goto LAB_00160ff0;
      }
      param_1->error = 0xf;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 != 0) goto LAB_00160fce;
    }
LAB_0016104c:
    iVar2 = 0;
    r = (EVP_PKEY *)0x0;
  }
LAB_0016101a:
  EVP_PKEY_free(r);
  return iVar2;
}

