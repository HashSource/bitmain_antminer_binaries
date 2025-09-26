
_STACK * mime_parse_hdr(BIO *param_1)

{
  _STACK *st;
  int iVar1;
  ushort **ppuVar2;
  size_t sVar3;
  ushort *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *__s;
  void *data;
  byte local_428 [1028];
  
  st = sk_new((cmp *)0x1be081);
  if (st != (_STACK *)0x0) {
    data = (void *)0x0;
    do {
      iVar1 = BIO_gets(param_1,(char *)local_428,0x400);
      if (iVar1 < 1) {
        return st;
      }
      if (data == (void *)0x0) {
        uVar7 = (uint)local_428[0];
LAB_001be3a2:
        iVar1 = 1;
      }
      else {
        ppuVar2 = __ctype_b_loc();
        uVar7 = (uint)local_428[0];
        if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) goto LAB_001be3a2;
        iVar1 = 3;
      }
      pbVar9 = local_428;
      pbVar5 = local_428;
      if (uVar7 == 0) {
        __s = (byte *)0x0;
      }
      else if (uVar7 == 0xd || uVar7 == 10) {
        __s = (byte *)0x0;
      }
      else {
        __s = (byte *)0x0;
        do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(iVar1) {
          case 1:
            if (uVar7 == 0x3a) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              __s = pbVar6;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  __s = pbVar5;
                  do {
                    pbVar5 = __s + 1;
                    if (-1 < (int)((uint)(*ppuVar2)[(int)pbVar6] << 0x12)) goto LAB_001be478;
                    pbVar6 = (byte *)(uint)__s[1];
                    __s = pbVar6;
                    if (pbVar6 == (byte *)0x0) goto LAB_001be4c8;
                    __s = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                __s = (byte *)(uint)pbVar5[1];
                if ((__s != (byte *)0x0) && (__s = pbVar5 + 1, __s != (byte *)0x0)) {
LAB_001be478:
                  sVar3 = strlen((char *)__s);
                  uVar7 = sVar3 - 1;
                  pbVar6 = __s + uVar7;
                  if (!CARRY4((uint)__s,uVar7)) {
                    uVar7 = (uint)__s[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar5 = pbVar6;
                      do {
                        pbVar6 = pbVar5 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001be4c8;
                        *pbVar5 = 0;
                        if (pbVar6 == __s + -1) goto LAB_001be7da;
                        uVar7 = (uint)*pbVar6;
                        pbVar5 = pbVar6;
                      } while (uVar7 != 0x22);
                    }
                    if (__s != pbVar6 + -1) {
                      pbVar5 = pbVar9 + 1;
                      *pbVar6 = 0;
                      iVar1 = 2;
                      break;
                    }
                  }
LAB_001be7da:
                  pbVar5 = pbVar9 + 1;
                  __s = (byte *)0x0;
                  iVar1 = 2;
                  break;
                }
              }
LAB_001be4c8:
              pbVar5 = pbVar9 + 1;
              iVar1 = 2;
            }
            break;
          case 2:
            if (uVar7 == 0x3b) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  pbVar8 = pbVar5;
                  do {
                    puVar4 = *ppuVar2 + (int)pbVar6;
                    pbVar5 = pbVar8 + 1;
                    pbVar6 = pbVar8;
                    if (-1 < (int)((uint)*puVar4 << 0x12)) goto LAB_001be59c;
                    pbVar6 = (byte *)(uint)pbVar8[1];
                    if (pbVar6 == (byte *)0x0) goto LAB_001be5e6;
                    pbVar8 = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                pbVar6 = (byte *)(uint)pbVar5[1];
                if ((pbVar6 != (byte *)0x0) && (pbVar6 = pbVar5 + 1, pbVar6 != (byte *)0x0)) {
LAB_001be59c:
                  sVar3 = strlen((char *)pbVar6);
                  uVar7 = sVar3 - 1;
                  pbVar5 = pbVar6 + uVar7;
                  if (!CARRY4((uint)pbVar6,uVar7)) {
                    uVar7 = (uint)pbVar6[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar8 = pbVar5;
                      do {
                        pbVar5 = pbVar8 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001be5e6;
                        *pbVar8 = 0;
                        if (pbVar5 == pbVar6 + -1) goto LAB_001be7f6;
                        uVar7 = (uint)*pbVar5;
                        pbVar8 = pbVar5;
                      } while (uVar7 != 0x22);
                    }
                    if (pbVar6 != pbVar5 + -1) {
                      *pbVar5 = 0;
                      goto LAB_001be5e6;
                    }
                  }
LAB_001be7f6:
                  pbVar6 = (byte *)0x0;
                }
              }
LAB_001be5e6:
              data = (void *)mime_hdr_new(__s,pbVar6);
              pbVar5 = pbVar9 + 1;
              sk_push(st,data);
              __s = (byte *)0x0;
              iVar1 = 3;
            }
            else if (uVar7 == 0x28) {
              iVar1 = 6;
            }
            break;
          case 3:
            if (uVar7 == 0x3d) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              __s = pbVar6;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  __s = pbVar5;
                  do {
                    pbVar5 = __s + 1;
                    if (-1 < (int)((uint)(*ppuVar2)[(int)pbVar6] << 0x12)) goto LAB_001be510;
                    pbVar6 = (byte *)(uint)__s[1];
                    __s = pbVar6;
                    if (pbVar6 == (byte *)0x0) goto LAB_001be560;
                    __s = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                __s = (byte *)(uint)pbVar5[1];
                if ((__s != (byte *)0x0) && (__s = pbVar5 + 1, __s != (byte *)0x0)) {
LAB_001be510:
                  sVar3 = strlen((char *)__s);
                  uVar7 = sVar3 - 1;
                  pbVar6 = __s + uVar7;
                  if (!CARRY4((uint)__s,uVar7)) {
                    uVar7 = (uint)__s[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar5 = pbVar6;
                      do {
                        pbVar6 = pbVar5 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001be560;
                        *pbVar5 = 0;
                        if (pbVar6 == __s + -1) goto LAB_001be7e4;
                        uVar7 = (uint)*pbVar6;
                        pbVar5 = pbVar6;
                      } while (uVar7 != 0x22);
                    }
                    if (__s != pbVar6 + -1) {
                      pbVar5 = pbVar9 + 1;
                      *pbVar6 = 0;
                      iVar1 = 4;
                      break;
                    }
                  }
LAB_001be7e4:
                  pbVar5 = pbVar9 + 1;
                  __s = (byte *)0x0;
                  iVar1 = 4;
                  break;
                }
              }
LAB_001be560:
              pbVar5 = pbVar9 + 1;
              iVar1 = 4;
            }
          }
          pbVar9 = pbVar9 + 1;
          uVar7 = (uint)*pbVar9;
        } while ((uVar7 != 0) && (uVar7 != 10 && uVar7 != 0xd));
      }
      if (iVar1 == 2) {
        pbVar6 = (byte *)(uint)*pbVar5;
        if (pbVar6 != (byte *)0x0) {
          if (pbVar6 != (byte *)0x22) {
            ppuVar2 = __ctype_b_loc();
            pbVar8 = pbVar5;
            do {
              puVar4 = *ppuVar2 + (int)pbVar6;
              pbVar5 = pbVar8 + 1;
              pbVar6 = pbVar8;
              if (-1 < (int)((uint)*puVar4 << 0x12)) goto LAB_001be6de;
              pbVar6 = (byte *)(uint)pbVar8[1];
              if (pbVar6 == (byte *)0x0) goto LAB_001be728;
              pbVar8 = pbVar5;
            } while (pbVar6 != (byte *)0x22);
          }
          pbVar6 = (byte *)(uint)pbVar5[1];
          if ((pbVar6 != (byte *)0x0) && (pbVar6 = pbVar5 + 1, pbVar6 != (byte *)0x0)) {
LAB_001be6de:
            sVar3 = strlen((char *)pbVar6);
            uVar7 = sVar3 - 1;
            pbVar5 = pbVar6 + uVar7;
            if (!CARRY4((uint)pbVar6,uVar7)) {
              uVar7 = (uint)pbVar6[uVar7];
              if (uVar7 != 0x22) {
                ppuVar2 = __ctype_b_loc();
                puVar4 = *ppuVar2;
                pbVar8 = pbVar5;
                do {
                  pbVar5 = pbVar8 + -1;
                  if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001be728;
                  *pbVar8 = 0;
                  if (pbVar5 == pbVar6 + -1) goto LAB_001be892;
                  uVar7 = (uint)*pbVar5;
                  pbVar8 = pbVar5;
                } while (uVar7 != 0x22);
              }
              if (pbVar6 != pbVar5 + -1) {
                *pbVar5 = 0;
                goto LAB_001be728;
              }
            }
LAB_001be892:
            pbVar6 = (byte *)0x0;
          }
        }
LAB_001be728:
        data = (void *)mime_hdr_new(__s,pbVar6);
        sk_push(st,data);
      }
      else if (iVar1 == 4) {
        uVar7 = (uint)*pbVar5;
        if (uVar7 == 0) {
LAB_001be8c6:
          mime_hdr_addparam(data,__s,uVar7);
        }
        else {
          if (uVar7 != 0x22) {
            ppuVar2 = __ctype_b_loc();
            pbVar6 = pbVar5;
            do {
              pbVar5 = pbVar6 + 1;
              if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) goto LAB_001be776;
              uVar7 = (uint)pbVar6[1];
              if (uVar7 == 0) goto LAB_001be8c6;
              pbVar6 = pbVar5;
            } while (uVar7 != 0x22);
          }
          if ((pbVar5[1] == 0) || (pbVar6 = pbVar5 + 1, pbVar6 == (byte *)0x0)) {
LAB_001be7d0:
            mime_hdr_addparam(data,__s);
          }
          else {
LAB_001be776:
            sVar3 = strlen((char *)pbVar6);
            uVar7 = sVar3 - 1;
            pbVar5 = pbVar6 + uVar7;
            if (!CARRY4((uint)pbVar6,uVar7)) {
              uVar7 = (uint)pbVar6[uVar7];
              if (uVar7 != 0x22) {
                ppuVar2 = __ctype_b_loc();
                puVar4 = *ppuVar2;
                pbVar8 = pbVar5;
                do {
                  pbVar5 = pbVar8 + -1;
                  if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001be7d0;
                  *pbVar8 = 0;
                  if (pbVar5 == pbVar6 + -1) goto LAB_001be8d2;
                  uVar7 = (uint)*pbVar5;
                  pbVar8 = pbVar5;
                } while (uVar7 != 0x22);
              }
              if (pbVar6 != pbVar5 + -1) {
                *pbVar5 = 0;
                mime_hdr_addparam(data,__s);
                goto LAB_001be3f0;
              }
            }
LAB_001be8d2:
            mime_hdr_addparam(data,__s,0);
          }
        }
      }
LAB_001be3f0:
    } while (pbVar9 != local_428);
  }
  return st;
}

