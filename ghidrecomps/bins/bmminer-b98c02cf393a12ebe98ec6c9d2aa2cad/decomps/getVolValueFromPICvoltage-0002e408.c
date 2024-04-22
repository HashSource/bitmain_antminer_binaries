
int getVolValueFromPICvoltage(int param_1)

{
  return ((int)(longlong)
               (((DAT_0002e468 / ((double)(longlong)param_1 + DAT_0002e460) + DAT_0002e470) *
                DAT_0002e478) / 4.75) / 10) * 10;
}

