
/* WARNING: Unknown calling convention */

int getVolValueFromPICvoltage(uchar vol_pic)

{
  return ((int)(longlong)
               (((DAT_0002b9c8 / ((double)(longlong)(int)(uint)vol_pic + DAT_0002b9d0) +
                 DAT_0002b9d8) * DAT_0002b9e0) / 4.75) / 10) * 10;
}

