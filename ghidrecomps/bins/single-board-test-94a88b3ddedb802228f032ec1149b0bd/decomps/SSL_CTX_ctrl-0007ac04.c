
long SSL_CTX_ctrl(SSL_CTX *ctx,int cmd,long larg,void *parg)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  if (ctx != (SSL_CTX *)0x0) {
    switch(cmd) {
    case 0x10:
      ctx->msg_callback_arg = parg;
      return 1;
    default:
      lVar3 = (*ctx->method->ssl_ctx_ctrl)(ctx,cmd,larg,parg);
      return lVar3;
    case 0x14:
      uVar2 = lh_num_items((_LHASH *)ctx->sessions);
      return uVar2;
    case 0x15:
      return (ctx->stats).sess_connect;
    case 0x16:
      return (ctx->stats).sess_connect_good;
    case 0x17:
      return (ctx->stats).sess_connect_renegotiate;
    case 0x18:
      return (ctx->stats).sess_accept;
    case 0x19:
      return (ctx->stats).sess_accept_good;
    case 0x1a:
      return (ctx->stats).sess_accept_renegotiate;
    case 0x1b:
      return (ctx->stats).sess_hit;
    case 0x1c:
      return (ctx->stats).sess_cb_hit;
    case 0x1d:
      return (ctx->stats).sess_miss;
    case 0x1e:
      return (ctx->stats).sess_timeout;
    case 0x1f:
      return (ctx->stats).sess_cache_full;
    case 0x20:
      uVar1 = ctx->options | larg;
      ctx->options = uVar1;
      return uVar1;
    case 0x21:
      uVar1 = ctx->mode | larg;
      ctx->mode = uVar1;
      return uVar1;
    case 0x28:
      return ctx->read_ahead;
    case 0x29:
      lVar3 = ctx->read_ahead;
      ctx->read_ahead = larg;
      return lVar3;
    case 0x2a:
      uVar2 = ctx->session_cache_size;
      ctx->session_cache_size = larg;
      return uVar2;
    case 0x2b:
      return ctx->session_cache_size;
    case 0x2c:
      lVar3 = ctx->session_cache_mode;
      ctx->session_cache_mode = larg;
      return lVar3;
    case 0x2d:
      return ctx->session_cache_mode;
    case 0x32:
      return ctx->max_cert_list;
    case 0x33:
      lVar3 = ctx->max_cert_list;
      ctx->max_cert_list = larg;
      return lVar3;
    case 0x34:
      goto switchD_0007ac16_caseD_34;
    case 0x4d:
      uVar1 = ctx->options & ~larg;
      ctx->options = uVar1;
      return uVar1;
    case 0x4e:
      uVar1 = ctx->mode & ~larg;
      ctx->mode = uVar1;
      return uVar1;
    case 99:
      uVar1 = *(uint *)(ctx->cert + 0x38) | larg;
      *(uint *)(ctx->cert + 0x38) = uVar1;
      return uVar1;
    case 100:
      uVar1 = *(uint *)(ctx->cert + 0x38) & ~larg;
      *(uint *)(ctx->cert + 0x38) = uVar1;
      return uVar1;
    }
  }
  if ((cmd != 0x62) && (cmd != 0x66)) {
    if (cmd != 0x5c) {
      return 0;
    }
    lVar3 = tls1_set_curves_list(0,0,parg,parg);
    return lVar3;
  }
  lVar3 = tls1_set_sigalgs_list(0,parg,0,parg);
  return lVar3;
switchD_0007ac16_caseD_34:
  if (larg - 0x200U < 0x3e01) {
    ctx->max_send_fragment = larg;
    return 1;
  }
  return 0;
}

