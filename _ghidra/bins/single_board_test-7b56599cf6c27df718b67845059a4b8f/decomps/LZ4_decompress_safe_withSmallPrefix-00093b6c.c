
/* WARNING: Removing unreachable block (ram,0x00094048) */
/* WARNING: Removing unreachable block (ram,0x00094052) */
/* WARNING: Removing unreachable block (ram,0x00094054) */
/* WARNING: Removing unreachable block (ram,0x00094056) */
/* WARNING: Removing unreachable block (ram,0x0009405c) */
/* WARNING: Removing unreachable block (ram,0x00093c26) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int LZ4_decompress_safe_withSmallPrefix
              (char *source,char *dest,int compressedSize,int maxOutputSize,size_t prefixSize)

{
  U16 UVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  BYTE *pBVar8;
  int iVar9;
  BYTE *pBVar10;
  size_t sVar11;
  uint uVar12;
  BYTE *pBVar13;
  bool bVar14;
  int maxOutputSize_local;
  int compressedSize_local;
  char *dest_local;
  char *source_local;
  BYTE *ip;
  BYTE *e_2;
  BYTE *s_4;
  BYTE *d_2;
  BYTE *local_e8;
  BYTE *local_e4;
  BYTE *local_e0;
  BYTE *e_1;
  BYTE *s_3;
  BYTE *d_1;
  BYTE *local_d0;
  BYTE *local_cc;
  BYTE *local_c8;
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
  undefined4 local_98;
  BYTE *local_94;
  BYTE **local_90;
  BYTE *e;
  BYTE *s_1;
  BYTE *d;
  BYTE *local_80;
  BYTE *local_7c;
  BYTE *local_78;
  BYTE *cpy;
  size_t addl;
  Rvl_t s;
  Rvl_t length_1;
  undefined4 local_64;
  BYTE *local_60;
  BYTE **local_5c;
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
  BYTE *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  char *local_18;
  char *local_14;
  
  local_2c = (BYTE *)(dest + -prefixSize);
  local_24 = 0;
  local_28 = 0;
  if ((source == (char *)0x0) || (maxOutputSize < 0)) {
    pBVar8 = (BYTE *)0xffffffff;
  }
  else {
    iend = (BYTE *)(source + compressedSize);
    oend = (BYTE *)(dest + maxOutputSize);
    dictEnd = (BYTE *)0x0;
    checkOffset = 1;
    shortiend = iend + -0x10;
    shortoend = oend + -0x20;
    iVar9 = maxOutputSize;
    if (maxOutputSize == 0) {
      iVar9 = 1;
    }
    cVar5 = (char)iVar9;
    if (maxOutputSize != 0) {
      cVar5 = '\0';
    }
    if (cVar5 == '\0') {
      iVar9 = compressedSize;
      if (compressedSize == 0) {
        iVar9 = 1;
      }
      cVar5 = (char)iVar9;
      if (compressedSize != 0) {
        cVar5 = '\0';
      }
      ip = (BYTE *)source;
      op = (BYTE *)dest;
      local_20 = maxOutputSize;
      local_1c = compressedSize;
      local_18 = dest;
      local_14 = source;
      if (cVar5 == '\0') {
LAB_00093c66:
        do {
          pBVar8 = ip + 1;
          token = (uint)*ip;
          length = (size_t)(*ip >> 4);
          if (length == 0xf) {
LAB_00093d84:
            ip = pBVar8;
            if (length == 0xf) {
              local_60 = iend + -0xf;
              local_5c = &ip;
              local_64 = 1;
              length_1 = 0;
              pBVar10 = pBVar8;
              if (local_60 <= pBVar8) {
                pBVar10 = (BYTE *)0x1;
              }
              cVar5 = (char)pBVar10;
              if (pBVar8 < local_60) {
                cVar5 = '\0';
              }
              length = 0xf;
              if (cVar5 == '\0') {
                do {
                  s = (Rvl_t)**local_5c;
                  *local_5c = *local_5c + 1;
                  length_1 = s + length_1;
                  pBVar8 = *local_5c;
                  bVar14 = local_60 < pBVar8;
                  if (bVar14) {
                    pBVar8 = (BYTE *)0x1;
                  }
                  cVar5 = (char)pBVar8;
                  if (!bVar14) {
                    cVar5 = '\0';
                  }
                  if (cVar5 != '\0') {
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
              if (addl == 0xffffffff) goto LAB_000944e0;
              length = addl + length;
              pBVar8 = op;
              if (op + length < op) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar5 = (char)pBVar8;
              if (op + length >= op) {
                cVar5 = '\0';
              }
              if (cVar5 != '\0') goto LAB_000944e0;
              pBVar8 = ip + length;
              bVar14 = pBVar8 < ip;
              if (bVar14) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar5 = (char)pBVar8;
              if (!bVar14) {
                cVar5 = '\0';
              }
              if (cVar5 != '\0') goto LAB_000944e0;
            }
            cpy = op + length;
            if ((oend + -0xc < cpy) || (iend + -8 < ip + length)) {
              if (local_24 == 0) {
                if ((iend != ip + length) || (oend < cpy)) goto LAB_000944e0;
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
              if (((local_24 == 0) || (oend == cpy)) || (iend + -2 <= ip)) break;
            }
            else {
              local_78 = op;
              local_7c = ip;
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
              local_80 = cpy;
              op = cpy;
            }
            UVar1 = LZ4_readLE16(ip);
            offset = (size_t)UVar1;
            ip = ip + 2;
            match = op + -offset;
            length = token & 0xf;
          }
          else {
            pBVar10 = pBVar8;
            if (pBVar8 < shortiend) {
              pBVar10 = (BYTE *)0x1;
            }
            bVar6 = (byte)pBVar10;
            if (shortiend <= pBVar8) {
              bVar6 = 0;
            }
            pBVar10 = op;
            if (op <= shortoend) {
              pBVar10 = (BYTE *)0x1;
            }
            bVar7 = (byte)pBVar10;
            if (op > shortoend) {
              bVar7 = 0;
            }
            if ((bVar7 & bVar6) == 0) goto LAB_00093d84;
            uVar2 = *(undefined4 *)(ip + 5);
            uVar3 = *(undefined4 *)(ip + 9);
            uVar4 = *(undefined4 *)(ip + 0xd);
            *(undefined4 *)op = *(undefined4 *)pBVar8;
            *(undefined4 *)(op + 4) = uVar2;
            *(undefined4 *)(op + 8) = uVar3;
            *(undefined4 *)(op + 0xc) = uVar4;
            op = op + length;
            ip = pBVar8 + length;
            length = token & 0xf;
            UVar1 = LZ4_readLE16(ip);
            offset = (size_t)UVar1;
            ip = ip + 2;
            match = op + -offset;
            if (((length != 0xf) && (7 < offset)) && ((local_28 == 1 || (local_2c <= match)))) {
              uVar2 = *(undefined4 *)(match + 4);
              *(undefined4 *)op = *(undefined4 *)match;
              *(undefined4 *)(op + 4) = uVar2;
              uVar2 = *(undefined4 *)(match + 0xc);
              *(undefined4 *)(op + 8) = *(undefined4 *)(match + 8);
              *(undefined4 *)(op + 0xc) = uVar2;
              *(undefined2 *)(op + 0x10) = *(undefined2 *)(match + 0x10);
              op = op + length + 4;
              goto LAB_00093c66;
            }
          }
          if (length == 0xf) {
            local_94 = iend + -4;
            local_90 = &ip;
            local_98 = 0;
            length_2 = 0;
            do {
              s_2 = (Rvl_t)**local_90;
              *local_90 = *local_90 + 1;
              length_2 = s_2 + length_2;
              pBVar8 = *local_90;
              bVar14 = local_94 < pBVar8;
              if (bVar14) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar5 = (char)pBVar8;
              if (!bVar14) {
                cVar5 = '\0';
              }
              if (cVar5 != '\0') {
                addl_1 = 0xffffffff;
                break;
              }
              if ((int)length_2 < 0) {
                addl_1 = 0xffffffff;
                break;
              }
              addl_1 = length_2;
            } while (s_2 == 0xff);
            if (addl_1 == 0xffffffff) goto LAB_000944e0;
            length = addl_1 + length;
            pBVar8 = op;
            if (op + length < op) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar5 = (char)pBVar8;
            if (op + length >= op) {
              cVar5 = '\0';
            }
            if (cVar5 != '\0') goto LAB_000944e0;
          }
          length = length + 4;
          if (checkOffset != 0) {
            pBVar8 = match;
            if (match < local_2c) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar5 = (char)pBVar8;
            if (local_2c <= match) {
              cVar5 = '\0';
            }
            if (cVar5 != '\0') goto LAB_000944e0;
          }
          if ((local_28 == 2) && (match < local_2c)) {
            pBVar10 = oend + -5;
            pBVar8 = pBVar10;
            if (pBVar10 < op + length) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar5 = (char)pBVar8;
            if (op + length <= pBVar10) {
              cVar5 = '\0';
            }
            if (cVar5 != '\0') {
              if (local_24 == 0) {
LAB_000944e0:
                return (int)(local_14 + (-1 - (int)ip));
              }
              if ((uint)((int)oend - (int)op) <= length) {
                length = (int)oend - (int)op;
              }
            }
            if ((uint)((int)local_2c - (int)match) < length) {
              copySize = (int)local_2c - (int)match;
              restSize = length - copySize;
              memcpy(op,dictEnd + -copySize,copySize);
              op = op + copySize;
              if ((uint)((int)op - (int)local_2c) < restSize) {
                endOfMatch = op + restSize;
                copyFrom = local_2c;
                while (op < endOfMatch) {
                  *op = *copyFrom;
                  copyFrom = copyFrom + 1;
                  op = op + 1;
                }
              }
              else {
                memcpy(op,local_2c,restSize);
                op = op + restSize;
              }
            }
            else {
              memmove(op,dictEnd + -((int)local_2c - (int)match),length);
              op = op + length;
            }
            goto LAB_00093c66;
          }
          cpy = op + length;
          if ((local_24 == 0) || (cpy <= oend + -0xc)) {
            sVar11 = offset;
            if (offset < 8) {
              sVar11 = 1;
            }
            cVar5 = (char)sVar11;
            if (7 < offset) {
              cVar5 = '\0';
            }
            if (cVar5 == '\0') {
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
              uVar12 = inc32table[offset];
              *(undefined4 *)(op + 4) = *(undefined4 *)(match + uVar12);
              match = match + uVar12 + -dec64table[offset];
            }
            pBVar10 = op + 8;
            pBVar13 = oend + -0xc;
            pBVar8 = pBVar13;
            if (pBVar13 < cpy) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar5 = (char)pBVar8;
            if (cpy <= pBVar13) {
              cVar5 = '\0';
            }
            if (cVar5 == '\0') {
              uVar2 = *(undefined4 *)(match + 4);
              *(undefined4 *)pBVar10 = *(undefined4 *)match;
              *(undefined4 *)(op + 0xc) = uVar2;
              if (0x10 < length) {
                local_e0 = op + 0x10;
                local_e4 = match + 8;
                local_e8 = cpy;
                e_2 = cpy;
                s_4 = local_e4;
                d_2 = local_e0;
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
              if (oend + -5 < cpy) goto LAB_000944e0;
              op = pBVar10;
              if (pBVar10 < oCopyLimit) {
                local_cc = match;
                s_3 = match;
                d_1 = pBVar10;
                do {
                  uVar2 = *(undefined4 *)(s_3 + 4);
                  *(undefined4 *)d_1 = *(undefined4 *)s_3;
                  *(undefined4 *)(d_1 + 4) = uVar2;
                  d_1 = d_1 + 8;
                  s_3 = s_3 + 8;
                } while (d_1 < oCopyLimit);
                e_1 = oCopyLimit;
                local_d0 = oCopyLimit;
                local_c8 = pBVar10;
                match = match + ((int)oCopyLimit - (int)pBVar10);
                op = oCopyLimit;
              }
              while (op < cpy) {
                *op = *match;
                match = match + 1;
                op = op + 1;
              }
            }
            op = cpy;
            goto LAB_00093c66;
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
        pBVar8 = op + -(int)local_18;
      }
      else {
        pBVar8 = (BYTE *)0xffffffff;
      }
    }
    else if ((compressedSize == 1) && (*source == '\0')) {
      pBVar8 = (BYTE *)0x0;
    }
    else {
      pBVar8 = (BYTE *)0xffffffff;
    }
  }
  return (int)pBVar8;
}

