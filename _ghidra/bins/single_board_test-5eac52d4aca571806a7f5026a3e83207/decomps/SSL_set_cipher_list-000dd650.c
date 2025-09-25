
int SSL_set_cipher_list(SSL *s,char *str)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = ssl_create_cipher_list
                    ((s[3].method)->version,s->generate_session_id,s->sid_ctx + 0x1c,&s->session,str
                     ,s[2].error);
  if (iVar1 == 0) {
    return 0;
  }
  iVar5 = 0;
  iVar3 = 0;
  while( true ) {
    iVar2 = OPENSSL_sk_num(iVar1);
    iVar4 = iVar3 + 1;
    if (iVar2 <= iVar3) break;
    iVar2 = OPENSSL_sk_value(iVar1,iVar3);
    iVar3 = iVar4;
    if (*(int *)(iVar2 + 0x20) < 0x304) {
      iVar5 = iVar5 + 1;
    }
  }
  if (iVar5 != 0) {
    return 1;
  }
  ERR_put_error(0x14,0x10f,0xb9,"ssl/ssl_lib.c",0xa2e);
  return 0;
}

