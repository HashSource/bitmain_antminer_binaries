
/* WARNING: Unknown calling convention */

api_data * print_data(io_data *io_data,api_data *root,_Bool isjson,_Bool precom)

{
  int iVar1;
  K_ITEM *item;
  int *piVar2;
  char *func;
  char *func_00;
  char *func_01;
  api_data *paVar3;
  char *func_02;
  char *func_03;
  char *func_04;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  char *pcVar4;
  api_data *__ptr;
  pthread_mutex_t *ppVar5;
  char *str;
  char buf [64];
  char tmp42 [2048];
  
  ppVar5 = (pthread_mutex_t *)strbufs->lock;
  iVar1 = pthread_mutex_lock(ppVar5);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"print_data",(char *)0x4ac,func,line);
  }
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar5 + 1));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
             "print_data",0x4ac);
    _applog(3,tmp42,true);
    _quit(1);
  }
  item = _k_unlink_head(strbufs,"api.c","print_data",0x4ad);
  ppVar5 = (pthread_mutex_t *)strbufs->lock;
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar5 + 1));
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"print_data",(char *)0x4ae,func_00,line_00);
  }
  iVar1 = pthread_mutex_unlock(ppVar5);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"print_data",(char *)0x4ae,func_01,line_01);
  }
  (*selective_yield)();
  *(undefined4 *)((int)item->data + 4) = 0;
  if (precom) {
    add_item_buf(item,",");
  }
  if (isjson) {
    add_item_buf(item,"{");
  }
  if (root == (api_data *)0x0) {
LAB_00019784:
    if (isjson) {
      add_item_buf(item,"}");
    }
    else {
      add_item_buf(item,"|");
    }
                    /* WARNING: Load size is inaccurate */
    io_add(io_data,*item->data);
    ppVar5 = (pthread_mutex_t *)strbufs->lock;
    iVar1 = pthread_mutex_lock(ppVar5);
    if (iVar1 != 0) {
      _mutex_lock((pthread_mutex_t *)"print_data",(char *)0x558,func_02,line_02);
    }
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar5 + 1));
    if (iVar1 != 0) {
      piVar2 = __errno_location();
      snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
               "print_data",0x558);
      _applog(3,tmp42,true);
      _quit(1);
    }
    _k_add_head(strbufs,item,"api.c","print_data",0x559);
    ppVar5 = (pthread_mutex_t *)strbufs->lock;
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar5 + 1));
    if (iVar1 != 0) {
      _rw_unlock((pthread_rwlock_t *)"print_data",(char *)0x55a,func_03,line_03);
    }
    iVar1 = pthread_mutex_unlock(ppVar5);
    if (iVar1 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"print_data",(char *)0x55a,func_04,line_04);
    }
    (*selective_yield)();
    return (api_data *)0x0;
  }
  if (isjson) goto LAB_0001974c;
LAB_000196b6:
  add_item_buf(item,root->name);
  add_item_buf(item,"=");
  __ptr = root;
  do {
    switch(__ptr->type) {
    case API_ESCAPE:
      str = (char *)__ptr->data;
      pcVar4 = escape_string(str,isjson);
      if (isjson) {
        add_item_buf(item,"\"");
        add_item_buf(item,pcVar4);
        add_item_buf(item,"\"");
      }
      else {
        add_item_buf(item,pcVar4);
      }
      if (pcVar4 != str) {
        free(pcVar4);
      }
      goto LAB_0001971e;
    case API_STRING:
    case API_CONST:
      if (isjson) {
        add_item_buf(item,"\"");
        add_item_buf(item,(char *)__ptr->data);
        add_item_buf(item,"\"");
      }
      else {
        add_item_buf(item,(char *)__ptr->data);
      }
      goto LAB_0001971e;
    case API_UINT8:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",(uint)*__ptr->data);
      break;
    case API_INT16:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%d",(int)*__ptr->data);
      break;
    case API_UINT16:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",(uint)*__ptr->data);
      break;
    case API_INT:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%d",*__ptr->data);
      break;
    case API_UINT:
    case API_UINT32:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",*__ptr->data);
      break;
    case API_HEX32:
      if (isjson) {
        add_item_buf(item,"\"");
                    /* WARNING: Load size is inaccurate */
        snprintf(buf,0x40,"0x%08x",*__ptr->data);
        add_item_buf(item,buf);
        add_item_buf(item,"\"");
      }
      else {
                    /* WARNING: Load size is inaccurate */
        snprintf(buf,0x40,"0x%08x",*__ptr->data);
        add_item_buf(item,buf);
      }
      goto LAB_0001971e;
    case API_UINT64:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%llu",__ptr->data,*__ptr->data);
      break;
    case API_INT64:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%lld",__ptr->data,*__ptr->data);
      break;
    case API_DOUBLE:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%f",__ptr->data,*__ptr->data);
      break;
    case API_ELAPSED:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.0f",__ptr->data,*__ptr->data);
      break;
    case API_BOOL:
      pcVar4 = "true";
                    /* WARNING: Load size is inaccurate */
      if (*__ptr->data == '\0') {
        pcVar4 = "false";
      }
      snprintf(buf,0x40,"%s",pcVar4);
      break;
    case API_TIMEVAL:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%ld.%06ld",*__ptr->data,*(undefined4 *)((int)__ptr->data + 4));
      break;
    case API_TIME:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%lu",*__ptr->data);
      break;
    case API_MHS:
    case API_UTILITY:
    case API_FREQ:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.2f",__ptr->data,*__ptr->data);
      break;
    case API_MHTOTAL:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.4f",__ptr->data,*__ptr->data);
      break;
    case API_TEMP:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.2f",__ptr->data,(double)*__ptr->data);
      break;
    case API_VOLTS:
    case API_AVG:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.3f",__ptr->data,(double)*__ptr->data);
      break;
    case API_HS:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.15f",__ptr->data,*__ptr->data);
      break;
    case API_DIFF:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.8f",__ptr->data,*__ptr->data);
      break;
    case API_PERCENT:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.4f",__ptr->data,*__ptr->data * 100.0);
      break;
    default:
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"API: unknown2 data type %d ignored");
        _applog(3,tmp42,false);
      }
      if (isjson) {
        add_item_buf(item,"\"");
        add_item_buf(item,"Unknown");
        add_item_buf(item,"\"");
      }
      else {
        add_item_buf(item,"Unknown");
      }
      goto LAB_0001971e;
    }
    add_item_buf(item,buf);
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
    paVar3 = __ptr->prev;
    root->prev = paVar3;
    paVar3->next = root;
    free(__ptr);
    add_item_buf(item,",");
    if (!isjson) goto LAB_000196b6;
LAB_0001974c:
    add_item_buf(item,"\"");
    add_item_buf(item,root->name);
    add_item_buf(item,"\"");
    add_item_buf(item,":");
    __ptr = root;
  } while( true );
}

