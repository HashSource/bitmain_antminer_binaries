
/* WARNING: Removing unreachable block (ram,0x000cfc14) */
/* WARNING: Removing unreachable block (ram,0x000cfc1e) */
/* WARNING: Removing unreachable block (ram,0x000cfc20) */
/* WARNING: Removing unreachable block (ram,0x000cfc22) */
/* WARNING: Removing unreachable block (ram,0x000cfc28) */
/* WARNING: Removing unreachable block (ram,0x000cf7f2) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int LZ4_decompress_safe_forceExtDict
              (char *source,char *dest,int compressedSize,int maxOutputSize,void *dictStart,
              size_t dictSize)

{
  U16 UVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  BYTE *pBVar8;
  size_t sVar9;
  int iVar10;
  BYTE *pBVar11;
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
  BYTE *local_f0;
  BYTE *local_ec;
  BYTE *local_e8;
  BYTE *e_1;
  BYTE *s_3;
  BYTE *d_1;
  BYTE *local_d8;
  BYTE *local_d4;
  BYTE *local_d0;
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
  undefined4 local_a0;
  BYTE *local_9c;
  BYTE **local_98;
  BYTE *e;
  BYTE *s_1;
  BYTE *d;
  BYTE *local_88;
  BYTE *local_84;
  BYTE *local_80;
  BYTE *cpy;
  size_t addl;
  Rvl_t s;
  Rvl_t length_1;
  undefined4 local_6c;
  BYTE *local_68;
  BYTE **local_64;
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
  size_t local_34;
  void *local_30;
  BYTE *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  char *local_18;
  char *local_14;
  
  local_24 = 0;
  local_28 = 2;
  local_30 = dictStart;
  local_34 = dictSize;
  if ((source == (char *)0x0) || (maxOutputSize < 0)) {
    pBVar8 = (BYTE *)0xffffffff;
  }
  else {
    iend = (BYTE *)(source + compressedSize);
    oend = (BYTE *)(dest + maxOutputSize);
    if (dictStart == (void *)0x0) {
      dictEnd = (BYTE *)0x0;
    }
    else {
      dictEnd = (BYTE *)(dictSize + (int)dictStart);
    }
    sVar9 = dictSize;
    if (dictSize < 0x10000) {
      sVar9 = 1;
    }
    bVar5 = (byte)sVar9;
    if (0xffff < dictSize) {
      bVar5 = 0;
    }
    checkOffset = (int)bVar5;
    shortiend = iend + -0x10;
    shortoend = oend + -0x20;
    iVar10 = maxOutputSize;
    if (maxOutputSize == 0) {
      iVar10 = 1;
    }
    cVar6 = (char)iVar10;
    if (maxOutputSize != 0) {
      cVar6 = '\0';
    }
    if (cVar6 == '\0') {
      iVar10 = compressedSize;
      if (compressedSize == 0) {
        iVar10 = 1;
      }
      cVar6 = (char)iVar10;
      if (compressedSize != 0) {
        cVar6 = '\0';
      }
      ip = (BYTE *)source;
      op = (BYTE *)dest;
      local_2c = (BYTE *)dest;
      local_20 = maxOutputSize;
      local_1c = compressedSize;
      local_18 = dest;
      local_14 = source;
      if (cVar6 == '\0') {
LAB_000cf832:
        do {
          pBVar8 = ip + 1;
          token = (uint)*ip;
          length = (size_t)(*ip >> 4);
          if (length == 0xf) {
LAB_000cf950:
            ip = pBVar8;
            if (length == 0xf) {
              local_68 = iend + -0xf;
              local_64 = &ip;
              local_6c = 1;
              length_1 = 0;
              pBVar11 = pBVar8;
              if (local_68 <= pBVar8) {
                pBVar11 = (BYTE *)0x1;
              }
              cVar6 = (char)pBVar11;
              if (pBVar8 < local_68) {
                cVar6 = '\0';
              }
              length = 0xf;
              if (cVar6 == '\0') {
                do {
                  s = (Rvl_t)**local_64;
                  *local_64 = *local_64 + 1;
                  length_1 = s + length_1;
                  pBVar8 = *local_64;
                  bVar14 = local_68 < pBVar8;
                  if (bVar14) {
                    pBVar8 = (BYTE *)0x1;
                  }
                  cVar6 = (char)pBVar8;
                  if (!bVar14) {
                    cVar6 = '\0';
                  }
                  if (cVar6 != '\0') {
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
              if (addl == 0xffffffff) goto LAB_000d00b2;
              length = addl + length;
              pBVar8 = op;
              if (op + length < op) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar6 = (char)pBVar8;
              if (op + length >= op) {
                cVar6 = '\0';
              }
              if (cVar6 != '\0') goto LAB_000d00b2;
              pBVar8 = ip + length;
              bVar14 = pBVar8 < ip;
              if (bVar14) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar6 = (char)pBVar8;
              if (!bVar14) {
                cVar6 = '\0';
              }
              if (cVar6 != '\0') goto LAB_000d00b2;
            }
            cpy = op + length;
            if ((oend + -0xc < cpy) || (iend + -8 < ip + length)) {
              if (local_24 == 0) {
                if ((iend != ip + length) || (oend < cpy)) goto LAB_000d00b2;
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
              local_80 = op;
              local_84 = ip;
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
              local_88 = cpy;
              op = cpy;
            }
            UVar1 = LZ4_readLE16(ip);
            offset = (size_t)UVar1;
            ip = ip + 2;
            match = op + -offset;
            length = token & 0xf;
          }
          else {
            pBVar11 = pBVar8;
            if (pBVar8 < shortiend) {
              pBVar11 = (BYTE *)0x1;
            }
            bVar5 = (byte)pBVar11;
            if (shortiend <= pBVar8) {
              bVar5 = 0;
            }
            pBVar11 = op;
            if (op <= shortoend) {
              pBVar11 = (BYTE *)0x1;
            }
            bVar7 = (byte)pBVar11;
            if (op > shortoend) {
              bVar7 = 0;
            }
            if ((bVar7 & bVar5) == 0) goto LAB_000cf950;
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
              goto LAB_000cf832;
            }
          }
          if (length == 0xf) {
            local_9c = iend + -4;
            local_98 = &ip;
            local_a0 = 0;
            length_2 = 0;
            do {
              s_2 = (Rvl_t)**local_98;
              *local_98 = *local_98 + 1;
              length_2 = s_2 + length_2;
              pBVar8 = *local_98;
              bVar14 = local_9c < pBVar8;
              if (bVar14) {
                pBVar8 = (BYTE *)0x1;
              }
              cVar6 = (char)pBVar8;
              if (!bVar14) {
                cVar6 = '\0';
              }
              if (cVar6 != '\0') {
                addl_1 = 0xffffffff;
                break;
              }
              if ((int)length_2 < 0) {
                addl_1 = 0xffffffff;
                break;
              }
              addl_1 = length_2;
            } while (s_2 == 0xff);
            if (addl_1 == 0xffffffff) goto LAB_000d00b2;
            length = addl_1 + length;
            pBVar8 = op;
            if (op + length < op) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar6 = (char)pBVar8;
            if (op + length >= op) {
              cVar6 = '\0';
            }
            if (cVar6 != '\0') goto LAB_000d00b2;
          }
          length = length + 4;
          if (checkOffset != 0) {
            pBVar11 = match + local_34;
            pBVar8 = pBVar11;
            if (pBVar11 < local_2c) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar6 = (char)pBVar8;
            if (local_2c <= pBVar11) {
              cVar6 = '\0';
            }
            if (cVar6 != '\0') goto LAB_000d00b2;
          }
          if ((local_28 == 2) && (match < local_2c)) {
            pBVar11 = oend + -5;
            pBVar8 = pBVar11;
            if (pBVar11 < op + length) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar6 = (char)pBVar8;
            if (op + length <= pBVar11) {
              cVar6 = '\0';
            }
            if (cVar6 != '\0') {
              if (local_24 == 0) {
LAB_000d00b2:
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
            goto LAB_000cf832;
          }
          cpy = op + length;
          if ((local_24 == 0) || (cpy <= oend + -0xc)) {
            sVar9 = offset;
            if (offset < 8) {
              sVar9 = 1;
            }
            cVar6 = (char)sVar9;
            if (7 < offset) {
              cVar6 = '\0';
            }
            if (cVar6 == '\0') {
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
            pBVar11 = op + 8;
            pBVar13 = oend + -0xc;
            pBVar8 = pBVar13;
            if (pBVar13 < cpy) {
              pBVar8 = (BYTE *)0x1;
            }
            cVar6 = (char)pBVar8;
            if (cpy <= pBVar13) {
              cVar6 = '\0';
            }
            if (cVar6 == '\0') {
              uVar2 = *(undefined4 *)(match + 4);
              *(undefined4 *)pBVar11 = *(undefined4 *)match;
              *(undefined4 *)(op + 0xc) = uVar2;
              if (0x10 < length) {
                local_e8 = op + 0x10;
                local_ec = match + 8;
                local_f0 = cpy;
                e_2 = cpy;
                s_4 = local_ec;
                d_2 = local_e8;
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
              if (oend + -5 < cpy) goto LAB_000d00b2;
              op = pBVar11;
              if (pBVar11 < oCopyLimit) {
                local_d4 = match;
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
                local_d8 = oCopyLimit;
                local_d0 = pBVar11;
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
            goto LAB_000cf832;
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

