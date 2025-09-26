
undefined4 ssl_cipher_id_cmp_BSEARCH_CMP_FN(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0xc)) {
    return 1;
  }
  if (*(uint *)(param_1 + 0xc) < *(uint *)(param_2 + 0xc)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

