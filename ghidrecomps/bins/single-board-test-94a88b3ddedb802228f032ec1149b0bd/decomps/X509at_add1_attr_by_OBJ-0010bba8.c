
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_OBJ(stack_st_X509_ATTRIBUTE **x,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a;
  _STACK *p_Var3;
  _STACK *st;
  
  attr = X509_ATTRIBUTE_new();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    attr = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
    if (attr == (X509_ATTRIBUTE *)0x0) {
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
LAB_0010bbf0:
    if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
      ERR_put_error(0xb,0x87,0x43,DAT_0010bc88,0x81);
      p_Var3 = (_STACK *)0x0;
    }
    else {
      st = &(*x)->stack;
      if ((&(*x)->stack == (_STACK *)0x0) &&
         (p_Var3 = sk_new_null(), st = p_Var3, p_Var3 == (_STACK *)0x0)) {
        ERR_put_error(0xb,0x87,0x41,DAT_0010bc88,0x93);
      }
      else {
        a = X509_ATTRIBUTE_dup(attr);
        p_Var3 = st;
        if (a == (X509_ATTRIBUTE *)0x0) {
          if (st != (_STACK *)0x0) {
            p_Var3 = (_STACK *)0x0;
            sk_free(st);
          }
        }
        else {
          iVar2 = sk_push(st,a);
          if (iVar2 == 0) {
            ERR_put_error(0xb,0x87,0x41,DAT_0010bc88,0x93);
            X509_ATTRIBUTE_free(a);
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
  else {
    if (obj != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(attr->object);
      pAVar1 = OBJ_dup(obj);
      attr->object = pAVar1;
      iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
      if (iVar2 != 0) goto LAB_0010bbf0;
    }
    p_Var3 = (_STACK *)0x0;
    X509_ATTRIBUTE_free(attr);
  }
  return (stack_st_X509_ATTRIBUTE *)p_Var3;
}

