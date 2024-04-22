
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  bool bVar1;
  X509 *pXVar2;
  _STACK *p_Var3;
  int iVar4;
  X509 *pXVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  X509 *pXVar9;
  uint uVar10;
  char *pcVar11;
  void *pvVar12;
  X509_NAME *nm;
  _STACK *st;
  _func_1998 *p_Var13;
  ulong uVar14;
  X509 *pXVar15;
  _func_1998 *p_Var16;
  _STACK **pp_Var17;
  X509_VERIFY_PARAM *pXVar18;
  int iVar19;
  uint uVar20;
  _func_2006 *p_Var21;
  int iVar22;
  bool bVar23;
  X509 *local_44;
  int local_3c;
  X509 *local_2c [2];
  
  pXVar18 = ctx->param;
  if (ctx->cert == (X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x69,DAT_000c2194,0xc6);
    return -1;
  }
  p_Var13 = ctx->verify_cb;
  if (ctx->chain == (stack_st_X509 *)0x0) {
    p_Var3 = sk_new_null();
    ctx->chain = (stack_st_X509 *)p_Var3;
    if ((p_Var3 != (_STACK *)0x0) && (iVar4 = sk_push(p_Var3,ctx->cert), iVar4 != 0)) {
      CRYPTO_add_lock(&ctx->cert->references,1,3,DAT_000c2008,0xd6);
      ctx->last_untrusted = 1;
      goto LAB_000c1956;
    }
    p_Var3 = (_STACK *)0x0;
    pXVar15 = (X509 *)0x0;
    ERR_put_error(0xb,0x7f,0x41,DAT_000c2008,0xd3);
    local_44 = (X509 *)0x0;
  }
  else {
LAB_000c1956:
    if (&ctx->untrusted->stack == (_STACK *)0x0) {
      p_Var3 = (_STACK *)0x0;
LAB_000c196a:
      iVar4 = sk_num(&ctx->chain->stack);
      pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar4 + -1);
      iVar22 = pXVar18->depth;
      while ((iVar4 <= iVar22 &&
             (X509_check_purpose(pXVar5,-1,0), -1 < (int)(pXVar5->ex_flags << 0x12)))) {
        if ((int)(ctx->param->flags << 0x10) < 0) {
          pXVar15 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
          if ((int)pXVar15 < 0) {
            return (int)pXVar15;
          }
          if (pXVar15 != (X509 *)0x0) {
            X509_free(local_2c[0]);
            goto LAB_000c19de;
          }
        }
        pXVar15 = (X509 *)ctx->untrusted;
        if (pXVar15 == (X509 *)0x0) goto LAB_000c19de;
        iVar19 = 0;
        do {
          iVar6 = sk_num(p_Var3);
          if (iVar6 <= iVar19) {
            pXVar15 = (X509 *)0x0;
            local_2c[0] = (X509 *)0x0;
            goto LAB_000c19de;
          }
          pXVar15 = (X509 *)sk_value(p_Var3,iVar19);
          iVar6 = (*ctx->check_issued)(ctx,pXVar5,pXVar15);
          iVar19 = iVar19 + 1;
        } while (iVar6 == 0);
        local_2c[0] = pXVar15;
        if (pXVar15 == (X509 *)0x0) goto LAB_000c19de;
        iVar19 = sk_push(&ctx->chain->stack,pXVar15);
        if (iVar19 == 0) {
          ERR_put_error(0xb,0x7f,0x41,DAT_000c1cec,0x106);
          pXVar15 = (X509 *)0x0;
          local_44 = (X509 *)0x0;
          goto LAB_000c1a64;
        }
        iVar4 = iVar4 + 1;
        CRYPTO_add_lock(&local_2c[0]->references,1,3,DAT_000c1cec,0x109);
        sk_delete_ptr(p_Var3,local_2c[0]);
        ctx->last_untrusted = ctx->last_untrusted + 1;
        pXVar5 = local_2c[0];
      }
      pXVar15 = (X509 *)0x0;
LAB_000c19de:
      bVar1 = false;
      local_44 = (X509 *)0x0;
      iVar19 = iVar4;
LAB_000c19ea:
      iVar7 = sk_num(&ctx->chain->stack);
      iVar7 = iVar7 + -1;
      pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar7);
      X509_check_purpose(pXVar5,-1,0);
      iVar6 = iVar19;
      if ((int)(pXVar5->ex_flags << 0x12) < 0) {
        iVar8 = sk_num(&ctx->chain->stack);
        if (iVar8 == 1) {
          pXVar15 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
          if ((int)pXVar15 < 1) {
            ctx->current_cert = pXVar5;
            ctx->error = 0x12;
            ctx->error_depth = iVar7;
          }
          else {
            iVar19 = X509_cmp(pXVar5,local_2c[0]);
            if (iVar19 == 0) {
              X509_free(pXVar5);
              pXVar5 = local_2c[0];
              sk_set(&ctx->chain->stack,iVar7,local_2c[0]);
              ctx->last_untrusted = 0;
              goto LAB_000c1ad8;
            }
            ctx->error = 0x12;
            ctx->current_cert = pXVar5;
            ctx->error_depth = iVar7;
            if (pXVar15 == (X509 *)0x1) {
              X509_free(local_2c[0]);
            }
          }
          pXVar15 = (X509 *)(*p_Var13)(0,ctx);
          if (pXVar15 == (X509 *)0x0) goto LAB_000c1a64;
          bVar1 = true;
        }
        else {
          local_44 = (X509 *)sk_pop(&ctx->chain->stack);
          iVar4 = iVar4 + -1;
          ctx->last_untrusted = ctx->last_untrusted + -1;
          pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar19 + -2);
          iVar6 = iVar19 + -1;
        }
      }
