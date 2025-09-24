
int X509v3_get_ext_by_OBJ(stack_st_X509_EXTENSION *x,ASN1_OBJECT *obj,int lastpos)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return -1;
  }
  uVar4 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
  uVar1 = OPENSSL_sk_num();
  if ((int)uVar4 < (int)uVar1) {
    do {
      puVar2 = (undefined4 *)OPENSSL_sk_value(x,uVar4);
      iVar3 = OBJ_cmp((ASN1_OBJECT *)*puVar2,obj);
      if (iVar3 == 0) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != uVar1);
  }
  return -1;
}

