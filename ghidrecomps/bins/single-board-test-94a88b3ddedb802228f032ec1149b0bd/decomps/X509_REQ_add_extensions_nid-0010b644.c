
int X509_REQ_add_extensions_nid(X509_REQ *req,stack_st_X509_EXTENSION *exts,int nid)

{
  _STACK *p_Var1;
  ASN1_STRING *a;
  int iVar2;
  _STACK *st;
  ASN1_OBJECT *pAVar3;
  X509_REQ_INFO *pXVar4;
  
  p_Var1 = (_STACK *)ASN1_TYPE_new();
  if (p_Var1 == (_STACK *)0x0) {
    a = (ASN1_STRING *)0x0;
  }
  else {
    a = ASN1_STRING_new();
    ((_union_263 *)&p_Var1->data)->asn1_string = a;
    if (a != (ASN1_STRING *)0x0) {
      p_Var1->num = 0x10;
      iVar2 = ASN1_item_i2d((ASN1_VALUE *)exts,&a->data,DAT_0010b6d8);
      a->length = iVar2;
      a = (ASN1_STRING *)X509_ATTRIBUTE_new();
      if (a != (ASN1_STRING *)0x0) {
        st = sk_new_null();
        a->data = (uchar *)st;
        if ((st != (_STACK *)0x0) && (iVar2 = sk_push(st,p_Var1), iVar2 != 0)) {
          a->type = 0;
          pAVar3 = OBJ_nid2obj(nid);
          pXVar4 = req->req_info;
          a->length = (int)pAVar3;
          p_Var1 = &pXVar4->attributes->stack;
          if (p_Var1 == (_STACK *)0x0) {
            p_Var1 = sk_new_null();
            pXVar4->attributes = (stack_st_X509_ATTRIBUTE *)p_Var1;
            if (p_Var1 == (_STACK *)0x0) goto LAB_0010b68c;
            p_Var1 = &req->req_info->attributes->stack;
          }
          p_Var1 = (_STACK *)sk_push(p_Var1,a);
          if (p_Var1 != (_STACK *)0x0) {
            return 1;
          }
        }
      }
    }
  }
LAB_0010b68c:
  X509_ATTRIBUTE_free((X509_ATTRIBUTE *)a);
  ASN1_TYPE_free((ASN1_TYPE *)p_Var1);
  return 0;
}

