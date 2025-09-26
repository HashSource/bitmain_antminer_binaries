
undefined4 def_crl_lookup(int *param_1,undefined4 *param_2,ASN1_INTEGER *param_3,X509_NAME *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  _STACK *p_Var4;
  int iVar5;
  int *piVar6;
  X509_NAME *a;
  ASN1_INTEGER *local_40 [7];
  
  local_40[0] = param_3;
  iVar1 = sk_is_sorted(*(_STACK **)(*param_1 + 0x14));
  if (iVar1 == 0) {
    CRYPTO_lock(9,6,"x_crl.c",0x1ba);
    sk_sort(*(_STACK **)(*param_1 + 0x14));
    CRYPTO_lock(10,6,"x_crl.c",0x1bc);
  }
  iVar1 = sk_find(*(_STACK **)(*param_1 + 0x14),local_40);
  if ((-1 < iVar1) && (iVar2 = sk_num(*(_STACK **)(*param_1 + 0x14)), iVar1 < iVar2)) {
    do {
      puVar3 = (undefined4 *)sk_value(*(_STACK **)(*param_1 + 0x14),iVar1);
      iVar2 = ASN1_INTEGER_cmp((ASN1_INTEGER *)*puVar3,param_3);
      if (iVar2 != 0) {
        return 0;
      }
      p_Var4 = (_STACK *)puVar3[3];
      if (p_Var4 == (_STACK *)0x0) {
        if ((param_4 == (X509_NAME *)0x0) ||
           (iVar2 = X509_NAME_cmp(param_4,*(X509_NAME **)(*param_1 + 8)), iVar2 == 0)) {
LAB_001a1762:
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = puVar3;
          }
          if (puVar3[4] != 8) {
            return 1;
          }
          return 2;
        }
      }
      else {
        a = param_4;
        if (param_4 == (X509_NAME *)0x0) {
          a = *(X509_NAME **)(*param_1 + 8);
        }
        iVar2 = 0;
        while( true ) {
          iVar5 = sk_num(p_Var4);
          if (iVar5 <= iVar2) break;
          piVar6 = (int *)sk_value((_STACK *)puVar3[3],iVar2);
          if ((*piVar6 == 4) && (iVar5 = X509_NAME_cmp(a,(X509_NAME *)piVar6[1]), iVar5 == 0))
          goto LAB_001a1762;
          p_Var4 = (_STACK *)puVar3[3];
          iVar2 = iVar2 + 1;
        }
      }
      iVar1 = iVar1 + 1;
      iVar2 = sk_num(*(_STACK **)(*param_1 + 0x14));
    } while (iVar1 < iVar2);
  }
  return 0;
}

