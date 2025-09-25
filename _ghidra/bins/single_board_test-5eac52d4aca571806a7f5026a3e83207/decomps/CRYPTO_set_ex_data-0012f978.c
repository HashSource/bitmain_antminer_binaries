
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad,int idx,void *val)

{
  int iVar1;
  int iVar2;
  stack_st_void *psVar3;
  
  psVar3 = ad->sk;
  if (psVar3 == (stack_st_void *)0x0) {
    psVar3 = (stack_st_void *)OPENSSL_sk_new_null();
    ad->sk = psVar3;
    if (psVar3 == (stack_st_void *)0x0) {
      iVar1 = 0x177;
      goto LAB_0012f9b2;
    }
  }
  iVar1 = OPENSSL_sk_num(psVar3);
  do {
    if (idx < iVar1) {
      OPENSSL_sk_set(ad->sk,idx,val);
      return 1;
    }
    iVar2 = OPENSSL_sk_push(ad->sk,0);
    iVar1 = iVar1 + 1;
  } while (iVar2 != 0);
  iVar1 = 0x17e;
LAB_0012f9b2:
  ERR_put_error(0xf,0x66,0x41,"crypto/ex_data.c",iVar1);
  return 0;
}

