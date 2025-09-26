
undefined4 tls12_get_sigandhash(undefined1 *param_1,int *param_2,EVP_MD *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  if (param_3 != (EVP_MD *)0x0) {
    iVar1 = EVP_MD_type(param_3);
    puVar2 = &tls12_md;
    if (iVar1 != tls12_md) {
      if (iVar1 == DAT_0024d2e8) {
        puVar2 = &DAT_0024d2e8;
      }
      else if (iVar1 == DAT_0024d2f0) {
        puVar2 = &DAT_0024d2f0;
      }
      else if (iVar1 == DAT_0024d2f8) {
        puVar2 = &DAT_0024d2f8;
      }
      else if (iVar1 == DAT_0024d300) {
        puVar2 = &DAT_0024d300;
      }
      else {
        if (iVar1 != DAT_0024d308) {
          return 0;
        }
        puVar2 = &DAT_0024d308;
      }
    }
    if (puVar2[1] != -1) {
      iVar1 = *param_2;
      if (iVar1 == tls12_sig._0_4_) {
        puVar3 = tls12_sig;
      }
      else if (iVar1 == tls12_sig._8_4_) {
        puVar3 = (undefined1 *)0x24d318;
      }
      else {
        if (iVar1 != tls12_sig._16_4_) {
          return 0;
        }
        puVar3 = (undefined1 *)0x24d320;
      }
      iVar1 = *(int *)(puVar3 + 4);
      if (iVar1 != -1) {
        *param_1 = (char)puVar2[1];
        param_1[1] = (char)iVar1;
        return 1;
      }
    }
  }
  return 0;
}

