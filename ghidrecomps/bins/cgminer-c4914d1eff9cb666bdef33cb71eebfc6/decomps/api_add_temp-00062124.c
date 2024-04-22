
api_data * api_add_temp(api_data *root,char *name,float *data,_Bool copy_data)

{
  api_data *paVar1;
  _Bool copy_data_local;
  float *data_local;
  char *name_local;
  api_data *root_local;
  
  paVar1 = api_add_data_full(root,name,API_TEMP,data,copy_data);
  return paVar1;
}

