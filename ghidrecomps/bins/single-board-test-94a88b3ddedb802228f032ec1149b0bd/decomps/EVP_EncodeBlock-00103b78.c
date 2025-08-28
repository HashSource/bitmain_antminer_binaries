
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  uchar uVar1;
  uchar uVar2;
  uchar *puVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar uVar7;
  uint uVar8;
  uchar *puVar9;
  
  if (n < 1) {
    iVar4 = 0;
    puVar9 = t;
  }
  else {
    puVar5 = f + 3;
    iVar4 = 0;
    puVar3 = t + 4;
    puVar6 = puVar5;
    do {
      puVar9 = puVar3;
      if (n < 3) {
        uVar7 = '=';
        uVar8 = (uint)puVar5[-3] << 0x10;
        if (n == 2) {
          uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uVar8 | (uint)f[1] << 8) << 0xe) >> 0x1a];
          uVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [((uint)f[1] << 8 & 0xfc0) >> 6];
          puVar9[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                       [uVar8 >> 0x12];
          t[1] = uVar1;
        }
        else {
          uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                  [uVar8 >> 0xc & 0x3f];
          puVar9[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                       [uVar8 >> 0x12];
          t[1] = uVar1;
        }
        t[2] = uVar7;
        t[3] = '=';
      }
      else {
        uVar8 = (uint)CONCAT12(puVar5[-3],CONCAT11(f[1],f[2]));
        uVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar8 << 0xe) >> 0x1a];
        uVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar8 << 0x14) >> 0x1a];
        uVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar8 & 0x3f];
        puVar9[-4] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                     [puVar5[-3] >> 2];
        t[1] = uVar1;
        t[2] = uVar2;
        t[3] = uVar7;
      }
      n = n + -3;
      iVar4 = iVar4 + 4;
      puVar5 = puVar5 + 3;
      t = t + 4;
      f = puVar6;
      puVar3 = puVar9 + 4;
      puVar6 = puVar6 + 3;
    } while (0 < n);
  }
  *puVar9 = '\0';
  return iVar4;
}

