
/* WARNING: Unknown calling convention */

void rev(uchar *s,size_t l)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = l - 1;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      uVar1 = s[uVar3];
      s[uVar3] = s[uVar2];
      uVar3 = uVar3 + 1;
      s[uVar2] = uVar1;
      uVar2 = uVar2 - 1;
    } while (uVar3 < uVar2);
  }
  return;
}

