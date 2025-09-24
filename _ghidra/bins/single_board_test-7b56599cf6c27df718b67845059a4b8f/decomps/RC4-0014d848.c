
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  uchar *puVar6;
  int iVar7;
  uchar *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar2 = key->x;
  uVar1 = key->y;
  if (len >> 3 != 0) {
    iVar7 = ((len >> 3) + 1) * 8;
    puVar5 = indata + 8;
    puVar8 = outdata + 8;
    do {
      puVar6 = puVar5 + 8;
      uVar10 = uVar2 + 1 & 0xff;
      uVar2 = key->data[uVar10];
      uVar11 = uVar10 + 1 & 0xff;
      uVar1 = uVar1 + uVar2 & 0xff;
      uVar12 = uVar11 + 1 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar10] = uVar3;
      key->data[uVar1] = uVar2;
      uVar4 = uVar12 + 1 & 0xff;
      puVar8[-8] = (byte)key->data[uVar3 + uVar2 & 0xff] ^ puVar5[-8];
      uVar3 = key->data[uVar11];
      uVar9 = uVar4 + 1 & 0xff;
      uVar1 = uVar1 + uVar3 & 0xff;
      uVar2 = key->data[uVar1];
      key->data[uVar11] = uVar2;
      key->data[uVar1] = uVar3;
      uVar11 = uVar9 + 1 & 0xff;
      puVar8[-7] = (byte)key->data[uVar3 + uVar2 & 0xff] ^ puVar5[-7];
      uVar3 = key->data[uVar12];
      uVar1 = uVar1 + uVar3 & 0xff;
      uVar2 = key->data[uVar1];
      key->data[uVar12] = uVar2;
      key->data[uVar1] = uVar3;
      uVar12 = uVar11 + 1 & 0xff;
      puVar8[-6] = (byte)key->data[uVar3 + uVar2 & 0xff] ^ puVar5[-6];
      uVar10 = key->data[uVar4];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar4] = uVar3;
      key->data[uVar1] = uVar10;
      uVar2 = uVar12 + 1 & 0xff;
      puVar8[-5] = (byte)key->data[uVar10 + uVar3 & 0xff] ^ puVar5[-5];
      uVar10 = key->data[uVar9];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar9] = uVar3;
      key->data[uVar1] = uVar10;
      puVar8[-4] = (byte)key->data[uVar10 + uVar3 & 0xff] ^ puVar5[-4];
      uVar10 = key->data[uVar11];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar11] = uVar3;
      key->data[uVar1] = uVar10;
      puVar8[-3] = (byte)key->data[uVar10 + uVar3 & 0xff] ^ puVar5[-3];
      uVar10 = key->data[uVar12];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar12] = uVar3;
      key->data[uVar1] = uVar10;
      puVar8[-2] = (byte)key->data[uVar10 + uVar3 & 0xff] ^ puVar5[-2];
      uVar10 = key->data[uVar2];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar3 = key->data[uVar1];
      key->data[uVar2] = uVar3;
      key->data[uVar1] = uVar10;
      puVar8[-1] = (byte)key->data[uVar10 + uVar3 & 0xff] ^ puVar5[-1];
      puVar5 = puVar6;
      puVar8 = puVar8 + 8;
    } while (indata + iVar7 != puVar6);
    iVar7 = iVar7 + -8;
    indata = indata + iVar7;
    outdata = outdata + iVar7;
  }
  uVar3 = len & 7;
  if (uVar3 != 0) {
    uVar2 = uVar2 + 1 & 0xff;
    uVar10 = key->data[uVar2];
    uVar1 = uVar1 + uVar10 & 0xff;
    uVar4 = key->data[uVar1];
    key->data[uVar2] = uVar4;
    key->data[uVar1] = uVar10;
    *outdata = (byte)key->data[uVar10 + uVar4 & 0xff] ^ *indata;
    if (uVar3 != 1) {
      uVar2 = uVar2 + 1 & 0xff;
      uVar10 = key->data[uVar2];
      uVar1 = uVar1 + uVar10 & 0xff;
      uVar4 = key->data[uVar1];
      key->data[uVar2] = uVar4;
      key->data[uVar1] = uVar10;
      outdata[1] = (byte)key->data[uVar10 + uVar4 & 0xff] ^ indata[1];
      if (uVar3 != 2) {
        uVar2 = uVar2 + 1 & 0xff;
        uVar10 = key->data[uVar2];
        uVar1 = uVar1 + uVar10 & 0xff;
        uVar4 = key->data[uVar1];
        key->data[uVar2] = uVar4;
        key->data[uVar1] = uVar10;
        outdata[2] = (byte)key->data[uVar10 + uVar4 & 0xff] ^ indata[2];
        if (uVar3 != 3) {
          uVar2 = uVar2 + 1 & 0xff;
          uVar10 = key->data[uVar2];
          uVar1 = uVar1 + uVar10 & 0xff;
          uVar4 = key->data[uVar1];
          key->data[uVar2] = uVar4;
          key->data[uVar1] = uVar10;
          outdata[3] = (byte)key->data[uVar10 + uVar4 & 0xff] ^ indata[3];
          if (uVar3 != 4) {
            uVar2 = uVar2 + 1 & 0xff;
            uVar10 = key->data[uVar2];
            uVar1 = uVar1 + uVar10 & 0xff;
            uVar4 = key->data[uVar1];
            key->data[uVar2] = uVar4;
            key->data[uVar1] = uVar10;
            outdata[4] = (byte)key->data[uVar10 + uVar4 & 0xff] ^ indata[4];
            if (uVar3 != 5) {
              uVar2 = uVar2 + 1 & 0xff;
              uVar10 = key->data[uVar2];
              uVar1 = uVar1 + uVar10 & 0xff;
              uVar4 = key->data[uVar1];
              key->data[uVar2] = uVar4;
              key->data[uVar1] = uVar10;
              outdata[5] = (byte)key->data[uVar10 + uVar4 & 0xff] ^ indata[5];
              if (uVar3 != 6) {
                uVar2 = uVar2 + 1 & 0xff;
                uVar3 = key->data[uVar2];
                uVar1 = uVar1 + uVar3 & 0xff;
                uVar10 = key->data[uVar1];
                key->data[uVar2] = uVar10;
                key->data[uVar1] = uVar3;
                outdata[6] = indata[6] ^ (byte)key->data[uVar3 + uVar10 & 0xff];
              }
            }
          }
        }
      }
    }
  }
  key->x = uVar2;
  key->y = uVar1;
  return;
}

