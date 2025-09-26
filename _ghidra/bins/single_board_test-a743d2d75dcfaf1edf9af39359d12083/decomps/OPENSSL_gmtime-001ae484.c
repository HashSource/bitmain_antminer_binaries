
tm * OPENSSL_gmtime(time_t *param_1,tm *param_2)

{
  gmtime_r(param_1,param_2);
  return param_2;
}

