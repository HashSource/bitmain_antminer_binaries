
/* WARNING: Unknown calling convention */

api_data *
api_add_data_full(api_data *root,char *name,api_data_type type,void *data,_Bool copy_data)

{
  undefined1 uVar1;
  undefined2 uVar2;
  api_data *paVar3;
  char *pcVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  size_t sVar9;
  api_data *paVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  char tmp42 [2048];
  
  paVar3 = (api_data *)malloc(0x18);
  pcVar4 = (char *)__strdup(name);
  paVar3->type = type;
  paVar3->name = pcVar4;
  if (root == (api_data *)0x0) {
    paVar3->prev = paVar3;
    paVar3->next = paVar3;
    root = paVar3;
  }
  else {
    paVar10 = root->prev;
    paVar3->next = root;
    paVar3->prev = paVar10;
    root->prev = paVar3;
    paVar3->prev->next = paVar3;
  }
  paVar3->data_was_malloc = copy_data;
  if (data == (void *)0x0) {
    paVar3->data_was_malloc = false;
    data = &DAT_00045634;
    paVar3->type = API_CONST;
  }
  else if (copy_data) {
    switch(type) {
    case API_ESCAPE:
    case API_STRING:
    case API_CONST:
      sVar9 = strlen((char *)data);
      pcVar4 = (char *)malloc(sVar9 + 1);
      paVar3->data = pcVar4;
      strcpy(pcVar4,(char *)data);
      return root;
    case API_UINT8:
      puVar8 = (undefined1 *)malloc(4);
      paVar3->data = puVar8;
                    /* WARNING: Load size is inaccurate */
      *puVar8 = *data;
      return root;
    case API_INT16:
    case API_UINT16:
      puVar5 = (undefined2 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar2 = *data;
      paVar3->data = puVar5;
      *puVar5 = uVar2;
      return root;
    case API_INT:
    case API_UINT:
    case API_UINT32:
    case API_HEX32:
    case API_TIME:
      puVar6 = (undefined4 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar12 = *data;
      paVar3->data = puVar6;
      *puVar6 = uVar12;
      return root;
    case API_UINT64:
    case API_INT64:
      puVar6 = (undefined4 *)malloc(8);
                    /* WARNING: Load size is inaccurate */
      uVar12 = *data;
      uVar11 = *(undefined4 *)((int)data + 4);
      paVar3->data = puVar6;
      *puVar6 = uVar12;
      puVar6[1] = uVar11;
      return root;
    case API_DOUBLE:
    case API_ELAPSED:
    case API_MHS:
    case API_MHTOTAL:
    case API_UTILITY:
    case API_FREQ:
    case API_HS:
    case API_DIFF:
    case API_PERCENT:
      puVar7 = (undefined8 *)malloc(8);
                    /* WARNING: Load size is inaccurate */
      uVar13 = *data;
      paVar3->data = puVar7;
      *puVar7 = uVar13;
      return root;
    case API_BOOL:
      puVar8 = (undefined1 *)malloc(1);
                    /* WARNING: Load size is inaccurate */
      uVar1 = *data;
      paVar3->data = puVar8;
      *puVar8 = uVar1;
      return root;
    case API_TIMEVAL:
      puVar6 = (undefined4 *)malloc(8);
      paVar3->data = puVar6;
      uVar12 = *(undefined4 *)((int)data + 4);
                    /* WARNING: Load size is inaccurate */
      *puVar6 = *data;
      puVar6[1] = uVar12;
      return root;
    case API_TEMP:
    case API_VOLTS:
    case API_AVG:
      puVar6 = (undefined4 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar12 = *data;
      paVar3->data = puVar6;
      *puVar6 = uVar12;
      return root;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"API: unknown1 data type %d ignored",type);
      _applog(3,tmp42,false);
    }
    paVar3->type = API_STRING;
    paVar3->data_was_malloc = false;
    paVar3->data = "Unknown";
    return root;
  }
  paVar3->data = data;
  return root;
}

