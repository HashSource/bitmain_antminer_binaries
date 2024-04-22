
int ser_number(uchar *s,int32_t val)

{
  int32_t val_local;
  uchar *s_local;
  int32_t *i32;
  int len;
  
  if (val < 0x80) {
    len = 1;
  }
  else if (val < 0x4080) {
    len = 2;
  }
  else if (val < 0x204080) {
    len = 3;
  }
  else {
    len = 4;
  }
  *(int32_t *)(s + 1) = val;
  *s = (uchar)len;
  return len + 1;
}

