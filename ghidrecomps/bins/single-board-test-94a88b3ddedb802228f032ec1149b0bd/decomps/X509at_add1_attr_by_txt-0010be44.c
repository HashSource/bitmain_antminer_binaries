
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_txt(stack_st_X509_ATTRIBUTE **x,char *attrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *a;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a_00;
  _STACK *st;
  _STACK *p_Var3;
  
  a = OBJ_txt2obj(attrname,0);
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,DAT_0010bf60,0x116);
    ERR_add_error_data(2,DAT_0010bf64,attrname);
    p_Var3 = (_STACK *)0x0;
  }
  else {
    attr = X509_ATTRIBUTE_new();
    if (attr == (X509_ATTRIBUTE *)0x0) {
      attr = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
      ASN1_OBJECT_free(a);
      if (attr == (X509_ATTRIBUTE *)0x0) {
        return (stack_st_X509_ATTRIBUTE *)0x0;
      }
    }
    else {
      ASN1_OBJECT_free(attr->object);
      pAVar1 = OBJ_dup(a);
      attr->object = pAVar1;
      iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
      if (iVar2 == 0) {
        X509_ATTRIBUTE_free(attr);
        ASN1_OBJECT_free(a);
        return (stack_st_X509_ATTRIBUTE *)0x0;
      }
      ASN1_OBJECT_free(a);
    }
    if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
      ERR_put_error(0xb,0x87,0x43,DAT_0010bf60,0x81);
      p_Var3 = (_STACK *)0x0;
    }
    else {
      st = &(*x)->stack;
      if ((&(*x)->stack == (_STACK *)0x0) &&
         (p_Var3 = sk_new_null(), st = p_Var3, p_Var3 == (_STACK *)0x0)) {
        ERR_put_error(0xb,0x87,0x41,DAT_0010bf60,0x93);
      }
      else {
        a_00 = X509_ATTRIBUTE_dup(attr);
        p_Var3 = st;
        if (a_00 == (X509_ATTRIBUTE *)0x0) {
          if (st != (_STACK *)0x0) {
            p_Var3 = (_STACK *)0x0;
            sk_free(st);
          }
        }
        else {
          iVar2 = sk_push(st,a_00);
          if (iVar2 == 0) {
            ERR_put_error(0xb,0x87,0x41,DAT_0010bf60,0x93);
            X509_ATTRIBUTE_free(a_00);
            sk_free(st);
            p_Var3 = (_STACK *)0x0;
          }
          else if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
            *x = (stack_st_X509_ATTRIBUTE *)st;
          }
        }
      }
    }
    X509_ATTRIBUTE_free(attr);
  }
  return (stack_st_X509_ATTRIBUTE *)p_Var3;
}

