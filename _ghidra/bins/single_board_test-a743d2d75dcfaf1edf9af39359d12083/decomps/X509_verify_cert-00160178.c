
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
  void *pvVar11;
  X509_NAME *nm;
  _STACK *st;
  _func_1998 *p_Var12;
  ulong uVar13;
  X509 *pXVar14;
  _func_1998 *p_Var15;
  char *pcVar16;
  X509_VERIFY_PARAM *pXVar17;
  int iVar18;
  uint uVar19;
  _func_2006 *p_Var20;
  int iVar21;
  bool bVar22;
  X509 *local_44;
  int local_3c;
  X509 *local_2c [2];
  
  pXVar17 = ctx->param;
  if (ctx->cert == (X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x69,"x509_vfy.c",0xc6);
    return -1;
  }
  p_Var12 = ctx->verify_cb;
  if (ctx->chain == (stack_st_X509 *)0x0) {
    p_Var3 = sk_new_null();
    ctx->chain = (stack_st_X509 *)p_Var3;
    if ((p_Var3 != (_STACK *)0x0) && (iVar4 = sk_push(p_Var3,ctx->cert), iVar4 != 0)) {
      CRYPTO_add_lock(&ctx->cert->references,1,3,"x509_vfy.c",0xd6);
      ctx->last_untrusted = 1;
      goto LAB_00160196;
    }
    p_Var3 = (_STACK *)0x0;
    pXVar14 = (X509 *)0x0;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xd3);
    local_44 = (X509 *)0x0;
  }
  else {
LAB_00160196:
    if (&ctx->untrusted->stack == (_STACK *)0x0) {
      p_Var3 = (_STACK *)0x0;
LAB_001601aa:
      iVar4 = sk_num(&ctx->chain->stack);
      pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar4 + -1);
      iVar21 = pXVar17->depth;
      while ((iVar4 <= iVar21 &&
             (X509_check_purpose(pXVar5,-1,0), -1 < (int)(pXVar5->ex_flags << 0x12)))) {
        if ((int)(ctx->param->flags << 0x10) < 0) {
          pXVar14 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
          if ((int)pXVar14 < 0) {
            return (int)pXVar14;
          }
          if (pXVar14 != (X509 *)0x0) {
            X509_free(local_2c[0]);
            goto LAB_0016021e;
          }
        }
        pXVar14 = (X509 *)ctx->untrusted;
        if (pXVar14 == (X509 *)0x0) goto LAB_0016021e;
        iVar18 = 0;
        do {
          iVar6 = sk_num(p_Var3);
          if (iVar6 <= iVar18) {
            pXVar14 = (X509 *)0x0;
            local_2c[0] = (X509 *)0x0;
            goto LAB_0016021e;
          }
          pXVar14 = (X509 *)sk_value(p_Var3,iVar18);
          iVar6 = (*ctx->check_issued)(ctx,pXVar5,pXVar14);
          iVar18 = iVar18 + 1;
        } while (iVar6 == 0);
        local_2c[0] = pXVar14;
        if (pXVar14 == (X509 *)0x0) goto LAB_0016021e;
        iVar18 = sk_push(&ctx->chain->stack,pXVar14);
        if (iVar18 == 0) {
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x106);
          pXVar14 = (X509 *)0x0;
          local_44 = (X509 *)0x0;
          goto LAB_001602a4;
        }
        iVar4 = iVar4 + 1;
        CRYPTO_add_lock(&local_2c[0]->references,1,3,"x509_vfy.c",0x109);
        sk_delete_ptr(p_Var3,local_2c[0]);
        ctx->last_untrusted = ctx->last_untrusted + 1;
        pXVar5 = local_2c[0];
      }
      pXVar14 = (X509 *)0x0;
LAB_0016021e:
      bVar1 = false;
      local_44 = (X509 *)0x0;
      iVar18 = iVar4;
