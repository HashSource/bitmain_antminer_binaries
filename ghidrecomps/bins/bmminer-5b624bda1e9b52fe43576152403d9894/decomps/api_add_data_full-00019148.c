
/* WARNING: Unknown calling convention */

api_data *
api_add_data_full(api_data *root,char *name,api_data_type type,void *data,_Bool copy_data)

{
  undefined uVar1;
  undefined2 uVar2;
  void *pvVar3;
  api_data *paVar4;
  api_data *api_data;
  char *pcVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  undefined *puVar9;
  size_t sVar10;
  api_data *paVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  char tmp42 [2048];
  
  paVar4 = (api_data *)malloc(0x18);
  pcVar5 = (char *)__strdup(name);
  paVar4->type = type;
  paVar4->name = pcVar5;
  if (root == (api_data *)0x0) {
    paVar4->prev = paVar4;
    paVar4->next = paVar4;
    root = paVar4;
  }
  else {
    paVar11 = root->prev;
    paVar4->next = root;
    paVar4->prev = paVar11;
    root->prev = paVar4;
    paVar4->prev->next = paVar4;
  }
  paVar4->data_was_malloc = copy_data;
  if (data == (void *)0x0) {
    paVar4->data_was_malloc = false;
    data = DAT_00019298;
    paVar4->type = API_CONST;
  }
  else if (copy_data) {
    switch(type) {
    case API_ESCAPE:
    case API_STRING:
    case API_CONST:
      sVar10 = strlen((char *)data);
      pcVar5 = (char *)malloc(sVar10 + 1);
      paVar4->data = pcVar5;
      strcpy(pcVar5,(char *)data);
      return root;
    case API_UINT8:
      puVar9 = (undefined *)malloc(4);
      paVar4->data = puVar9;
                    /* WARNING: Load size is inaccurate */
      *puVar9 = *data;
      return root;
    case API_INT16:
    case API_UINT16:
      puVar6 = (undefined2 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar2 = *data;
      paVar4->data = puVar6;
      *puVar6 = uVar2;
      return root;
    case API_INT:
    case API_UINT:
    case API_UINT32:
    case API_HEX32:
    case API_TIME:
      puVar7 = (undefined4 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar13 = *data;
      paVar4->data = puVar7;
      *puVar7 = uVar13;
      return root;
    case API_UINT64:
    case API_INT64:
      puVar7 = (undefined4 *)malloc(8);
                    /* WARNING: Load size is inaccurate */
      uVar13 = *data;
      uVar12 = *(undefined4 *)((int)data + 4);
      paVar4->data = puVar7;
      *puVar7 = uVar13;
      puVar7[1] = uVar12;
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
      puVar8 = (undefined8 *)malloc(8);
                    /* WARNING: Load size is inaccurate */
      uVar14 = *data;
      paVar4->data = puVar8;
      *puVar8 = uVar14;
      return root;
    case API_BOOL:
      puVar9 = (undefined *)malloc(1);
                    /* WARNING: Load size is inaccurate */
      uVar1 = *data;
      paVar4->data = puVar9;
      *puVar9 = uVar1;
      return root;
    case API_TIMEVAL:
      puVar7 = (undefined4 *)malloc(8);
      paVar4->data = puVar7;
      uVar13 = *(undefined4 *)((int)data + 4);
                    /* WARNING: Load size is inaccurate */
      *puVar7 = *data;
      puVar7[1] = uVar13;
      return root;
    case API_TEMP:
    case API_VOLTS:
    case API_AVG:
      puVar7 = (undefined4 *)malloc(4);
                    /* WARNING: Load size is inaccurate */
      uVar13 = *data;
      paVar4->data = puVar7;
      *puVar7 = uVar13;
      return root;
    }
    if (((*DAT_0001929c != '\0') || (*DAT_000192a0 != '\0')) || (2 < *DAT_000192a4)) {
      snprintf(tmp42,0x800,DAT_000192a8,type);
      _applog(3,tmp42,false);
    }
    pvVar3 = DAT_000192ac;
    paVar4->type = API_STRING;
    paVar4->data_was_malloc = false;
    paVar4->data = pvVar3;
    return root;
  }
  paVar4->data = data;
  return root;
}

