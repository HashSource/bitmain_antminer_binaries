
int v2i_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    ERR_put_error(0x22,0x67,0x41,"crypto/x509v3/v3_extku.c",0x52);
    OPENSSL_sk_free(0);
  }
  else if (0 < iVar1) {
    iVar5 = 0;
    do {
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_3,iVar5);
      iVar5 = iVar5 + 1;
      if ((char *)puVar3[2] == (char *)0x0) {
        pAVar4 = OBJ_txt2obj((char *)puVar3[1],0);
      }
      else {
        pAVar4 = OBJ_txt2obj((char *)puVar3[2],0);
      }
      if (pAVar4 == (ASN1_OBJECT *)0x0) {
        OPENSSL_sk_pop_free(iVar2,0x18981d);
        ERR_put_error(0x22,0x67,0x6e,"crypto/x509v3/v3_extku.c",0x60);
        ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        return 0;
      }
      OPENSSL_sk_push(iVar2,pAVar4);
    } while (iVar1 != iVar5);
  }
  return iVar2;
}

