
/* WARNING: Unknown calling convention */

int8_t calc_offset(int remote,int local)

{
  return (int8_t)(int)(DAT_00032920 -
                      (float)(((double)(longlong)remote -
                              ((double)(longlong)local + DAT_00032910) * DAT_00032918) -
                             (double)(longlong)local));
}

