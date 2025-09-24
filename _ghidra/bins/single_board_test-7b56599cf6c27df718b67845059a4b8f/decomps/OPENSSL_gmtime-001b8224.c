
tm * OPENSSL_gmtime(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
  ptVar1 = gmtime_r(param_1,param_2);
  if (ptVar1 == (tm *)0x0) {
    param_2 = (tm *)0x0;
  }
  return param_2;
}

