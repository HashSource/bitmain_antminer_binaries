
/* WARNING: Unknown calling convention */

api_data * print_data(io_data *io_data,api_data *root,_Bool isjson,_Bool precom)

{
  double dVar1;
  code **ppcVar2;
  int iVar3;
  K_ITEM *item_00;
  K_ITEM *item;
  int iVar4;
  char *str;
  char *escape;
  int *piVar5;
  char *pcVar6;
  pthread_rwlock_t *func;
  char *pcVar7;
  api_data *paVar8;
  int iVar9;
  undefined4 uVar10;
  api_data *__ptr;
  api_data *tmp;
  pthread_mutex_t *ppVar11;
  char *str_00;
  char *original;
  pthread_rwlock_t *local_874;
  char buf [64];
  char tmp42 [2048];
  
  iVar4 = DAT_00019914;
  pcVar6 = (char *)(uint)isjson;
  iVar9 = *(int *)(DAT_00019914 + 0x28);
  ppVar11 = *(pthread_mutex_t **)(iVar9 + 8);
  pcVar7 = pcVar6;
  iVar3 = pthread_mutex_lock(ppVar11);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00019c44,(char *)0x4ac,pcVar7,iVar9);
  }
  iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar11 + 1));
  if (iVar3 == 0) {
    local_874 = DAT_000198d8;
  }
  else {
    piVar5 = __errno_location();
    local_874 = DAT_00019c44;
    snprintf(tmp42,0x800,DAT_00019c4c,*piVar5,DAT_00019c48,DAT_00019c44,0x4ac);
    _applog(3,tmp42,true);
    _quit(1);
  }
  func = DAT_000198d8;
  item_00 = _k_unlink_head(*(K_LIST **)(iVar4 + 0x28),DAT_000198dc,DAT_000198d8->__size,0x4ad);
  iVar9 = *(int *)(iVar4 + 0x28);
  ppVar11 = *(pthread_mutex_t **)(iVar9 + 8);
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar11 + 1));
  if (iVar3 != 0) {
    _rw_unlock(DAT_00019bd0,(char *)0x4ae,func->__size,iVar9);
  }
  iVar3 = pthread_mutex_unlock(ppVar11);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00019c44,(char *)0x4ae,func->__size,iVar9);
  }
  ppcVar2 = DAT_00019918;
  (**DAT_00019918)();
  pcVar7 = (char *)0x0;
  *(undefined4 *)((int)item_00->data + 4) = 0;
  if (precom) {
    add_item_buf(item_00,DAT_00019bc0);
  }
  if (pcVar6 != (char *)0x0) {
    add_item_buf(item_00,DAT_00019bbc);
  }
  dVar1 = DAT_000198d0;
  if (root == (api_data *)0x0) {
LAB_00019784:
    if (pcVar6 == (char *)0x0) {
      add_item_buf(item_00,DAT_000198f4);
    }
    else {
      add_item_buf(item_00,DAT_00019bc4);
    }
                    /* WARNING: Load size is inaccurate */
    io_add(io_data,*item_00->data);
    iVar9 = *(int *)(iVar4 + 0x28);
    ppVar11 = *(pthread_mutex_t **)(iVar9 + 8);
    iVar3 = pthread_mutex_lock(ppVar11);
    if (iVar3 != 0) {
      _mutex_lock((pthread_mutex_t *)DAT_00019c44,(char *)0x558,pcVar7,iVar9);
    }
    iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar11 + 1));
    if (iVar3 != 0) {
      piVar5 = __errno_location();
      snprintf(tmp42,0x800,DAT_00019bd8,*piVar5,DAT_00019bd4,local_874,0x558);
      _applog(3,tmp42,true);
      _quit(1);
    }
    pcVar7 = DAT_000198dc;
    _k_add_head(*(K_LIST **)(iVar4 + 0x28),item_00,DAT_000198dc,DAT_000198d8->__size,0x559);
    iVar3 = *(int *)(iVar4 + 0x28);
    ppVar11 = *(pthread_mutex_t **)(iVar3 + 8);
    iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar11 + 1));
    if (iVar4 != 0) {
      _rw_unlock(DAT_00019c44,(char *)0x55a,pcVar7,iVar3);
    }
    iVar4 = pthread_mutex_unlock(ppVar11);
    if (iVar4 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)DAT_00019bd0,(char *)0x55a,pcVar7,iVar3);
    }
    (**ppcVar2)();
    return (api_data *)0x0;
  }
  if (pcVar6 != (char *)0x0) goto LAB_0001974c;
