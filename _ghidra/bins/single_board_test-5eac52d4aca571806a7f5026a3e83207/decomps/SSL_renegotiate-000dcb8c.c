
int SSL_renegotiate(SSL *s)

{
  int iVar1;
  int *piVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  piVar2 = (int *)s->type;
  if ((-1 < *(int *)(piVar2[0x19] + 0x30) << 0x1c) && (*piVar2 != 0x10000 && 0x303 < *piVar2)) {
    ERR_put_error(0x14,0x204,0x10a,"ssl/ssl_lib.c",0x86d);
    return 0;
  }
  if (s[3].server << 1 < 0) {
    ERR_put_error(0x14,0x204,0x153,"ssl/ssl_lib.c",0x872);
    return 0;
  }
  UNRECOVERED_JUMPTABLE = (code *)piVar2[0xc];
  s[3].tlsext_hostname = (char *)0x1;
  s->handshake_func = (_func_3291 *)0x1;
                    /* WARNING: Could not recover jumptable at 0x000dcbcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*UNRECOVERED_JUMPTABLE)(s);
  return iVar1;
}

