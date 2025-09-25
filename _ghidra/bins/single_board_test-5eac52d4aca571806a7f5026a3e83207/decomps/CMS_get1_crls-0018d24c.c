
stack_st_X509_CRL * CMS_get1_crls(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  stack_st_X509_CRL *psVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    puVar5 = (undefined4 *)(*(int *)(cms + 4) + 0x10);
    if (puVar5 != (undefined4 *)0x0) {
LAB_0018d270:
      psVar6 = (stack_st_X509_CRL *)0x0;
      iVar1 = 0;
      while( true ) {
        do {
          iVar2 = OPENSSL_sk_num(*puVar5);
          iVar4 = iVar1 + 1;
          if (iVar2 <= iVar1) {
            return psVar6;
          }
          piVar3 = (int *)OPENSSL_sk_value(*puVar5,iVar1);
          iVar1 = iVar4;
        } while (*piVar3 != 0);
        if (psVar6 == (stack_st_X509_CRL *)0x0) {
          psVar6 = (stack_st_X509_CRL *)OPENSSL_sk_new_null();
          if (psVar6 == (stack_st_X509_CRL *)0x0) {
            return (stack_st_X509_CRL *)0x0;
          }
          iVar2 = OPENSSL_sk_push(psVar6,piVar3[1]);
        }
        else {
          iVar2 = OPENSSL_sk_push(psVar6,piVar3[1]);
        }
        if (iVar2 == 0) break;
        X509_CRL_up_ref(piVar3[1]);
      }
      OPENSSL_sk_pop_free(psVar6,0x169025);
      return (stack_st_X509_CRL *)0x0;
    }
  }
  else if (iVar1 == 0x17) {
    if (*(int *)(*(int *)(cms + 4) + 4) != 0) {
      puVar5 = (undefined4 *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
      goto LAB_0018d270;
    }
  }
  else {
    ERR_put_error(0x2e,0x84,0x98,"crypto/cms/cms_lib.c",0x1b0);
  }
  return (stack_st_X509_CRL *)0x0;
}