LAB_000196b6:
  pcVar7 = pcVar6;
  add_item_buf(item_00,root->name);
  add_item_buf(item_00,DAT_000198e0);
  __ptr = root;
  do {
    switch(__ptr->type) {
    case API_ESCAPE:
      str_00 = (char *)__ptr->data;
      str = escape_string(str_00,isjson);
      if (pcVar6 == (char *)0x0) {
        add_item_buf(item_00,str);
      }
      else {
        add_item_buf(item_00,DAT_00019bcc);
        add_item_buf(item_00,str);
        add_item_buf(item_00,DAT_00019bcc);
      }
      if (str != str_00) {
        free(str);
      }
      goto LAB_0001971e;
    case API_STRING:
    case API_CONST:
      if (pcVar6 == (char *)0x0) {
        add_item_buf(item_00,(char *)__ptr->data);
      }
      else {
        add_item_buf(item_00,DAT_00019bcc);
        add_item_buf(item_00,(char *)__ptr->data);
        add_item_buf(item_00,DAT_00019bcc);
      }
      goto LAB_0001971e;
    case API_UINT8:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019bac;
      snprintf(buf,0x40,DAT_00019bac,(uint)*__ptr->data);
      break;
    case API_INT16:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019ba8;
      snprintf(buf,0x40,DAT_00019ba8,(int)*__ptr->data);
      break;
    case API_UINT16:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019bac;
      snprintf(buf,0x40,DAT_00019bac,(uint)*__ptr->data);
      break;
    case API_INT:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019ba8;
      snprintf(buf,0x40,DAT_00019ba8,*__ptr->data);
      break;
    case API_UINT:
    case API_UINT32:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_000198e4;
      snprintf(buf,0x40,DAT_000198e4,*__ptr->data);
      break;
    case API_HEX32:
      if (pcVar6 == (char *)0x0) {
                    /* WARNING: Load size is inaccurate */
        pcVar7 = DAT_00019ba0;
        snprintf(buf,0x40,DAT_00019ba0,*__ptr->data);
        add_item_buf(item_00,buf);
      }
      else {
        add_item_buf(item_00,DAT_00019bcc);
                    /* WARNING: Load size is inaccurate */
        pcVar7 = DAT_00019ba0;
        snprintf(buf,0x40,DAT_00019ba0,*__ptr->data);
        add_item_buf(item_00,buf);
        add_item_buf(item_00,DAT_00019bcc);
      }
      goto LAB_0001971e;
    case API_UINT64:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019b9c;
      snprintf(buf,0x40,DAT_00019b9c,__ptr->data,*__ptr->data);
      break;
    case API_INT64:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019b98;
      snprintf(buf,0x40,DAT_00019b98,__ptr->data,*__ptr->data);
      break;
    case API_DOUBLE:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019b94;
      snprintf(buf,0x40,DAT_00019b94,__ptr->data,*__ptr->data);
      break;
    case API_ELAPSED:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019b90;
      snprintf(buf,0x40,DAT_00019b90,__ptr->data,*__ptr->data);
      break;
    case API_BOOL:
                    /* WARNING: Load size is inaccurate */
      uVar10 = DAT_00019b88;
      if (*__ptr->data == '\0') {
        uVar10 = DAT_00019bdc;
      }
      pcVar7 = DAT_00019b8c;
      snprintf(buf,0x40,DAT_00019b8c,uVar10);
      break;
    case API_TIMEVAL:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019910;
      snprintf(buf,0x40,DAT_00019910,*__ptr->data,*(undefined4 *)((int)__ptr->data + 4));
      break;
    case API_TIME:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_0001990c;
      snprintf(buf,0x40,DAT_0001990c,*__ptr->data);
      break;
    case API_MHS:
    case API_UTILITY:
    case API_FREQ:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019904;
      snprintf(buf,0x40,DAT_00019904,__ptr->data,*__ptr->data);
      break;
    case API_MHTOTAL:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019908;
      snprintf(buf,0x40,DAT_00019908,__ptr->data,*__ptr->data);
      break;
    case API_TEMP:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019904;
      snprintf(buf,0x40,DAT_00019904,__ptr->data,(double)*__ptr->data);
      break;
    case API_VOLTS:
    case API_AVG:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019900;
      snprintf(buf,0x40,DAT_00019900,__ptr->data,(double)*__ptr->data);
      break;
    case API_HS:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_000198fc;
      snprintf(buf,0x40,DAT_000198fc,__ptr->data,*__ptr->data);
      break;
    case API_DIFF:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_000198f8;
      snprintf(buf,0x40,DAT_000198f8,__ptr->data,*__ptr->data);
      break;
    case API_PERCENT:
                    /* WARNING: Load size is inaccurate */
      pcVar7 = DAT_00019ba4;
      snprintf(buf,0x40,DAT_00019ba4,__ptr->data,*__ptr->data * dVar1);
      break;
    default:
      if (((use_syslog != false) || (*DAT_00019bb0 != '\0')) ||
         (pcVar7 = *DAT_00019bc8, 2 < (int)pcVar7)) {
        snprintf(tmp42,0x800,DAT_00019bb4);
        pcVar7 = (char *)0x0;
        _applog(3,tmp42,false);
      }
      if (pcVar6 == (char *)0x0) {
        add_item_buf(item_00,DAT_00019bb8);
      }
      else {
        add_item_buf(item_00,DAT_00019bcc);
        add_item_buf(item_00,DAT_00019bb8);
        add_item_buf(item_00,DAT_00019bcc);
      }
      goto LAB_0001971e;
    }
    add_item_buf(item_00,buf);
LAB_0001971e:
    free(__ptr->name);
    if (__ptr->data_was_malloc == false) {
      root = __ptr->next;
    }
    else {
      free(__ptr->data);
      root = __ptr->next;
    }
    if (root == __ptr) {
      free(__ptr);
      goto LAB_00019784;
    }
    paVar8 = __ptr->prev;
    root->prev = paVar8;
    paVar8->next = root;
    free(__ptr);
    add_item_buf(item_00,DAT_000198e8);
    if (pcVar6 == (char *)0x0) goto LAB_000196b6;
LAB_0001974c:
    pcVar7 = pcVar6;
    add_item_buf(item_00,DAT_000198ec);
    add_item_buf(item_00,root->name);
    add_item_buf(item_00,DAT_000198ec);
    add_item_buf(item_00,DAT_000198f0);
    __ptr = root;
  } while( true );
}

