
int parse_config_ini_array(char *str,void **pointer)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  void **pointer_local;
  char *str_local;
  char item_str [32];
  int str_len;
  int i_1;
  int j;
  int item_str_counter;
  int i;
  void *local_pointer;
  int item_num;
  int type;
  
  sVar2 = strlen(str);
  bVar1 = true;
  item_num = 0;
  for (i = 0; i < (int)sVar2; i = i + 1) {
    if (str[i] == '.') {
      bVar1 = false;
    }
    if (str[i] == ',') {
      item_num = item_num + 1;
    }
  }
  iVar4 = item_num + 1;
  if (bVar1) {
    local_pointer = malloc(iVar4 * 4);
    memset(local_pointer,0,iVar4 * 4);
  }
  else {
    local_pointer = malloc(iVar4 * 8);
    memset(local_pointer,0,iVar4 * 8);
  }
  item_str_counter = 0;
  memset(item_str,0,0x20);
  j = 0;
  for (i_1 = 0; i_1 < (int)sVar2; i_1 = i_1 + 1) {
    if (((0x2f < (byte)str[i_1]) && ((byte)str[i_1] < 0x3a)) || (str[i_1] == '.')) {
      item_str[item_str_counter] = str[i_1];
      item_str_counter = item_str_counter + 1;
    }
    if ((str[i_1] == ',') || (str[i_1] == ']')) {
      item_str[item_str_counter] = '\0';
      if (bVar1) {
        iVar3 = atoi(item_str);
        *(int *)((int)local_pointer + j * 4) = iVar3;
      }
      else {
        dVar5 = atof(item_str);
        *(double *)((int)local_pointer + j * 8) = dVar5;
      }
      j = j + 1;
      memset(item_str,0x20,0x20);
      item_str_counter = 0;
    }
  }
  *pointer = local_pointer;
  return iVar4;
}

