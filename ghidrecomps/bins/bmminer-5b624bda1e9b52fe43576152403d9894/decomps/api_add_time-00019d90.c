
/* WARNING: Unknown calling convention */

api_data * api_add_time(api_data *root,char *name,time_t *data,_Bool copy_data)

{
  api_data *paVar1;
  
  paVar1 = api_add_data_full(root,name,API_TIME,data,copy_data);
  return paVar1;
}

