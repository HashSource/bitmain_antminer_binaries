
api_data * api_add_timeval(api_data *root,char *name,timeval *data,_Bool copy_data)

{
  api_data *paVar1;
  _Bool copy_data_local;
  timeval *data_local;
  char *name_local;
  api_data *root_local;
  
  paVar1 = api_add_data_full(root,name,API_TIMEVAL,data,copy_data);
  return paVar1;
}

