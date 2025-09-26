
stack_st_X509 * CMS_get0_signers(CMS_ContentInfo *cms)

{
  stack_st_CMS_SignerInfo *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  stack_st_X509 *psVar6;
  
  psVar1 = CMS_get0_SignerInfos(cms);
  psVar6 = (stack_st_X509 *)0x0;
  iVar4 = 0;
  do {
    do {
      iVar2 = OPENSSL_sk_num(psVar1);
      iVar5 = iVar4 + 1;
      if (iVar2 <= iVar4) {
        return psVar6;
      }
      iVar2 = OPENSSL_sk_value(psVar1,iVar4);
      iVar3 = *(int *)(iVar2 + 0x1c);
      iVar4 = iVar5;
    } while (iVar3 == 0);
    if (psVar6 == (stack_st_X509 *)0x0) {
      psVar6 = (stack_st_X509 *)OPENSSL_sk_new_null();
      if (psVar6 == (stack_st_X509 *)0x0) {
        return (stack_st_X509 *)0x0;
      }
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    iVar2 = OPENSSL_sk_push(psVar6,iVar3);
  } while (iVar2 != 0);
  OPENSSL_sk_free(psVar6);
  return (stack_st_X509 *)0x0;
}