LAB_000c1ad8:
      while (pXVar2 = local_44, iVar6 <= iVar22) {
        X509_check_purpose(pXVar5,-1,0);
        if ((int)(pXVar5->ex_flags << 0x12) < 0) break;
        pXVar15 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
        pXVar9 = local_2c[0];
        if ((int)pXVar15 < 0) {
          return (int)pXVar15;
        }
        if (pXVar15 == (X509 *)0x0) break;
        iVar19 = sk_push(&ctx->chain->stack,local_2c[0]);
        pXVar5 = pXVar9;
        iVar6 = iVar6 + 1;
        if (iVar19 == 0) {
          X509_free(local_2c[0]);
          ERR_put_error(0xb,0x7f,0x41,DAT_000c2008,0x15e);
          return 0;
        }
      }
      p_Var16 = ctx->verify_cb;
      for (iVar19 = ctx->last_untrusted; iVar7 = sk_num(&ctx->chain->stack), iVar19 < iVar7;
          iVar19 = iVar19 + 1) {
        pXVar9 = (X509 *)sk_value(&ctx->chain->stack,iVar19);
        iVar7 = X509_check_trust(pXVar9,ctx->param->trust,0);
        if (iVar7 == 1) goto LAB_000c1b68;
        if (iVar7 == 2) {
          ctx->error_depth = iVar19;
          ctx->current_cert = pXVar9;
          ctx->error = 0x1c;
          iVar7 = (*p_Var16)(0,ctx);
          if (iVar7 == 0) goto LAB_000c1a64;
        }
      }
      pXVar18 = ctx->param;
      if ((int)(pXVar18->flags << 0xc) < 0) {
        iVar7 = ctx->last_untrusted;
        iVar19 = sk_num(&ctx->chain->stack);
        if (iVar19 <= iVar7) {
          pXVar15 = (X509 *)sk_value(&ctx->chain->stack,0);
          p_Var21 = ctx->lookup_certs;
          nm = X509_get_subject_name(pXVar15);
          st = &(*p_Var21)(ctx,nm)->stack;
          if (st != (_STACK *)0x0) {
            pXVar9 = (X509 *)0x0;
            for (iVar19 = 0; iVar7 = sk_num(st), iVar19 < iVar7; iVar19 = iVar19 + 1) {
              pXVar9 = (X509 *)sk_value(st,iVar19);
              iVar7 = X509_cmp(pXVar9,pXVar15);
              if (iVar7 == 0) break;
            }
            iVar7 = sk_num(st);
            if (iVar19 < iVar7) {
              CRYPTO_add_lock(&pXVar9->references,1,3,DAT_000c2194,0xb5);
              sk_pop_free(st,DAT_000c2198);
              if (pXVar9 != (X509 *)0x0) {
                sk_set(&ctx->chain->stack,0,pXVar9);
                X509_free(pXVar15);
                ctx->last_untrusted = 0;
                goto LAB_000c1b68;
              }
            }
            else {
              sk_pop_free(st,DAT_000c2010);
            }
          }
          pXVar18 = ctx->param;
          goto LAB_000c1cfc;
        }
      }
      else {
LAB_000c1cfc:
        if ((pXVar18->flags & 0x108000) == 0) {
          iVar19 = iVar4 + -1;
          do {
            iVar4 = iVar19;
            if (iVar4 + 1 < 2) goto LAB_000c1d04;
            pXVar15 = (X509 *)sk_value(&ctx->chain->stack,iVar4 + -1);
            pXVar15 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar15);
            if ((int)pXVar15 < 0) goto LAB_000c1a64;
            iVar19 = iVar4 + -1;
          } while (pXVar15 == (X509 *)0x0);
          X509_free(local_2c[0]);
          iVar19 = iVar6;
          if (iVar4 < iVar6) {
            do {
              iVar6 = iVar6 + -1;
              local_2c[0] = (X509 *)sk_pop(&ctx->chain->stack);
              X509_free(local_2c[0]);
              ctx->last_untrusted = ctx->last_untrusted + -1;
              iVar19 = iVar4;
            } while (iVar6 != iVar4);
          }
          goto LAB_000c19ea;
        }
