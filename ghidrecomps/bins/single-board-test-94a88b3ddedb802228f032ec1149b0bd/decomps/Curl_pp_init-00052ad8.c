
void Curl_pp_init(int param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar1 = **(int **)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined *)(param_1 + 0x10) = 1;
  *(int *)(param_1 + 0xc) = iVar1 + 0x59c;
  curlx_tvnow(&local_18);
  *(undefined4 *)(param_1 + 0x20) = local_18;
  *(undefined4 *)(param_1 + 0x24) = uStack_14;
  return;
}

