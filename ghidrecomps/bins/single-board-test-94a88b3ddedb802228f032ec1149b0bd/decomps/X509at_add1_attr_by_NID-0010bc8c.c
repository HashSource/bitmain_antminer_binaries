
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_NID(stack_st_X509_ATTRIBUTE **x,int nid,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a;
  _STACK *st;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x88,0x6d,DAT_0010bd8c,0xe4);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  attr = X509_ATTRIBUTE_new();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    attr = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
    if (attr == (X509_ATTRIBUTE *)0x0) goto LAB_0010bd1e;
  }
  else {
    ASN1_OBJECT_free(attr->object);
    pAVar1 = OBJ_dup(o);
    attr->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
    if (iVar2 == 0) {
      X509_ATTRIBUTE_free(attr);
LAB_0010bd1e:
      ASN1_OBJECT_free(o);
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
  }
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    ERR_put_error(0xb,0x87,0x43,DAT_0010bd8c,0x81);
    st = (_STACK *)0x0;
  }
  else {
    st = &(*x)->stack;
    if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
      ERR_put_error(0xb,0x87,0x41,DAT_0010bd8c,0x93);
    }
    else {
      a = X509_ATTRIBUTE_dup(attr);
      if (a == (X509_ATTRIBUTE *)0x0) {
        if (st != (_STACK *)0x0) goto LAB_0010bd02;
      }
      else {
        iVar2 = sk_push(st,a);
        if (iVar2 == 0) {
          ERR_put_error(0xb,0x87,0x41,DAT_0010bd8c,0x93);
          X509_ATTRIBUTE_free(a);
LAB_0010bd02:
          sk_free(st);
          X509_ATTRIBUTE_free(attr);
          return (stack_st_X509_ATTRIBUTE *)0x0;
        }
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = (stack_st_X509_ATTRIBUTE *)st;
        }
      }
    }
  }
  X509_ATTRIBUTE_free(attr);
  return (stack_st_X509_ATTRIBUTE *)st;
}

