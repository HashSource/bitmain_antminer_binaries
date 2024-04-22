
int getVolValueFromPICvoltage(byte param_1)

{
  return ((int)(longlong)
               (((DAT_000249c0 / ((double)(longlong)(int)(uint)param_1 + DAT_000249b8) +
                 DAT_000249c8) * DAT_000249d0) / 4.75) / 10) * 10;
}

