
int OSSL_STORE_load(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  param_1[7] = 1;
LAB_001bfeda:
  iVar2 = OSSL_STORE_eof(param_1);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*param_1 + 0x18))
                      (param_1[1],param_1[2],param_1[3],*(code **)(*param_1 + 0x18),param_4);
    if ((code *)param_1[4] == (code *)0x0) {
      if (iVar2 != 0) {
        if (param_1[6] == 0) {
          return iVar2;
        }
        goto LAB_001bfec4;
      }
    }
    else if (iVar2 != 0) goto LAB_001bfeb6;
  }
  return 0;
LAB_001bfeb6:
  iVar2 = (*(code *)param_1[4])(iVar2,param_1[5]);
  if (iVar2 != 0) {
    if (param_1[6] != 0) {
LAB_001bfec4:
      uVar1 = OSSL_STORE_INFO_get_type(iVar2);
      if ((1 < uVar1) && (uVar1 != param_1[6])) {
        OSSL_STORE_INFO_free(iVar2);
        goto LAB_001bfeda;
      }
    }
    return iVar2;
  }
  goto LAB_001bfeda;
}

