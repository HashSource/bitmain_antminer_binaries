
int parse_config_ini_array(char *str,void **pointer)

{
  char *pcVar1;
  int iVar2;
  double dVar3;
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
  
  str_len = strlen(str);
  type = 1;
  item_num = 0;
  for (i = 0; i < str_len; i = i + 1) {
    if (str[i] == '.') {
      type = 0;
    }
    if (str[i] == ',') {
      item_num = item_num + 1;
    }
  }
  item_num = item_num + 1;
  if (type == 0) {
    local_pointer = malloc(item_num * 8);
    memset(local_pointer,0,item_num * 8);
  }
  else {
    local_pointer = malloc(item_num * 4);
    memset(local_pointer,0,item_num * 4);
  }
  item_str_counter = 0;
  memset(item_str,0,0x20);
  j = 0;
  for (i_1 = 0; i_1 < str_len; i_1 = i_1 + 1) {
    if (((0x2f < (byte)str[i_1]) && ((byte)str[i_1] < 0x3a)) || (str[i_1] == '.')) {
      pcVar1 = item_str + item_str_counter;
      item_str_counter = item_str_counter + 1;
      *pcVar1 = str[i_1];
    }
    if ((str[i_1] == ',') || (str[i_1] == ']')) {
      item_str[item_str_counter] = '\0';
      if (type == 0) {
        dVar3 = atof(item_str);
        *(double *)((int)local_pointer + j * 8) = dVar3;
      }
      else {
        iVar2 = atoi(item_str);
        *(int *)((int)local_pointer + j * 4) = iVar2;
      }
      j = j + 1;
      memset(item_str,0x20,0x20);
      item_str_counter = 0;
    }
  }
  *pointer = local_pointer;
  return item_num;
}

