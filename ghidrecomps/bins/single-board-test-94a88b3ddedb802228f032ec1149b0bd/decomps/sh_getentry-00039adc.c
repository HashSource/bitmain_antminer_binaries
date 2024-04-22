
undefined4 sh_getentry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int local_c [3];
  
  if (param_2 == -1) {
    uVar1 = 0;
  }
  else {
    local_c[0] = param_2;
    uVar1 = Curl_hash_pick(param_1,local_c,4);
  }
  return uVar1;
}

