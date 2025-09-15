
int Curl_multi_add_perform(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = curl_multi_add_handle();
  if (iVar1 == 0) {
    Curl_init_do(param_2,0);
    mstate(param_2,0xe);
    *(undefined4 *)(param_2 + 8) = param_3;
    *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) | 1;
  }
  return iVar1;
}

