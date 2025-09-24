
/* WARNING: Removing unreachable block (ram,0x00096b56) */
/* WARNING: Removing unreachable block (ram,0x00096b60) */
/* WARNING: Removing unreachable block (ram,0x00096b62) */
/* WARNING: Removing unreachable block (ram,0x00096b64) */
/* WARNING: Removing unreachable block (ram,0x00096b6a) */
/* WARNING: Removing unreachable block (ram,0x000966c8) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int LZ4_decompress_safe_continue
              (LZ4_streamDecode_t *LZ4_streamDecode,char *source,char *dest,int compressedSize,
              int maxOutputSize)

{
  U16 UVar1;
  undefined4 uVar2;
  BYTE *pBVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  BYTE *pBVar11;
  size_t sVar12;
  BYTE *pBVar13;
  bool bVar14;
  int compressedSize_local;
  char *dest_local;
  char *source_local;
  LZ4_streamDecode_t *LZ4_streamDecode_local;
  BYTE *ip;
  BYTE *e_2;
  BYTE *s_4;
  BYTE *d_2;
  BYTE *local_114;
  BYTE *local_110;
  BYTE *local_10c;
  BYTE *e_1;
  BYTE *s_3;
  BYTE *d_1;
  BYTE *local_fc;
  BYTE *local_f8;
  BYTE *local_f4;
  BYTE *oCopyLimit;
  BYTE *copyEnd;
  BYTE *matchEnd;
  size_t mlen;
  BYTE *copyFrom;
  BYTE *endOfMatch;
  size_t restSize;
  size_t copySize;
  size_t addl_1;
  Rvl_t s_2;
  Rvl_t length_2;
  undefined4 local_c4;
  BYTE *local_c0;
  BYTE **local_bc;
  BYTE *e;
  BYTE *s_1;
  BYTE *d;
  BYTE *local_ac;
  BYTE *local_a8;
  BYTE *local_a4;
  BYTE *cpy;
  size_t addl;
  Rvl_t s;
  Rvl_t length_1;
  undefined4 local_90;
  BYTE *local_8c;
  BYTE **local_88;
  BYTE *match;
  size_t offset;
  size_t length;
  uint token;
  BYTE *shortoend;
  BYTE *shortiend;
  int checkOffset;
  BYTE *dictEnd;
  BYTE *oend;
  BYTE *op;
  BYTE *iend;
  uint local_58;
  LZ4_byte *local_54;
  BYTE *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  char *local_3c;
  char *local_38;
  uint local_34;
  LZ4_byte *local_30;
  size_t local_2c;
  int local_28;
  int local_24;
  char *local_20;
  char *local_1c;
  LZ4_streamDecode_t_internal *lz4sd;
  int result;
  
  lz4sd = (LZ4_streamDecode_t_internal *)LZ4_streamDecode;
  if ((LZ4_streamDecode->internal_donotuse).prefixSize == 0) {
    result = LZ4_decompress_safe(source,dest,compressedSize,maxOutputSize);
    if (0 < result) {
      lz4sd->prefixSize = result;
      lz4sd->prefixEnd = (LZ4_byte *)(dest + result);
    }
  }
  else if ((LZ4_streamDecode->internal_donotuse).prefixEnd == (LZ4_byte *)dest) {
    if ((LZ4_streamDecode->internal_donotuse).prefixSize < 0xffff) {
      if ((LZ4_streamDecode->internal_donotuse).extDictSize == 0) {
        result = LZ4_decompress_safe_withSmallPrefix
                           (source,dest,compressedSize,maxOutputSize,
                            (LZ4_streamDecode->internal_donotuse).prefixSize);
      }
      else {
        local_2c = (LZ4_streamDecode->internal_donotuse).prefixSize;
        local_54 = (LZ4_streamDecode->internal_donotuse).externalDict;
        local_58 = (LZ4_streamDecode->internal_donotuse).extDictSize;
        local_28 = maxOutputSize;
        local_50 = (BYTE *)(dest + -local_2c);
        local_44 = maxOutputSize;
        local_48 = 0;
        local_4c = 2;
        if ((source == (char *)0x0) || (maxOutputSize < 0)) {
          result = -1;
        }
        else {
          iend = (BYTE *)(source + compressedSize);
          oend = (BYTE *)(dest + maxOutputSize);
          if (local_54 == (LZ4_byte *)0x0) {
            dictEnd = (LZ4_byte *)0x0;
          }
          else {
            dictEnd = local_54 + local_58;
          }
          uVar9 = local_58;
          if (local_58 < 0x10000) {
            uVar9 = 1;
          }
          bVar6 = (byte)uVar9;
          if (0xffff < local_58) {
            bVar6 = 0;
          }
          checkOffset = (int)bVar6;
          shortiend = iend + -0x10;
          shortoend = oend + -0x20;
          bVar14 = maxOutputSize == 0;
          if (bVar14) {
            maxOutputSize = 1;
          }
          cVar7 = (char)maxOutputSize;
          if (!bVar14) {
            cVar7 = '\0';
          }
          if (cVar7 == '\0') {
            iVar10 = compressedSize;
            if (compressedSize == 0) {
              iVar10 = 1;
            }
            cVar7 = (char)iVar10;
            if (compressedSize != 0) {
              cVar7 = '\0';
            }
            ip = (BYTE *)source;
            op = (BYTE *)dest;
            local_40 = compressedSize;
            local_3c = dest;
            local_38 = source;
            local_34 = local_58;
            local_30 = local_54;
            local_24 = compressedSize;
            local_20 = dest;
            local_1c = source;
            if (cVar7 == '\0') {
LAB_0009670a:
              do {
                pBVar3 = ip + 1;
                token = (uint)*ip;
                length = (size_t)(*ip >> 4);
                if (length == 0xf) {
LAB_0009684e:
                  ip = pBVar3;
                  if (length == 0xf) {
                    local_8c = iend + -0xf;
                    local_88 = &ip;
                    local_90 = 1;
                    length_1 = 0;
                    pBVar11 = pBVar3;
                    if (local_8c <= pBVar3) {
                      pBVar11 = (BYTE *)0x1;
                    }
                    cVar7 = (char)pBVar11;
                    if (pBVar3 < local_8c) {
                      cVar7 = '\0';
                    }
                    length = 0xf;
                    if (cVar7 == '\0') {
                      do {
                        s = (Rvl_t)**local_88;
                        *local_88 = *local_88 + 1;
                        length_1 = s + length_1;
                        pBVar3 = *local_88;
                        bVar14 = local_8c < pBVar3;
                        if (bVar14) {
                          pBVar3 = (BYTE *)0x1;
                        }
                        cVar7 = (char)pBVar3;
                        if (!bVar14) {
                          cVar7 = '\0';
                        }
                        if (cVar7 != '\0') {
                          addl = 0xffffffff;
                          break;
                        }
                        if ((int)length_1 < 0) {
                          addl = 0xffffffff;
                          break;
                        }
                        addl = length_1;
                      } while (s == 0xff);
                    }
                    else {
                      addl = 0xffffffff;
                    }
                    if (addl != 0xffffffff) {
                      length = addl + length;
                      pBVar3 = op;
                      if (op + length < op) {
                        pBVar3 = (BYTE *)0x1;
                      }
                      cVar7 = (char)pBVar3;
                      if (op + length >= op) {
                        cVar7 = '\0';
                      }
                      if (cVar7 == '\0') {
                        pBVar3 = ip + length;
                        bVar14 = pBVar3 < ip;
                        if (bVar14) {
                          pBVar3 = (BYTE *)0x1;
                        }
                        cVar7 = (char)pBVar3;
                        if (!bVar14) {
                          cVar7 = '\0';
                        }
                        if (cVar7 == '\0') goto LAB_00096962;
                      }
                    }
LAB_00097032:
                    result = (int)(local_38 + (-1 - (int)ip));
                    goto LAB_00097044;
                  }
LAB_00096962:
                  cpy = op + length;
                  if ((oend + -0xc < cpy) || (iend + -8 < ip + length)) {
                    if (local_48 == 0) {
                      if ((iend != ip + length) || (oend < cpy)) goto LAB_00097032;
                    }
                    else {
                      if (iend < ip + length) {
                        length = (int)iend - (int)ip;
                        cpy = op + length;
                      }
                      if (oend < cpy) {
                        cpy = oend;
                        length = (int)oend - (int)op;
                      }
                    }
                    memmove(op,ip,length);
                    ip = ip + length;
                    op = op + length;
                    if (((local_48 == 0) || (oend == cpy)) || (iend + -2 <= ip)) break;
                  }
                  else {
                    local_a4 = op;
                    local_a8 = ip;
                    d = op;
                    s_1 = ip;
                    do {
                      uVar2 = *(undefined4 *)(s_1 + 4);
                      *(undefined4 *)d = *(undefined4 *)s_1;
                      *(undefined4 *)(d + 4) = uVar2;
                      d = d + 8;
                      s_1 = s_1 + 8;
                    } while (d < cpy);
                    ip = ip + length;
                    e = cpy;
                    local_ac = cpy;
                    op = cpy;
                  }
                  UVar1 = LZ4_readLE16(ip);
                  offset = (size_t)UVar1;
                  ip = ip + 2;
                  match = op + -offset;
                  length = token & 0xf;
                  goto LAB_00096b32;
                }
                pBVar11 = pBVar3;
                if (pBVar3 < shortiend) {
                  pBVar11 = (BYTE *)0x1;
                }
                bVar6 = (byte)pBVar11;
                if (shortiend <= pBVar3) {
                  bVar6 = 0;
                }
                pBVar11 = op;
                if (op <= shortoend) {
                  pBVar11 = (BYTE *)0x1;
                }
                bVar8 = (byte)pBVar11;
                if (op > shortoend) {
                  bVar8 = 0;
                }
                if ((bVar8 & bVar6) == 0) goto LAB_0009684e;
                uVar2 = *(undefined4 *)(ip + 5);
                uVar4 = *(undefined4 *)(ip + 9);
                uVar5 = *(undefined4 *)(ip + 0xd);
                *(undefined4 *)op = *(undefined4 *)pBVar3;
                *(undefined4 *)(op + 4) = uVar2;
                *(undefined4 *)(op + 8) = uVar4;
                *(undefined4 *)(op + 0xc) = uVar5;
                op = op + length;
                ip = pBVar3 + length;
                length = token & 0xf;
                UVar1 = LZ4_readLE16(ip);
                offset = (size_t)UVar1;
                ip = ip + 2;
                match = op + -offset;
                if (((length != 0xf) && (7 < offset)) && ((local_4c == 1 || (local_50 <= match)))) {
                  uVar2 = *(undefined4 *)(match + 4);
                  *(undefined4 *)op = *(undefined4 *)match;
                  *(undefined4 *)(op + 4) = uVar2;
                  uVar2 = *(undefined4 *)(match + 0xc);
                  *(undefined4 *)(op + 8) = *(undefined4 *)(match + 8);
                  *(undefined4 *)(op + 0xc) = uVar2;
                  *(undefined2 *)(op + 0x10) = *(undefined2 *)(match + 0x10);
                  op = op + length + 4;
                  goto LAB_0009670a;
                }
LAB_00096b32:
                if (length == 0xf) {
                  local_c0 = iend + -4;
                  local_bc = &ip;
                  local_c4 = 0;
                  length_2 = 0;
                  do {
                    s_2 = (Rvl_t)**local_bc;
                    *local_bc = *local_bc + 1;
                    length_2 = s_2 + length_2;
                    pBVar3 = *local_bc;
                    bVar14 = local_c0 < pBVar3;
                    if (bVar14) {
                      pBVar3 = (BYTE *)0x1;
                    }
                    cVar7 = (char)pBVar3;
                    if (!bVar14) {
                      cVar7 = '\0';
                    }
                    if (cVar7 != '\0') {
                      addl_1 = 0xffffffff;
                      break;
                    }
                    if ((int)length_2 < 0) {
                      addl_1 = 0xffffffff;
                      break;
                    }
                    addl_1 = length_2;
                  } while (s_2 == 0xff);
                  if (addl_1 != 0xffffffff) {
                    length = addl_1 + length;
                    pBVar3 = op;
                    if (op + length < op) {
                      pBVar3 = (BYTE *)0x1;
                    }
                    cVar7 = (char)pBVar3;
                    if (op + length >= op) {
                      cVar7 = '\0';
                    }
                    if (cVar7 == '\0') goto LAB_00096bf4;
                  }
                  goto LAB_00097032;
                }
LAB_00096bf4:
                length = length + 4;
                if (checkOffset != 0) {
                  pBVar11 = match + local_58;
                  pBVar3 = pBVar11;
                  if (pBVar11 < local_50) {
                    pBVar3 = (BYTE *)0x1;
                  }
                  cVar7 = (char)pBVar3;
                  if (local_50 <= pBVar11) {
                    cVar7 = '\0';
                  }
                  if (cVar7 != '\0') goto LAB_00097032;
                }
                if ((local_4c == 2) && (match < local_50)) {
                  pBVar11 = oend + -5;
                  pBVar3 = pBVar11;
                  if (pBVar11 < op + length) {
                    pBVar3 = (BYTE *)0x1;
                  }
                  cVar7 = (char)pBVar3;
                  if (op + length <= pBVar11) {
                    cVar7 = '\0';
                  }
                  if (cVar7 != '\0') {
                    if (local_48 == 0) goto LAB_00097032;
                    if ((uint)((int)oend - (int)op) <= length) {
                      length = (int)oend - (int)op;
                    }
                  }
                  if ((uint)((int)local_50 - (int)match) < length) {
                    copySize = (int)local_50 - (int)match;
                    restSize = length - copySize;
                    memcpy(op,dictEnd + -copySize,copySize);
                    op = op + copySize;
                    if ((uint)((int)op - (int)local_50) < restSize) {
                      endOfMatch = op + restSize;
                      copyFrom = local_50;
                      while (op < endOfMatch) {
                        *op = *copyFrom;
                        copyFrom = copyFrom + 1;
                        op = op + 1;
                      }
                    }
                    else {
                      memcpy(op,local_50,restSize);
                      op = op + restSize;
                    }
                  }
                  else {
                    memmove(op,dictEnd + -((int)local_50 - (int)match),length);
                    op = op + length;
                  }
                  goto LAB_0009670a;
                }
                cpy = op + length;
                if ((local_48 == 0) || (cpy <= oend + -0xc)) {
                  sVar12 = offset;
                  if (offset < 8) {
                    sVar12 = 1;
                  }
                  cVar7 = (char)sVar12;
                  if (7 < offset) {
                    cVar7 = '\0';
                  }
                  if (cVar7 == '\0') {
                    uVar2 = *(undefined4 *)(match + 4);
                    *(undefined4 *)op = *(undefined4 *)match;
                    *(undefined4 *)(op + 4) = uVar2;
                    match = match + 8;
                  }
                  else {
                    LZ4_write32(op,0);
                    *op = *match;
                    op[1] = match[1];
                    op[2] = match[2];
                    op[3] = match[3];
                    uVar9 = inc32table[offset];
                    *(undefined4 *)(op + 4) = *(undefined4 *)(match + uVar9);
                    match = match + uVar9 + -dec64table[offset];
                  }
                  pBVar11 = op + 8;
                  pBVar13 = oend + -0xc;
                  pBVar3 = pBVar13;
                  if (pBVar13 < cpy) {
                    pBVar3 = (BYTE *)0x1;
                  }
                  cVar7 = (char)pBVar3;
                  if (cpy <= pBVar13) {
                    cVar7 = '\0';
                  }
                  if (cVar7 == '\0') {
                    uVar2 = *(undefined4 *)(match + 4);
                    *(undefined4 *)pBVar11 = *(undefined4 *)match;
                    *(undefined4 *)(op + 0xc) = uVar2;
                    if (0x10 < length) {
                      local_10c = op + 0x10;
                      local_110 = match + 8;
                      local_114 = cpy;
                      e_2 = cpy;
                      s_4 = local_110;
                      d_2 = local_10c;
                      do {
                        uVar2 = *(undefined4 *)(s_4 + 4);
                        *(undefined4 *)d_2 = *(undefined4 *)s_4;
                        *(undefined4 *)(d_2 + 4) = uVar2;
                        d_2 = d_2 + 8;
                        s_4 = s_4 + 8;
                      } while (d_2 < cpy);
                    }
                  }
                  else {
                    oCopyLimit = oend + -7;
                    if (oend + -5 < cpy) goto LAB_00097032;
                    op = pBVar11;
                    if (pBVar11 < oCopyLimit) {
                      local_f8 = match;
                      s_3 = match;
                      d_1 = pBVar11;
                      do {
                        uVar2 = *(undefined4 *)(s_3 + 4);
                        *(undefined4 *)d_1 = *(undefined4 *)s_3;
                        *(undefined4 *)(d_1 + 4) = uVar2;
                        d_1 = d_1 + 8;
                        s_3 = s_3 + 8;
                      } while (d_1 < oCopyLimit);
                      e_1 = oCopyLimit;
                      local_fc = oCopyLimit;
                      local_f4 = pBVar11;
                      match = match + ((int)oCopyLimit - (int)pBVar11);
                      op = oCopyLimit;
                    }
                    while (op < cpy) {
                      *op = *match;
                      match = match + 1;
                      op = op + 1;
                    }
                  }
                  op = cpy;
                  goto LAB_0009670a;
                }
                mlen = length;
                if ((uint)((int)oend - (int)op) <= length) {
                  mlen = (int)oend - (int)op;
                }
                matchEnd = match + mlen;
                copyEnd = op + mlen;
                if (op < matchEnd) {
                  while (op < copyEnd) {
                    *op = *match;
                    match = match + 1;
                    op = op + 1;
                  }
                }
                else {
                  memcpy(op,match,mlen);
                }
                op = copyEnd;
              } while (oend != copyEnd);
              result = (int)op - (int)local_3c;
            }
            else {
              result = -1;
            }
          }
          else if ((compressedSize == 1) && (*source == '\0')) {
            result = 0;
          }
          else {
            result = -1;
          }
        }
      }
    }
    else {
      result = LZ4_decompress_safe_withPrefix64k(source,dest,compressedSize,maxOutputSize);
    }
LAB_00097044:
    if (0 < result) {
      lz4sd->prefixSize = lz4sd->prefixSize + result;
      lz4sd->prefixEnd = lz4sd->prefixEnd + result;
    }
  }
  else {
    (LZ4_streamDecode->internal_donotuse).extDictSize =
         (LZ4_streamDecode->internal_donotuse).prefixSize;
    (LZ4_streamDecode->internal_donotuse).externalDict =
         (LZ4_streamDecode->internal_donotuse).prefixEnd +
         -(LZ4_streamDecode->internal_donotuse).extDictSize;
    result = LZ4_decompress_safe_forceExtDict
                       (source,dest,compressedSize,maxOutputSize,
                        (LZ4_streamDecode->internal_donotuse).externalDict,
                        (LZ4_streamDecode->internal_donotuse).extDictSize);
    if (0 < result) {
      lz4sd->prefixSize = result;
      lz4sd->prefixEnd = (LZ4_byte *)(dest + result);
    }
  }
  return result;
}