LAB_0016022a:
      iVar7 = sk_num(&ctx->chain->stack);
      iVar7 = iVar7 + -1;
      pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar7);
      X509_check_purpose(pXVar5,-1,0);
      iVar6 = iVar18;
      if ((int)(pXVar5->ex_flags << 0x12) < 0) {
        iVar8 = sk_num(&ctx->chain->stack);
        if (iVar8 == 1) {
          pXVar14 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
          if ((int)pXVar14 < 1) {
            ctx->current_cert = pXVar5;
            ctx->error = 0x12;
            ctx->error_depth = iVar7;
          }
          else {
            iVar18 = X509_cmp(pXVar5,local_2c[0]);
            if (iVar18 == 0) {
              X509_free(pXVar5);
              pXVar5 = local_2c[0];
              sk_set(&ctx->chain->stack,iVar7,local_2c[0]);
              ctx->last_untrusted = 0;
              goto LAB_00160318;
            }
            ctx->error = 0x12;
            ctx->current_cert = pXVar5;
            ctx->error_depth = iVar7;
            if (pXVar14 == (X509 *)0x1) {
              X509_free(local_2c[0]);
            }
          }
          pXVar14 = (X509 *)(*p_Var12)(0,ctx);
          if (pXVar14 == (X509 *)0x0) goto LAB_001602a4;
          bVar1 = true;
        }
        else {
          local_44 = (X509 *)sk_pop(&ctx->chain->stack);
          iVar4 = iVar4 + -1;
          ctx->last_untrusted = ctx->last_untrusted + -1;
          pXVar5 = (X509 *)sk_value(&ctx->chain->stack,iVar18 + -2);
          iVar6 = iVar18 + -1;
        }
      }
LAB_00160318:
      while (pXVar2 = local_44, iVar6 <= iVar21) {
        X509_check_purpose(pXVar5,-1,0);
        if ((int)(pXVar5->ex_flags << 0x12) < 0) break;
        pXVar14 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar5);
        pXVar9 = local_2c[0];
        if ((int)pXVar14 < 0) {
          return (int)pXVar14;
        }
        if (pXVar14 == (X509 *)0x0) break;
        iVar18 = sk_push(&ctx->chain->stack,local_2c[0]);
        pXVar5 = pXVar9;
        iVar6 = iVar6 + 1;
        if (iVar18 == 0) {
          X509_free(local_2c[0]);
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x15e);
          return 0;
        }
      }
      p_Var15 = ctx->verify_cb;
      for (iVar18 = ctx->last_untrusted; iVar7 = sk_num(&ctx->chain->stack), iVar18 < iVar7;
          iVar18 = iVar18 + 1) {
        pXVar9 = (X509 *)sk_value(&ctx->chain->stack,iVar18);
        iVar7 = X509_check_trust(pXVar9,ctx->param->trust,0);
        if (iVar7 == 1) goto LAB_001603a8;
        if (iVar7 == 2) {
          ctx->error_depth = iVar18;
          ctx->current_cert = pXVar9;
          ctx->error = 0x1c;
          iVar7 = (*p_Var15)(0,ctx);
          if (iVar7 == 0) goto LAB_001602a4;
        }
      }
      pXVar17 = ctx->param;
      if ((int)(pXVar17->flags << 0xc) < 0) {
        iVar7 = ctx->last_untrusted;
        iVar18 = sk_num(&ctx->chain->stack);
        if (iVar18 <= iVar7) {
          pXVar14 = (X509 *)sk_value(&ctx->chain->stack,0);
          p_Var20 = ctx->lookup_certs;
          nm = X509_get_subject_name(pXVar14);
          st = &(*p_Var20)(ctx,nm)->stack;
          if (st != (_STACK *)0x0) {
            pXVar9 = (X509 *)0x0;
            for (iVar18 = 0; iVar7 = sk_num(st), iVar18 < iVar7; iVar18 = iVar18 + 1) {
              pXVar9 = (X509 *)sk_value(st,iVar18);
              iVar7 = X509_cmp(pXVar9,pXVar14);
              if (iVar7 == 0) break;
            }
            iVar7 = sk_num(st);
            if (iVar18 < iVar7) {
              CRYPTO_add_lock(&pXVar9->references,1,3,"x509_vfy.c",0xb5);
              sk_pop_free(st,X509_free);
              if (pXVar9 != (X509 *)0x0) {
                sk_set(&ctx->chain->stack,0,pXVar9);
                X509_free(pXVar14);
                ctx->last_untrusted = 0;
                goto LAB_001603a8;
              }
            }
            else {
              sk_pop_free(st,X509_free);
            }
          }
          pXVar17 = ctx->param;
          goto LAB_0016053c;
        }
      }
      else {
LAB_0016053c:
        if ((pXVar17->flags & 0x108000) == 0) {
          iVar18 = iVar4 + -1;
          do {
            iVar4 = iVar18;
            if (iVar4 + 1 < 2) goto LAB_00160544;
            pXVar14 = (X509 *)sk_value(&ctx->chain->stack,iVar4 + -1);
            pXVar14 = (X509 *)(*ctx->get_issuer)(local_2c,ctx,pXVar14);
            if ((int)pXVar14 < 0) goto LAB_001602a4;
            iVar18 = iVar4 + -1;
          } while (pXVar14 == (X509 *)0x0);
          X509_free(local_2c[0]);
          iVar18 = iVar6;
          if (iVar4 < iVar6) {
            do {
              iVar6 = iVar6 + -1;
              local_2c[0] = (X509 *)sk_pop(&ctx->chain->stack);
              X509_free(local_2c[0]);
              ctx->last_untrusted = ctx->last_untrusted + -1;
              iVar18 = iVar4;
            } while (iVar6 != iVar4);
          }
          goto LAB_0016022a;
        }
LAB_00160544:
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
          pXVar14 = (X509 *)(*p_Var12)(0,ctx);
          if (pXVar14 != (X509 *)0x0) {
            bVar1 = true;
            goto LAB_001603a8;
          }
          goto LAB_001602a4;
        }
      }
