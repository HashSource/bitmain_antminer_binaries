
uint safe_strequal(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 != 0 && param_1 != 0) {
    uVar1 = Curl_raw_equal();
    if (uVar1 != 0) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return (uint)(param_2 == 0 && param_1 == 0);
}

