
void * CRYPTO_get_ex_data(CRYPTO_EX_DATA *ad,int idx)

{
  int iVar1;
  void *pvVar2;
  
  if ((&ad->sk->stack != (_STACK *)0x0) && (iVar1 = sk_num(&ad->sk->stack), idx < iVar1)) {
    pvVar2 = sk_value(&ad->sk->stack,idx);
    return pvVar2;
  }
  return (void *)0x0;
}

