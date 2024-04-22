
api_data *
api_add_data_full(api_data *root,char *name,api_data_type type,void *data,_Bool copy_data)

{
  api_data *paVar1;
  char *pcVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  void *data_local;
  api_data_type type_local;
  char *name_local;
  api_data *root_local;
  char tmp42 [2048];
  api_data *api_data;
  
  paVar1 = (api_data *)_cgmalloc(0x18,"api-btm.c","api_add_data_full",0x38c);
  pcVar2 = strdup(name);
  paVar1->name = pcVar2;
  paVar1->type = type;
  if (root == (api_data *)0x0) {
    paVar1->prev = paVar1;
    paVar1->next = paVar1;
    root_local = paVar1;
  }
  else {
    paVar1->prev = root->prev;
    root->prev = paVar1;
    paVar1->next = root;
    paVar1->prev->next = paVar1;
    root_local = root;
  }
  paVar1->data_was_malloc = copy_data;
  data_local = data;
  type_local = type;
  if (data == (void *)0x0) {
    type_local = API_CONST;
    paVar1->type = API_CONST;
    data_local = NULLSTR;
    copy_data = false;
    paVar1->data_was_malloc = false;
  }
  if (copy_data == true) {
    switch(type_local) {
    case API_ESCAPE:
    case API_STRING:
    case API_CONST:
      sVar3 = strlen((char *)data_local);
      pvVar4 = _cgmalloc(sVar3 + 1,"api-btm.c","api_add_data_full",0x3b1);
      paVar1->data = pvVar4;
      strcpy((char *)paVar1->data,(char *)data_local);
      break;
    case API_UINT8:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3b6);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined *)paVar1->data = *data_local;
      break;
    case API_INT16:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3bb);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)paVar1->data = *data_local;
      break;
    case API_UINT16:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3c0);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)paVar1->data = *data_local;
      break;
    case API_INT:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3c4);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    case API_UINT:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3c8);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    case API_UINT32:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3cc);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    case API_HEX32:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3d0);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    case API_UINT64:
      pvVar4 = _cgmalloc(8,"api-btm.c","api_add_data_full",0x3d4);
      paVar1->data = pvVar4;
      puVar5 = (undefined4 *)paVar1->data;
                    /* WARNING: Load size is inaccurate */
      uVar6 = *(undefined4 *)((int)data_local + 4);
      *puVar5 = *data_local;
      puVar5[1] = uVar6;
      break;
    case API_INT64:
      pvVar4 = _cgmalloc(8,"api-btm.c","api_add_data_full",0x3d8);
      paVar1->data = pvVar4;
      puVar5 = (undefined4 *)paVar1->data;
                    /* WARNING: Load size is inaccurate */
      uVar6 = *(undefined4 *)((int)data_local + 4);
      *puVar5 = *data_local;
      puVar5[1] = uVar6;
      break;
    case API_DOUBLE:
    case API_ELAPSED:
    case API_MHS:
    case API_MHTOTAL:
    case API_UTILITY:
    case API_FREQ:
    case API_HS:
    case API_DIFF:
    case API_PERCENT:
      pvVar4 = _cgmalloc(8,"api-btm.c","api_add_data_full",0x3e4);
      paVar1->data = pvVar4;
      puVar5 = (undefined4 *)paVar1->data;
                    /* WARNING: Load size is inaccurate */
      uVar6 = *(undefined4 *)((int)data_local + 4);
      *puVar5 = *data_local;
      puVar5[1] = uVar6;
      break;
    case API_BOOL:
      pvVar4 = _cgmalloc(1,"api-btm.c","api_add_data_full",1000);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined *)paVar1->data = *data_local;
      break;
    case API_TIMEVAL:
      pvVar4 = _cgmalloc(8,"api-btm.c","api_add_data_full",0x3ec);
      paVar1->data = pvVar4;
      memcpy(paVar1->data,data_local,8);
      break;
    case API_TIME:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3f0);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    case API_TEMP:
    case API_VOLTS:
    case API_AVG:
      pvVar4 = _cgmalloc(4,"api-btm.c","api_add_data_full",0x3f6);
      paVar1->data = pvVar4;
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)paVar1->data = *data_local;
      break;
    default:
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"API: unknown1 data type %d ignored",type_local);
        _applog(3,tmp42,false);
      }
      paVar1->type = API_STRING;
      paVar1->data_was_malloc = false;
      paVar1->data = UNKNOWN;
    }
  }
  else {
    paVar1->data = data_local;
  }
  return root_local;
}