LAB_000c1d04:
        if (!bVar1) {
          if ((local_44 == (X509 *)0x0) ||
             (iVar4 = (*ctx->check_issued)(ctx,pXVar5,local_44), iVar4 == 0)) {
            ctx->current_cert = pXVar5;
            if (ctx->last_untrusted < iVar6) {
              iVar4 = 2;
            }
            else {
              iVar4 = 0x14;
            }
            ctx->error = iVar4;
          }
          else {
            iVar6 = iVar6 + 1;
            sk_push(&ctx->chain->stack,local_44);
            local_44 = (X509 *)0x0;
            ctx->last_untrusted = iVar6;
            ctx->current_cert = pXVar2;
            ctx->error = 0x13;
          }
          ctx->error_depth = iVar6 + -1;
          pXVar15 = (X509 *)(*p_Var13)(0,ctx);
          if (pXVar15 != (X509 *)0x0) {
            bVar1 = true;
            goto LAB_000c1b68;
          }
          goto LAB_000c1a64;
        }
      }
LAB_000c1b68:
      p_Var16 = ctx->verify_cb;
      if (ctx->parent == (X509_STORE_CTX *)0x0) {
        uVar14 = ctx->param->flags;
        pcVar11 = getenv(DAT_000c200c);
        uVar20 = (uVar14 << 0x19) >> 0x1f;
        if (pcVar11 != (char *)0x0) {
          uVar20 = 1;
        }
        local_3c = ctx->param->purpose;
      }
      else {
        uVar20 = 0;
        local_3c = 6;
      }
      if (ctx->last_untrusted < 1) goto LAB_000c1c86;
      iVar19 = 0;
      iVar22 = -1;
      iVar6 = 0;
      iVar4 = 0;
      goto LAB_000c1b96;
    }
    p_Var3 = sk_dup(&ctx->untrusted->stack);
    if (p_Var3 != (_STACK *)0x0) goto LAB_000c196a;
    ERR_put_error(0xb,0x7f,0x41,DAT_000c2008,0xdd);
    pXVar15 = (X509 *)0x0;
    local_44 = (X509 *)0x0;
  }
  goto LAB_000c1a64;
