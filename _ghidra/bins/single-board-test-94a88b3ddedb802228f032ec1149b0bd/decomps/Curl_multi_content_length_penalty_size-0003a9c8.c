
undefined8 Curl_multi_content_length_penalty_size(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xa4);
    iVar2 = iVar1 >> 0x1f;
  }
  return CONCAT44(iVar2,iVar1);
}

