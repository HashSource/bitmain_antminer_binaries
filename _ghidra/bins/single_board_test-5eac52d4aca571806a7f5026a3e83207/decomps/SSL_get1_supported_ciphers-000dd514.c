
int SSL_get1_supported_ciphers(SSL *param_1)

{
  stack_st_SSL_CIPHER *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  psVar1 = SSL_get_ciphers(param_1);
  if ((psVar1 != (stack_st_SSL_CIPHER *)0x0) &&
     (iVar2 = ssl_set_client_disabled(param_1), iVar2 != 0)) {
    iVar6 = 0;
    iVar2 = 0;
    while( true ) {
      do {
        iVar3 = OPENSSL_sk_num(psVar1);
        iVar5 = iVar2 + 1;
        if (iVar3 <= iVar2) {
          return iVar6;
        }
        uVar4 = OPENSSL_sk_value(psVar1,iVar2);
        iVar3 = ssl_cipher_disabled(param_1,uVar4,0x10001,0);
        iVar2 = iVar5;
      } while (iVar3 != 0);
      if ((iVar6 == 0) && (iVar6 = OPENSSL_sk_new_null(), iVar6 == 0)) break;
      iVar3 = OPENSSL_sk_push(iVar6,uVar4);
      if (iVar3 == 0) {
        OPENSSL_sk_free(iVar6);
        return 0;
      }
    }
  }
  return 0;
}

