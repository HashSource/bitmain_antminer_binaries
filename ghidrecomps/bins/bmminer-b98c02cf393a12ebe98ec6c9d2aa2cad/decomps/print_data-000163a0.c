
undefined4 print_data(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  void *__ptr;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  pthread_mutex_t *ppVar10;
  void *local_874;
  char acStack_870 [64];
  char acStack_830 [2052];
  
  ppVar10 = *(pthread_mutex_t **)(strbufs + 8);
  iVar3 = pthread_mutex_lock(ppVar10);
  uVar1 = DAT_000166f8;
  if (iVar3 == 0) {
    iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar10 + 1));
  }
  else {
    piVar5 = __errno_location();
    uVar1 = DAT_00016bec;
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             DAT_00016bec,0x4af);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar10 + 1));
  }
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x4af);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  iVar3 = _k_unlink_head(strbufs,"api.c",DAT_000166f8,0x4b0);
  ppVar10 = *(pthread_mutex_t **)(strbufs + 8);
  iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar10 + 1));
  if (iVar4 != 0) {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x4b1);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  iVar4 = pthread_mutex_unlock(ppVar10);
  if (iVar4 != 0) {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x4b1);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  (*selective_yield)();
  *(undefined4 *)(*(int *)(iVar3 + 0xc) + 4) = 0;
  if (param_4 != 0) {
    add_item_buf_isra_2(iVar3 + 0xc,&DAT_0005c74c);
  }
  iVar4 = iVar3 + 0xc;
  if (param_3 == 0) {
    if (param_2 != (undefined4 *)0x0) {
LAB_0001644e:
      dVar2 = DAT_000166f0;
      if (param_3 != 0) goto LAB_00016506;
LAB_0001646a:
      add_item_buf_isra_2(iVar4,param_2[1]);
      add_item_buf_isra_2(iVar4,"=");
      puVar9 = param_2;
      switch(*param_2) {
      case 0:
        local_874 = (void *)param_2[2];
        __ptr = (void *)escape_string(local_874,0);
        add_item_buf_isra_2(iVar4,__ptr);
        break;
      case 1:
      case 2:
        add_item_buf_isra_2(iVar4,param_2[2]);
        goto LAB_000164da;
      case 3:
        goto switchD_00016482_caseD_3;
      case 4:
        goto switchD_00016482_caseD_4;
      case 5:
        goto switchD_00016482_caseD_5;
      case 6:
        goto switchD_00016482_caseD_6;
      case 7:
      case 8:
        goto switchD_00016482_caseD_7;
      case 9:
        snprintf(acStack_870,0x40,"0x%08x",*(undefined4 *)param_2[2]);
        add_item_buf_isra_2(iVar4,acStack_870);
        goto LAB_000164da;
      case 10:
        goto switchD_00016482_caseD_a;
      case 0xb:
        goto switchD_00016482_caseD_b;
      case 0xc:
        goto switchD_00016482_caseD_c;
      case 0xd:
        goto switchD_00016482_caseD_d;
      case 0xe:
        goto switchD_00016482_caseD_e;
      case 0xf:
        goto switchD_00016482_caseD_f;
      case 0x10:
        goto switchD_00016482_caseD_10;
      case 0x11:
      case 0x14:
      case 0x15:
        goto switchD_00016482_caseD_11;
      case 0x12:
        goto switchD_00016482_caseD_12;
      case 0x13:
        goto switchD_00016482_caseD_13;
      case 0x16:
      case 0x1a:
        goto switchD_00016482_caseD_16;
      case 0x17:
        goto switchD_00016482_caseD_17;
      case 0x18:
        goto switchD_00016482_caseD_18;
      case 0x19:
        goto switchD_00016482_caseD_19;
      default:
        goto switchD_00016482_caseD_1b;
      }
LAB_00016670:
      puVar9 = param_2;
      if (local_874 != __ptr) {
        free(__ptr);
      }
LAB_000164da:
      free((void *)puVar9[1]);
      if (*(char *)(puVar9 + 3) == '\0') {
        param_2 = (undefined4 *)puVar9[5];
      }
      else {
        free((void *)puVar9[2]);
        param_2 = (undefined4 *)puVar9[5];
      }
      if (puVar9 == param_2) {
        free(puVar9);
        if (param_3 != 0) goto LAB_00016974;
        goto LAB_000165d0;
      }
      iVar7 = puVar9[4];
      param_2[4] = iVar7;
      *(undefined4 **)(iVar7 + 0x14) = param_2;
      free(puVar9);
      add_item_buf_isra_2(iVar4,&DAT_0005c74c);
      if (param_3 == 0) goto LAB_0001646a;
LAB_00016506:
      add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
      add_item_buf_isra_2(iVar4,param_2[1]);
      add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
      add_item_buf_isra_2(iVar4,&DAT_000670e8);
      switch(*param_2) {
      case 0:
        goto switchD_00016542_caseD_0;
      case 1:
      case 2:
        add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
        pcVar6 = (char *)param_2[2];
        goto LAB_000168f0;
      case 3:
switchD_00016482_caseD_3:
        snprintf(acStack_870,0x40,"%u",(uint)*(byte *)param_2[2]);
        break;
      case 4:
switchD_00016482_caseD_4:
        snprintf(acStack_870,0x40,"%d",(int)*(short *)param_2[2]);
        break;
      case 5:
switchD_00016482_caseD_5:
        snprintf(acStack_870,0x40,"%u",(uint)*(ushort *)param_2[2]);
        break;
      case 6:
switchD_00016482_caseD_6:
        snprintf(acStack_870,0x40,"%d",*(undefined4 *)param_2[2]);
        break;
      case 7:
      case 8:
switchD_00016482_caseD_7:
        snprintf(acStack_870,0x40,"%u",*(undefined4 *)param_2[2]);
        break;
      case 9:
        add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
        snprintf(acStack_870,0x40,"0x%08x",*(undefined4 *)param_2[2]);
        pcVar6 = acStack_870;
LAB_000168f0:
        add_item_buf_isra_2(iVar4,pcVar6);
        add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
        puVar9 = param_2;
        goto LAB_000164da;
      case 10:
switchD_00016482_caseD_a:
        snprintf(acStack_870,0x40,"%llu",(undefined4 *)param_2[2],*(undefined4 *)param_2[2]);
        break;
      case 0xb:
switchD_00016482_caseD_b:
        snprintf(acStack_870,0x40,"%lld",(undefined4 *)param_2[2],*(undefined4 *)param_2[2]);
        break;
      case 0xc:
switchD_00016482_caseD_c:
        snprintf(acStack_870,0x40,"%f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0xd:
switchD_00016482_caseD_d:
        snprintf(acStack_870,0x40,"%.0f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0xe:
switchD_00016482_caseD_e:
        pcVar6 = "false";
        if (*(char *)param_2[2] != '\0') {
          pcVar6 = "true";
        }
        snprintf(acStack_870,0x40,"%s",pcVar6);
        break;
      case 0xf:
switchD_00016482_caseD_f:
        snprintf(acStack_870,0x40,"%ld.%06ld",*(undefined4 *)param_2[2],
                 ((undefined4 *)param_2[2])[1]);
        break;
      case 0x10:
switchD_00016482_caseD_10:
        snprintf(acStack_870,0x40,"%lu",*(undefined4 *)param_2[2]);
        break;
      case 0x11:
      case 0x14:
      case 0x15:
switchD_00016482_caseD_11:
        snprintf(acStack_870,0x40,"%.2f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0x12:
switchD_00016482_caseD_12:
        snprintf(acStack_870,0x40,"%.4f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0x13:
switchD_00016482_caseD_13:
        pfVar8 = (float *)param_2[2];
        pcVar6 = "%.2f";
        goto LAB_000166c8;
      case 0x16:
      case 0x1a:
switchD_00016482_caseD_16:
        pfVar8 = (float *)param_2[2];
        pcVar6 = "%.3f";
LAB_000166c8:
        snprintf(acStack_870,0x40,pcVar6,pfVar8,(double)*pfVar8);
        break;
      case 0x17:
switchD_00016482_caseD_17:
        snprintf(acStack_870,0x40,"%.15f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0x18:
switchD_00016482_caseD_18:
        snprintf(acStack_870,0x40,"%.8f",(undefined8 *)param_2[2],*(undefined8 *)param_2[2]);
        break;
      case 0x19:
switchD_00016482_caseD_19:
        snprintf(acStack_870,0x40,"%.4f",(double *)param_2[2],*(double *)param_2[2] * dVar2);
        break;
      default:
switchD_00016482_caseD_1b:
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf(acStack_830,0x800,"API: unknown2 data type %d ignored");
          _applog(3,acStack_830,0);
        }
        if (param_3 != 0) {
          add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
          pcVar6 = "Unknown";
          goto LAB_000168f0;
        }
        add_item_buf_isra_2(iVar4,"Unknown");
        puVar9 = param_2;
        goto LAB_000164da;
      }
      add_item_buf_isra_2(iVar4,acStack_870);
      puVar9 = param_2;
      goto LAB_000164da;
    }
LAB_000165d0:
    add_item_buf_isra_2(iVar4,&DAT_00057a28);
  }
  else {
    add_item_buf_isra_2(iVar4,&DAT_000634c8);
    if (param_2 != (undefined4 *)0x0) goto LAB_0001644e;
LAB_00016974:
    add_item_buf_isra_2(iVar4,"}");
  }
  io_add(param_1,**(undefined4 **)(iVar3 + 0xc));
  ppVar10 = *(pthread_mutex_t **)(strbufs + 8);
  iVar4 = pthread_mutex_lock(ppVar10);
  if (iVar4 == 0) {
    iVar4 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar10 + 1));
  }
  else {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x55b);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar4 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar10 + 1));
  }
  if (iVar4 != 0) {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x55b);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  _k_add_head(strbufs,iVar3,"api.c",DAT_000166f8,0x55c);
  ppVar10 = *(pthread_mutex_t **)(strbufs + 8);
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar10 + 1));
  if (iVar3 == 0) {
    iVar3 = pthread_mutex_unlock(ppVar10);
  }
  else {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x55d);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar3 = pthread_mutex_unlock(ppVar10);
  }
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,"api.c",
             uVar1,0x55d);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  (*selective_yield)();
  return 0;
switchD_00016542_caseD_0:
  local_874 = (void *)param_2[2];
  __ptr = (void *)escape_string(local_874,1);
  add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
  add_item_buf_isra_2(iVar4,__ptr);
  add_item_buf_isra_2(iVar4,&DAT_0005c7f8);
  goto LAB_00016670;
}

