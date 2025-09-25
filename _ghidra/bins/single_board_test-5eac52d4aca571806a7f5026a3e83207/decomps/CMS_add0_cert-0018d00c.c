
int CMS_add0_cert(CMS_ContentInfo *cms,X509 *cert)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  CMS_CertificateChoices *pCVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    puVar6 = (undefined4 *)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,"crypto/cms/cms_lib.c",0x163);
      return 0;
    }
    puVar6 = *(undefined4 **)(*(int *)(cms + 4) + 4);
  }
  if (puVar6 != (undefined4 *)0x0) {
    iVar1 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(*puVar6);
      iVar5 = iVar1 + 1;
      if (iVar2 <= iVar1) break;
      piVar3 = (int *)OPENSSL_sk_value(*puVar6,iVar1);
      iVar1 = iVar5;
      if ((*piVar3 == 0) && (iVar2 = X509_cmp((X509 *)piVar3[1],cert), iVar2 == 0)) {
        ERR_put_error(0x2e,0xa4,0xaf,"crypto/cms/cms_lib.c",0x18b);
        return 0;
      }
    }
    pCVar4 = CMS_add0_CertificateChoices(cms);
    if (pCVar4 != (CMS_CertificateChoices *)0x0) {
      *(undefined4 *)pCVar4 = 0;
      *(X509 **)(pCVar4 + 4) = cert;
      return 1;
    }
  }
  return 0;
}

