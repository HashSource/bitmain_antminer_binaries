
void SCT_LIST_print(undefined4 param_1,BIO *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = param_4;
  iVar1 = OPENSSL_sk_num();
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      while( true ) {
        uVar2 = OPENSSL_sk_value(param_1,iVar4);
        SCT_print(uVar2,param_2,param_3,param_5,uVar6);
        iVar3 = OPENSSL_sk_num(param_1);
        iVar5 = iVar4 + 1;
        if (iVar3 + -1 <= iVar4) break;
        BIO_printf(param_2,"%s",param_4);
        iVar4 = iVar5;
        if (iVar5 == iVar1) {
          return;
        }
      }
      iVar4 = iVar5;
    } while (iVar5 != iVar1);
  }
  return;
}

