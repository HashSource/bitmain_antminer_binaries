
stack_st_X509_ATTRIBUTE * X509at_add1_attr(stack_st_X509_ATTRIBUTE **x,X509_ATTRIBUTE *attr)

{
  X509_ATTRIBUTE *a;
  int iVar1;
  _STACK *st;
  
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    ERR_put_error(0xb,0x87,0x43,DAT_0010b92c,0x81);
  }
  else {
    st = &(*x)->stack;
    if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
      ERR_put_error(0xb,0x87,0x41,DAT_0010b92c,0x93);
    }
    else {
      a = X509_ATTRIBUTE_dup(attr);
      if (a == (X509_ATTRIBUTE *)0x0) {
        if (st == (_STACK *)0x0) {
          return (stack_st_X509_ATTRIBUTE *)0x0;
        }
      }
      else {
        iVar1 = sk_push(st,a);
        if (iVar1 != 0) {
          if (*x != (stack_st_X509_ATTRIBUTE *)0x0) {
            return (stack_st_X509_ATTRIBUTE *)st;
          }
          *x = (stack_st_X509_ATTRIBUTE *)st;
          return (stack_st_X509_ATTRIBUTE *)st;
        }
        ERR_put_error(0xb,0x87,0x41,DAT_0010b92c,0x93);
        X509_ATTRIBUTE_free(a);
      }
      sk_free(st);
    }
  }
  return (stack_st_X509_ATTRIBUTE *)0x0;
}

