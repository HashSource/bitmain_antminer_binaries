
int * ossl_store_attach_pem_bio(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = ossl_store_get0_loader_int("file");
  if ((iVar1 == 0) || (iVar2 = ossl_store_file_attach_pem_bio_int(param_1), iVar2 == 0)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)CRYPTO_zalloc(0x20,"crypto/store/store_lib.c",0x28e);
    if (piVar3 == (int *)0x0) {
      ERR_put_error(0x2c,0x7f,0x41,"crypto/store/store_lib.c",0x290);
      (**(code **)(iVar1 + 0x24))(iVar2);
      return (int *)0x0;
    }
    *piVar3 = iVar1;
    piVar3[1] = iVar2;
    piVar3[2] = param_2;
    piVar3[3] = param_3;
    piVar3[4] = 0;
    piVar3[5] = 0;
  }
  return piVar3;
}

