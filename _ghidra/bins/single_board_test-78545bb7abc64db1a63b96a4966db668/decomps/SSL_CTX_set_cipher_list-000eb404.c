
int SSL_CTX_set_cipher_list(SSL_CTX *param_1,char *str)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = ssl_create_cipher_list
                    (param_1->method,param_1->cert_store,&param_1->cipher_list,
                     &param_1->cipher_list_by_id,str,param_1->verify_mode);
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
  ERR_put_error(0x14,0x10d,0xb9,"ssl/ssl_lib.c",0xa1c);
  return 0;
}

