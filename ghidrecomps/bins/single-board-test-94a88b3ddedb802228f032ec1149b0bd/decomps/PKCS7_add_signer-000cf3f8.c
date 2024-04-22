
int PKCS7_add_signer(PKCS7 *p7,PKCS7_SIGNER_INFO *p7i)

{
  int iVar1;
  int n;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  X509_ALGOR *a;
  ASN1_TYPE *pAVar4;
  ASN1_OBJECT *pAVar5;
  _STACK *st;
  _STACK *st_00;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 == 0x16) || (iVar1 == 0x18)) {
    st_00 = &((p7->d).sign)->signer_info->stack;
    st = &((p7->d).sign)->md_algs->stack;
    n = OBJ_obj2nid(p7i->digest_alg->algorithm);
    iVar1 = 0;
    do {
      iVar3 = sk_num(st);
      if (iVar3 <= iVar1) {
        a = X509_ALGOR_new();
        if (a != (X509_ALGOR *)0x0) {
          pAVar4 = ASN1_TYPE_new();
          a->parameter = pAVar4;
          if (pAVar4 != (ASN1_TYPE *)0x0) {
            pAVar5 = OBJ_nid2obj(n);
            a->algorithm = pAVar5;
            a->parameter->type = 5;
            iVar1 = sk_push(st,a);
            if (iVar1 == 0) {
              X509_ALGOR_free(a);
              return 0;
            }
            break;
          }
        }
        X509_ALGOR_free(a);
        ERR_put_error(0x21,0x67,0x41,DAT_000cf4c0,0x112);
        return 0;
      }
      ppAVar2 = (ASN1_OBJECT **)sk_value(st,iVar1);
      iVar3 = OBJ_obj2nid(*ppAVar2);
      iVar1 = iVar1 + 1;
    } while (iVar3 != n);
    iVar1 = sk_push(st_00,p7i);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    ERR_put_error(0x21,0x67,0x71,DAT_000cf4c0,0xff);
    iVar1 = 0;
  }
  return iVar1;
}

