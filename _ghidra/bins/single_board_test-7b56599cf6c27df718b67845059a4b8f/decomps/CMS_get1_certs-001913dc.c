
stack_st_X509 * CMS_get1_certs(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  stack_st_X509 *psVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    puVar5 = (undefined4 *)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,"crypto/cms/cms_lib.c",0x163);
      return (stack_st_X509 *)0x0;
    }
    puVar5 = *(undefined4 **)(*(int *)(cms + 4) + 4);
  }
  if (puVar5 == (undefined4 *)0x0) {
    return (stack_st_X509 *)0x0;
  }
  psVar6 = (stack_st_X509 *)0x0;
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
    if (psVar6 == (stack_st_X509 *)0x0) {
      psVar6 = (stack_st_X509 *)OPENSSL_sk_new_null();
      if (psVar6 == (stack_st_X509 *)0x0) {
        return (stack_st_X509 *)0x0;
      }
      iVar2 = OPENSSL_sk_push(psVar6,piVar3[1]);
    }
    else {
      iVar2 = OPENSSL_sk_push(psVar6,piVar3[1]);
    }
    if (iVar2 == 0) break;
    X509_up_ref(piVar3[1]);
  }
  OPENSSL_sk_pop_free(psVar6,0x16e591);
  return (stack_st_X509 *)0x0;
}

