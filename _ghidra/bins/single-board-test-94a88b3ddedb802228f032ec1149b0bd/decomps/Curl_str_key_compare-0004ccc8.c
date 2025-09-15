
int Curl_str_key_compare(void *param_1,size_t param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 != param_4) {
    return 0;
  }
  uVar1 = memcmp(param_1,param_3,param_2);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

