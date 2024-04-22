
/* WARNING: Unknown calling convention */

uchar twoc2hex(uchar high,uchar low)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = c2hex(high);
  bVar2 = c2hex(low);
  return bVar2 ^ (byte)((bVar1 & 0xf) << 4);
}

