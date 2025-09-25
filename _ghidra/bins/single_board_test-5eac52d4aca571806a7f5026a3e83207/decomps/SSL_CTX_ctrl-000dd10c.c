
long SSL_CTX_ctrl(SSL_CTX *ctx,int cmd,long larg,void *parg)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  uint uVar4;
  SSL_CIPHER *pSVar5;
  int iVar6;
  cert_st *pcVar7;
  int iVar8;
  _func_3237 *p_Var9;
  void *pvVar10;
  ssl_session_st *psVar11;
  
  if (ctx == (SSL_CTX *)0x0) {
    if ((cmd != 0x62) && (cmd != 0x66)) {
      if (cmd != 0x5c) {
        return 0;
      }
      lVar3 = tls1_set_groups_list(0,0,parg);
      return lVar3;
    }
    lVar3 = tls1_set_sigalgs_list(0,parg);
    return lVar3;
  }
  if (0x73 < cmd - 0x10U) {
switchD_000dd11e_caseD_11:
                    /* WARNING: Could not recover jumptable at 0x000dd414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pSVar5 = (*ctx->method->get_cipher_by_char)((uchar *)ctx);
    return (long)pSVar5;
  }
  iVar6 = larg >> 8;
  switch(cmd) {
  case 0x10:
    *(void **)(ctx->sid_ctx + 4) = parg;
    return 1;
  default:
    goto switchD_000dd11e_caseD_11;
  case 0x14:
    lVar3 = OPENSSL_LH_num_items(ctx->session_cache_size);
    return lVar3;
  case 0x15:
    return (ctx->stats).sess_connect_renegotiate;
  case 0x16:
    return (ctx->stats).sess_accept;
  case 0x17:
    return (ctx->stats).sess_connect_good;
  case 0x18:
    return (ctx->stats).sess_accept_renegotiate;
  case 0x19:
    return (ctx->stats).sess_miss;
  case 0x1a:
    return (ctx->stats).sess_accept_good;
  case 0x1b:
    return (ctx->stats).sess_cb_hit;
  case 0x1c:
    return ctx->references;
  case 0x1d:
    return (ctx->stats).sess_timeout;
  case 0x1e:
    return (ctx->stats).sess_cache_full;
  case 0x1f:
    return (ctx->stats).sess_hit;
  case 0x21:
    pcVar7 = (cert_st *)(larg | (uint)ctx->cert);
    ctx->cert = pcVar7;
    return (long)pcVar7;
  case 0x28:
    return ctx->sid_ctx_length;
  case 0x29:
    uVar4 = ctx->sid_ctx_length;
    ctx->sid_ctx_length = larg;
    return uVar4;
  case 0x2a:
    if (-1 < larg) {
      psVar11 = ctx->session_cache_head;
      ctx->session_cache_head = (ssl_session_st *)larg;
      return (long)psVar11;
    }
    break;
  case 0x2b:
    return (long)ctx->session_cache_head;
  case 0x2c:
    lVar3 = ctx->session_timeout;
    ctx->session_timeout = larg;
    return lVar3;
  case 0x2d:
    return ctx->session_timeout;
  case 0x32:
    return (long)ctx->msg_callback_arg;
  case 0x33:
    if (-1 < larg) {
      pvVar10 = ctx->msg_callback_arg;
      ctx->msg_callback_arg = (void *)larg;
      return (long)pvVar10;
    }
    break;
  case 0x34:
    if (larg - 0x200U < 0x3e01) {
      uVar4 = *(uint *)(ctx->tlsext_tick_key_name + 0xc);
      *(long *)ctx->tlsext_tick_hmac_key = larg;
      if (uVar4 <= (uint)larg) {
        return 1;
      }
LAB_000dd260:
      *(long *)(ctx->tlsext_tick_key_name + 0xc) = larg;
      return 1;
    }
    break;
  case 0x4e:
    pcVar7 = (cert_st *)((uint)ctx->cert & ~larg);
    ctx->cert = pcVar7;
    return (long)pcVar7;
  case 99:
    uVar4 = larg | *(uint *)(ctx->verify_mode + 0x10);
    *(uint *)(ctx->verify_mode + 0x10) = uVar4;
    return uVar4;
  case 100:
    uVar4 = *(uint *)(ctx->verify_mode + 0x10) & ~larg;
    *(uint *)(ctx->verify_mode + 0x10) = uVar4;
    return uVar4;
  case 0x7b:
    p_Var9 = ctx->msg_callback;
    if (larg == 0x100) {
      if ((p_Var9 == (_func_3237 *)0x100) || ((int)p_Var9 >> 8 == 0xfe)) goto LAB_000dd314;
      bVar1 = true;
    }
    else {
      bVar1 = iVar6 == 0xfe;
      if ((p_Var9 == (_func_3237 *)0x100) || ((int)p_Var9 >> 8 == 0xfe)) {
        if (iVar6 != 0xfe && larg != 0) {
          return 0;
        }
        goto LAB_000dd314;
      }
    }
    bVar2 = bVar1;
    if (p_Var9 == (_func_3237 *)0x0) {
      bVar2 = false;
    }
    if (!bVar2) {
      if ((!bVar1) && (larg != 0)) {
        if (p_Var9 == (_func_3237 *)0x0) {
          if (larg < 0x300) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = larg < 0x300 && 0x2ff < (int)p_Var9;
        }
        if (bVar1) {
          return 0;
        }
      }
LAB_000dd314:
      iVar6 = ssl_set_version_bound(ctx->method->version,larg,&ctx->read_ahead);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
      return iVar6;
    }
    break;
  case 0x7c:
    iVar8 = ctx->read_ahead;
    if (iVar8 == 0x100) {
      if ((larg == 0x100) || (iVar6 == 0xfe)) goto LAB_000dd428;
      bVar1 = true;
    }
    else {
      bVar1 = iVar8 >> 8 == 0xfe;
      if ((larg == 0x100) || (iVar6 == 0xfe)) {
        if (iVar8 >> 8 != 0xfe && iVar8 != 0) {
          return 0;
        }
        goto LAB_000dd428;
      }
    }
    bVar2 = bVar1;
    if (larg == 0) {
      bVar2 = false;
    }
    if (!bVar2) {
      if ((!bVar1) && (iVar8 != 0)) {
        if (larg == 0) {
          if (iVar8 < 0x300) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = 0x2ff < larg && iVar8 < 0x300;
        }
        if (bVar1) {
          return 0;
        }
      }
LAB_000dd428:
      iVar6 = ssl_set_version_bound(ctx->method->version,larg,&ctx->msg_callback);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
      return iVar6;
    }
    break;
  case 0x7d:
    if ((uint)larg <= *(uint *)ctx->tlsext_tick_hmac_key && larg != 0) goto LAB_000dd260;
    break;
  case 0x7e:
    if (larg - 1U < 0x20) {
      *(long *)(ctx->tlsext_tick_hmac_key + 4) = larg;
      return 1;
    }
    break;
  case 0x82:
    return ctx->read_ahead;
  case 0x83:
    return (long)ctx->msg_callback;
  }
  return 0;
}

