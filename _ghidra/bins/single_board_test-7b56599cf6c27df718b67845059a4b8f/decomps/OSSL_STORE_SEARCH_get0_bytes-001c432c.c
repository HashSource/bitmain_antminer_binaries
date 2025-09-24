
undefined4 OSSL_STORE_SEARCH_get0_bytes(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  return uVar1;
}

