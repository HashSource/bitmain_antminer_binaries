
undefined4 print_data(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *__ptr;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  pthread_mutex_t *ppVar8;
  void *local_874;
  char acStack_870 [64];
  char acStack_830 [2052];
  
  ppVar8 = *(pthread_mutex_t **)(strbufs + 8);
  iVar1 = pthread_mutex_lock(ppVar8);
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar8 + 1));
  }
  else {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x4af);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar8 + 1));
  }
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x4af);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  iVar1 = _k_unlink_head(strbufs,"api.c","print_data",0x4b0);
  ppVar8 = *(pthread_mutex_t **)(strbufs + 8);
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar8 + 1));
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x4b1);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  iVar2 = pthread_mutex_unlock(ppVar8);
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x4b1);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  (*selective_yield)();
  *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4) = 0;
  if (param_4 != 0) {
    add_item_buf_isra_2(iVar1 + 0xc,&DAT_0005c74c);
  }
  iVar2 = iVar1 + 0xc;
  if (param_3 == 0) {
    if (param_2 != (undefined4 *)0x0) {
LAB_0001644e:
      if (param_3 != 0) goto LAB_00016506;
LAB_0001646a:
      add_item_buf_isra_2(iVar2,param_2[1]);
      add_item_buf_isra_2(iVar2,"=");
      puVar7 = param_2;
      switch(*param_2) {
      case 0:
        local_874 = (void *)param_2[2];
        __ptr = (void *)escape_string(local_874,0);
        add_item_buf_isra_2(iVar2,__ptr);
        break;
      case 1:
      case 2:
        add_item_buf_isra_2(iVar2,param_2[2]);
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
        add_item_buf_isra_2(iVar2,acStack_870);
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
        goto switchD_00016482_default;
      }
LAB_00016670:
      puVar7 = param_2;
      if (local_874 != __ptr) {
        free(__ptr);
      }
LAB_000164da:
      free((void *)puVar7[1]);
      if (*(char *)(puVar7 + 3) == '\0') {
        param_2 = (undefined4 *)puVar7[5];
      }
      else {
        free((void *)puVar7[2]);
        param_2 = (undefined4 *)puVar7[5];
      }
      if (puVar7 == param_2) {
        free(puVar7);
        if (param_3 == 0) goto LAB_000165d0;
        goto LAB_00016974;
      }
      iVar5 = puVar7[4];
      param_2[4] = iVar5;
      *(undefined4 **)(iVar5 + 0x14) = param_2;
      free(puVar7);
      add_item_buf_isra_2(iVar2,&DAT_0005c74c);
      if (param_3 == 0) goto LAB_0001646a;
LAB_00016506:
      add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
      add_item_buf_isra_2(iVar2,param_2[1]);
      add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
      add_item_buf_isra_2(iVar2,&DAT_000670e8);
      switch(*param_2) {
      case 0:
        goto switchD_00016542_caseD_0;
      case 1:
      case 2:
        add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
        pcVar4 = (char *)param_2[2];
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
        add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
        snprintf(acStack_870,0x40,"0x%08x",*(undefined4 *)param_2[2]);
        pcVar4 = acStack_870;
LAB_000168f0:
        add_item_buf_isra_2(iVar2,pcVar4);
        add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
        puVar7 = param_2;
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
        pcVar4 = "false";
        if (*(char *)param_2[2] != '\0') {
          pcVar4 = "true";
        }
        snprintf(acStack_870,0x40,"%s",pcVar4);
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
        pfVar6 = (float *)param_2[2];
        pcVar4 = "%.2f";
        goto LAB_000166c8;
      case 0x16:
      case 0x1a:
switchD_00016482_caseD_16:
        pfVar6 = (float *)param_2[2];
        pcVar4 = "%.3f";
LAB_000166c8:
        snprintf(acStack_870,0x40,pcVar4,pfVar6,(double)*pfVar6);
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
        snprintf(acStack_870,0x40,"%.4f",(double *)param_2[2],*(double *)param_2[2] * 100.0);
        break;
      default:
switchD_00016482_default:
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf(acStack_830,0x800,"API: unknown2 data type %d ignored");
          _applog(3,acStack_830,0);
        }
        if (param_3 != 0) {
          add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
          pcVar4 = "Unknown";
          goto LAB_000168f0;
        }
        add_item_buf_isra_2(iVar2,"Unknown");
        puVar7 = param_2;
        goto LAB_000164da;
      }
      add_item_buf_isra_2(iVar2,acStack_870);
      puVar7 = param_2;
      goto LAB_000164da;
    }
LAB_000165d0:
    add_item_buf_isra_2(iVar2,&DAT_00057a28);
  }
  else {
    add_item_buf_isra_2(iVar2,&DAT_000634c8);
    if (param_2 != (undefined4 *)0x0) goto LAB_0001644e;
LAB_00016974:
    add_item_buf_isra_2(iVar2,"}");
  }
  io_add(param_1,**(undefined4 **)(iVar1 + 0xc));
  ppVar8 = *(pthread_mutex_t **)(strbufs + 8);
  iVar2 = pthread_mutex_lock(ppVar8);
  if (iVar2 == 0) {
    iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar8 + 1));
  }
  else {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x55b);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar8 + 1));
  }
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x55b);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  _k_add_head(strbufs,iVar1,"api.c","print_data",0x55c);
  ppVar8 = *(pthread_mutex_t **)(strbufs + 8);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar8 + 1));
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_unlock(ppVar8);
  }
  else {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x55d);
    _applog(3,acStack_830,1);
    _quit(1);
    iVar1 = pthread_mutex_unlock(ppVar8);
  }
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    snprintf(acStack_830,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,"api.c",
             "print_data",0x55d);
    _applog(3,acStack_830,1);
    _quit(1);
  }
  (*selective_yield)();
  return 0;
switchD_00016542_caseD_0:
  local_874 = (void *)param_2[2];
  __ptr = (void *)escape_string(local_874,1);
  add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
  add_item_buf_isra_2(iVar2,__ptr);
  add_item_buf_isra_2(iVar2,&DAT_0005c7f8);
  goto LAB_00016670;
}

