
void X509_STORE_free(X509_STORE *v)

{
  int iVar1;
  void *ptr;
  int iVar2;
  _STACK *p_Var3;
  
  if (v != (X509_STORE *)0x0) {
    iVar1 = CRYPTO_add_lock(&v->references,-1,0xb,DAT_000c3b10,0xf1);
    if (iVar1 < 1) {
      p_Var3 = &v->get_cert_methods->stack;
      iVar1 = 0;
      do {
        iVar2 = sk_num(p_Var3);
        if (iVar2 <= iVar1) {
          sk_free(p_Var3);
          sk_pop_free(&v->objs->stack,DAT_000c3b14);
          CRYPTO_free_ex_data(4,v,&v->ex_data);
          if (v->param != (X509_VERIFY_PARAM *)0x0) {
            X509_VERIFY_PARAM_free(v->param);
          }
          CRYPTO_free(v);
          return;
        }
        ptr = sk_value(p_Var3,iVar1);
        iVar2 = *(int *)((int)ptr + 8);
        if (iVar2 != 0) {
          if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
            (**(code **)(iVar2 + 0x10))();
            iVar2 = *(int *)((int)ptr + 8);
            if (iVar2 == 0) goto LAB_000c3acc;
          }
          if (*(code **)(iVar2 + 8) != (code *)0x0) {
            (**(code **)(iVar2 + 8))(ptr);
          }
        }
LAB_000c3acc:
        CRYPTO_free(ptr);
        iVar1 = iVar1 + 1;
      } while( true );
    }
  }
  return;
}

