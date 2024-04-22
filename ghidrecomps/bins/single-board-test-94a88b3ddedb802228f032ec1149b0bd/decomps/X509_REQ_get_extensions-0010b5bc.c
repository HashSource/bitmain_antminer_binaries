
stack_st_X509_EXTENSION * X509_REQ_get_extensions(X509_REQ *req)

{
  X509_ATTRIBUTE *pXVar1;
  _STACK *p_Var2;
  stack_st_X509_EXTENSION *psVar3;
  int iVar4;
  int *piVar5;
  X509_REQ_INFO *pXVar6;
  uchar *local_14 [2];
  
  if ((((req != (X509_REQ *)0x0) && (pXVar6 = req->req_info, pXVar6 != (X509_REQ_INFO *)0x0)) &&
      (piVar5 = *DAT_0010b63c, piVar5 != (int *)0x0)) && (iVar4 = *piVar5, iVar4 != 0)) {
    while (iVar4 = X509at_get_attr_by_NID(pXVar6->attributes,iVar4,-1), iVar4 == -1) {
      piVar5 = piVar5 + 1;
      iVar4 = *piVar5;
      if (iVar4 == 0) {
        return (stack_st_X509_EXTENSION *)0x0;
      }
      pXVar6 = req->req_info;
    }
    pXVar1 = X509at_get_attr(req->req_info->attributes,iVar4);
    p_Var2 = &((pXVar1->value).set)->stack;
    if (pXVar1->single == 0) {
      iVar4 = sk_num(p_Var2);
      if (iVar4 == 0) {
        return (stack_st_X509_EXTENSION *)0x0;
      }
      p_Var2 = (_STACK *)sk_value(&((pXVar1->value).set)->stack,0);
    }
    if ((p_Var2 != (_STACK *)0x0) && (p_Var2->num == 0x10)) {
      local_14[0] = (uchar *)p_Var2->data[2];
      psVar3 = (stack_st_X509_EXTENSION *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,local_14,(long)*p_Var2->data,DAT_0010b640);
      return psVar3;
    }
  }
  return (stack_st_X509_EXTENSION *)0x0;
}

