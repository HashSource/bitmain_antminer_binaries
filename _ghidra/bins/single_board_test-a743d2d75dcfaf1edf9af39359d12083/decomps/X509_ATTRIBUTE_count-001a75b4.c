
int X509_ATTRIBUTE_count(X509_ATTRIBUTE *attr)

{
  _STACK *p_Var1;
  int iVar2;
  
  p_Var1 = &((attr->value).set)->stack;
  if (attr->single != 0) {
    if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = (_STACK *)0x1;
    }
    return (int)p_Var1;
  }
  iVar2 = sk_num(p_Var1);
  return iVar2;
}