LAB_000c1b96:
  do {
    pXVar15 = (X509 *)sk_value(&ctx->chain->stack,iVar4);
    if (((ctx->param->flags & 0x10) == 0) && ((int)(pXVar15->ex_flags << 0x16) < 0)) {
      ctx->error_depth = iVar4;
      ctx->error = 0x22;
      ctx->current_cert = pXVar15;
      iVar7 = (*p_Var16)(0,ctx);
      if (iVar7 == 0) goto LAB_000c1e44;
    }
    if ((uVar20 == 0) && ((int)(pXVar15->ex_flags << 0x15) < 0)) {
      ctx->error = 0x28;
      ctx->error_depth = iVar4;
      ctx->current_cert = pXVar15;
      iVar7 = (*p_Var16)(0,ctx);
      if (iVar7 == 0) goto LAB_000c1e44;
    }
    uVar10 = X509_check_ca(pXVar15);
    if (iVar22 == -1) {
      pXVar18 = ctx->param;
      if (((int)(pXVar18->flags << 0x1a) < 0) && (1 < uVar10)) {
LAB_000c1e9c:
        ctx->error = 0x18;
LAB_000c1bde:
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar15;
        iVar7 = (*p_Var16)(0,ctx);
        if (iVar7 != 0) goto LAB_000c1bf2;
        goto LAB_000c1e44;
      }
    }
    else if (iVar22 == 0) {
      if (uVar10 != 0) {
        ctx->error = 0x25;
        goto LAB_000c1bde;
      }
LAB_000c1bf2:
      pXVar18 = ctx->param;
    }
    else if ((uVar10 == 0) ||
            ((pXVar18 = ctx->param, (int)(pXVar18->flags << 0x1a) < 0 && (uVar10 != 1))))
    goto LAB_000c1e9c;
    if ((0 < pXVar18->purpose) &&
       ((iVar22 = X509_check_purpose(pXVar15,local_3c,(uint)(0 < iVar22)), iVar22 == 0 ||
        (((int)(ctx->param->flags << 0x1a) < 0 && (iVar22 != 1)))))) {
      ctx->error = 0x1a;
      ctx->error_depth = iVar4;
      ctx->current_cert = pXVar15;
      iVar22 = (*p_Var16)(0,ctx);
      if (iVar22 == 0) goto LAB_000c1e44;
    }
    if (iVar4 < 2) {
LAB_000c1e7e:
      uVar14 = pXVar15->ex_flags;
      if (-1 < (int)(uVar14 << 0x1a)) {
LAB_000c1c58:
        iVar19 = iVar19 + 1;
      }
    }
    else {
      uVar14 = pXVar15->ex_flags;
      if ((uVar14 & 0x20) == 0) {
        if ((pXVar15->ex_pathlen == -1) || (iVar19 <= pXVar15->ex_pathlen + iVar6 + 1))
        goto LAB_000c1c58;
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar15;
        ctx->error = 0x19;
        iVar22 = (*p_Var16)(0,ctx);
        if (iVar22 != 0) goto LAB_000c1e7e;
        goto LAB_000c1e44;
      }
    }
    if ((int)(uVar14 << 0x15) < 0) {
      if ((pXVar15->ex_pcpathlen != -1) && (pXVar15->ex_pcpathlen < iVar4)) {
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar15;
        ctx->error = 0x26;
        iVar22 = (*p_Var16)(0,ctx);
        if (iVar22 == 0) goto LAB_000c1e44;
      }
      iVar6 = iVar6 + 1;
      iVar22 = 0;
    }
    else {
      iVar22 = 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < ctx->last_untrusted);
LAB_000c1c86:
  iVar4 = sk_num(&ctx->chain->stack);
  iVar4 = iVar4 + -1;
  if (-1 < iVar4) {
    do {
      pXVar15 = (X509 *)sk_value(&ctx->chain->stack,iVar4);
      if ((iVar4 == 0) || (-1 < (int)(pXVar15->ex_flags << 0x1a))) {
        iVar22 = sk_num(&ctx->chain->stack);
        iVar22 = iVar22 + -1;
        if (iVar4 < iVar22) {
          do {
            pvVar12 = sk_value(&ctx->chain->stack,iVar22);
            iVar22 = iVar22 + -1;
            if ((*(NAME_CONSTRAINTS **)((int)pvVar12 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
               (iVar19 = NAME_CONSTRAINTS_check(pXVar15,*(NAME_CONSTRAINTS **)((int)pvVar12 + 0x4c))
               , iVar19 != 0)) {
              ctx->error = iVar19;
              ctx->error_depth = iVar4;
              ctx->current_cert = pXVar15;
              iVar19 = (*ctx->verify_cb)(0,ctx);
              if (iVar19 == 0) {
                pXVar15 = (X509 *)0x0;
                goto LAB_000c1a64;
              }
            }
          } while (iVar22 != iVar4);
        }
      }
      bVar23 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar23);
  }
  pXVar15 = ctx->cert;
  pp_Var17 = (_STACK **)ctx->param[1].name;
  if (*pp_Var17 == (_STACK *)0x0) {
LAB_000c20b8:
    if ((pp_Var17[3] != (_STACK *)0x0) &&
       (iVar4 = X509_check_email(pXVar15,pp_Var17[3],pp_Var17[4],0), iVar4 < 1)) {
      ctx->error = 0x3f;
      ctx->error_depth = 0;
      ctx->current_cert = ctx->cert;
      iVar4 = (*ctx->verify_cb)(0,ctx);
      if (iVar4 == 0) goto LAB_000c1e44;
    }
    if ((pp_Var17[5] != (_STACK *)0x0) &&
       (iVar4 = X509_check_ip(pXVar15,pp_Var17[5],pp_Var17[6],0), iVar4 < 1)) {
      ctx->error = 0x40;
      ctx->error_depth = 0;
      ctx->current_cert = ctx->cert;
      iVar4 = (*ctx->verify_cb)(0,ctx);
      if (iVar4 == 0) goto LAB_000c1e44;
    }
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
    pXVar15 = (X509 *)(*ctx->check_revocation)(ctx);
    if (pXVar15 != (X509 *)0x0) {
      iVar4 = X509_chain_check_suiteb(&ctx->error_depth,0,ctx->chain,ctx->param->flags);
      if (iVar4 != 0) {
        ctx->error = iVar4;
        pXVar15 = (X509 *)sk_value(&ctx->chain->stack,ctx->error_depth);
        ctx->current_cert = pXVar15;
        pXVar15 = (X509 *)(*p_Var13)(0,ctx);
        if (pXVar15 == (X509 *)0x0) goto LAB_000c1a64;
      }
      if (ctx->verify == (_func_1997 *)0x0) {
        pXVar15 = (X509 *)internal_verify(ctx);
      }
      else {
        pXVar15 = (X509 *)(*ctx->verify)(ctx);
      }
      if ((pXVar15 != (X509 *)0x0) &&
         (((bVar1 || (-1 < (int)(ctx->param->flags << 0x18))) ||
          (pXVar15 = (X509 *)(*ctx->check_policy)(ctx), pXVar15 != (X509 *)0x0))))
      goto LAB_000c1a6c;
    }
  }
  else {
    iVar4 = sk_num(*pp_Var17);
    if (iVar4 < 1) {
      if (iVar4 == 0) goto LAB_000c20b8;
    }
    else {
      iVar22 = 0;
      do {
        pvVar12 = sk_value(*pp_Var17,iVar22);
        iVar22 = iVar22 + 1;
        iVar19 = X509_check_host(pXVar15,pvVar12,0,pp_Var17[1],pp_Var17 + 2);
        if (0 < iVar19) goto LAB_000c20b8;
      } while (iVar22 != iVar4);
    }
    ctx->error = 0x3e;
    ctx->error_depth = 0;
    ctx->current_cert = ctx->cert;
    iVar4 = (*ctx->verify_cb)(0,ctx);
    if (iVar4 != 0) goto LAB_000c20b8;
LAB_000c1e44:
    pXVar15 = (X509 *)0x0;
  }
LAB_000c1a64:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
LAB_000c1a6c:
  if (p_Var3 != (_STACK *)0x0) {
    sk_free(p_Var3);
  }
  if (local_44 != (X509 *)0x0) {
    X509_free(local_44);
  }
  return (int)pXVar15;
}

