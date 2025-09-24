
int PKCS7_add_signer(PKCS7 *p7,PKCS7_SIGNER_INFO *p7i)

{
  int iVar1;
  int n;
  undefined4 *puVar2;
  int iVar3;
  X509_ALGOR *a;
  ASN1_TYPE *pAVar4;
  ASN1_OBJECT *pAVar5;
  stack_st_X509_ALGOR *psVar6;
  stack_st_PKCS7_SIGNER_INFO *psVar7;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 != 0x18)) {
    ERR_put_error(0x21,0x67,0x71,"crypto/pkcs7/pk7_lib.c",0xcb);
    return 0;
  }
  psVar7 = ((p7->d).sign)->signer_info;
  psVar6 = ((p7->d).sign)->md_algs;
  n = OBJ_obj2nid(p7i->digest_alg->algorithm);
  iVar1 = 0;
  do {
    iVar3 = OPENSSL_sk_num(psVar6);
    if (iVar3 <= iVar1) {
      a = X509_ALGOR_new();
      if (a != (X509_ALGOR *)0x0) {
        pAVar4 = ASN1_TYPE_new();
        a->parameter = pAVar4;
        if (pAVar4 != (ASN1_TYPE *)0x0) {
          pAVar5 = OBJ_nid2obj(n);
          a->algorithm = pAVar5;
          a->parameter->type = 5;
          iVar1 = OPENSSL_sk_push(psVar6,a);
          if (iVar1 == 0) {
            X509_ALGOR_free(a);
            return 0;
          }
          break;
        }
      }
      X509_ALGOR_free(a);
      ERR_put_error(0x21,0x67,0x41,"crypto/pkcs7/pk7_lib.c",0xde);
      return 0;
    }
    puVar2 = (undefined4 *)OPENSSL_sk_value(psVar6,iVar1);
    iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar2);
    iVar1 = iVar1 + 1;
  } while (n != iVar3);
  iVar1 = OPENSSL_sk_push(psVar7,p7i);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

