
/* WARNING: Unknown calling convention */

void print_summary(void)

{
  double *pdVar1;
  uint *puVar2;
  uint *puVar3;
  byte *pbVar4;
  int *piVar5;
  _func_void_char_ptr_size_t_cgpu_info_ptr *p_Var6;
  _func_void_char_ptr_size_t_cgpu_info_ptr *p_Var7;
  cgpu_info *cgpu_00;
  cgpu_info *cgpu;
  byte bVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  device_drv *pdVar12;
  byte *pbVar13;
  int secs;
  int iVar14;
  undefined4 uVar15;
  int hours;
  uint uVar16;
  uint uVar17;
  int mins;
  uint uVar18;
  int iVar19;
  pool *pool;
  int i;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  char logline [255];
  char tmp42 [2048];
  
  pbVar4 = DAT_00023b64;
  puVar3 = DAT_00023b60;
  pdVar1 = DAT_00023b10;
  dVar21 = DAT_00023b08;
  iVar9 = total_tv_end.tv_sec - total_tv_start.tv_sec;
  if (total_tv_end.tv_usec - total_tv_start.tv_usec < 0) {
    iVar9 = iVar9 + -1;
  }
  dVar24 = *DAT_00023b10;
  dVar20 = (double)__aeabi_l2d(*DAT_00023b60,DAT_00023b60[1]);
  dVar22 = (double)__aeabi_l2d(*DAT_00023b14,DAT_00023b14[1]);
  if (((*pbVar4 == 0) && (*DAT_00023b18 == 0)) && ((int)*DAT_000243c8 < 4)) {
    if (total_pools != 1) goto LAB_00023938;
LAB_00024276:
    if (((*pbVar4 != 0) || (*DAT_000243b0 != 0)) || (3 < (int)*DAT_000243c8)) {
      snprintf(tmp42,0x800,DAT_000243d0,*(undefined4 *)(**DAT_000243cc + 0xa4));
      _applog(4,tmp42,false);
      goto LAB_00023938;
    }
  }
  else {
    tmp42._0_4_ = *DAT_00023b68;
    tmp42._4_4_ = DAT_00023b68[1];
    tmp42._8_4_ = DAT_00023b68[2];
    tmp42._12_4_ = DAT_00023b68[3];
    tmp42._16_4_ = DAT_00023b68[4];
    tmp42._20_4_ = DAT_00023b68[5];
    tmp42._24_4_ = DAT_00023b68[6];
    tmp42._28_4_ = DAT_00023b68[7];
    tmp42[32] = (char)DAT_00023b68[8];
    _applog(4,tmp42,false);
    if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
      snprintf(tmp42,0x800,DAT_00023b1c,DAT_00023b20);
      _applog(4,tmp42,false);
    }
    if (total_pools == 1) goto LAB_00024276;
LAB_00023938:
    if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
      snprintf(tmp42,0x800,DAT_00023b24,iVar9 / 0xe10,(iVar9 % 0xe10) / 0x3c,iVar9 % 0x3c);
      _applog(4,tmp42,false);
      uVar10 = (uint)*pbVar4;
      dVar23 = *DAT_00023b28 / *pdVar1;
      if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023b18, uVar10 != 0)) ||
         (uVar10 = *DAT_00024414, 3 < (int)uVar10)) {
        snprintf(tmp42,0x800,DAT_00023b2c,uVar10,dVar23);
        _applog(4,tmp42,false);
        if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
          snprintf(tmp42,0x800,DAT_00023b34,*DAT_00023b30,dVar23);
          _applog(4,tmp42,false);
          if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
            snprintf(tmp42,0x800,DAT_00023b3c,DAT_00023b38,dVar23);
            _applog(4,tmp42,false);
            puVar2 = DAT_00023b5c;
            uVar10 = (uint)*pbVar4;
            if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023b18, uVar10 != 0)) ||
               (uVar10 = *DAT_000243c8, 3 < (int)uVar10)) {
              snprintf(tmp42,0x800,DAT_00023b40,uVar10,*DAT_00023b5c + *puVar3,
                       DAT_00023b5c[1] + puVar3[1] + (uint)CARRY4(*DAT_00023b5c,*puVar3));
              _applog(4,tmp42,false);
              uVar10 = (uint)*pbVar4;
              if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023b18, uVar10 != 0)) ||
                 (uVar10 = *DAT_000243c8, 3 < (int)uVar10)) {
                snprintf(tmp42,0x800,DAT_00023b44,uVar10,*puVar3,puVar3[1]);
                _applog(4,tmp42,false);
                uVar10 = (uint)*pbVar4;
                if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023b18, uVar10 != 0)) ||
                   (uVar10 = *DAT_000243c8, 3 < (int)uVar10)) {
                  snprintf(tmp42,0x800,DAT_00023b48,uVar10,*puVar2,puVar2[1]);
                  _applog(4,tmp42,false);
                  if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
                    snprintf(tmp42,0x800,DAT_00023b50,DAT_00023b4c,*DAT_00023b4c);
                    _applog(4,tmp42,false);
                    if (((*pbVar4 != 0) || (*DAT_00023b18 != 0)) || (3 < (int)*DAT_000243c8)) {
                      snprintf(tmp42,0x800,DAT_00023b58,DAT_00023b54,*DAT_00023b54);
                      _applog(4,tmp42,false);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar10 = *puVar3;
  uVar16 = puVar3[1];
  if (((uVar10 | uVar16) == 0) && ((*DAT_00023b5c | DAT_00023b5c[1]) == 0)) {
LAB_00023bc4:
    if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_000243c8)) {
      snprintf(tmp42,0x800,DAT_00023d74,*DAT_00023d70);
      _applog(4,tmp42,false);
      uVar10 = (uint)*pbVar4;
      if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023d64, uVar10 != 0)) ||
         (uVar10 = *DAT_000243c8, 3 < (int)uVar10)) {
        snprintf(tmp42,0x800,DAT_00023d78,uVar10,(dVar20 / dVar24) * dVar21);
        _applog(4,tmp42,false);
        uVar10 = (uint)*pbVar4;
        if (((uVar10 != 0) || (uVar10 = (uint)*DAT_00023d64, uVar10 != 0)) ||
           (uVar10 = *DAT_000243c8, 3 < (int)uVar10)) {
          snprintf(tmp42,0x800,DAT_00023d7c,uVar10,(dVar22 / dVar24) * dVar21);
          _applog(4,tmp42,false);
          if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_000243c8)) {
            snprintf(tmp42,0x800,DAT_00023d84,DAT_00023d80,*DAT_00023d80,DAT_00023d80[1]);
            _applog(4,tmp42,false);
            if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_000243c8)) {
              snprintf(tmp42,0x800,DAT_00023d8c,*DAT_00023d88);
              _applog(4,tmp42,false);
              if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_000243c8)) {
                snprintf(tmp42,0x800,DAT_00023d94,*DAT_00023d90);
                _applog(4,tmp42,false);
                if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_00024414)) {
                  snprintf(tmp42,0x800,DAT_00023d9c,*DAT_00023d98);
                  _applog(4,tmp42,false);
                  if (((*pbVar4 != 0) || (*DAT_00023d64 != 0)) || (3 < (int)*DAT_000243c8)) {
                    snprintf(tmp42,0x800,DAT_00023da4,*DAT_00023da0);
                    _applog(4,tmp42,false);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if ((*pbVar4 != 0) || ((*DAT_00023d64 != 0 || (3 < (int)*DAT_000243c8)))) {
    uVar17 = *DAT_00023d68;
    uVar18 = DAT_00023d68[1];
    __aeabi_l2d((int)((ulonglong)uVar17 * 100),uVar18 * 100 + (int)((ulonglong)uVar17 * 100 >> 0x20)
               );
    __aeabi_l2d(uVar10 + uVar17,uVar16 + uVar18 + CARRY4(uVar10,uVar17));
    snprintf(tmp42,0x800,DAT_00023d6c);
    _applog(4,tmp42,false);
    goto LAB_00023bc4;
  }
  puVar3 = DAT_00023dac;
  piVar5 = DAT_00023da8;
  pbVar13 = DAT_00023d64;
  if (1 < total_pools) {
    iVar9 = 0;
    do {
      iVar19 = *(int *)(*piVar5 + iVar9 * 4);
      if (((*pbVar4 == 0) && (*pbVar13 == 0)) && ((int)*puVar3 < 4)) {
        iVar14 = *(int *)(iVar19 + 0x20);
        pbVar11 = DAT_00023d64;
        if (iVar14 == 0) goto LAB_0002410e;
LAB_00023de0:
        if ((*pbVar11 != 0) || (3 < (int)*puVar3)) goto LAB_000240e0;
      }
      else {
        snprintf(tmp42,0x800,DAT_00024088,*(undefined4 *)(iVar19 + 0xa4));
        _applog(4,tmp42,false);
        iVar14 = *(int *)(iVar19 + 0x20);
        bVar8 = *pbVar4;
        if (iVar14 != 0) {
          pbVar11 = DAT_0002408c;
          if (bVar8 == 0) goto LAB_00023de0;
LAB_000240e0:
          uVar15 = DAT_000243a8;
          if (1 < iVar14) {
            uVar15 = DAT_000243a4;
          }
          snprintf(tmp42,0x800,DAT_000243ac,iVar14,uVar15);
          _applog(4,tmp42,false);
          bVar8 = *pbVar4;
        }
        pbVar11 = DAT_000243b0;
        if (bVar8 == 0) {
LAB_0002410e:
          if ((*pbVar11 == 0) && ((int)*puVar3 < 4)) goto LAB_00023df2;
        }
        snprintf(tmp42,0x800,DAT_000243b4,*(undefined4 *)(iVar19 + 0x14),
                 *(int *)(iVar19 + 8) + *(int *)(iVar19 + 0x10));
        _applog(4,tmp42,false);
        uVar10 = (uint)*pbVar4;
        if ((uVar10 != 0) ||
           ((uVar10 = (uint)*pbVar13, uVar10 != 0 || (uVar10 = *puVar3, 3 < (int)uVar10)))) {
          snprintf(tmp42,0x800,DAT_000243b8,uVar10,*(undefined4 *)(iVar19 + 8));
          _applog(4,tmp42,false);
          uVar10 = (uint)*pbVar4;
          if ((uVar10 != 0) ||
             ((uVar10 = (uint)*pbVar13, uVar10 != 0 || (uVar10 = *puVar3, 3 < (int)uVar10)))) {
            snprintf(tmp42,0x800,DAT_000243bc,uVar10,*(undefined4 *)(iVar19 + 0x10));
            _applog(4,tmp42,false);
            uVar10 = (uint)*pbVar4;
            if ((uVar10 != 0) ||
               ((uVar10 = (uint)*pbVar13, uVar10 != 0 || (uVar10 = *puVar3, 3 < (int)uVar10)))) {
              snprintf(tmp42,0x800,DAT_000243c0,uVar10,*(undefined8 *)(iVar19 + 0x48));
              _applog(4,tmp42,false);
              uVar10 = (uint)*pbVar4;
              if ((uVar10 != 0) ||
                 ((uVar10 = (uint)*pbVar13, uVar10 != 0 || (uVar10 = *puVar3, 3 < (int)uVar10)))) {
                snprintf(tmp42,0x800,DAT_000243c4,uVar10,*(undefined8 *)(iVar19 + 0x50));
                _applog(4,tmp42,false);
              }
            }
          }
        }
      }
LAB_00023df2:
      uVar10 = *(uint *)(iVar19 + 8);
      uVar16 = *(uint *)(iVar19 + 0xc);
      if (((uVar10 | uVar16) == 0) && ((*(uint *)(iVar19 + 0x10) | *(uint *)(iVar19 + 0x14)) == 0))
      {
LAB_00023e68:
        if (((*pbVar4 != 0) || (*pbVar13 != 0)) || (3 < (int)*puVar3)) {
          snprintf(tmp42,0x800,DAT_00024094,*(undefined4 *)(iVar19 + 0x44));
          _applog(4,tmp42,false);
          if (((*pbVar4 != 0) || (*pbVar13 != 0)) || (3 < (int)*puVar3)) {
            snprintf(tmp42,0x800,DAT_00024098,*(undefined4 *)(iVar19 + 0x78));
            _applog(4,tmp42,false);
            if (((*pbVar4 != 0) || (*pbVar13 != 0)) || (3 < (int)*puVar3)) {
              snprintf(tmp42,0x800,DAT_0002409c,*(undefined4 *)(iVar19 + 0x80));
              _applog(4,tmp42,false);
              if (((*pbVar4 != 0) || (*pbVar13 != 0)) || (3 < (int)*puVar3)) {
                snprintf(tmp42,0x800,DAT_000240a0,*(undefined4 *)(iVar19 + 0x84));
                _applog(4,tmp42,false);
              }
            }
          }
        }
      }
      else if ((*pbVar4 != 0) || ((*pbVar13 != 0 || (3 < (int)*puVar3)))) {
        uVar17 = *(uint *)(iVar19 + 0x10);
        iVar14 = *(int *)(iVar19 + 0x14);
        __aeabi_l2d((int)((ulonglong)uVar17 * 100),
                    iVar14 * 100 + (int)((ulonglong)uVar17 * 100 >> 0x20));
        __aeabi_l2d(uVar10 + uVar17,uVar16 + iVar14 + (uint)CARRY4(uVar10,uVar17));
        snprintf(tmp42,0x800,DAT_00024090);
        _applog(4,tmp42,false);
        goto LAB_00023e68;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < total_pools);
  }
  if (((*pbVar4 != 0) || (*DAT_0002408c != 0)) || (3 < (int)*DAT_000243c8)) {
    tmp42._0_4_ = *DAT_000240a4;
    tmp42._4_4_ = DAT_000240a4[1];
    tmp42._8_4_ = DAT_000240a4[2];
    tmp42._12_4_ = DAT_000240a4[3];
    tmp42._16_4_ = DAT_000240a4[4];
    tmp42._20_4_ = DAT_000240a4[5];
    tmp42._24_4_ = DAT_000240a4[6];
    tmp42._28_4_ = DAT_000240a4[7];
    tmp42._32_2_ = (undefined2)DAT_000240a4[8];
    tmp42[34] = (char)((uint)DAT_000240a4[8] >> 0x10);
    _applog(4,tmp42,false);
  }
  puVar3 = DAT_000240c0;
  p_Var7 = DAT_000240b0;
  p_Var6 = DAT_000240ac;
  piVar5 = DAT_000240a8;
  pbVar13 = DAT_0002408c;
  if (0 < *DAT_000240a8) {
    iVar9 = 0;
    do {
      iVar19 = iVar9 + 1;
      cgpu_00 = get_devices(iVar9);
      pdVar12 = cgpu_00->drv;
      pdVar12->get_statline_before = p_Var6;
      pdVar12->get_statline = p_Var7;
      get_statline(logline,0xff,cgpu_00);
      if (((*pbVar4 != 0) || (*pbVar13 != 0)) || (3 < (int)*puVar3)) {
        snprintf(tmp42,0x800,DAT_000240b4,logline);
        _applog(4,tmp42,false);
      }
      iVar9 = iVar19;
    } while (iVar19 < *piVar5);
  }
  pdVar1 = DAT_000240b8;
  if (opt_shares == 0) {
LAB_00024056:
    uVar10 = (uint)*pbVar4;
LAB_0002405a:
    if (uVar10 == 0) goto LAB_0002405e;
  }
  else {
    pbVar13 = (byte *)(uint)*pbVar4;
    if ((((byte *)(uint)*pbVar4 != (byte *)0x0) || (pbVar13 = DAT_0002408c, *DAT_0002408c != 0)) ||
       (3 < (int)*DAT_00024414)) {
      snprintf(tmp42,0x800,DAT_000240bc,pbVar13,*DAT_000240b8,opt_shares);
      _applog(4,tmp42,false);
      dVar20 = *pdVar1;
      uVar10 = (uint)*pbVar4;
      dVar21 = (double)(longlong)opt_shares;
      if (dVar21 != dVar20 && dVar21 < dVar20 == (NAN(dVar21) || NAN(dVar20))) {
        if (uVar10 == 0) goto LAB_0002402a;
        goto LAB_0002403a;
      }
      goto LAB_0002405a;
    }
    dVar21 = (double)(longlong)opt_shares;
    dVar20 = *DAT_00024418;
    if (dVar21 != dVar20 && dVar21 < dVar20 == (NAN(dVar21) || NAN(dVar20))) {
LAB_0002402a:
      uVar10 = (uint)*DAT_0002408c;
      if ((uVar10 == 0) && (uVar10 = *DAT_000240c0, (int)uVar10 < 4)) goto LAB_00024076;
LAB_0002403a:
      snprintf(tmp42,0x800,DAT_000240c4,uVar10,dVar20,opt_shares);
      _applog(4,tmp42,false);
      goto LAB_00024056;
    }
LAB_0002405e:
    if ((*DAT_0002408c == 0) && ((int)*DAT_000243c8 < 4)) goto LAB_00024076;
  }
  tmp42[0] = ' ';
  tmp42[1] = '\0';
  _applog(4,tmp42,false);
LAB_00024076:
  fflush(*DAT_000240c8);
  fflush(*DAT_000240cc);
  return;
}

