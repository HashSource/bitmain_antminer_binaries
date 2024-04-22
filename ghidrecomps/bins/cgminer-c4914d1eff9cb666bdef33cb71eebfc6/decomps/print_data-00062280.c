
api_data * print_data(io_data *io_data,api_data *root,_Bool isjson,_Bool precom)

{
  bool bVar1;
  bool bVar2;
  K_ITEM *item_00;
  char *pcVar3;
  api_data *paVar4;
  char *pcVar5;
  _Bool precom_local;
  _Bool isjson_local;
  api_data *root_local;
  io_data *io_data_local;
  char tmp42 [2048];
  char buf [64];
  api_data *tmp;
  char *escape;
  char *original;
  K_ITEM *item;
  _Bool first;
  _Bool done;
  
  bVar1 = true;
  _cg_wlock(strbufs->lock,"api-btm.c","print_data",0x4a8);
  item_00 = _k_unlink_head(strbufs,"api-btm.c","print_data",0x4a9);
  _cg_wunlock(strbufs->lock,"api-btm.c","print_data",0x4aa);
  *(undefined4 *)((int)item_00->data + 4) = 0;
  if (precom) {
    add_item_buf(item_00,COMMA);
  }
  root_local = root;
  if (isjson) {
    add_item_buf(item_00,"{");
    root_local = root;
  }
  while (root_local != (api_data *)0x0) {
    if (!bVar1) {
      add_item_buf(item_00,COMMA);
    }
    if (isjson) {
      add_item_buf(item_00,"\"");
    }
    add_item_buf(item_00,root_local->name);
    if (isjson) {
      add_item_buf(item_00,"\"");
      add_item_buf(item_00,":");
    }
    else {
      add_item_buf(item_00,"=");
    }
    bVar1 = false;
    bVar2 = false;
    switch(root_local->type) {
    case API_ESCAPE:
      pcVar5 = (char *)root_local->data;
      pcVar3 = escape_string((char *)root_local->data,isjson);
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      add_item_buf(item_00,pcVar3);
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      if (pcVar3 != pcVar5) {
        free(pcVar3);
      }
      bVar2 = true;
      break;
    case API_STRING:
    case API_CONST:
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      add_item_buf(item_00,(char *)root_local->data);
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      bVar2 = true;
      break;
    case API_UINT8:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",(uint)*root_local->data);
      break;
    case API_INT16:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%d",(int)*root_local->data);
      break;
    case API_UINT16:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",(uint)*root_local->data);
      break;
    case API_INT:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%d",*root_local->data);
      break;
    case API_UINT:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",*root_local->data);
      break;
    case API_UINT32:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%u",*root_local->data);
      break;
    case API_HEX32:
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"0x%08x",*root_local->data);
      add_item_buf(item_00,buf);
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      bVar2 = true;
      break;
    case API_UINT64:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%llu",*root_local->data,*root_local->data);
      break;
    case API_INT64:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%lld",*root_local->data,*root_local->data);
      break;
    case API_DOUBLE:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%f",*root_local->data,*root_local->data);
      break;
    case API_ELAPSED:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.0f",*root_local->data,*root_local->data);
      break;
    case API_BOOL:
                    /* WARNING: Load size is inaccurate */
      pcVar3 = FALSESTR;
      if (*root_local->data != '\0') {
        pcVar3 = TRUESTR;
      }
      snprintf(buf,0x40,"%s",pcVar3);
      break;
    case API_TIMEVAL:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%ld.%06ld",*root_local->data,*(undefined4 *)((int)root_local->data + 4));
      break;
    case API_TIME:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%lu",*root_local->data);
      break;
    case API_MHS:
    case API_UTILITY:
    case API_FREQ:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.2f",*root_local->data,*root_local->data);
      break;
    case API_MHTOTAL:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.4f",*root_local->data,*root_local->data);
      break;
    case API_TEMP:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.2f",buf,(double)*root_local->data);
      break;
    case API_VOLTS:
    case API_AVG:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.3f",buf,(double)*root_local->data);
      break;
    case API_HS:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.15f",*root_local->data,*root_local->data);
      break;
    case API_DIFF:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.8f",*root_local->data,*root_local->data);
      break;
    case API_PERCENT:
                    /* WARNING: Load size is inaccurate */
      snprintf(buf,0x40,"%.4f",buf,*root_local->data * DAT_00062a90);
      break;
    default:
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"API: unknown2 data type %d ignored",root_local->type);
        _applog(3,tmp42,false);
      }
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      add_item_buf(item_00,UNKNOWN);
      if (isjson) {
        add_item_buf(item_00,"\"");
      }
      bVar2 = true;
    }
    if (!bVar2) {
      add_item_buf(item_00,buf);
    }
    free(root_local->name);
    if (root_local->data_was_malloc != false) {
      free(root_local->data);
    }
    if (root_local == root_local->next) {
      free(root_local);
      root_local = (api_data *)0x0;
    }
    else {
      paVar4 = root_local->next;
      paVar4->prev = root_local->prev;
      paVar4->prev->next = paVar4;
      free(root_local);
      root_local = paVar4;
    }
  }
  if (isjson) {
    add_item_buf(item_00,"}");
  }
  else {
    add_item_buf(item_00,(char *)&DAT_00092f08);
  }
                    /* WARNING: Load size is inaccurate */
  io_add(io_data,*item_00->data);
  _cg_wlock(strbufs->lock,"api-btm.c","print_data",0x554);
  _k_add_head(strbufs,item_00,"api-btm.c","print_data",0x555);
  _cg_wunlock(strbufs->lock,"api-btm.c","print_data",0x556);
  return (api_data *)0x0;
}

