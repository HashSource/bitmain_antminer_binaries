
void BUF_reverse(uchar *out,uchar *in,size_t siz)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  if (in == (uchar *)0x0) {
    if (siz >> 1 != 0) {
      puVar2 = out;
      puVar4 = out + (siz - 1);
      do {
        uVar1 = *puVar4;
        puVar3 = puVar4 + -1;
        *puVar4 = *puVar2;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
        puVar4 = puVar3;
      } while (puVar3 != out + (siz - 1) + -(siz >> 1));
    }
  }
  else if (siz != 0) {
    puVar2 = out + (siz - 1);
    puVar4 = in;
    do {
      puVar3 = puVar4 + 1;
      *puVar2 = *puVar4;
      puVar2 = puVar2 + -1;
      puVar4 = puVar3;
    } while (puVar3 != in + siz);
  }
  return;
}

