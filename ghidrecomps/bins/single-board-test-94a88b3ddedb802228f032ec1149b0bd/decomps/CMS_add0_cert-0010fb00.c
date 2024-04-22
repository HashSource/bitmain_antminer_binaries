
int CMS_add0_cert(CMS_ContentInfo *cms,X509 *cert)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  _STACK **pp_Var6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var6 = (_STACK **)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,DAT_0010fb9c,0x1a4);
      return 0;
    }
    pp_Var6 = *(_STACK ***)(*(int *)(cms + 4) + 4);
  }
  if (pp_Var6 != (_STACK **)0x0) {
    iVar1 = 0;
    do {
      iVar2 = sk_num(*pp_Var6);
      iVar5 = iVar1 + 1;
      if (iVar2 <= iVar1) {
        puVar4 = (undefined4 *)CMS_add0_CertificateChoices(cms);
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
        *puVar4 = 0;
        puVar4[1] = cert;
        return 1;
      }
      piVar3 = (int *)sk_value(*pp_Var6,iVar1);
      iVar1 = iVar5;
    } while ((*piVar3 != 0) || (iVar2 = X509_cmp((X509 *)piVar3[1],cert), iVar2 != 0));
    ERR_put_error(0x2e,0xa4,0xaf,DAT_0010fb9c,0x1cc);
  }
  return 0;
}

