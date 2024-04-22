
int EVP_EncodeBlock(uchar *t,uchar *f,int n)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  uchar *puVar6;
  uchar *puVar7;
  uchar uVar8;
  uint uVar9;
  uchar *puVar10;
  
  iVar3 = DAT_00103c60;
  if (n < 1) {
    iVar5 = 0;
    puVar10 = t;
  }
  else {
    puVar6 = f + 3;
    iVar5 = 0;
    puVar4 = t + 4;
    puVar7 = puVar6;
    do {
      puVar10 = puVar4;
      if (n < 3) {
        uVar8 = '=';
        uVar9 = (uint)puVar6[-3] << 0x10;
        if (n == 2) {
          uVar1 = *(uchar *)(iVar3 + (((uVar9 | (uint)f[1] << 8) << 0xe) >> 0x1a));
          uVar8 = *(uchar *)(iVar3 + (((uint)f[1] << 8 & 0xfc0) >> 6));
          puVar10[-4] = *(uchar *)(iVar3 + (uVar9 >> 0x12));
          t[1] = uVar1;
        }
        else {
          uVar1 = *(uchar *)(iVar3 + (uVar9 >> 0xc & 0x3f));
          puVar10[-4] = *(uchar *)(iVar3 + (uVar9 >> 0x12));
          t[1] = uVar1;
        }
        t[2] = uVar8;
        t[3] = '=';
      }
      else {
        uVar9 = (uint)CONCAT12(puVar6[-3],CONCAT11(f[1],f[2]));
        uVar1 = *(uchar *)(iVar3 + ((uVar9 << 0xe) >> 0x1a));
        uVar2 = *(uchar *)(iVar3 + ((uVar9 << 0x14) >> 0x1a));
        uVar8 = *(uchar *)(iVar3 + (uVar9 & 0x3f));
        puVar10[-4] = *(uchar *)(iVar3 + (uint)(puVar6[-3] >> 2));
        t[1] = uVar1;
        t[2] = uVar2;
        t[3] = uVar8;
      }
      n = n + -3;
      iVar5 = iVar5 + 4;
      puVar6 = puVar6 + 3;
      t = t + 4;
      f = puVar7;
      puVar4 = puVar10 + 4;
      puVar7 = puVar7 + 3;
    } while (0 < n);
  }
  *puVar10 = '\0';
  return iVar5;
}

