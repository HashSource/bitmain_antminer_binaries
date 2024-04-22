
void Curl_pgrsStartNow(int param_1)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  *(undefined4 *)(param_1 + 0x578) = 0;
  curlx_tvnow(&local_18);
  *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) & 0x90;
  *(undefined4 *)(param_1 + 0x4f8) = local_18;
  *(undefined4 *)(param_1 + 0x4fc) = uStack_14;
  return;
}

