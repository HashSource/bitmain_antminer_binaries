
int X509_check_trust(X509 *x,int id,int flags)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  _STACK **pp_Var7;
  int local_30 [7];
  
  if (id == -1) {
    return 1;
  }
  if (id == 0) {
    pp_Var7 = *(_STACK ***)(x->sha1_hash + 0xc);
    if (pp_Var7 != (_STACK **)0x0) {
      p_Var1 = pp_Var7[1];
      if (p_Var1 != (_STACK *)0x0) {
        iVar4 = 0;
        while( true ) {
          iVar2 = sk_num(p_Var1);
          if (iVar2 <= iVar4) break;
          pAVar3 = (ASN1_OBJECT *)sk_value(pp_Var7[1],iVar4);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (iVar2 == 0x38e) {
            return 2;
          }
          p_Var1 = pp_Var7[1];
          iVar4 = iVar4 + 1;
        }
      }
      p_Var1 = *pp_Var7;
      if (p_Var1 != (_STACK *)0x0) {
        iVar4 = 0;
        while( true ) {
          iVar2 = sk_num(p_Var1);
          if (iVar2 <= iVar4) break;
          pAVar3 = (ASN1_OBJECT *)sk_value(*pp_Var7,iVar4);
          iVar2 = OBJ_obj2nid(pAVar3);
          if (iVar2 == 0x38e) {
            return 1;
          }
          p_Var1 = *pp_Var7;
          iVar4 = iVar4 + 1;
        }
      }
    }
    X509_check_purpose(x,-1,0);
    if ((x->ex_flags & 0x2000) == 0) {
      return 3;
    }
    return 1;
  }
  uVar6 = id - 1;
  if (7 < uVar6) {
    local_30[0] = id;
    if (((*DAT_000c50a0 == (_STACK *)0x0) || (iVar4 = sk_find(*DAT_000c50a0,local_30), iVar4 == -1))
       || (uVar6 = iVar4 + 8, iVar4 == -9)) {
      iVar4 = (**DAT_000c50a8)(id,x,flags);
      return iVar4;
    }
    if ((int)uVar6 < 0) {
      pvVar5 = (void *)0x0;
      goto LAB_000c506c;
    }
  }
  if ((int)uVar6 < 8) {
    pvVar5 = (void *)(DAT_000c50a4 + uVar6 * 0x18);
  }
  else {
    pvVar5 = sk_value(*DAT_000c50a0,uVar6 - 8);
  }
LAB_000c506c:
  iVar4 = (**(code **)((int)pvVar5 + 8))(pvVar5,x,flags);
  return iVar4;
}

