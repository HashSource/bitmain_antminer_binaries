
api_data * api_add_int64(api_data *root,char *name,int64_t *data,_Bool copy_data)

{
  api_data *paVar1;
  _Bool copy_data_local;
  int64_t *data_local;
  char *name_local;
  api_data *root_local;
  
  paVar1 = api_add_data_full(root,name,API_INT64,data,copy_data);
  return paVar1;
}

