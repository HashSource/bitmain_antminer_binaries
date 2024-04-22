
int calc_offset(int param_1,int param_2)

{
  char local_4;
  
  local_4 = (char)(int)(DAT_000328d8 -
                       (float)(((double)(longlong)param_1 -
                               ((double)(longlong)param_2 + DAT_000328c8) * DAT_000328d0) -
                              (double)(longlong)param_2));
  return (int)local_4;
}

