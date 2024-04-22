
/* WARNING: Removing unreachable block (ram,0x000259de) */
/* WARNING: Type propagation algorithm not settling */

void hash_sole_work(undefined4 *param_1)

{
  undefined *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  time_t tVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  int iVar13;
  undefined *puVar14;
  int iVar15;
  undefined *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  double dVar22;
  double dVar23;
  longlong lVar24;
  undefined8 uVar25;
  uint local_890;
  uint local_868;
  int local_84c;
  int local_848;
  int local_844;
  int local_840;
  int local_83c;
  int local_838;
  int local_834;
  int local_830;
  int local_82c;
  timespec local_828 [256];
  
  iVar19 = param_1[9];
  uVar3 = *param_1;
  iVar15 = *(int *)(iVar19 + 4);
  iVar10 = opt_log_interval / 5;
  if (iVar10 == 0) {
    iVar10 = 1;
  }
  if (param_1[1] == 0) {
    local_868 = 1;
  }
  else {
    local_868 = (uint)*(byte *)(param_1 + 2);
  }
  local_890 = (**(code **)(iVar15 + 0x30))(param_1);
  cgtime(&local_848);
  cgtime(&local_830);
  if (*(char *)(iVar19 + 0x16c) == '\0') {
    lVar2 = 0;
    iVar11 = iVar10 * 1000000;
    iVar18 = 0;
    iVar20 = 0;
    do {
      local_84c = get_work(param_1,uVar3);
      *(undefined *)((int)param_1 + 0x3e) = 0;
      *(undefined *)(iVar19 + 0xac) = 1;
      cgtime(&local_838);
      pcVar12 = *(code **)(iVar15 + 0x38);
      *(undefined4 *)(local_84c + 0xf8) = 0;
      *(undefined4 *)(iVar19 + 0xa0) = 0;
      *(undefined4 *)(iVar19 + 0xa4) = 0;
      iVar4 = (*pcVar12)(param_1);
      if (iVar4 == 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf((char *)local_828,0x800,"work prepare failed, exiting mining thread %d",uVar3);
          _applog(3,local_828,0);
          *(undefined4 *)(iVar19 + 0x20) = 1;
          return;
        }
        break;
      }
      dVar23 = *(double *)(iVar15 + 0x68);
      dVar22 = *(double *)(local_84c + 0x178);
      if (dVar23 != dVar22 && dVar23 < dVar22 == (NAN(dVar23) || NAN(dVar22))) {
        dVar23 = dVar22;
      }
      if ((int)((uint)(dVar23 < *(double *)(iVar15 + 0x70)) << 0x1f) < 0) {
        dVar23 = *(double *)(iVar15 + 0x70);
      }
      *(double *)(local_84c + 0xe0) = dVar23;
      while( true ) {
        cgtime(&local_840);
        subtime(&local_840,&local_848);
        addtime(&local_848,iVar19 + 0x128);
        iVar4 = time_more(&local_848,iVar19 + 0x130);
        if (iVar4 != 0) {
          copy_time(iVar19 + 0x130,&local_848);
        }
        iVar4 = time_less(&local_848,iVar19 + 0x138);
        if (iVar4 != 0) {
          copy_time(iVar19 + 0x138,&local_848);
        }
        iVar17 = *(int *)(local_84c + 0x104);
        *(int *)(iVar19 + 0x124) = *(int *)(iVar19 + 0x124) + 1;
        addtime(&local_848,iVar17 + 0x184);
        iVar4 = time_more(&local_848,iVar17 + 0x18c);
        if (iVar4 != 0) {
          copy_time(iVar17 + 0x18c,&local_848);
        }
        iVar4 = time_less(&local_848,iVar17 + 0x194);
        if (iVar4 != 0) {
          copy_time(iVar17 + 0x194,&local_848);
        }
        *(int *)(iVar17 + 0x180) = *(int *)(iVar17 + 0x180) + 1;
        cgtime(local_84c + 0x1a8);
        pthread_setcancelstate(1,(int *)0x0);
        *(undefined *)((int)param_1 + 0x3d) = 0;
        cgtime(param_1 + 0xb);
        iVar4 = param_1[9];
        *(undefined4 *)(iVar4 + 0x60) = 0;
        tVar5 = time((time_t *)0x0);
        *(time_t *)(iVar4 + 0xf0) = tVar5;
        lVar24 = (**(code **)(iVar15 + 0x40))
                           (param_1,local_84c,*(int *)(local_84c + 0xf8) + local_890,0);
        iVar9 = (int)((ulonglong)lVar24 >> 0x20);
        uVar6 = (uint)lVar24;
        thread_reportout(param_1);
        pthread_setcancelstate(0,(int *)0x0);
        pthread_testcancel();
        cgtime(&local_848);
        iVar17 = local_844;
        iVar4 = local_848;
        if (iVar9 == -1 && uVar6 == 0xffffffff) break;
        iVar13 = *(int *)(iVar19 + 0xa4);
        lVar2 = lVar24 + lVar2;
        uVar8 = (undefined4)((ulonglong)lVar2 >> 0x20);
        uVar25 = CONCAT44(uVar8,local_890);
        bVar21 = *(uint *)(iVar19 + 0xa0) < uVar6;
        if ((int)((iVar13 - iVar9) - (uint)bVar21) < 0 !=
            (SBORROW4(iVar13,iVar9) != SBORROW4(iVar13 - iVar9,(uint)bVar21))) {
          *(longlong *)(iVar19 + 0xa0) = lVar24;
        }
        puVar14 = (undefined *)(local_844 - local_83c);
        bVar21 = (int)puVar14 < 0;
        if (bVar21) {
          puVar14 = &DAT_000f4240 + (int)puVar14;
        }
        iVar9 = local_848 - local_840;
        iVar20 = iVar20 + (int)puVar14;
        if (bVar21) {
          iVar9 = iVar9 + -1;
        }
        iVar18 = iVar18 + iVar9;
        if (1000000 < iVar20) {
          iVar18 = iVar18 + 1;
          iVar20 = iVar20 + -1000000;
        }
        iVar9 = local_848 - local_838;
        if (local_844 - local_834 < 0) {
          iVar9 = iVar9 + -1;
        }
        if (iVar18 < iVar10) {
          if (local_890 != 0xffffffff) {
            iVar13 = iVar20 + 0x7ff;
            if (-1 < iVar20 + 0x400) {
              iVar13 = iVar20 + 0x400;
            }
            iVar13 = __aeabi_idiv(&DAT_000f4240,iVar13 >> 10);
            iVar13 = (iVar13 + 0x10) * iVar10;
            uVar25 = __udivsi3(0xfffffc00,iVar13);
            uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
            if ((uint)uVar25 < local_890) {
              uVar25 = CONCAT44(uVar7,0xffffffff);
            }
            else {
              uVar25 = CONCAT44(uVar7,iVar13 * local_890 >> 10);
            }
            goto LAB_00025bdc;
          }
        }
        else {
          if (iVar10 < iVar18) {
            uVar25 = __udivsi3(iVar10 * local_890,iVar18);
          }
          else if (100000 < iVar20) {
            uVar7 = __aeabi_idiv(iVar20 + iVar11,(int)(iVar11 + 0x3ffU & iVar11 >> 0x20) >> 10);
            uVar25 = __udivsi3(local_890 << 10,uVar7);
          }
LAB_00025bdc:
          local_890 = (uint)uVar25;
          puVar14 = (undefined *)(iVar4 - local_830);
          puVar16 = (undefined *)(iVar17 - local_82c);
          if ((int)puVar16 < 0) {
            puVar14 = puVar14 + -1;
            puVar16 = &DAT_000f4240 + (int)puVar16;
          }
          if (lVar2 == 0) {
LAB_00025c04:
            if (opt_log_interval <= (int)puVar14) goto LAB_00025c0e;
          }
          else {
            bVar21 = puVar14 == (undefined *)0x0;
            puVar1 = puVar14;
            if ((int)puVar14 < 1) {
              puVar1 = puVar16 + -200000;
              bVar21 = puVar16 == (undefined *)0x30d40;
            }
            if (bVar21 || (int)puVar1 < 0 != ((int)puVar14 < 1 && SBORROW4((int)puVar16,200000)))
            goto LAB_00025c04;
LAB_00025c0e:
            hashmeter(uVar3,(int)((ulonglong)uVar25 >> 0x20),(int)lVar2,uVar8);
            lVar2 = 0;
            copy_time(&local_830,&local_848);
          }
          if (*(char *)((int)param_1 + 0x3e) != '\0') {
            if (local_868 == 0) {
              local_828[0].tv_sec = local_868;
              local_828[0].tv_nsec = param_1[1] * 250000000;
              nanosleep(local_828,(timespec *)0x0);
            }
            goto LAB_00025c70;
          }
          if ((*(char *)(param_1 + 0xf) != '\0') ||
             (iVar18 = *(int *)(iVar19 + 0x20), iVar20 = iVar18, iVar18 != 0)) {
            iVar20 = 0;
            mt_disable_isra_16(param_1,uVar3,iVar15 + 0x5c);
            iVar18 = 0;
          }
        }
        bVar21 = *(int *)(iVar19 + 0xa4) == 0;
        if (*(int *)(iVar19 + 0xa4) == 0) {
          bVar21 = *(uint *)(iVar19 + 0xa0) < 0xfffffffe;
        }
        if ((opt_scantime < iVar9 || !bVar21) || (iVar4 = stale_work(local_84c), iVar4 != 0))
        goto LAB_00025c70;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)local_828,0x800,"%s %d failure, disabling!",*(undefined4 *)(iVar15 + 8),
                 *(undefined4 *)(iVar19 + 8));
        _applog(3,local_828,0);
      }
      *(undefined4 *)(iVar19 + 0x20) = 1;
      dev_error(iVar19,1);
      *(undefined *)(iVar19 + 0x16c) = 1;
LAB_00025c70:
      _free_work(&local_84c,"cgminer.c",DAT_00025e4c,0x241f);
    } while (*(char *)(iVar19 + 0x16c) == '\0');
  }
  *(undefined4 *)(iVar19 + 0x20) = 1;
  return;
}