LAB_001603a8:
      p_Var15 = ctx->verify_cb;
      if (ctx->parent == (X509_STORE_CTX *)0x0) {
        uVar13 = ctx->param->flags;
        pcVar16 = getenv("OPENSSL_ALLOW_PROXY_CERTS");
        uVar19 = (uVar13 << 0x19) >> 0x1f;
        if (pcVar16 != (char *)0x0) {
          uVar19 = 1;
        }
        local_3c = ctx->param->purpose;
      }
      else {
        uVar19 = 0;
        local_3c = 6;
      }
      if (ctx->last_untrusted < 1) goto LAB_001604c6;
      iVar18 = 0;
      iVar21 = -1;
      iVar6 = 0;
      iVar4 = 0;
      goto LAB_001603d6;
    }
    p_Var3 = sk_dup(&ctx->untrusted->stack);
    if (p_Var3 != (_STACK *)0x0) goto LAB_001601aa;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xdd);
    pXVar14 = (X509 *)0x0;
    local_44 = (X509 *)0x0;
  }
  goto LAB_001602a4;
LAB_001603d6:
  do {
    pXVar14 = (X509 *)sk_value(&ctx->chain->stack,iVar4);
    if (((ctx->param->flags & 0x10) == 0) && ((int)(pXVar14->ex_flags << 0x16) < 0)) {
      ctx->error_depth = iVar4;
      ctx->error = 0x22;
      ctx->current_cert = pXVar14;
      iVar7 = (*p_Var15)(0,ctx);
      if (iVar7 == 0) goto LAB_00160684;
    }
    if ((uVar19 == 0) && ((int)(pXVar14->ex_flags << 0x15) < 0)) {
      ctx->error = 0x28;
      ctx->error_depth = iVar4;
      ctx->current_cert = pXVar14;
      iVar7 = (*p_Var15)(0,ctx);
      if (iVar7 == 0) goto LAB_00160684;
    }
    uVar10 = X509_check_ca(pXVar14);
    if (iVar21 == -1) {
      pXVar17 = ctx->param;
      if (((int)(pXVar17->flags << 0x1a) < 0) && (1 < uVar10)) {
LAB_001606dc:
        ctx->error = 0x18;
LAB_0016041e:
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar14;
        iVar7 = (*p_Var15)(0,ctx);
        if (iVar7 != 0) goto LAB_00160432;
        goto LAB_00160684;
      }
    }
    else if (iVar21 == 0) {
      if (uVar10 != 0) {
        ctx->error = 0x25;
        goto LAB_0016041e;
      }
LAB_00160432:
      pXVar17 = ctx->param;
    }
    else if ((uVar10 == 0) ||
            ((pXVar17 = ctx->param, (int)(pXVar17->flags << 0x1a) < 0 && (uVar10 != 1))))
    goto LAB_001606dc;
    if ((0 < pXVar17->purpose) &&
       ((iVar21 = X509_check_purpose(pXVar14,local_3c,(uint)(0 < iVar21)), iVar21 == 0 ||
        (((int)(ctx->param->flags << 0x1a) < 0 && (iVar21 != 1)))))) {
      ctx->error = 0x1a;
      ctx->error_depth = iVar4;
      ctx->current_cert = pXVar14;
      iVar21 = (*p_Var15)(0,ctx);
      if (iVar21 == 0) goto LAB_00160684;
    }
    if (iVar4 < 2) {
LAB_001606be:
      uVar13 = pXVar14->ex_flags;
      if (-1 < (int)(uVar13 << 0x1a)) {
LAB_00160498:
        iVar18 = iVar18 + 1;
      }
    }
    else {
      uVar13 = pXVar14->ex_flags;
      if ((uVar13 & 0x20) == 0) {
        if ((pXVar14->ex_pathlen == -1) || (iVar18 <= pXVar14->ex_pathlen + iVar6 + 1))
        goto LAB_00160498;
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar14;
        ctx->error = 0x19;
        iVar21 = (*p_Var15)(0,ctx);
        if (iVar21 != 0) goto LAB_001606be;
        goto LAB_00160684;
      }
    }
    if ((int)(uVar13 << 0x15) < 0) {
      if ((pXVar14->ex_pcpathlen != -1) && (pXVar14->ex_pcpathlen < iVar4)) {
        ctx->error_depth = iVar4;
        ctx->current_cert = pXVar14;
        ctx->error = 0x26;
        iVar21 = (*p_Var15)(0,ctx);
        if (iVar21 == 0) goto LAB_00160684;
      }
      iVar6 = iVar6 + 1;
      iVar21 = 0;
    }
    else {
      iVar21 = 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < ctx->last_untrusted);
LAB_001604c6:
  iVar4 = sk_num(&ctx->chain->stack);
  iVar4 = iVar4 + -1;
  if (-1 < iVar4) {
    do {
      pXVar14 = (X509 *)sk_value(&ctx->chain->stack,iVar4);
      if ((iVar4 == 0) || (-1 < (int)(pXVar14->ex_flags << 0x1a))) {
        iVar21 = sk_num(&ctx->chain->stack);
        iVar21 = iVar21 + -1;
        if (iVar4 < iVar21) {
          do {
            pvVar11 = sk_value(&ctx->chain->stack,iVar21);
            iVar21 = iVar21 + -1;
            if ((*(NAME_CONSTRAINTS **)((int)pvVar11 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
               (iVar18 = NAME_CONSTRAINTS_check(pXVar14,*(NAME_CONSTRAINTS **)((int)pvVar11 + 0x4c))
               , iVar18 != 0)) {
              ctx->error = iVar18;
              ctx->error_depth = iVar4;
              ctx->current_cert = pXVar14;
              iVar18 = (*ctx->verify_cb)(0,ctx);
              if (iVar18 == 0) {
                pXVar14 = (X509 *)0x0;
                goto LAB_001602a4;
              }
            }
          } while (iVar21 != iVar4);
        }
      }
      bVar22 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar22);
  }
  pXVar14 = ctx->cert;
  pcVar16 = ctx->param[1].name;
  if (*(_STACK **)pcVar16 == (_STACK *)0x0) {
LAB_001608f8:
    if ((*(int *)(pcVar16 + 0xc) != 0) &&
       (iVar4 = X509_check_email(pXVar14,*(int *)(pcVar16 + 0xc),*(undefined4 *)(pcVar16 + 0x10),0),
       iVar4 < 1)) {
      ctx->error = 0x3f;
      ctx->error_depth = 0;
      ctx->current_cert = ctx->cert;
      iVar4 = (*ctx->verify_cb)(0,ctx);
      if (iVar4 == 0) goto LAB_00160684;
    }
    if ((*(int *)(pcVar16 + 0x14) != 0) &&
       (iVar4 = X509_check_ip(pXVar14,*(int *)(pcVar16 + 0x14),*(undefined4 *)(pcVar16 + 0x18),0),
       iVar4 < 1)) {
      ctx->error = 0x40;
      ctx->error_depth = 0;
      ctx->current_cert = ctx->cert;
      iVar4 = (*ctx->verify_cb)(0,ctx);
      if (iVar4 == 0) goto LAB_00160684;
    }
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
    pXVar14 = (X509 *)(*ctx->check_revocation)(ctx);
    if (pXVar14 != (X509 *)0x0) {
      iVar4 = X509_chain_check_suiteb(&ctx->error_depth,0,ctx->chain,ctx->param->flags);
      if (iVar4 != 0) {
        ctx->error = iVar4;
        pXVar14 = (X509 *)sk_value(&ctx->chain->stack,ctx->error_depth);
        ctx->current_cert = pXVar14;
        pXVar14 = (X509 *)(*p_Var12)(0,ctx);
        if (pXVar14 == (X509 *)0x0) goto LAB_001602a4;
      }
      if (ctx->verify == (_func_1997 *)0x0) {
        pXVar14 = (X509 *)internal_verify(ctx);
      }
      else {
        pXVar14 = (X509 *)(*ctx->verify)(ctx);
      }
      if ((pXVar14 != (X509 *)0x0) &&
         (((bVar1 || (-1 < (int)(ctx->param->flags << 0x18))) ||
          (pXVar14 = (X509 *)(*ctx->check_policy)(ctx), pXVar14 != (X509 *)0x0))))
      goto LAB_001602ac;
    }
  }
  else {
    iVar4 = sk_num(*(_STACK **)pcVar16);
    if (iVar4 < 1) {
      if (iVar4 == 0) goto LAB_001608f8;
    }
    else {
      iVar21 = 0;
      do {
        pvVar11 = sk_value(*(_STACK **)pcVar16,iVar21);
        iVar21 = iVar21 + 1;
        iVar18 = X509_check_host(pXVar14,pvVar11,0,*(undefined4 *)(pcVar16 + 4),pcVar16 + 8);
        if (0 < iVar18) goto LAB_001608f8;
      } while (iVar21 != iVar4);
    }
    ctx->error = 0x3e;
    ctx->error_depth = 0;
    ctx->current_cert = ctx->cert;
    iVar4 = (*ctx->verify_cb)(0,ctx);
    if (iVar4 != 0) goto LAB_001608f8;
LAB_00160684:
    pXVar14 = (X509 *)0x0;
  }
LAB_001602a4:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
LAB_001602ac:
  if (p_Var3 != (_STACK *)0x0) {
    sk_free(p_Var3);
  }
  if (local_44 != (X509 *)0x0) {
    X509_free(local_44);
  }
  return (int)pXVar14;
}

