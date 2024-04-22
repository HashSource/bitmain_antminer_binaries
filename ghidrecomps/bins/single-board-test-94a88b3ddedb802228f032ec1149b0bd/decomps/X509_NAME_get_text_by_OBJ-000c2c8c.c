
int X509_NAME_get_text_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,char *buf,int len)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  size_t *psVar5;
  size_t sVar6;
  int iVar7;
  size_t __n;
  _STACK *p_Var8;
  
  if (name != (X509_NAME *)0x0) {
    p_Var8 = &name->entries->stack;
    iVar1 = sk_num(p_Var8);
    if (0 < iVar1) {
      iVar7 = 0;
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var8,iVar7);
        iVar3 = OBJ_cmp(*ppAVar2,obj);
        if (iVar3 == 0) {
          iVar1 = sk_num(&name->entries->stack);
          if ((iVar7 < iVar1) &&
             (pvVar4 = sk_value(&name->entries->stack,iVar7), pvVar4 != (void *)0x0)) {
            psVar5 = *(size_t **)((int)pvVar4 + 4);
          }
          else {
            psVar5 = (size_t *)0x0;
          }
          sVar6 = *psVar5;
          __n = sVar6;
          if (len <= (int)sVar6) {
            __n = len - 1;
          }
          if (buf != (char *)0x0) {
            memcpy(buf,(void *)psVar5[2],__n);
            buf[__n] = '\0';
            return __n;
          }
          return sVar6;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != iVar1);
    }
  }
  return -1;
}

