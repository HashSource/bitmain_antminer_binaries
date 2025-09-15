
/* WARNING: Unknown calling convention */

int getVolValueFromPICvoltage(uchar vol_pic)

{
  return ((int)(longlong)(((364.0704 / ((double)vol_pic + 30.72) + 32.79) * 100.0) / 4.75) / 10) *
         10;
}

