
undefined4 EVP_PKEY_set1_engine(int *param_1,ENGINE *param_2)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  
  if (param_2 != (ENGINE *)0x0) {
    iVar1 = ENGINE_init(param_2);
    if (iVar1 == 0) {
      ERR_put_error(6,0xbb,0x26,"crypto/evp/p_lib.c",0x185);
      return 0;
    }
    pEVar2 = ENGINE_get_pkey_meth(param_2,*param_1);
    if (pEVar2 == (EVP_PKEY_METHOD *)0x0) {
      ENGINE_finish(param_2);
      ERR_put_error(6,0xbb,0x9c,"crypto/evp/p_lib.c",0x18a);
      return 0;
    }
  }
  ENGINE_finish((ENGINE *)param_1[5]);
  param_1[5] = (int)param_2;
  return 1;
}

