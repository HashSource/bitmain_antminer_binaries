
undefined4 ssl_cert_set0_chain(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar4 = **(int **)(param_2 + 0xc0);
  }
  else {
    iVar4 = **(int **)(param_1 + 0x404);
  }
  if (iVar4 != 0) {
    iVar3 = 0;
    do {
      iVar2 = OPENSSL_sk_num(param_3);
      if (iVar2 <= iVar3) {
        OPENSSL_sk_pop_free(*(undefined4 *)(iVar4 + 8),0x16e591);
        *(undefined4 *)(iVar4 + 8) = param_3;
        return 1;
      }
      uVar1 = OPENSSL_sk_value(param_3,iVar3);
      iVar2 = ssl_security_cert(param_1,param_2,uVar1,0,0);
      iVar3 = iVar3 + 1;
    } while (iVar2 == 1);
    ERR_put_error(0x14,0x154,iVar2,"ssl/ssl_cert.c",0x105);
    return 0;
  }
  return 0;
}

