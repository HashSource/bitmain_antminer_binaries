
bool tailmatch(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_2);
  if (sVar1 <= sVar2) {
    iVar3 = Curl_raw_equal(param_1,param_2 + (sVar2 - sVar1),param_3,sVar2 - sVar1,param_4);
    if (iVar3 != 0) {
      if (sVar2 != sVar1) {
        return (param_2 + (sVar2 - sVar1))[-1] == '.';
      }
      return true;
    }
  }
  return false;
}

