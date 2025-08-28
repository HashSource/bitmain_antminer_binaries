
int8_t calc_offset(int remote,int local)

{
  int local_local;
  int remote_local;
  float t_noise;
  
  return (int8_t)(int)(0.0 - (float)(((double)(longlong)remote -
                                     ((double)(longlong)local + 273.15) * 0.10119047619047628) -
                                    (double)(longlong)local));
}

