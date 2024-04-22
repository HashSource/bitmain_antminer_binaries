
/* WARNING: Unknown calling convention */

void rev(uchar *s,uchar l)

{
  uchar uVar1;
  uchar j;
  uint uVar3;
  uchar t;
  uint uVar2;
  
  uVar2 = l - 1 & 0xff;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      uVar1 = s[uVar3];
      s[uVar3] = s[uVar2];
      uVar3 = uVar3 + 1 & 0xff;
      s[uVar2] = uVar1;
      uVar2 = uVar2 - 1 & 0xff;
    } while (uVar3 < uVar2);
  }
  return;
}

