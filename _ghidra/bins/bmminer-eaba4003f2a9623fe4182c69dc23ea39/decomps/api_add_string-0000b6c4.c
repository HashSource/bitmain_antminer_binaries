
api_data * api_add_string(api_data *root,char *name,char *data,_Bool copy_data)

{
  api_data *paVar1;
  _Bool copy_data_local;
  char *data_local;
  char *name_local;
  api_data *root_local;
  
  paVar1 = api_add_data_full(root,name,API_STRING,data,copy_data);
  return paVar1;
}

