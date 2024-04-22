
uchar * string_to_hex(char *str,long *len)

{
  byte bVar1;
  size_t sVar2;
  byte *ptr;
  ushort **ppuVar3;
  __int32_t **pp_Var4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  byte *pbVar11;
  
  if (str == (char *)0x0) {
    ERR_put_error(0x22,0x71,0x6b,DAT_000c81ac,0x1ba);
    ptr = (byte *)0x0;
  }
  else {
    sVar2 = strlen(str);
    ptr = (byte *)CRYPTO_malloc((int)sVar2 >> 1,DAT_000c81ac,0x1bd);
    pbVar11 = ptr;
    if (ptr == (byte *)0x0) {
      ERR_put_error(0x22,0x71,0x41,DAT_000c81ac,0x1ed);
    }
    else {
      while( true ) {
        pbVar5 = (byte *)str;
        bVar6 = *pbVar5;
        uVar7 = (uint)bVar6;
        if (uVar7 == 0) break;
        str = (char *)(pbVar5 + 1);
        if (uVar7 != 0x3a) {
          bVar1 = pbVar5[1];
          uVar8 = (uint)bVar1;
          if (uVar8 == 0) {
            ERR_put_error(0x22,0x71,0x70,DAT_000c81ac,0x1cb);
            CRYPTO_free(ptr);
            return (uchar *)0x0;
          }
          ppuVar3 = __ctype_b_loc();
          puVar9 = *ppuVar3;
          if ((int)((uint)puVar9[(short)(ushort)bVar6] << 0x17) < 0) {
            pp_Var4 = __ctype_tolower_loc();
            uVar7 = (uint)*(byte *)(*pp_Var4 + (short)(ushort)bVar6);
          }
          if ((int)((uint)puVar9[(short)(ushort)bVar1] << 0x17) < 0) {
            pp_Var4 = __ctype_tolower_loc();
            uVar8 = (uint)*(byte *)(*pp_Var4 + (short)(ushort)bVar1);
          }
          uVar10 = uVar7 - 0x30 & 0xff;
          if (9 < uVar10) {
            if (5 < uVar7 - 0x61) goto LAB_000c8162;
            uVar10 = uVar7 - 0x57 & 0xff;
          }
          bVar6 = (byte)(uVar8 - 0x30);
          if (9 < (uVar8 - 0x30 & 0xff)) {
            if (5 < uVar8 - 0x61) {
LAB_000c8162:
              CRYPTO_free(ptr);
              ERR_put_error(0x22,0x71,0x71,DAT_000c81ac,0x1f2);
              return (uchar *)0x0;
            }
            bVar6 = (char)uVar8 + 0xa9;
          }
          *pbVar11 = bVar6 | (byte)(uVar10 << 4);
          str = (char *)(pbVar5 + 2);
          pbVar11 = pbVar11 + 1;
        }
      }
      if (len != (long *)0x0) {
        *len = (int)pbVar11 - (int)ptr;
      }
    }
  }
  return ptr;
}

