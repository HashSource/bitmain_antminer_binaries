
uint IsPipeliningPossible(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(*(int *)(param_2 + 0x218) + 0x3c) & 3;
  if (((uVar1 != 0) &&
      (((iVar2 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40),1), iVar2 == 0 ||
        (*(int *)(param_1 + 0x27c) == 1)) ||
       (uVar1 = *(uint *)(param_1 + 0x278) & 0xfffffffb, uVar1 != 1)))) &&
     (uVar1 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40),2), uVar1 != 0)) {
    if (*(int *)(param_1 + 0x27c) < 3) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

