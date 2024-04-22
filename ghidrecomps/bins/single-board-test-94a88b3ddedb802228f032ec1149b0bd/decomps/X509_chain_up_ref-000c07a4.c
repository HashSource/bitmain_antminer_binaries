
void X509_chain_up_ref(_STACK *param_1)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  p_Var1 = sk_dup(param_1);
  iVar4 = 0;
  while( true ) {
    iVar3 = sk_num(p_Var1);
    if (iVar3 <= iVar4) break;
    pvVar2 = sk_value(p_Var1,iVar4);
    CRYPTO_add_lock((int *)((int)pvVar2 + 0x10),1,3,DAT_000c07e0,0x1ef);
    iVar4 = iVar4 + 1;
  }
  return;
}

