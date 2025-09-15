
int getVolValueFromPICvoltage(uchar vol_pic)

{
  uchar vol_pic_local;
  int vol_value;
  
  return (int)(longlong)
              (((double)vol_pic * 218900.7 + 9332700.36) / ((double)vol_pic * 249.5 + 7664.64));
}

