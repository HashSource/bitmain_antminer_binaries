
stack_st_X509_EXTENSION * X509v3_add_ext(stack_st_X509_EXTENSION **x,X509_EXTENSION *ex,int loc)

{
  uint uVar1;
  X509_EXTENSION *a;
  int iVar2;
  _STACK *sk;
  uint where;
  
  if (x == (stack_st_X509_EXTENSION **)0x0) {
    ERR_put_error(0xb,0x68,0x43,DAT_000c34c4,0x98);
    return (stack_st_X509_EXTENSION *)0x0;
  }
  sk = &(*x)->stack;
  if ((sk == (_STACK *)0x0) && (sk = sk_new_null(), sk == (_STACK *)0x0)) {
    ERR_put_error(0xb,0x68,0x41,DAT_000c34c4,0xb0);
    return (stack_st_X509_EXTENSION *)0x0;
  }
  uVar1 = sk_num(sk);
  if ((int)uVar1 < loc) {
    a = X509_EXTENSION_dup(ex);
    where = uVar1;
  }
  else {
    where = loc & ~(loc >> 0x20);
    if (loc < 0) {
      where = uVar1;
    }
    a = X509_EXTENSION_dup(ex);
  }
  if (a == (X509_EXTENSION *)0x0) {
    if (sk == (_STACK *)0x0) {
      return (stack_st_X509_EXTENSION *)0x0;
    }
  }
  else {
    iVar2 = sk_insert(sk,a,where);
    if (iVar2 != 0) {
      if (*x == (stack_st_X509_EXTENSION *)0x0) {
        *x = (stack_st_X509_EXTENSION *)sk;
        return (stack_st_X509_EXTENSION *)sk;
      }
      return (stack_st_X509_EXTENSION *)sk;
    }
    ERR_put_error(0xb,0x68,0x41,DAT_000c34c4,0xb0);
    X509_EXTENSION_free(a);
  }
  sk_free(sk);
  return (stack_st_X509_EXTENSION *)0x0;
}

