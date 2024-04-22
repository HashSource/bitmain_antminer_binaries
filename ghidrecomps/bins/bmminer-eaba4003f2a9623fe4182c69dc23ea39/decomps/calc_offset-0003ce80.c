
int8_t calc_offset(int remote,int local)

{
  int local_local;
  int remote_local;
  float t_noise;
  
  return (int8_t)(int)(DAT_0003cef8 -
                      (float)(((double)(longlong)remote -
                              ((double)(longlong)local + DAT_0003cee8) * DAT_0003cef0) -
                             (double)(longlong)local));
}

