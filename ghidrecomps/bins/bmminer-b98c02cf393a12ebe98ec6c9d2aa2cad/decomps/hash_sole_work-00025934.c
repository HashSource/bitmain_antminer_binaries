
/* WARNING: Removing unreachable block (ram,0x000259de) */
/* WARNING: Type propagation algorithm not settling */

void hash_sole_work(undefined4 *param_1)

{
  undefined *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  time_t tVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  undefined *puVar13;
  int iVar14;
  undefined *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  double dVar21;
  longlong lVar22;
  undefined8 uVar23;
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
  
  iVar18 = param_1[9];
  uVar3 = *param_1;
  iVar14 = *(int *)(iVar18 + 4);
  iVar9 = opt_log_interval / 5;
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  if (param_1[1] == 0) {
    local_868 = 1;
  }
  else {
    local_868 = (uint)*(byte *)(param_1 + 2);
  }
  local_890 = (**(code **)(iVar14 + 0x30))(param_1);
  cgtime(&local_848);
  cgtime(&local_830);
  if (*(char *)(iVar18 + 0x16c) == '\0') {
    lVar2 = 0;
    iVar10 = iVar9 * 1000000;
    iVar17 = 0;
    iVar19 = 0;
    do {
      local_84c = get_work(param_1,uVar3);
      *(undefined1 *)((int)param_1 + 0x3e) = 0;
      *(undefined1 *)(iVar18 + 0xac) = 1;
      cgtime(&local_838);
      pcVar11 = *(code **)(iVar14 + 0x38);
      *(undefined4 *)(local_84c + 0xf8) = 0;
      *(undefined4 *)(iVar18 + 0xa0) = 0;
      *(undefined4 *)(iVar18 + 0xa4) = 0;
      iVar4 = (*pcVar11)(param_1);
      if (iVar4 == 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf((char *)local_828,0x800,"work prepare failed, exiting mining thread %d",uVar3);
          _applog(3,local_828,0);
          *(undefined4 *)(iVar18 + 0x20) = 1;
          return;
        }
        break;
      }
      dVar21 = *(double *)(iVar14 + 0x68);
      if (*(double *)(local_84c + 0x178) < *(double *)(iVar14 + 0x68)) {
        dVar21 = *(double *)(local_84c + 0x178);
      }
      if ((int)((uint)(dVar21 < *(double *)(iVar14 + 0x70)) << 0x1f) < 0) {
        dVar21 = *(double *)(iVar14 + 0x70);
      }
      *(double *)(local_84c + 0xe0) = dVar21;
      while( true ) {
        cgtime(&local_840);
        subtime(&local_840,&local_848);
        addtime(&local_848,iVar18 + 0x128);
        iVar4 = time_more(&local_848,iVar18 + 0x130);
        if (iVar4 != 0) {
          copy_time(iVar18 + 0x130,&local_848);
        }
        iVar4 = time_less(&local_848,iVar18 + 0x138);
        if (iVar4 != 0) {
          copy_time(iVar18 + 0x138,&local_848);
        }
        iVar16 = *(int *)(local_84c + 0x104);
        *(int *)(iVar18 + 0x124) = *(int *)(iVar18 + 0x124) + 1;
        addtime(&local_848,iVar16 + 0x184);
        iVar4 = time_more(&local_848,iVar16 + 0x18c);
        if (iVar4 != 0) {
          copy_time(iVar16 + 0x18c,&local_848);
        }
        iVar4 = time_less(&local_848,iVar16 + 0x194);
        if (iVar4 != 0) {
          copy_time(iVar16 + 0x194,&local_848);
        }
        *(int *)(iVar16 + 0x180) = *(int *)(iVar16 + 0x180) + 1;
        cgtime(local_84c + 0x1a8);
        pthread_setcancelstate(1,(int *)0x0);
        *(undefined1 *)((int)param_1 + 0x3d) = 0;
        cgtime(param_1 + 0xb);
        iVar4 = param_1[9];
        *(undefined4 *)(iVar4 + 0x60) = 0;
        tVar5 = time((time_t *)0x0);
        *(time_t *)(iVar4 + 0xf0) = tVar5;
        lVar22 = (**(code **)(iVar14 + 0x40))
                           (param_1,local_84c,*(int *)(local_84c + 0xf8) + local_890,0);
        iVar8 = (int)((ulonglong)lVar22 >> 0x20);
        thread_reportout(param_1);
        pthread_setcancelstate(0,(int *)0x0);
        pthread_testcancel();
        cgtime(&local_848);
        iVar16 = local_844;
        iVar4 = local_848;
        if (lVar22 == -1) break;
        iVar12 = *(int *)(iVar18 + 0xa4);
        lVar2 = lVar22 + lVar2;
        uVar7 = (undefined4)((ulonglong)lVar2 >> 0x20);
        uVar23 = CONCAT44(uVar7,local_890);
        bVar20 = *(uint *)(iVar18 + 0xa0) < (uint)lVar22;
        if ((int)((iVar12 - iVar8) - (uint)bVar20) < 0 !=
            (SBORROW4(iVar12,iVar8) != SBORROW4(iVar12 - iVar8,(uint)bVar20))) {
          *(longlong *)(iVar18 + 0xa0) = lVar22;
        }
        puVar13 = (undefined *)(local_844 - local_83c);
        bVar20 = (int)puVar13 < 0;
        if (bVar20) {
          puVar13 = &DAT_000f4240 + (int)puVar13;
        }
        iVar8 = local_848 - local_840;
        iVar19 = iVar19 + (int)puVar13;
        if (bVar20) {
          iVar8 = iVar8 + -1;
        }
        iVar17 = iVar17 + iVar8;
        if (1000000 < iVar19) {
          iVar17 = iVar17 + 1;
          iVar19 = iVar19 + -1000000;
        }
        iVar8 = local_848 - local_838;
        if (local_844 - local_834 < 0) {
          iVar8 = iVar8 + -1;
        }
        if (iVar17 < iVar9) {
          if (local_890 != 0xffffffff) {
            iVar12 = iVar19 + 0x7ff;
            if (-1 < iVar19 + 0x400) {
              iVar12 = iVar19 + 0x400;
            }
            iVar12 = __aeabi_idiv(&DAT_000f4240,iVar12 >> 10);
            iVar12 = (iVar12 + 0x10) * iVar9;
            uVar23 = __udivsi3(0xfffffc00,iVar12);
            uVar6 = (undefined4)((ulonglong)uVar23 >> 0x20);
            if ((uint)uVar23 < local_890) {
              uVar23 = CONCAT44(uVar6,0xffffffff);
            }
            else {
              uVar23 = CONCAT44(uVar6,iVar12 * local_890 >> 10);
            }
            goto LAB_00025bdc;
          }
        }
        else {
          if (iVar9 < iVar17) {
            uVar23 = __udivsi3(iVar9 * local_890,iVar17);
          }
          else if (100000 < iVar19) {
            uVar6 = __aeabi_idiv(iVar19 + iVar10,(int)(iVar10 + 0x3ffU & iVar10 >> 0x20) >> 10);
            uVar23 = __udivsi3(local_890 << 10,uVar6);
          }
LAB_00025bdc:
          local_890 = (uint)uVar23;
          puVar13 = (undefined *)(iVar4 - local_830);
          puVar15 = (undefined *)(iVar16 - local_82c);
          if ((int)puVar15 < 0) {
            puVar13 = puVar13 + -1;
            puVar15 = &DAT_000f4240 + (int)puVar15;
          }
          if (lVar2 == 0) {
LAB_00025c04:
            if (opt_log_interval <= (int)puVar13) goto LAB_00025c0e;
          }
          else {
            bVar20 = puVar13 == (undefined *)0x0;
            puVar1 = puVar13;
            if ((int)puVar13 < 1) {
              puVar1 = puVar15 + -200000;
              bVar20 = puVar15 == (undefined *)0x30d40;
            }
            if (bVar20 || (int)puVar1 < 0 != ((int)puVar13 < 1 && SBORROW4((int)puVar15,200000)))
            goto LAB_00025c04;
LAB_00025c0e:
            hashmeter(uVar3,(int)((ulonglong)uVar23 >> 0x20),(int)lVar2,uVar7);
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
             (iVar17 = *(int *)(iVar18 + 0x20), iVar19 = iVar17, iVar17 != 0)) {
            iVar19 = 0;
            mt_disable_isra_16(param_1,uVar3,iVar14 + 0x5c);
            iVar17 = 0;
          }
        }
        bVar20 = *(int *)(iVar18 + 0xa4) == 0;
        if (*(int *)(iVar18 + 0xa4) == 0) {
          bVar20 = *(uint *)(iVar18 + 0xa0) < 0xfffffffe;
        }
        if ((opt_scantime < iVar8 || !bVar20) || (iVar4 = stale_work(local_84c), iVar4 != 0))
        goto LAB_00025c70;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)local_828,0x800,"%s %d failure, disabling!",*(undefined4 *)(iVar14 + 8),
                 *(undefined4 *)(iVar18 + 8));
        _applog(3,local_828,0);
      }
      *(undefined4 *)(iVar18 + 0x20) = 1;
      dev_error(iVar18,1);
      *(undefined1 *)(iVar18 + 0x16c) = 1;
LAB_00025c70:
      _free_work(&local_84c,"cgminer.c","hash_sole_work",0x241f);
    } while (*(char *)(iVar18 + 0x16c) == '\0');
  }
  *(undefined4 *)(iVar18 + 0x20) = 1;
  return;
}

