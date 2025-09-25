
uchar twoc2hex(uchar high,uchar low)

{
  uchar uVar1;
  byte bVar2;
  uchar low_local;
  uchar high_local;
  uchar ret;
  
  uVar1 = c2hex(high);
  bVar2 = c2hex(low);
  return bVar2 ^ uVar1 << 4;
}

