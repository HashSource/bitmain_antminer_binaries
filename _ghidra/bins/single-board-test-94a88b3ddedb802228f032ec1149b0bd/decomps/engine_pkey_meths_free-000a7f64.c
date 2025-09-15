
void engine_pkey_meths_free(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  EVP_PKEY_METHOD *local_20;
  int local_1c [2];
  
  if ((*(code **)(param_1 + 0x2c) != (code *)0x0) &&
     (iVar1 = (**(code **)(param_1 + 0x2c))(param_1,0,local_1c,0), 0 < iVar1)) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        iVar2 = (**(code **)(param_1 + 0x2c))
                          (param_1,&local_20,0,*(undefined4 *)(local_1c[0] + iVar2));
        if (iVar2 == 0) break;
        EVP_PKEY_meth_free(local_20);
        if (iVar3 == iVar1) {
          return;
        }
      }
    } while (iVar3 != iVar1);
  }
  return;
}

