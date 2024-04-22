
int getVolValueFromPICvoltage(uchar vol_pic)

{
  uchar vol_pic_local;
  int vol_value;
  
  return (int)(longlong)
              (((double)(longlong)(int)(uint)vol_pic * DAT_00032210 + DAT_00032218) /
              ((double)(longlong)(int)(uint)vol_pic * DAT_00032220 + DAT_00032228));
}

