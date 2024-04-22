
undefined4 Curl_gmtime(time_t param_1,tm *param_2)

{
  tm *ptVar1;
  undefined4 uVar2;
  time_t local_c [3];
  
  local_c[0] = param_1;
  ptVar1 = gmtime_r(local_c,param_2);
  if (ptVar1 == (tm *)0x0) {
    uVar2 = 0x2b;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

