
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  ssl3_state_st *psVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    return 1;
  default:
    lVar2 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar2;
  case 0x20:
    uVar4 = ssl->references | larg;
    ssl->references = uVar4;
    return uVar4;
  case 0x21:
    uVar4 = ssl->options | larg;
    ssl->options = uVar4;
    return uVar4;
  case 0x28:
    return ssl->read_ahead;
  case 0x29:
    lVar2 = ssl->read_ahead;
    ssl->read_ahead = larg;
    return lVar2;
  case 0x32:
    return ssl->mode;
  case 0x33:
    uVar3 = ssl->mode;
    ssl->mode = larg;
    return uVar3;
  case 0x34:
    if (larg - 0x200U < 0x3e01) {
      ssl->client_version = larg;
      return 1;
    }
    psVar1 = (ssl3_state_st *)0x0;
    break;
  case 0x4c:
    psVar1 = ssl->s3;
    if (psVar1 != (ssl3_state_st *)0x0) {
      return psVar1->send_connection_binding;
    }
    break;
  case 0x4d:
    uVar4 = ssl->references & ~larg;
    ssl->references = uVar4;
    return uVar4;
  case 0x4e:
    uVar4 = ssl->options & ~larg;
    ssl->options = uVar4;
    return uVar4;
  case 99:
    uVar4 = *(uint *)(ssl->cert + 0x38) | larg;
    *(uint *)(ssl->cert + 0x38) = uVar4;
    return uVar4;
  case 100:
    uVar4 = *(uint *)(ssl->cert + 0x38) & ~larg;
    *(uint *)(ssl->cert + 0x38) = uVar4;
    return uVar4;
  case 0x6e:
    if (parg == (void *)0x0) {
      iVar5 = (*ssl->method->put_cipher_by_char)((SSL_CIPHER *)0x0,(uchar *)0x0);
      return iVar5;
    }
    psVar1 = *(ssl3_state_st **)(ssl->cert + 0x154);
    if (psVar1 != (ssl3_state_st *)0x0) {
      *(ssl3_state_st **)parg = psVar1;
      return *(long *)(ssl->cert + 0x158);
    }
  }
  return (long)psVar1;
}

