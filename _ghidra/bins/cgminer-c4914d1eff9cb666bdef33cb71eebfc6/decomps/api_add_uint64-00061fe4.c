
api_data * api_add_uint64(api_data *root,char *name,uint64_t *data,_Bool copy_data)

{
  api_data *paVar1;
  _Bool copy_data_local;
  uint64_t *data_local;
  char *name_local;
  api_data *root_local;
  
  paVar1 = api_add_data_full(root,name,API_UINT64,data,copy_data);
  return paVar1;
}

